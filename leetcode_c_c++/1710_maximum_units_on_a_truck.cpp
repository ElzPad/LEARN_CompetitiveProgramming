class Solution {
public:
    static bool sortCriteria(vector<int>& a, vector<int> &b) {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int total = 0;
        sort(boxTypes.begin(), boxTypes.end(), sortCriteria);
        for (auto box: boxTypes) {
            int amount = min(box[0], truckSize);
            total += amount*box[1];
            truckSize -= amount;
            if (!truckSize) break;
        }
        return total;
    }
};