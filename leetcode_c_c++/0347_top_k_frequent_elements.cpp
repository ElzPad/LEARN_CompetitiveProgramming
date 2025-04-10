class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);
        vector<int> res;

        for (int i=0; i<nums.size(); i++)
            count[nums[i]]++;

        for (auto& [num, count]: count)
            freq[count].push_back(num);

        for (int i=freq.size()-1; i>0; i--) {
            for (int num: freq[i]) {
                res.push_back(num);
                if (res.size() == k) return res;
            }
        }
        return res; 
    }
};