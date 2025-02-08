class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int min=INT_MAX, minPos, max=INT_MIN, maxPos, dim=nums.size(), res=0;

        for (int i=0; i<dim; i++) {
            if (nums[i]<min) {
                min = nums[i];
                minPos = i;
            }
        }
        for (int i = dim-1; i>=0; i--) {
            if (nums[i]>max) {
                max = nums[i];
                maxPos = i;
            }
        }
        
        if (minPos!=0 || maxPos!=-1)
            res = minPos + (dim-1-maxPos) - (minPos>maxPos ? 1 : 0);
        return res;
    }
};