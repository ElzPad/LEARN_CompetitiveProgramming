class Solution {
public:
    int minimumKeypresses(string s) {
        vector<int> freq;
        int dim = s.size(), res = 0;

        for (int i=0; i<26; i++)    freq.push_back(0);
        for (int i=0; i<dim; i++)
            freq[s[i]-'a'] += 1;

        sort(freq.rbegin(), freq.rend());
        for (int i=0; i<9; i++)   res += freq[i];
        for (int i=9; i<18; i++)  res += 2*freq[i];
        for (int i=18; i<26; i++) res += 3*freq[i];
        return res;
    }
};