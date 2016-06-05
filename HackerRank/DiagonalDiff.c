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
    int a[n][n];
    for(int a_i = 0; a_i < n; a_i++){
       for(int a_j = 0; a_j < n; a_j++){
          
          scanf("%d",&a[a_i][a_j]);
       }
    }
    
    int colcounter = 0;
    int rowcounter = 0;
    int sum1 = 0;
    int sum2 = 0;
    int ans = 0;
    
    while (colcounter < n) {
        while (rowcounter < n) {
            if (rowcounter == colcounter) {
                sum1 += a[colcounter][rowcounter];
                //printf("sum1 was incremented by %d\n",a[colcounter][rowcounter]);
            } 
            if (rowcounter + colcounter == (n-1)) {
                sum2 += a[colcounter][rowcounter];
                //printf("sum2 was incremented by %d\n",a[colcounter][rowcounter]);
            }
        rowcounter ++;
        }
    rowcounter = 0;
    colcounter ++;
    }
    //printf("sum1 is %d\n", sum1); 
    //printf("sum2 is %d\n", sum2); 
    ans = sum2 - sum1;
    if (ans < 0) {
        ans = -ans;
    }
    printf("%d", ans);  
    
    
    
    return 0;
}