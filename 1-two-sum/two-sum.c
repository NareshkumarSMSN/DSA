/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *returnarray = malloc(2*sizeof(int));
    returnarray[0]=1;
    returnarray[1]=1;
    for(int i=0;i<numsSize;++i){
    for(int j=i+1;j<numsSize;++j){
        if(nums[i]+nums[j]==target){
        *returnSize=2;
        returnarray[0]=i;
        returnarray[1]=j;
        return returnarray;
        }
    }
    }
    *returnSize=0;
    return NULL;
}