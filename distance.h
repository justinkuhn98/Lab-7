/**********************************************************
 * AUTHOR       : Justin Kuhn, Matthew Endo
 * Lab        #7: Distance
 * CLASS        : CS3A
 * SECTION      : MW: 1:00p - 2:25p, TR: 1:00p - 3:05p
 * Due Date     : 10/3/18
*********************************************************/

#ifndef DISTANCE_H
#define DISTANCE_H


class Distance
{
    private:
        unsigned feet;   // IN/OUT -- feet of measurement
        double inches;   // IN/OUT -- inches of measurement
    public:
        /***** CONSTRUCTORS *****/
        Distance();
        Distance(unsigned, double);
        Distance(double);
        /************************/

        /***** ACCESSORS *****/
        double convertToInches() const;
        const Distance operator+(const Distance &) const;
        const Distance operator-(const Distance &) const;
        void display() const;
        /*********************/
    private:
        /***** MUTATORS *****/
        void init();
        /********************/
};

#endif // DISTANCE_H
/******************************************************************************
 * Distance Class
 *   This class represents a complete Distance object. It manages two
 *      attributes, feet and inches.
 *****************************************************************************/


/***** CONSTRUCTORS *****/

/******************************************************************************
 * Distance();
 *   Constructor; Initialize class attributes ( feet = 0,
 *                                                  inches = 0.0)
 *   Parameters: None
 *   Returns: Nothing
 *****************************************************************************/


/******************************************************************************
 * Distance(double inch);
 *   Constructor; Initialize class attributes ( feet = inches/12,
 *                              inches -= (static_cast<int>(inches)/ 12) * 12)
 *   Parameters: inches: inches to convert to feet and inches
 *   Returns: Nothing
 *****************************************************************************/

/******************************************************************************
 * Distance(unsigned ft, double inches);
 *   Constructor; Initialize class attributes ( feet += inches/12,
 *                              inches -= (static_cast<int>(inches)/ 12) * 12)
 *   Parameters: inches: inches to add to also convert to feet, feet: feet from
 *                                                                  inches
 *   Returns: Nothing
 *****************************************************************************/

/***** ACCESSORS *****/

/****************************************************************
* double convertToInches() const;
*
*   Accessor; This method will return a double represnting all the inches in
*               in the Distance measurement in total.
* --------------------------------------------------------------
*   Parameters: None
* --------------------------------------------------------------
*   Return: double total_inches
***************************************************************/

/****************************************************************
* void display() const;
*
*   Accessor; This method will display the feet and inches of Distance in
*               the appropriate format.
*               Ex: 3' 0.00"
* --------------------------------------------------------------
*   Parameters: None
* --------------------------------------------------------------
*   Return: Nothing
***************************************************************/

/****************************************************************
* const Distance operator+(const Distance &dist) const;
*
*   Accessor; This method will define the addition operator for a
*               Distance object.
* --------------------------------------------------------------
*   Parameters: dist: right side of addition.
* --------------------------------------------------------------
*   Return: Distance sum (result of addition)
***************************************************************/


/****************************************************************
* const Distance operator-(const Distance &dist) const;
*
*   Accessor; This method will define the subtration operator for a
*               Distance object.
* --------------------------------------------------------------
*   Parameters: dist: right side of subtraction.
* --------------------------------------------------------------
*   Return: Distance difference (result of subtraction)
***************************************************************/

/***** MUTATORS *****/

/****************************************************************
* void init()
*
*   Mutator; This method will initialize an object with the correct
*               number of feet, if inches overflow. Used in addition,
*               subtraction, and constructors.
* --------------------------------------------------------------
*   Parameters: None
* --------------------------------------------------------------
*   Return: corrects values of Distance object
***************************************************************/


//1
