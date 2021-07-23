char * longestPalindrome(char * s) {
    if( s[1] == '\0' ) {
        return s;
    }

    int size = strlen(s), end = 1;
    char *start = s, *center = s;

    while( (center + end / 2) < (s + size) ) {
        char *i = center, *j = center + 1;

        while ( *i == *j ) {
            j++;
        }

        center = j;

        while ( (i > s) && (*(i - 1) == *j) ) {
            --i;
            j++;
        }

        if ( (j - i) > end ) {
            end = j - i;
            start = i;
        }
    }

    return strncpy(calloc(end + 1, sizeof(char)), start, end);
}