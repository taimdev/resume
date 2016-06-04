 //  Taimur Azhar z5116684
 //  tue12-kora William Archinal
 //  22/03/2016
 //  Danish Flag, prints out the danish flag
 /*  ** *********
     ** *********

     ** *********
     ** *********
 */


#include <stdio.h>
#include <stdlib.h>

void showDanish(void);

int main(int argc, char* argv[]) {

   showDanish();

   return EXIT_SUCCESS;
}

void showDanish(void){

   int col = 0; // 12 columns
   int row = 0;  // 2 rows with a space and another 2 spaces
   int flagHalf = 0;
   
   while (flagHalf <= 1) {
      while (row <= 1) {
         while (col < 12) {
            if (col != 2) {
               printf("*");
            } else {
               printf(" ");
            }
         col++;
         }
       printf("\n");
       row++;
       col = 0; 
     }
   if (flagHalf == 0) {
      printf("\n");
   }
   flagHalf++;
   row = 0;
   }
}
