// Calculator Body Mass Index.
// [weight] unit: kg
// [height] unit: cm
double body_mass_index(double weight, double height)
{
    double m = height / 100;

    return weight / (m * m);
}