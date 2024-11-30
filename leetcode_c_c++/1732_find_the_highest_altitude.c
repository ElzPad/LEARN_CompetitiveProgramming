int largestAltitude(int* gain, int gainSize) {
    int max=0, prefixSum=0;
    for (int i=0; i<gainSize; i++) {
        prefixSum += gain[i];
        if (prefixSum > max)    max = prefixSum;
    }
    return max;
}