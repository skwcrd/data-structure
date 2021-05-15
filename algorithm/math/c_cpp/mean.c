// Calculator Arithmetic Mean.
double arithmetic_mean(int num, double* score)
{
    int i;
    double mean;

    for ( i = 0 ; i < num ; i++ ) {
        mean += *(score + i);
    }

    mean /= num;

    return mean;
}