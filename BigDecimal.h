#ifndef BIGDECIMAL_H
#define BIGDECIMAL_H

#include <bits/stdc++.h>
#include <string>
#include <sstream>
#include <string.h>
#include <conio.h>

using namespace std;

class BigDecimal
{
    /**
    * Creating a string to contain the long number that we can later use string manipulation functions to
    * use in different operators like + and -
    *
    * Also creates a boolean value for the sign, true if positive and false if negative.
    */
    string number = "";
    bool positive = true;

    // This function overrides the << operator and prints the number
    friend ostream& operator<<(ostream& out, BigDecimal number)
    {
        if(!number.getSign())
        {
            out << '-';
        }
        out << number.getNumber();

        return out;
    }

public:
    // Constructor takes string and assigns it to the variable number and assigns the sign as well
    BigDecimal(string _number);

    // Getter methods for number and sign
    string getNumber();
    int getLength()
    {
        return number.length();
    }
    bool getSign();
    //this function returns true if number < number2
    bool isSmaller(BigDecimal number2);
    string trim(string a);

    // This function subtracts two BigDecimal objects and returns a new object with the result
    BigDecimal operator-(BigDecimal number2);


    // This function adds two BigDecimal objects and returns a new object with the result
    BigDecimal operator+(BigDecimal number2);
};




#endif // BIGDECIMAL_H
