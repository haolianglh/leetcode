/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i = 0;
    int j = 0;
    int *p = malloc(2*sizeof(int));
    
    for (i = 0; i < numsSize - 1; ++i)
    {
        p[0] = i;
        for (j = i + 1; j < numsSize; ++j)
        {
            if (target == nums[i]+nums[j])
            {
                p[1] = j;
                return p;
            }
        }
    }
    free(p);
    return NULL;
}