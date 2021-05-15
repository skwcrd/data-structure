#include<math.h>

// Calculator Square Root.
double square_root(double num)
{
    double upper, lower, sum;

    lower = 0;
	upper = num;
	sum = (lower + upper) / 2;

	while( fabs(pow(sum, 2) - num) > 0.000001 ){
		if ( pow(sum, 2) > num ) {
			upper = sum;
		} else {
			lower = sum;
		}

		sum = (lower + upper) / 2;
	}

    return sum;
}