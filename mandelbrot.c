// mandelbrot.c
// Emily Chen z5098910
// Taimur Azhar z5116684
// Tue-12 Kora, William Archinal
// April 22, 2016
// Displays the mandelbrot set for given coordinates
// Provides a viewer if no coordinates are specified in URL

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>

#include "pixelColor.h"
#include "mandelbrot.h"

#define MAX_STEPS 256
#define MAX_MAGNITUDE 2
#define HALF_SIZE 256.0
#define SIZE 512
#define TRUE 1
#define FALSE 0
//-----------------------bmpServer-----------------------
#define SIMPLE_SERVER_VERSION 1.0
#define REQUEST_BUFFER_SIZE 1000
#define DEFAULT_PORT 1917
#define NUMBER_OF_PAGES_TO_SERVE 100 
// after serving this many pages the server will halt
#define START_REQUEST_INDEX 5
//------------------------header-------------------------
#define BODY_START 54
#define BYTES_PER_PIXEL 3
//-----------------------extract-------------------------
#define MAX_SIZE 17
#define MAX_DECIMALS 1000000000000  //12 decimal places precision
//-------------------------------------------------------

typedef struct _complex {
   double real;
   double imaginary;
} complex;
typedef struct _triordinate {
   double x;
   double y;
   int z;
} triordinate;

//-----------------------mandelbrot----------------------
static complex add(complex c1, complex c2);
static complex multiply(complex c1, complex c2);

int escapeSteps (double x, double y);
static void writeBmp(double x, double y, int zoomlvl, unsigned char* bmp);

//-----------------------bmpServer-----------------------
static int waitForConnection (int serverSocket);
static int makeServerSocket (int portno);
static void serveBMP (int socket, int haveRequest, triordinate extract);
static void startServer();    //own function
//-----------------------extract-------------------------
static triordinate extract (char *message);
static double myAtoD (char *message);
static long myAtoL (char *message);
//-------------------------------------------------------

int main (int argc, char * argv[]) {

   startServer();
   
   return EXIT_SUCCESS;
}

int escapeSteps (double x, double y) {
   complex initialC = {x, y};
   complex currentZ = {0, 0};
   complex currentZSquared;
   
   int stepCounter = 0;
   int iteration = 0;
   double magnitude = 0;
   
   while (stepCounter < MAX_STEPS) {
   
      if (magnitude < MAX_MAGNITUDE) {
         currentZSquared = multiply(currentZ, currentZ);      
         currentZ = add(currentZSquared, initialC);                  
   
         magnitude = sqrt(pow(currentZ.real, 2) +       
                     pow(currentZ.imaginary, 2));
         iteration++;
      }
   
      stepCounter++;
   }

   return iteration;
}

static void writeBmp(double x, double y, int zoomlvl, unsigned char* bmp) {
   int i = BODY_START;
   double xlimit, ylimit, xMax, yMax;
   double increment = pow(2, zoomlvl);

   xlimit = x - (HALF_SIZE / increment);
   ylimit = y - (HALF_SIZE / increment);

   xMax = x + (HALF_SIZE / increment);
   yMax = y + (HALF_SIZE / increment);

   complex topRight = {xMax,yMax};
   complex location = {xlimit,ylimit};

   double scale = (1 / increment);

   while (location.imaginary < topRight.imaginary) {
      while (location.real < topRight.real) {
         int steps = escapeSteps(location.real, location.imaginary);
         bmp[i] = stepsToBlue(steps);
         i++;
         bmp[i] = stepsToGreen(steps);
         i++;
         bmp[i] = stepsToRed(steps);  
         i++;
         location.real = location.real + scale;
      }
      location.real = location.real  - 2 * (HALF_SIZE / increment) ;
      location.imaginary = location.imaginary + scale;
   }
}

//-------------complex manipulation functions------------
static complex add(complex c1, complex c2) {
   complex result;
   
   result.real = c1.real + c2.real;
   result.imaginary = c1.imaginary + c2.imaginary;
   
   return result;
}

static complex multiply(complex c1, complex c2) {
   complex result;
   
   result.real = (c1.real * c2.real) - (c1.imaginary * c2.imaginary);
   result.imaginary = (c1.real * c2.imaginary) + (c1.imaginary * c2.real);
   
   return result;
}

//-----------------bmpServer functions-------------------
static void startServer() {
   printf ("************************************\n");
   printf ("Starting simple server %f\n", SIMPLE_SERVER_VERSION);
   printf ("Serving bmps since 2012\n");   
   
   int serverSocket = makeServerSocket (DEFAULT_PORT);   
   printf ("Access this server at http://localhost:%d/\n",       
            DEFAULT_PORT);
   printf ("************************************\n");
   
   //string for URL
   char request[REQUEST_BUFFER_SIZE];

   int haveRequest;
   triordinate position;
   
   int numberServed = 0;
   while (numberServed < NUMBER_OF_PAGES_TO_SERVE) {
      
      printf ("*** So far served %d pages ***\n", numberServed);
      
      int connectionSocket = waitForConnection (serverSocket);
      // wait for a request to be sent from a web browser, open a new
      // connection for this conversation
      
      // read the first line of the request sent by the browser  
      int bytesRead;
      bytesRead = read (connectionSocket, request, (sizeof request)-1);
      assert (bytesRead >= 0); 
      // were we able to read any data from the connection?
      if (request[START_REQUEST_INDEX] == ' ') {
         //i.e. empty request: "GET / HTTP/1.1"
         //space at index 5 (START_REQUEST_INDEX)
         haveRequest = FALSE;
      } else {
         haveRequest = TRUE;
         position = extract(request);  
      }
      
      // print entire request to the console 
      printf (" *** Received http request ***\n %s\n", request);
      
      //send the browser a simple html page using http
      printf (" *** Sending http response ***\n");
      serveBMP(connectionSocket, haveRequest, position);
      
      // close the connection after sending the page- 
      // keep aust beautiful
      close(connectionSocket);
      
      numberServed++;
   } 
   
   // close the server connection after we are done- keep aust beautiful
   printf ("** shutting down the server **\n");
   close (serverSocket);
}

static void serveBMP (int socket, int haveRequest, triordinate position) {
   char* message;
   
   if (haveRequest == FALSE) {
      //respond w/ Mandelbrot viewer
      
      message = "HTTP/1.0 200 OK\r\n"
                "Content-Type: text/html\n"
                "\r\n";
      printf ("about to send=> %s\n", message);
      write (socket, message, strlen (message));
      
      message =
      "<!DOCTYPE html>\n"
      "<script src="
      "\"http://almondbread.cse.unsw.edu.au/tiles.js\"></script>"
      "\n";    
      write (socket, message, strlen (message));
   } else {
      //serve a BMP of the Mandelbrot set at the given x, y, and zoom
      
      message = "HTTP/1.0 200 OK\r\n"
                "Content-Type: image/bmp\r\n"
                "\r\n";
      printf ("about to send=> %s\n", message);
      write (socket, message, strlen (message));
      
      //hardcoded header for 512 x 512 bmp file
      unsigned char bmp[BODY_START + (SIZE * SIZE * BYTES_PER_PIXEL)] ={
         0x42, 0x4d, 0x36, 0x00, 0x0c, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
         0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02,
         0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x13, 0x0b,
         0x00, 0x00, 0x13, 0x0b, 0x00, 0x00, 0x00, 0x00,
         0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
      
      writeBmp(position.x, position.y, position.z, bmp);
      write (socket, bmp, sizeof(bmp));
   }
   
}

// start the server listening on the specified port number
static int makeServerSocket (int portNumber) { 
   
   // create socket
   int serverSocket = socket (AF_INET, SOCK_STREAM, 0);
   assert (serverSocket >= 0);   
   // error opening socket
   
   // bind socket to listening port
   struct sockaddr_in serverAddress;
   memset ((char *) &serverAddress, 0,sizeof (serverAddress));
   
   serverAddress.sin_family      = AF_INET;
   serverAddress.sin_addr.s_addr = INADDR_ANY;
   serverAddress.sin_port        = htons (portNumber);
   
   // let the server start immediately after a previous shutdown
   int optionValue = 1;
   setsockopt (
      serverSocket,
      SOL_SOCKET,
      SO_REUSEADDR,
      &optionValue, 
      sizeof(int)
   );

   int bindSuccess = 
      bind (
         serverSocket, 
         (struct sockaddr *) &serverAddress,
         sizeof (serverAddress)
      );
   
   assert (bindSuccess >= 0);
   // if this assert fails wait a short while to let the operating 
   // system clear the port before trying again
   
   return serverSocket;
}

// wait for a browser to request a connection,
// returns the socket on which the conversation will take place
static int waitForConnection (int serverSocket) {
   // listen for a connection
   const int serverMaxBacklog = 10;
   listen (serverSocket, serverMaxBacklog);
   
   // accept the connection
   struct sockaddr_in clientAddress;
   socklen_t clientLen = sizeof (clientAddress);
   int connectionSocket = 
      accept (
         serverSocket, 
         (struct sockaddr *) &clientAddress, 
         &clientLen
      );
   
   assert (connectionSocket >= 0);
   // error on accept
   
   return (connectionSocket);
}

//-----------------extract functions---------------------
//extract the x, y, zoom values from a string
static triordinate extract (char *message) {
   triordinate data;
   
   int counter = 0;
   char holder[MAX_SIZE];  //holder string for part of the string
   int holderCounter;
   
   // request is of type: GET /tile_x-1.0_y0.5_z8.bmp HTTP/1.1
   // so use b as sentinel character
   while (message[counter] != 'b') {
      
      if (message[counter] == 'x') {
         
         holderCounter = 0;
         
         counter++;  //skip past the x
         /*
            see if you can turn this into a function, avoid repetition
            ^ would have to return counter
            would have to re-initialize counter (repetition ≈ same)
         */
         //get the values in the string for x-coordinate
         while (message[counter] != '_') {
            holder[holderCounter] = message[counter];
            holderCounter++;
            
            counter++;
         }
         holder[holderCounter] = '\0';
         
         //store double version of coordinates in struct
         data.x = myAtoD(holder);
         counter--;
      } else if (message[counter] == 'y') {
         holderCounter = 0;
         
         //clear the holder array
         memset(holder, '\0', MAX_SIZE); 
      
         counter++;
         //get the values in the string for y-coordinate
         while (message[counter] != '_') {
            holder[holderCounter] = message[counter];
            holderCounter++;
            
            counter++;
         }
      
         data.y = myAtoD(holder);
         counter--;
      } else if (message[counter] == 'z') {
         holderCounter = 0;
         //clear the holder array
         memset(holder, '\0', MAX_SIZE);
      
         counter++;
         //get the values in the string for y-coordinate
         while (message[counter] != '.') {
            holder[holderCounter] = message[counter];
            holderCounter++;
            
            counter++;
         }
      
         data.z = myAtoL(holder);
         counter--;
      }
   
      counter++;
   }

   return data;
}

//convert a string into a double
static double myAtoD (char *message) {
   int counter = 0;
   int isPositive;
   int decimalPlace = 1;
   double extract = 0;
   double charConverted;
   
   //see if negative or positive
   if (message[0] == '-') {
      isPositive = FALSE;
   } else {
      isPositive = TRUE;
   }
   
   //loop through characters in string
   while (message[counter] != '\0') {
      
      charConverted = message[counter] - '0';
      
      if ((message[counter] != '.') && (message[counter] != '-')) {
         //before the decimal
         
         if (((isPositive == TRUE) && (counter == 0))
            || ((isPositive == FALSE) && (counter == 1))) {
            //first time reading in a whole number
            
            extract = charConverted;
         } else {
            //second+ time reading in a whole number
            
            extract = (extract * 10) + charConverted;
         }
   
      } else if (message[counter] == '.') {
         //after the decimal
         
         //loop through the rest of the string
         counter++;
         while (message[counter] != '\0') {
            charConverted = message[counter] - '0';
            
            extract += charConverted * pow(10, -decimalPlace);
            decimalPlace++;
            
            counter++;
         }
         
         counter--;  //put index back to null terminator 
      } else {
         // negative sign, do nothing
      }
      
      counter++;
   }
   
   //negative case
   if (isPositive == FALSE) {
      extract = -extract;
   }
   
   //round to avoid double type representation errors
   extract = round(extract * MAX_DECIMALS) / MAX_DECIMALS;

   return extract;
}

//convert a string into a long
static long myAtoL (char *message) {
   long charConverted;
   long extract = 0;
   int counter = 0;
   int isPositive;
   
   //see if negative or positive
   if (message[0] == '-') {
      isPositive = FALSE;
   } else {
      isPositive = TRUE;
   }
   
   //loop through string
   while (message[counter] != '\0') {
   
      charConverted = message[counter] - '0';
      
      if (((isPositive == TRUE) && (counter == 0))
         || ((isPositive == FALSE) && (counter == 1))) {
         //first time reading in a whole number
            
         extract = charConverted;
      } else {
         //second+ time reading in a whole number
            
         extract = (extract * 10) + charConverted;
      }
      
      counter++;
   }
   
   //negative case
   if (isPositive == FALSE) {
      extract = -extract;
   }
   
   return extract;
}