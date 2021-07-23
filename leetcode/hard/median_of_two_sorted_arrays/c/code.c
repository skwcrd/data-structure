double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    double result = 0;
    int size = nums1Size + nums2Size;
    int i = 0, j = 0, loop = size;
    int nums[size];
    int *num = &nums[0];

    while ( loop-- ) {
        if ( (i != nums1Size) && (j != nums2Size) ) {
            if ( *nums1 < *nums2 ) {
                *num++ = *nums1++;
                i++;
            } else {
                *num++ = *nums2++;
                j++;
            }
        }
    }

    if ( i != nums1Size ) {
        loop = nums1Size - i;

        while ( loop-- ) {
            *num++ = *nums1++;
        }
    }

    if ( j != nums2Size ) {
        loop = nums2Size - j;

        while ( loop-- ) {
            *num++ = *nums2++;
        }
    }

    if ( size & 1 ) {
        result = (double)nums[size / 2];
    } else {
        result = ((double)(nums[size / 2] + nums[size / 2 - 1]) / 2);
    }

    return result;
}