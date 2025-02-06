class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrecIndex=0, maxDiff=0;

        for (int i=1; i<prices.size(); i++) {
            if (prices[i] < prices[minPrecIndex]) {
                minPrecIndex = i;
            } else if (prices[i]-prices[minPrecIndex] > maxDiff) {
                maxDiff = prices[i]-prices[minPrecIndex];
            }
        }
        return maxDiff;
    }
};