class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 0)   return vector<vector<string>> ();

        vector<vector<string>> res;
        unordered_map<string, vector<string>> groupedStrings;
        int count[26];

        for (string s: strs) {
            fill(begin(count), end(count), 0);
            for (int i=0; i<s.size(); i++) count[s[i]-'a']++;

            string tmpKey = "";
            for (int i=0; i<26; i++) {
                tmpKey += "#" + to_string(count[i]);
            }
            if (groupedStrings.find(tmpKey) == groupedStrings.end())
                groupedStrings[tmpKey] = vector<string> ();
            groupedStrings[tmpKey].push_back(s);
        }
        for (auto [key, val] : groupedStrings) {
            res.push_back(val);
        }
        return res;
    }
};