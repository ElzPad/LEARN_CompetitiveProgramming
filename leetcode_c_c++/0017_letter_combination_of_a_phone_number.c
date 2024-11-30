int sol(char d2l[][5], char *digits, int index, int len, char *partial, char **res, int solNum) {
    if (len==0) {
        return 0;
    }
    
    if (index==len) {
        partial[len] = '\0';
        res[solNum] = (char *) malloc((len+1) * sizeof(char));
        strcpy(res[solNum], partial);
        return solNum+1;
    }

    for (int i=0; i<strlen(d2l[digits[index]-'0']); i++) {
        partial[index] = d2l[digits[index]-'0'][i];
        solNum = sol(d2l, digits, index+1, len, partial, res, solNum);
    }
    return solNum;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    char digToLetters[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    char **res = NULL;
    char *partial = NULL;
    int len=strlen(digits);

    *returnSize = len>0 ? 1 : 0;
    for (int i=0; i<len; i++) {
        *returnSize = (*returnSize) * strlen(digToLetters[digits[i]-'0']);
    }
    res = (char **) malloc(*returnSize * sizeof(char *));
    partial = (char *) malloc((len+1) * sizeof(char));

    sol(digToLetters, digits, 0, len, partial, res, 0);
    return res;
}