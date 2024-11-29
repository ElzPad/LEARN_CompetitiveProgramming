int findPeakElement(int* nums, int numsSize) {
    int left=0, right=numsSize-1;
    int mid = left+(right-left)/2;

    while(left<right) {
        if ((mid==0 || nums[mid]>nums[mid-1]) && (mid==numsSize-1 || nums[mid]>nums[mid+1]))
            break;

        if (mid==0 || nums[mid+1]>nums[mid])    left=mid+1;
        else                                    right=mid-1;

        mid = left+(right-left)/2;
    }
    return mid;
}