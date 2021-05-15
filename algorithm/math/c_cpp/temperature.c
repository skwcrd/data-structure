// Converters Kelvins to Degree Celsius.
double kelvin_to_celsius(double kelvin)
{
    return kelvin - 273.15;
}

// Converters Degree Fahrenheit to Degree Celsius.
double fahrenheit_to_celsius(double fahrenheit)
{
    return (fahrenheit - 32) / 1.8;
}

// Converters Degree Celsius to Kelvins.
double celsius_to_kelvin(double celsius)
{
    return celsius + 273.15;
}

// Converters Kelvins to Degree Fahrenheit.
double kelvin_to_fahrenheit(double kelvin)
{
    return kelvin * 1.8 - 459.67;
    //return 1.8 * kelvin_to_celsius(kelvin) + 32;
}

// Converters Degree Fahrenheit to Kelvins.
double fahrenheit_to_kelvin(double fahrenheit)
{
    return (fahrenheit + 459.67) / 1.8;
    // return fahrenheit_to_celsius(fahrenheit) + 273.15;
    // return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}