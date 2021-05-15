// Check Prime Number.
int prime(long long num)
{
    long long i;

    for ( i = 2 ; i < num ; i++ ) {
        if ( (num % i) == 0 ) {
            return 0;
        }
    }

    return 1;
}