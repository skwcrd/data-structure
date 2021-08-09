/***************************************************
 * bool isMatch(char * s, char * p) {
 *     if ( *p == NULL ) {
 *         return *s == NULL;
 *     }
 *
 *     int i = 1;
 *
 *     if ( (*p) && (*(p + 1)) && (*(p + 1) == '*') ) {
 *         if ( isMatch(s, p + 2) ) {
 *             return true;
 *         }
 *
 *         i = 0;
 *     }
 *
 *     if ( (*s) && (*p == '.') || (*s == *p) ) {
 *         return isMatch(s + 1, p + i);
 *     }
 *
 *     return false;
 * }
 ***************************************************/

bool isMatch(char * s, char * p) {
    if ( *p == NULL ) {
        return *s == NULL;
    }

    int i, j;
    int len_s = strlen(s) + 1;
    int len_p = strlen(p) + 1;
    int len_dp = len_s * len_p;

    bool *dp = (bool *)calloc(len_dp, sizeof(bool));
    memset(dp, false, len_dp);
    dp[0] = true;

    for ( i = 2 ; i < len_p ; i++ ) {
       dp[i * len_s] =  (p[i - 1] == '*') && dp[(i - 2) * len_s];
    }

    for ( i = 1 ; i < len_s ; i++ ) {
        for ( j = 1 ; j < len_p ; j++ ) {
            if ( (p[j - 1] == '.') || (s[i - 1] == p[j - 1]) ) {
                dp[i + j * len_s] = dp[i - 1 + (j - 1) * len_s];
            } else if ( (p[j - 1] == '*') && (j > 1) ) {
                if ( (p[j - 2] != '.') && (p[j - 2] != s[i - 1]) ) {
                    dp[i + j * len_s] = dp[i + (j - 2) * len_s];
                } else {
                    dp[i + j * len_s] = dp[i + (j - 2) * len_s] || dp[i - 1 + j * len_s];
                }
            }
        }
    }

    bool result = dp[len_dp - 1];
    free(dp);

    return result;
}