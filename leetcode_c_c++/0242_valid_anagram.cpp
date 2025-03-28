class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        // SOLUTION 1 - Time efficient
        /*
        unordered_map<int, int> occurrences;
        int dim = s.length();
        bool res = true;

        for (int i=0; i<26; i++) occurrences[i] = 0;
        for (int i=0; i<dim; i++) {
            occurrences[s[i]-'a']++;
            occurrences[t[i]-'a']--;
        }
        for (int i=0; i<26; i++) res = res && occurrences[i]==0;
        return res;
        */

        // SOLUTION 2 - Memory efficient
        int dim = s.length();
        bool res = true;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i=0; i<dim; i++) res = res && s[i]==t[i];
        return res;
    }
};