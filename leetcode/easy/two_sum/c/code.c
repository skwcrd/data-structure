/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *result = malloc(2 * sizeof(int));

    if ( numsSize == 2 ) {
        *result = 0;
        *(result + 1) = 1;
        return result;
    }

    int i, j;

    for ( i = 0 ; i < numsSize ; i++ ) {
        for ( j = i + 1 ; j < numsSize ; j++ ) {
            if ( ((*(nums + i)) + (*(nums + j))) == target ) {
                *result = i;
                *(result + 1) = j;
            }
        }
    }

    return result;
}