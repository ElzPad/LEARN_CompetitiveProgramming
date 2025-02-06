class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productsFrequency;
        int result=0;

        for (int i=0; i<nums.size(); i++) {
            for (int j=i+1; j<nums.size(); j++) {
                productsFrequency[nums[i]*nums[j]]++;
            }
        }

        for (auto [productValue, productFreq] : productsFrequency) {
            result += (productFreq-1) * productFreq / 2 * 8;
        }
        
        return result;
    }
};