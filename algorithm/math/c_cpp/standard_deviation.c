#include<math.h>

// Calculator Standard Deviation.
double standard_deviation(int num, double* value)
{
    int i;
    double sd, mean, sum;

    for ( i = 0 ; i < num ; i++ ) {
        double val = *(value + i);

        mean += val;
        sum += pow(val, 2);
    }

    mean /= num;
    sum /= num;

    sd = sqrt(sum - pow(mean, 2));

    return sd;
}