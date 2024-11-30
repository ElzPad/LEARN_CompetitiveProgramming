bool isVowel(char c) {
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
        c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
}

char* reverseVowels(char* s) {
    int len=strlen(s);
    int left=0, right=len;
    char tmp;

    while (left<right && left<=len-1 && right>=0) {
        while ( !isVowel(s[left]) && left<=len-2)      left++;
        while ( !isVowel(s[right]) && right>=1)        right--;

        if (left<right) {
            tmp = s[right];
            s[right] = s[left];
            s[left] = tmp;
        }
        left++;
        right--;
    }
    return s;
}