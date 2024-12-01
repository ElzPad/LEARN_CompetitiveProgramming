int writeString(char *src, char *dst, int start, int end, int pos) {
    while (start <= end)    dst[pos++] = src[start++];
    return pos;
}

char* reverseWords(char* s) {
    int len=strlen(s), start=len-1, end=len-1, pos=-1;
    char *res = (char *) malloc((len+1)*sizeof(char));

    while(start>=0) {
        while(end>=0 && s[end]==' ')        end--;
        start = end;
        while(start>=0 && s[start]!=' ')    start--;

        if (end!=-1) {
            pos = writeString(s, res, start+1, end, ++pos);
            res[pos] = ' ';
        }
        end=start;
    }
    res[pos] = '\0';
    return res;
}