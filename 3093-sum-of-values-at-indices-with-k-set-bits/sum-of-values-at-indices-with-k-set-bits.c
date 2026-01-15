int countbit(int n){
    int count=0;
    while(n){
        count++;
        n = n&(n-1);
    }
    return count;
}

int sumIndicesWithKSetBits(int* nums, int numsSize, int k) {
    int count = 0;
    for(int i=0;i<numsSize;i++){
        if(countbit(i) == k) count += nums[i];
    }
    return count;
}