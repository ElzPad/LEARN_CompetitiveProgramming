int longestSubarray(int* nums, int numsSize) {
    int res=0, curr=0, seq=0, zero=0;

    for (int i=0; i<numsSize; i++) {
        if (nums[i]==1) {
            if (seq) {
                seq++;
                nums[i] = seq-1;
            } else {
                seq = 1;
            }
        } else {
            zero = 1;

            if (seq==1)         nums[i-seq] = -1;
            else if (seq)       nums[i-seq] = seq;
            seq = 0;
        }
    }
    if (seq==1)         nums[numsSize-seq] = -1;
    else if (seq)       nums[numsSize-seq] = seq;

    for (int i=0; i<numsSize; i++) {
    }
    for (int i=0; i<numsSize; i++) {
        if (!nums[i]) {
            curr = 0;
            if (i!=0) {
                curr += (nums[i-1]==-1) ? 1 : 0;
                curr += (nums[i-1]) ? nums[i-1]+1 : 0;
            }
            if (i!=numsSize-1){
                curr += (nums[i+1]==-1) ? 1 : nums[i+1];
            }
            if (curr>res)          res = curr;
        }
    }
    return zero ? res : numsSize-1;
}