class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int partialSum=0, total=0;
        
        for (int i=0; i<k; i++) {
            partialSum += calories[i];
        }
        if (partialSum>upper) total++;
        else if (partialSum<lower) total--;  
        
        for (int i=0; i<calories.size()-k; i++) {
            partialSum -= calories[i];
            partialSum += calories[i+k];
            
            if (partialSum>upper) total++;
            else if (partialSum<lower) total--;            
        }
        return total;
    }
};