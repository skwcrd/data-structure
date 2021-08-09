/***************************************************
 * int myAtoi(char * s) {
 *     long long i = atol(s);
 *
 *     if ( i < INT_MIN ) {
 *         i = INT_MIN;
 *     } else if ( i > INT_MAX ) {
 *         i = INT_MAX;
 *     }
 *
 *     return (int)i;
 * }
 ***************************************************/

int myAtoi(char * s) {
    char *ch = s;
    char sign = 1;
    int result = 0;
    int max = INT_MAX / 10;
    int preMax = INT_MAX % 10;

    while ( *ch == ' ' ) {
        ch++;
    }

    if ( *ch == '-' ) {
        sign = -1;
        ch++;
    } else if ( *ch == '+' ) {
        ch++;
    }

    while ( (*ch >= 48) && (*ch <= 57) ) {
        int num = *ch - 48;
        if ( ((result == max) && (num > preMax)) || (result > max) ) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        result *= 10;
        result += num;
        ch++;
    }

    return result * sign;
}