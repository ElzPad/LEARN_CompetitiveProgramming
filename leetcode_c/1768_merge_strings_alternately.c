char *mergeAlternately(char * word1, char * word2){
    int finalLen=strlen(word1)+strlen(word2);
    char *res = malloc((finalLen+1) * sizeof(char));
    
    for (int i=0; i<finalLen; i++) {
        if (*word1=='\0') {
            res[i] = *word2;
            word2++;
        } else if (*word2=='\0' || i%2==0) {
            res[i] = *word1;
            word1++;
        } else {
            res[i] = *word2;
            word2++;
        }
    }
    res[finalLen] = '\0';
    return res;
}