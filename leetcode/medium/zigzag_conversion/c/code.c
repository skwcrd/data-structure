char * convert(char * s, int numRows) {
    if ( numRows == 1 || s[1] == '\0' ) {
        return s;
    }

    int size = strlen(s);

    if ( size <= numRows ) {
        return s;
    }

    char *result = (char *)calloc(size + 1, sizeof(char));
    char *res = result;
    int row, col;

    for ( col = (numRows - 1) * 2, row = 0 ; row < numRows ; row++ ) {
        int i = row;
        int j = col - row * 2;

        while ( i < size ) {
            *res++ = s[i];

            if ( (row == 0) || (row == (numRows - 1)) ) {
                i += col;
            } else {
                i += j;
                j = col - j;
            }
        }
    }

    return result;
}