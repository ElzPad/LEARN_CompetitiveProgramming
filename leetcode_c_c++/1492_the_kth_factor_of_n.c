int kthFactor(int n, int k) {
    // 12, 2 --> 1 |2| 3 4 6 12
    // 15, 1 --> |1| 3 5 15
    // 36, 6 --> 1 2 3 4 6 |9| 12 18 36
    // 07, 2 --> 1 |7|
    int count=0, last=0, total=0;
    for (int i=1; i<=sqrt(n); i++)
        if (n%i == 0) {
            last = i;
            if (++count==k) return i;
        }

    total = last*last == n ? 2*count-1 : 2*count;
    if (k > total) return -1;

    count = total-k+1;
    for (int i=1; i<=sqrt(n); i++)
        if (n%i == 0)
            if (--count == 0) return (int) n/i;
    
    return -2;
}