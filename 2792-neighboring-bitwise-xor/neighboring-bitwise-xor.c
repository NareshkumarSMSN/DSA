bool doesValidArrayExist(int* derived, int derivedSize) {
    int f = 0, l = 0;

    for(int i = 0; i<derivedSize; i++){
        if(derived[i] == 1){
            if(l == 0) l=1;
            else l = 0;
        }
        printf("%d,%d",f,l);
    }
    return f == l;
}