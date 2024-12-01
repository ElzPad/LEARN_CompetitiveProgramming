bool increasingTriplet(int* nums, int numsSize) {
    /* SOLUTION 1
    -- Time Complexity = O(n^3)
    -- Space Complexity = O(1)
    for (int i=0; i<numsSize; i++) {
        for (int j=i+1; j<numsSize; j++) {
            for (int k=j+1; k<numsSize; k++) {
                if (nums[i]<nums[j] && nums[j]<nums[k]) return true;
            }
        }
    }
    return false;
    */

    /* SOLUTION 2
    -- Time Complexity = O(n^2)
    -- Space Complexity = O(n)
    bool hasPrev[numsSize];
    for (int i=0; i<numsSize; i++)  hasPrev[i] = false;

    for (int i=0; i<numsSize; i++) {
        for (int j=i+1; j<numsSize; j++) {
            if (nums[i] < nums[j]) {
                if (hasPrev[i])
                    return true;
                hasPrev[j] = true;
            }
        }
    }
    return false;
    */

    /*SOLUTION 3
    -- Time Complexity = O(n)
    -- Space Complexity = O(n)
    */
    int minLeft, maxRight[numsSize];

    minLeft = nums[0];
    maxRight[numsSize-1] = nums[numsSize-1];

    for (int i=numsSize-2; i>=0; i--) 
        maxRight[i] = nums[i+1]>maxRight[i+1] ? nums[i+1] : maxRight[i+1];

    for (int i=1; i<numsSize; i++) {
        minLeft = nums[i-1]<minLeft ? nums[i-1] : minLeft;
        if (minLeft<nums[i] && nums[i]<maxRight[i])
            return true;
    }

    return false;
}