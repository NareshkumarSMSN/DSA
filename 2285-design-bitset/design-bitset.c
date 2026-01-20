#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
   int* bits;
   int size;
   int flipped;
   int onesCount;
} Bitset;


Bitset* bitsetCreate(int size) {
   Bitset* obj = (Bitset*)malloc(sizeof(Bitset));
   obj->bits = (int*)calloc(size,sizeof(int));
   obj->size = size;
   obj->flipped = 0;
   obj->onesCount = 0;
   return obj;
}

void bitsetFix(Bitset* obj, int idx) {
    int actual = obj->bits[idx] ^ obj->flipped;
    if(actual == 0){
        obj->bits[idx] = (obj->flipped) ? 0 : 1;
        obj->onesCount++;
    }
}

void bitsetUnfix(Bitset* obj, int idx) {
    int actual = obj->bits[idx] ^ obj->flipped;
    if(actual == 1){
        obj->bits[idx] = (obj->flipped) ? 1 : 0;
        obj->onesCount--;
    }
}

void bitsetFlip(Bitset* obj) {
    obj->flipped ^= 1;
    obj->onesCount = obj->size - obj->onesCount;
}

bool bitsetAll(Bitset* obj) {
    return obj->onesCount == obj->size;
}

bool bitsetOne(Bitset* obj) {
    return obj->onesCount > 0;
}

int bitsetCount(Bitset* obj) {
    return obj->onesCount;
}

char* bitsetToString(Bitset* obj) {
    char* s = (char*)malloc(obj->size+1);
    for(int i = 0; i<obj->size;i++){
        s[i] = (obj->bits[i] ^ obj->flipped) + '0';
    }
    s[obj->size] = '\0';
    return s;
}

void bitsetFree(Bitset* obj) {
    free(obj->bits);
    free(obj);
}

/**
 * Your Bitset struct will be instantiated and called as such:
 * Bitset* obj = bitsetCreate(size);
 * bitsetFix(obj, idx);
 
 * bitsetUnfix(obj, idx);
 
 * bitsetFlip(obj);
 
 * bool param_4 = bitsetAll(obj);
 
 * bool param_5 = bitsetOne(obj);
 
 * int param_6 = bitsetCount(obj);
 
 * char* param_7 = bitsetToString(obj);
 
 * bitsetFree(obj);
*/