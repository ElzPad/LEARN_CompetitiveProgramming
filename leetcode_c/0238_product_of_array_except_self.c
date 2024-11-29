/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *prefixProd, *suffixProd, *res;
    *returnSize = numsSize;

    prefixProd = (int *) malloc(numsSize * sizeof(int));
    suffixProd = (int *) malloc(numsSize * sizeof(int));
    res = (int *) malloc(numsSize * sizeof(int));
    
    prefixProd[0] = 1;
    suffixProd[numsSize-1] = 1;
    for (int i=1; i<numsSize; i++) {
        prefixProd[i] = prefixProd[i-1] * nums[i-1];
        suffixProd[numsSize-1-i] = suffixProd[numsSize-i] * nums[numsSize-i];
    }   

    for (int i=0; i<numsSize; i++) {
        res[i] = prefixProd[i] * suffixProd[i];
    }
    return res;
}