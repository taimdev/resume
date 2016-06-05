#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int value;
    scanf("%d", &value);
    
    int len;
    scanf("%d", &len);
    
    int array[len];
    
    for (int n = 0; n < len; n ++) {
        scanf("%d", &array[n]);        
    }
    
    int counter = 0;
    int store = 0;
    while (counter < len) {
        if (value == array[counter]) {
            store = counter;
        }
    counter ++;
    }
    
    printf("%d", store);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}