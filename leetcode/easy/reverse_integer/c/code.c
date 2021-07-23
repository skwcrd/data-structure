int reverse(int x) {
    if ( x == INT_MIN ) { // INT_MIN = -2147483648
        return 0;
    }

    if ( (-10 <= x) && (x <= 10) ) {
        if ( x == -10 ) {
            return -1;
        }

        if ( x == 10 ) {
            return 1;
        }

        return x;
    }

    int max = INT_MAX / 10; // INT_MAX = 2147483647
    int i = abs(x), result = 0;

    while ( i ) {
        if ( result > max ) {
            return 0;
        }

        result = result * 10 + i % 10;
        i /= 10;
    }

    return (x < 0) ? -result : result;
}