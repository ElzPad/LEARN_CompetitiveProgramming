class Solution {
public:
    int partitionString(string s) {
        int len = s.size(), occurrence[26], wordStart=0, res=1;

        for (int i=0; i<26; i++) occurrence[i] = -1;
        for (int i=0; i<len; i++) {
            if (occurrence[s[i]-'a'] >= wordStart) {
                wordStart = i;
                res++;
            }
            occurrence[s[i]-'a'] = i;
        }
        return res;
    }
};