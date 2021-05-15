#define DAY 365
#define HOUR 24
#define MINUTE 60
#define SECOND 60
#define C 299792458

// Calculator Light Year.
double light_year(long year)
{
    return (C * year * (DAY * HOUR * MINUTE * SECOND)) / 1609.344;
}