#include <stdbool.h>
int countset(int n){
    int count = 0;
    while(n){
        count++;
        n=n&(n-1);
    }

    return count;
}
bool isprime(int n){
    if(n==0 || n==1) return false;
    for(int i=2;i<n;i++){
        if(n%i == 0) return false;
    }
    return true;
}
int countPrimeSetBits(int left, int right) {
    int res = 0;
    for(int n=left;n<=right;n++){
        int c1=countset(n);
        if(isprime(c1)) res++;
    }
    return res;
}