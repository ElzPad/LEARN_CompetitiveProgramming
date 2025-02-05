int firstUniqChar(char* s) {
    int counter=0, pos[26], res=-1;
    for (int i=0; i<26; i++) pos[i] = -1;
 
    /*
    pos[i] =
        -1, not seen yet
        -2, seen more than once
         x, position of the occurence
    */
    while (*s != '\0') {
        switch(pos[*s-'a']) {
            case -1:
                pos[*s-'a'] = counter;
                break;
            case -2:
                break;
            default:
                pos[*s-'a'] = -2;
                break;
        }
        s++;
        counter++;
    }

    for (int i=0; i<26; i++) {
        if (pos[i]>=0 && (res==-1 || pos[i]<res))
            res = pos[i];
    }
    return (int) res;
}