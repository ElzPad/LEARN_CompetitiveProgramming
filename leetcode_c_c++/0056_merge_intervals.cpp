class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int resLen=1;

        sort(intervals.begin(), intervals.end(), compare);
        res.push_back(intervals[0]);
        for (int i=1; i<intervals.size(); i++) {
            if ( intervals[i][0]<=res[resLen-1][1]) {
                if (intervals[i][1]>=res[resLen-1][1] )
                    res[resLen-1][1] = intervals[i][1];
            } else {
                res.push_back(intervals[i]);
                resLen++;
            }
        }
        return res;
    }

private:
    static bool compare(vector<int>&a, vector<int>& b) {
        return a[0] < b[0];
    }
};