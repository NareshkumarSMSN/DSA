char findKthBit(int n, int k) {
    // char str[(1<<n)-1] = "0";

    // for(int i = 1; i<n; i++){
    //     char front[] = str;
    //     for(int j=0;j<s.size();j++){
    //         str[j] = str[j]=="0"?"1":"0";

    //         str = str[::-1];

    //         str = front + "1" + str;
    //     }
    //     return str[k-1];
    // }

    static char str[1<<20];
    static char temp[1<<20];

    str[0] = '0';
    str[1] = '\0';

    for(int i = 2; i<=n; i++){
        int len = strlen(str);

        strcpy(temp,str);

        for(int j = 0; j<len; j++){
            temp[j] = (temp[len-1-j] == '0') ? '1' : '0';
        }
        temp[len] = '\0';

        str[len] = '1';
        str[len+1] = '\0';
        strcat(str,temp);
    }
    return str[k-1];
}