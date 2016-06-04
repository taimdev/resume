 //  Taimur Azhar z5116684 and Grace Hua z5116714
 //  tue12-kora William Archinal
 //  22/03/2016
 //  Rot13.c Function. Encodes a character according to the Caeser Cipher rotated by 13

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define FIRSTHALF 1
#define SECONDHALF -1

char encode (char letter);
char whichHalf(char letter);
void testencode (void);

int main(int argc, char* argv[]) {
   char inputLetter, encodedLetter;
   printf("Enter a letter: \n");
   scanf("%c",&inputLetter);

   encodedLetter = encode(inputLetter);
   printf("%c\n",encodedLetter);

   return EXIT_SUCCESS;
}

char encode (char letter) {
   char encodedLetter;
   int halfNo;
   halfNo = whichHalf(letter);
   if ((letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122)) {
      encodedLetter = letter + 13 * halfNo;
   } else {
   	encodedLetter = letter;
   }
   return encodedLetter;
}

char whichHalf(char letter) {
   int halfNo;

   if ((letter >= 65 && letter <= 77) || (letter >= 97 && letter <= 109)) {
      halfNo = FIRSTHALF;
   } else {
      halfNo = SECONDHALF;
   }
   return halfNo;
}

void testencode (void) {
   assert (encode('A') == 'N');
   assert (encode('a') == 'n');
   assert (encode('U') == 'H');
   assert (encode('u') == 'h');
   assert (encode('M') == 'Z');
   assert (encode('m') == 'z');
   assert (encode(1) == 1);
   assert (encode('&') == '&');
}
