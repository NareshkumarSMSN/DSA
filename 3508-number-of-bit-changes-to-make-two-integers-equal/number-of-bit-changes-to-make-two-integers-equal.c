int minChanges(int n, int k) {
    if(n==k) return 0;
    if((k&~n)!=0) return -1;
    int count = 0;
    int n_last_bit, k_last_bit;
    while(n!=0 || k!=0){
        n_last_bit = n&1;
        k_last_bit = k&1;
        if(n_last_bit == 1 && k_last_bit == 0) count++;
        n >>= 1;
        k >>= 1;
    }
    return count;
}