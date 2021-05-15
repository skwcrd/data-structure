/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    static int ret[2];

    int i = 0, j = 0;

    *returnSize = 2;

    for ( i = 0 ; i < numsSize ; i++ ) {
        for ( j = 0 ; j < numsSize ; j++ ) {
            if ( i != j ) {
                if ( ((*(nums + i)) + (*(nums + j))) == target ) {
                    if ( i > j ) {
                        ret[0] = j;
                        ret[1] = i;
                    } else {
                        ret[0] = i;
                        ret[1] = j;
                    }
                }
            }
        }
    }

    return ret;
}