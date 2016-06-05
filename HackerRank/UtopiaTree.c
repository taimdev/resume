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
        
        int height = 1;
        int counter = 0;
        while (counter < n) {
            if (counter % 2 == 0) {
                height = height * 2;
            } else {
                height ++;
            }
        //printf("height is %d\n",height);
        counter ++;
        }
     printf("%d\n",height);   
        
    }
    return 0;
}
