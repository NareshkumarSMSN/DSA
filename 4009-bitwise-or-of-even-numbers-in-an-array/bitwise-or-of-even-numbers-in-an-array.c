int evenNumberBitwiseORs(int* nums, int numsSize) {
    int ans = 0;
    for(int i=0;i<numsSize;i++){
        if((nums[i]&1)==0){
            ans |= nums[i];
        }
    }
    return ans;
}