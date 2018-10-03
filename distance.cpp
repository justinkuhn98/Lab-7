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


const Distance Distance::operator+(const Distance &dist) const
{
    Distance sum;

    sum.inches = inches + dist.inches;
    sum.feet = feet + dist.feet;

    sum.init();

    return sum;
}


const Distance Distance::operator-(const Distance &dist) const
{
    Distance difference;



    if (feet >= dist.feet)
    {
        difference.feet = feet - dist.feet;
        if (inches >= dist.inches)
            difference.inches = inches - dist.inches;
        else if (inches < dist.inches)
        {
            difference.inches = 12 - (dist.inches - inches);
            difference.feet -= 1;
        }
    }

    else if (feet < dist.feet)
    {
        difference.feet = dist.feet - feet;
        if (dist.inches >= inches)
            difference.inches = dist.inches - inches;
        else if (dist.inches < inches)
        {
            difference.inches = 12 - (inches - dist.inches);
            difference.feet -= 1;
        }
    }


    difference.init();

    return difference;
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
        feet += (inches/12);
        inches = fmod(inches, 12);

    }
}
