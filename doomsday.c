/*
 *  doomsday.c
 *  A program to test a function dayOfWeek which determines which
 *  day of the week a particular date falls on.
 *  (only for dates after the start of the Gregorian calendar).
 *
 *  Program stub created by Richard Buckland on 17/03/14
 *  This program by Taimur Azhar z5116684
 *  Freely licensed under Creative Commons CC-BY-3.0
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define THURSDAY 0
#define FRIDAY   1
#define SATURDAY 2
#define SUNDAY   3
#define MONDAY   4
#define TUESDAY  5
#define WEDNESDAY 6

#define TRUE 1
#define FALSE 0
#define DAYS_PER_WEEK 7

int dayOfWeek (int doomsday, int leapYear, int month, int day);
int suitableCaseDay (int month, int leapYear);

int main (int argc, char *argv[]) {
   assert (dayOfWeek (THURSDAY,  FALSE,  4,  4) == THURSDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  6,  6) == FRIDAY);
   assert (dayOfWeek (MONDAY,    FALSE,  8,  8) == MONDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 10, 10) == WEDNESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 12, 12) == FRIDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  9,  5) == THURSDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  5,  9) == FRIDAY);
   assert (dayOfWeek (SUNDAY,    FALSE,  7, 11) == SUNDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 11,  7) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE,  3,  7) == WEDNESDAY);

   assert (dayOfWeek (THURSDAY,  FALSE,  4,  5) == FRIDAY);
   assert (dayOfWeek (SATURDAY,  FALSE,  6,  5) == FRIDAY);
   assert (dayOfWeek (MONDAY,    FALSE,  8,  9) == TUESDAY);
   assert (dayOfWeek (WEDNESDAY, FALSE, 10,  9) == TUESDAY);
   assert (dayOfWeek (FRIDAY,    FALSE, 12, 20) == SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  9,  9) == MONDAY);
   assert (dayOfWeek (FRIDAY,    FALSE,  5,  5) == MONDAY);
   assert (dayOfWeek (SUNDAY,    FALSE,  7,  7) == WEDNESDAY);
   assert (dayOfWeek (TUESDAY,   FALSE, 11, 11) == SATURDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  3, 30) == SATURDAY);

   assert (dayOfWeek (TUESDAY,   FALSE,  2,  28) == TUESDAY);
   assert (dayOfWeek (TUESDAY,   FALSE,  2,  27) == MONDAY);
   assert (dayOfWeek (THURSDAY,  FALSE,  1,  3)  == THURSDAY);

   printf ("all tests passed - You are awesome!\n");
   return EXIT_SUCCESS;
}


// given the doomsday for a year, and whether or not it is a
// leap year, this function return the day of the week for any
// given month and day in the year.
int dayOfWeek (int doomsday, int leapYear, int month, int day) {

   int daysDoomsday, suitMonth, doomsDay;

   suitMonth = suitableCaseDay (month, leapYear);


   // Figures out how many days between the doomsday and given date
   daysDoomsday = (day - suitMonth);
   //Adds 35 to ensure positive value becuase negative doesnt modulus then modulus to find days in the same week
   doomsDay = (daysDoomsday + 7 * 5 ) % 7;
   printf("%d\n",doomsDay);

   int dayOfWeek;
   // Adds the Doomsday and the difference to find the new day the modulus in case it goes over the limit
   dayOfWeek = (doomsDay + doomsday) % 7;
   return (dayOfWeek);
}

int suitableCaseDay (int month, int leapYear) {

  // The doomsdays are 28-29/2, 7/3, 4/4, 9/5, 6/6,
  // 11/7, 8/8, 5/9, 10/10, 7/11, 12/12

   int jan1, feb2, mar3, apr4, may5, jun6;
   int jul7, aug8, sep9, oct10, nov11, dec12;
   int suitMonth = 0;

  // Each Doomsday date for each month

   jan1 = 3;
   feb2 = 28;
   mar3 = 7;
   apr4 = 4;
   may5 = 9;
   jun6 = 6;
   jul7 = 11;
   aug8 = 8;
   sep9 = 5;
   oct10 = 10;
   nov11 = 7;
   dec12 = 12;

  // If leap year then changes doomsday for a few dates
   if (leapYear) {
      feb2 = 29;
      jan1 = 4;
   }


  // Checks the month so that the correct doomsday month/day is used
   if (month == 1) {
      suitMonth = jan1;
   } else if (month == 2) {
      suitMonth = feb2;
   } else if (month == 3) {
      suitMonth = mar3;
   } else if (month == 4) {
      suitMonth = apr4;
   } else if (month == 5) {
      suitMonth = may5;
   } else if (month == 6) {
      suitMonth = jun6;
   } else if (month == 7) {
      suitMonth = jul7;
   } else if (month == 8) {
      suitMonth = aug8;
   } else if (month == 9) {
      suitMonth = sep9;
   } else if (month == 10) {
      suitMonth = oct10;
   } else if (month == 11) {
      suitMonth = nov11;
   } else if (month == 12) {
      suitMonth = dec12;
   }

   return suitMonth;
}
