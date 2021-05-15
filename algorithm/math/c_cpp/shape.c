#define PI 3.1415926535897932384626433832795

// Area, Surface Area and Volume reference sheet.
// Two-dimensional plane shapes and Three-dimensional solid shapes.

// Area Two-dimensional plane shapes.
// The measure of how many squares will fit into a shape.
double square(double a)
{
    return a * a;
}

double rectangle(double width, double height)
{
    return width * height;
}

double triangle(double base, double height)
{
    return 0.5 * base * height;
}

double polygon(int num, double length, double apothem)
{
    return num * 0.5 * length * apothem;
}

double polyhedron(int side, int num, double length, double apothem)
{
    return side * polygon(num, length, apothem);
}

double circle(double radius)
{
    return PI * radius * radius;
}

double ellipse(double a_rad, double b_rad)
{
    return PI * a_rad * b_rad;
}

// Surface Area Three-dimensional solid shapes.
// The measure of the area of all outward facing sides.
double area_cube_square(double a)
{
    return 6 * square(a);
}

double area_cube_rectangle(double width, double height)
{
    return (4 * width * height) + (2 * square(width));
}

double area_pyrimid_square(double base, double lateral)
{
    return square(base) + (4 * triangle(base, lateral));
}

double area_pyrimid_rectangle(double width, double length, double lateral)
{
    return rectangle(width, length) + (2 * triangle(width, lateral)) + (2 * triangle(length, lateral));
}

double area_pyrimid_polygon(int num, double base, double apothem, double lateral)
{
    return polygon(num, base, apothem) + (num * triangle(base, lateral));
}

double area_sphere(double radius)
{
    return 4 * circle(radius);
}

double area_cylinder(double radius, double height)
{
    return (2 * PI * radius * height) + (2 * circle(radius));
}

// Volume Three-dimensional solid shapes.
// The measure of how many cubes will fit into a shape.
double volume_cube_square(double a)
{
    return a * a * a;
}

double volume_cube_rectangle(double width, double height, double length)
{
    return width * length * height;
}

double volume_pyrimid_square(double base, double height)
{
    return (1 / 3) * square(base) * height;
}

double volume_pyrimid_rectangle(double width, double height, double length)
{
    return (1 / 3) * rectangle(width, length) * height;
}

double volume_pyrimid_polygon(int num, double base, double apothem, double height)
{
    return (1 / 3) * polygon(num, base, apothem) * height;
}

double volume_sphere(double radius)
{
    return (4 / 3) * circle(radius) * radius;
}

double volume_cylinder(double radius, double height)
{
    return circle(radius) * height;
}