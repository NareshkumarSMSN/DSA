/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* ans = malloc(numsSize * sizeof(int));

    for (int i = 0; i<numsSize;i++){
        ans[i] = -1;
        for(int j = nums[i]/2;j <= nums[i];j++){
            if((j|j+1) == nums[i]){
                ans[i] = j;
                break;
            }
        }
    }
    return ans;
}