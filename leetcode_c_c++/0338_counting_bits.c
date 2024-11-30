int* countBits(int n, int* returnSize) {
    int *res = (int*) malloc(sizeof(int)*(n+1));
    int partialRes = 0;
    int num = 0;
    for (int i=0; i<=n; i++) {
        partialRes = 0;
        num = i;
        while (num>0) {
            partialRes += num&1;
            num = num>>1;
        }
        res[i] = partialRes;
    }
    *returnSize = n+1;
    return res;
}