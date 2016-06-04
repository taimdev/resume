// Taimur Azhar and Grace Hua
// 08/03/2016
// Function for taking a year above 1582 and returns 1 for leap year and 0 otherwise
// Checks if input is leap year
// 2000 1900 2100 1500 1111 2196 1984
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <assert.h>
# define GREG_CAL_START_YEAR 1582

int isLeapYear (int year);

int main (int argc, char * argv [] ) {
   int year ;
   int leapYear;
   printf("please enter the year you are interested in\n");
   scanf ("%d",&year);

   leapYear = isLeapYear(year);

   if (leapYear == 1) {
      printf("%d is a leap year!\n",year);
   } else {
      printf("%d is not a leap year!\n", year);
   }
   return EXIT_SUCCESS;
}


int isLeapYear (int year) {
   assert (year >= GREG_CAL_START_YEAR);
   int returnValue;

   if (year % 4 == 0 ) {
      if (year %100 != 0) {
         returnValue = 1;
      } else if (year % 400 == 0) {
         returnValue = 1;
      } else {
         returnValue = 0;
      }
   } else {
      returnValue = 0;
   }

   return returnValue;

}
