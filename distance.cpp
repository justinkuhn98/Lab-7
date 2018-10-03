#include "distance.h"

Distance::Distance()
{
    feet = 0;
    inches = 0;
}

Distance::Distance(unsigned ft, double inch)
{
    feet = ft;
    inches = inch;
    init();
}

Distance::Distance(double inch)
{
    feet = 0;
    inches = inch;
    init();
}

double Distance::convertToInches() const
{
    double total_inches;
    total_inches = feet * 12 + inches;
    return total_inches;
}

void Distance::display() const
{
    cout << feet << "' " << inches << "\"" << endl;
}

void Distance::init()
{
    if (inches < 0)
        inches = -inches;

    if (feet < 0)
        feet = -feet;

    if (inches >= 12)
    {
        feet += inches/12;
        inches = fmod(inches, 12);

    }
}
