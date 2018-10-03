
#include "distance.h"
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;



/***********************************************************
*  Constructor (no argument) : Class Distance
*_________________________________________________________
*This constructor initializes feet = 0, inches = 0.
*_________________________________________________________
* PRE-CONDITIONS
*   None
*
* POST-CONDITIONS
*   The Date object is now intialized to:
*       feet = 0;
*       inches = 0;
***********************************************************/
Distance::Distance()
{
    feet = 0;
    inches = 0;
}
/***********************************************************
*  Constructor (two argument) : Class Distance
*_________________________________________________________
*This constructor corrects for negative feet, and
* corrects for overflow  and negatice inches with init function.
*_________________________________________________________
* PRE-CONDITIONS
*   The following need to have been declared:
*       ft: feet measurement of distance
*       inches: inches measurement of distance
* POST-CONDITIONS
*   The Date object is now set and corrected through init().
***********************************************************/
Distance::Distance(unsigned ft, double inch)
{
    if ( ft < 0 ) ft = -ft;
    feet = ft;
    inches = inch;
    init();
}

/***********************************************************
*  Constructor (one argument) : Class Distance
*_________________________________________________________
*This constructor corrects for negative inches and corrects for
*   overflow with init function.
*_________________________________________________________
* PRE-CONDITIONS
*   The following need to have been declared:
*       inch: inches representing total Distance
* POST-CONDITIONS
*   The Date object is now set and corrected through init().
***********************************************************/
Distance::Distance(double inch)
{
    feet = 0;
    inches = inch;
    init();
}

/***********************************************************
* Method convertToInches: Class Distance
*_________________________________________________________
*This method will return a double represnting all the inches in
*               in the Distance measurement in total.
*  -returns double total
*_________________________________________________________
* PRE-CONDITIONS
*   None
* POST-CONDITIONS
*       Returns total_inches in Distance (from inches and feet)
***********************************************************/
double Distance::convertToInches() const
{
    double total_inches;
    total_inches = feet * 12 + inches;
    return total_inches;
}

/***********************************************************
* Method operator+: Class Distance
*_________________________________________________________
*This method will define the '+' operator for Distance objects.
*  -returns Distance sum (result of addition)
*_________________________________________________________
* PRE-CONDITIONS
*   The following need to have been declared:
*       dist: other object for addition
* POST-CONDITIONS
*       returns Distance sum
***********************************************************/
const Distance Distance::operator+(const Distance &dist) const
{
    Distance sum;

    sum.inches = inches + dist.inches;
    sum.feet = feet + dist.feet;

    sum.init();

    return sum;
}

/***********************************************************
* Method operator-: Class Distance
*_________________________________________________________
*This method will define the '-' operator for Distance objects.
*  -returns Distance difference (result of subtraction)
*_________________________________________________________
* PRE-CONDITIONS
*   The following need to have been declared:
*       dist: other object for subtraction
* POST-CONDITIONS
*       returns Distance difference
***********************************************************/
const Distance Distance::operator-(const Distance &dist) const
{
    Distance difference;



    if (feet > dist.feet)
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


    else if (feet == dist.feet)
    {
        difference.feet = feet - dist.feet;
        if (dist.inches >= inches)
            difference.inches = dist.inches - inches;
        else if (dist.inches < inches)
            difference.inches = inches - dist.inches;
    }

    difference.init();

    return difference;
}
/***********************************************************
* Method display: Class Distance
*_________________________________________________________
*This method will display the feet and inches of Distance in
*               the appropriate format.
*               Ex: 3' 0.00"
*  -returns nothing
*_________________________________________________________
* PRE-CONDITIONS
*   None
* POST-CONDITIONS
*       Displays the Distance
***********************************************************/
void Distance::display() const
{
    cout << feet << "' " << inches << "\"" ;
}

/***********************************************************
* Method init: Class Distance
*_________________________________________________________
*This method will calculated feet in inches(if overflow) and correct inches
*  after adding feet.
*  -returns nothing
*_________________________________________________________
* PRE-CONDITIONS
*   None
* POST-CONDITIONS
*       Distance now corrected for overflow
***********************************************************/
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
=======
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



    if (feet > dist.feet)
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


    else if (feet == dist.feet)
    {
        difference.feet = feet - dist.feet;
        if (dist.inches >= inches)
            difference.inches = dist.inches - inches;
        else if (dist.inches < inches)
            difference.inches = inches - dist.inches;
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

