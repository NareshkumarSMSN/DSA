/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int count(int n){
    int c = 0;
    while(n){
        c++;
        n = n&(n-1);
    }
    return c;
}

typedef struct{
    int value;
    int bits;
}Node;

int cmp(const void* a, const void* b){
    Node* x = (Node*)a;
    Node* y = (Node*)b;

    if(x->bits != y->bits){
        return x->bits - y->bits;
    }
    return x->value - y->value;
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {

    Node temp[arrSize];

    for(int i=0;i<arrSize;i++){
        temp[i].value = arr[i];
        temp[i].bits = count(arr[i]);
    }

    qsort(temp,arrSize,sizeof(Node),cmp);

    int* result = malloc(arrSize * sizeof(int));
    *returnSize = arrSize;
    for(int i=0;i<arrSize;i++){
        result[i] = temp[i].value;
    }
    return result;
}