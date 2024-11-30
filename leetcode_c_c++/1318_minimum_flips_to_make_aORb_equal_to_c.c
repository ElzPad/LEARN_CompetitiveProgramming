int minFlips(int a, int b, int c){
    int res=0;
    int remainderA, remainderB, remainderC;

    while (a>0 || b>0 || c>0) {
        remainderA = a%2;
        remainderB = b%2;
        remainderC = c%2;

        if (remainderC==1 && remainderA==0 && remainderB==0)
            res++;
        else if (remainderC==0 && (remainderA==1 || remainderB==1))
            res += remainderA + remainderB;

        a = a>>1;
        b = b>>1;
        c = c>>1;
    }
    return res;
}