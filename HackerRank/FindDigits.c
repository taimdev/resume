#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        scanf("%d",&n);
          
        
        int number = n;
        int numlen = 0;
        
        while (number != 0) {
            number /= 10;
            numlen++;
        }
        
        int numarray[numlen] ;
        int arraycounter = n;
        int counter = 0;
        
        while (arraycounter != 0) {
            numarray[numlen - counter - 1] = arraycounter % 10;
            arraycounter /= 10;
            counter ++;
        }
        
        counter = 0;
        int divisor;
        int store = 0;
        
        while (counter < numlen) {
            divisor = numarray[counter];
            if (divisor != 0) {
                if (n % divisor == 0) {
                    store ++;
                }        
            }
        counter ++;
        }
        
    printf("%d\n",store);
    }
    return 0;
}
