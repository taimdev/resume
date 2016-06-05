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
    int arr[n];
    for(int arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&arr[arr_i]);
    }
    
    int counter;
    double neg = 0;
    double pos = 0;
    double zero = 0;
    while (counter < n) {
        if (arr[counter] < 0){
            neg ++;
        } else if (arr[counter] > 0) {
            pos++;
        } else if (arr[counter] == 0) {
            zero++;
        }
    counter ++;
    }

    //printf("%lf\n",neg);
    //printf("%lf\n",pos);
    //printf("%lf\n",zero);      
    
    
    
    double negdec = neg/n;
    double posdec = pos/n;
    double zerodec = zero/n;
    
    printf("%lf\n",posdec);
    printf("%lf\n",negdec);
    printf("%lf\n",zerodec);    
    
    return 0;
}