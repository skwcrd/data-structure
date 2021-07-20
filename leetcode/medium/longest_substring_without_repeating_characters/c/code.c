int lengthOfLongestSubstring(char * s) {
    if ( *s == '\0' ) {
        return 0;
    }

    int res = 0, prev = 0;
    int id[128] = {0,};

    for ( char *ch = s ; *ch ; ch++ ) {
        int i = ch - s + 1;

        int l = i - id[*ch];
        int len = (++prev < l) ? prev : l;

        if ( len > res ) {
            res = len;
        }

        prev = len;
        id[*ch] = i;
    }

    return res;
}