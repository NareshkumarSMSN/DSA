#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* evenOddBit(int n, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    int ind = false;
    int even = 0;
    int odd = 0;
    while(n){
        if((n&1) == 1){
            if(ind){
                odd++;
            }
            else{
                even++;
            }
        }
        n>>=1;
        ind = !ind;
    }
    result[0] = even;
    result[1] = odd;
    return result;
}