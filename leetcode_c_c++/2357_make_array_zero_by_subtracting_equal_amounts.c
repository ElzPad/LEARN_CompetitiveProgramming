class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int numsLen=nums.size(), total=0;

        sort(nums.begin(), nums.end());
        total=nums[0]==0 ? 0:1;

        for (int i=0; i<numsLen-1; i++) {
            if (nums[i+1]!=nums[i])
                total++;
        }
        return total;
    }
};