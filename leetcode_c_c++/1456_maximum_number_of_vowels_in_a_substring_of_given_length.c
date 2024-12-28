int isVowel(char c) {
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ? 1 : 0;
}

int maxVowels(char* s, int k) {
    int res=0, count=0, len=strlen(s);
    int i;
    char *start=s;

    for (i=0; i<k; i++, s++) {
        if (isVowel(*s)) {
            count++;
        }
    }
    res = count;
    
    for (; i<len; i++, s++, start++) {
        if (isVowel(*start))    count--;
        if (isVowel(*s))        count++;

        if (count>res)          res = count;
    }
    return res;
}