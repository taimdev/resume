#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    scanf("%d",&n);
    
    int countercol = 0;
    int counterrow = 1;
    int counterstr = 0;
    int counter = 1;
    
    while (countercol < n) {
        while (counterrow < n) {
            printf(" ");
            counterrow++;
        }
        while (counterstr < counter) {
            printf("#");
            counterstr++;
        }
    counter ++;
    counterrow = counter;
    counterstr = 0;
    countercol++;
    printf("\n");
    }
    return 0;
}