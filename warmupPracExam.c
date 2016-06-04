 //  Taimur Azhar z5116684
 //  tue12-kora William Archinal
 //  09/04/2016
 //  Prints out a nxn square based on the input given

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
   int inputNumber = 0;
   int counter = 0;

   //int counterCol = 0;
   int counterRow = 0;

   scanf("%d", &inputNumber);

   while (counter < inputNumber) {
   	  //printf("Counter%d\n",counter);
      while (counterRow < inputNumber) {
      	 //prints out the row depening on the value of the counter and rowcounter variables
         if ((counterRow == counter) || (counterRow == inputNumber - counter - 1)) {
         	printf("#");
         } else {
            printf("-");
         }

      counterRow++;
      }

      printf("\n");
      counterRow = 0;
      counter ++;
   }

   return EXIT_SUCCESS;
}