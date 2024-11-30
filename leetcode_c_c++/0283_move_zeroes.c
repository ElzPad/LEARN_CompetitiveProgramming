void moveZeroes(int* nums, int numsSize) {
    int numPtr=0, zeroPtr=0, tmp;
    while (numPtr<numsSize) {
        while( zeroPtr<numsSize && nums[zeroPtr]!=0 )
            zeroPtr++;
        while( numPtr<numsSize && (numPtr<=zeroPtr || nums[numPtr]==0))
            numPtr++;

        if (zeroPtr<numPtr && zeroPtr<numsSize && numPtr<numsSize) {
            tmp = nums[zeroPtr];
            nums[zeroPtr] = nums[numPtr];
            nums[numPtr] = tmp;
        }
        numPtr++;
        zeroPtr++;
    }
}