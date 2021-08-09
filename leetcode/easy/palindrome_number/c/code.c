bool isPalindrome(int x) {
    unsigned int y = 0;
    unsigned int i = x;

    while ( i != 0 ) {
        y = (y * 10) + (i % 10);
        i /= 10;
    }

    return x == y;
}