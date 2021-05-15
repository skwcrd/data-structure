#define PI 3.1415926535897932384626433832795

// Converters Degrees to Radians.
double deg_to_rad(double degree)
{
    return degree * (PI / 180);
}

// Converters Radians to Degrees.
double rad_to_deg(double radian)
{
    return radian * 57.29578;
}

// Converters Gradians to Radians.
double grad_to_rad(double gradian)
{
    return gradian * 0.015708;
}