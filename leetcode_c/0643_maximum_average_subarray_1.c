double findMaxAverage(int* nums, int numsSize, int k) {
    int maxSum=0, partialSum=0;

    for (int i=0; i<k; i++)     partialSum += nums[i];
    maxSum = partialSum;

    for (int i=k; i<numsSize; i++) {
        partialSum += (nums[i] - nums[i-k]);
        if (partialSum > maxSum)
            maxSum = partialSum;
    }
    return (maxSum*1.0)/k;
}