#include "distance.h"
#include <iostream>
#include <iomanip>

using namespace std;

/***********************************************************
*  Constructor (no argument) : Class Distance
*_________________________________________________________
*This constructor initializes feet = 0, inches = 0.0.
*_________________________________________________________
* PRE-CONDITIONS
*   None
*
* POST-CONDITIONS
*   The Date object is now intialized to:
*       feet = 0;
*       inches = 0.0;
***********************************************************/
Distance::Distance()
{
    feet = 0;
    inches = 0.0;
}

/***********************************************************
*  Constructor (one argument) : Class Distance
*_________________________________________________________
*This constructor initializes corrects for negative inches, and corrects for
*   overflow with init function.
*_________________________________________________________
* PRE-CONDITIONS
*   The following need to have been declared:
*       inches: inches representing total Distance
* POST-CONDITIONS
*   The Date object is now set and corrected through init().
***********************************************************/
Distance::Distance(double inches)
{
    this->inches = inches;
    if(this->inches < 0) this->inches *= -1;
    init();
}

/***********************************************************
*  Constructor (two argument) : Class Distance
*_________________________________________________________
*This constructor initializes corrects for negative inches or feet, and
* corrects for overflow with init function.
*_________________________________________________________
* PRE-CONDITIONS
*   The following need to have been declared:
*       ft: feet measurement of distance
*       inches: inches measurement of distance
* POST-CONDITIONS
*   The Date object is now set and corrected through init().
***********************************************************/
Distance::Distance(unsigned ft, double inches)
{
    feet = ft;
    this->inches = inches;

    if(feet < 0) feet *= -1;
    if(this->inches < 0) this->inches *= -1;

    init();

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

    if( inches >= 12 )
    {
        feet += inches/12;
        inches -= (static_cast<int>(inches)/ 12) * 12;
    }
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
*       Returns total inches in Distance (from inches and feet)
***********************************************************/
double Distance::convertToInches() const
{
    double total;
    total = feet*12;
    total += inches;
    return total;
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
    cout << fixed << setprecision(2) <<  feet << "' " << inches <<"\"" << endl;
}

/***********************************************************
* Method operator+: Class Distance
*_________________________________________________________
*This method will define the '+' operator for Distance objects.
*  -returns Distance temp (result of addition)
*_________________________________________________________
* PRE-CONDITIONS
*   The following need to have been declared:
*       second: other object for addition
* POST-CONDITIONS
*       returns Distance temp
***********************************************************/

const Distance Distance::operator+(const Distance &second) const
{
    Distance temp;

    temp.feet = feet + second.feet;
    temp.inches = inches + second.inches;

    temp.init();

    return temp;
}

/***********************************************************
* Method operator-: Class Distance
*_________________________________________________________
*This method will define the '-' operator for Distance objects.
*  -returns Distance temp (result of subtraction)
*_________________________________________________________
* PRE-CONDITIONS
*   The following need to have been declared:
*       second: other object for subtraction
* POST-CONDITIONS
*       returns Distance temp
***********************************************************/
const Distance Distance::operator-(const Distance &second) const
{
    Distance temp;
    int hold;
    double hold2;

    hold = feet -second.feet;
    cout << endl << hold << endl;
    hold2= inches - second.inches;

    if (hold < 0 ) hold *= -1;
    if (hold2 < 0 )
    {
        hold2 *= -1;
        temp.feet -=1;
    }

    temp.feet = hold;
    temp.inches = hold2;

    temp.init();

    return temp;

}
