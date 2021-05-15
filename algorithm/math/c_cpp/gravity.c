#define G 6.67384E-11

// Calculator Gravity.
double gravity(double mass, double radius)
{
    return G * mass / radius * radius;
}