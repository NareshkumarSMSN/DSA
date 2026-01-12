#include <stdio.h>
#include <stdbool.h>
bool hasTrailingZeros(int* nums, int numsSize) {
    int even = 0;
    for(int i = 0;i < numsSize; i++){
        if((nums[i]&1) == 0) even++;
        if(even == 2) return true;
    }
    return false;
}