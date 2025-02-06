class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> presence;
        int numsLen = nums.size();

        for (int i=0; i<numsLen; i++) {
            if (presence.find(target-nums[i]) != presence.end())
                return {i, presence[target-nums[i]]};
            presence[nums[i]] = i;
            
        }
        return {};
    }
};