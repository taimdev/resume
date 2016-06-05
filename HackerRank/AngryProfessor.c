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
        int k; 
        scanf("%d %d",&n,&k);
        int a[n];
        for(int a_i = 0; a_i < n; a_i++){
           scanf("%d",&a[a_i]);
        }
        int students = n;
        int cancel = k;
        int counter = 0;
        int earlystud = 0;
        while (counter < n) {
            if (a[counter] <= 0) {
                earlystud ++;
                //printf("earlystud value %d\n",earlystud);
            }
        counter++;
        }
        if (earlystud >= cancel) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
        
        
    }
    return 0;
}
