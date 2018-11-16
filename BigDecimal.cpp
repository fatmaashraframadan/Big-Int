#include "BigDecimal.h"
#include<array>

BigDecimal::BigDecimal(string _number)
{
    if(_number[0] == '-')
    {
        positive = false;
        number = _number.substr(1);
    }
    else
    {
        positive = true;
        number = _number;
    }
}

string BigDecimal::getNumber()
{
    return number;
}

bool BigDecimal::getSign()
{
    return positive;
}
string trim(string a)   // for removing leading 0s
{
    string res="";
    int i=0;

    while(a[i]=='0')
        i++;

    for(; i<a.size(); i++)
        res+=a[i];

    return res;
}

// This function adds two BigDecimal objects and returns a new object with the result
BigDecimal BigDecimal:: operator+(BigDecimal number2)
{
    if(getSign() != number2.getSign())
    {
        if(!getSign())
        {
            BigDecimal g = getNumber();
            return(number2 - g);
        }

        BigDecimal g = number2.getNumber(); // g(number2.getNumber())

        return (*this - g);
    }

    int al = sizeof(number)-1;
    int bl = sizeof(number2)-1;
    string Number2 = number2.getNumber();
    int carry=0;
    string result="";
    if(this->getSign() == true && number2.getSign() == true)
    {

        while(al>=0 && bl>=0)
        {

            int temp = (int)(number[al] - '0') + (int)(Number2[bl] - '0') + carry ;
            carry = 0;
            if(temp > 9 )
            {
                carry=1;
                temp=temp-10;
            }

            result+=char(temp + '0');
            al--;
            bl--;
        }

        while(al>=0)
        {
            int temp = (int)(number[al] - '0') + carry ;
            carry = 0;
            if(temp>9)
            {
                carry=1;
                temp=temp%10;
            }

            result+=char(temp + '0');
            al--;
        }

        while(bl>=0)
        {
            int temp = (int)(Number2[bl] - '0') + carry ;
            carry = 0;
            if(temp>9)
            {
                carry=1;
                temp=temp%10;
            }

            result+=char(temp + '0');
            bl--;
        }

        if(carry)
            result+="1";

        string addition="";

        for(int i=result.size()-1; i>=0; i--)
            addition+=result[i];   // reversing the answer

        return addition;
    }
    if(this->getSign() == false && number2.getSign() == false)
    {

        while(al>=0 && bl>=0)
        {

            int temp = (int)(number[al] - '0') + (int)(Number2[bl] - '0') + carry ;
            carry = 0;
            if(temp > 9 )
            {
                carry=1;
                temp=temp-10;
            }

            result+=char(temp + '0');
            al--;
            bl--;
        }

        while(al>=0)
        {
            int temp = (int)(number[al] - '0') + carry ;
            carry = 0;
            if(temp>9)
            {
                carry=1;
                temp=temp%10;
            }

            result+=char(temp + '0');
            al--;
        }

        while(bl>=0)
        {
            int temp = (int)(Number2[bl] - '0') + carry ;
            carry = 0;
            if(temp>9)
            {
                carry=1;
                temp=temp%10;
            }

            result+=char(temp + '0');
            bl--;
        }

        if(carry)
            result+="1";

        string addition="";
        string sign1= "-" ;

        for(int i=result.size()-1; i>=0; i--)
            addition+=result[i];   // reversing the answer

        addition.insert(0,sign1);
        return addition;

    }
}


/**This Function returns true if number1 < number2**/
bool BigDecimal:: isSmaller(BigDecimal number2)
{
    int numsize1 = sizeof(number);
    int numsize2 = sizeof(number2);
    if(numsize1 < numsize2)
    {
        return true;
    }
    else
    {
        return false;
    }
    for(int i = 0 ; i < numsize1 ; i++)
    {
        if(numsize1 < numsize2)
        {
            return true ;
        }
        else if(numsize1 > numsize2)
        {
            return false;
        }
    }
    return false;
}
/** This function subtracts two BigDecimal objects and returns a new object with the result**/
BigDecimal BigDecimal:: operator-(BigDecimal number2)
{
    if(getSign() != number2.getSign())
    {
        if(!getSign())
        {
            BigDecimal g = getNumber();
            return(number2 + g);
        }

        BigDecimal g = number2.getNumber(); // g(number2.getNumber())

        return (*this + g);
    }
    //string to store result in
    string result =" ";
    string Number2 = number2.getNumber();
    int carry = 0;
    int numsize1 = sizeof(number);
    int numsize2 = sizeof(number2);
    if(this->getSign()==true && number2.getSign()==true)
    {
        if(isSmaller(number2))
        {
            positive = false;
        }
        for(int i = 0 ; i < numsize2 ; i++ )
        {

            int temp = (((int)number[i] -'0') - ((int)Number2[i] - '0') - carry);
            if(temp < 0)
            {
                temp+=10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            result.push_back(temp + '0');
        }
        for(int i = numsize2 ; i < numsize1 ; i++)
        {

            int temp = (((int)number[i] - '0 ' ) - carry);
            if(temp < 0)
            {
                temp +=10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            result.push_back(temp + '0');
        }
        return result;

    }
    if(this->getSign()==false && number2.getSign()==false)
    {
        if(isSmaller(number2))
        {
            positive = false;
        }
        for(int i = 0 ; i < numsize2 ; i++ )
        {

            int temp = (((int)number[i] -'0') - ((int)Number2[i] - '0') - carry);
            if(temp < 0)
            {
                temp+=10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            result.push_back(temp + '0');
        }
        for(int i = numsize2 ; i < numsize1 ; i++)
        {

            int temp = (((int)number[i] - '0 ' ) - carry);
            if(temp < 0)
            {
                temp +=10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            result.push_back(temp + '0');
        }
        string sign2 = "-";
        result.insert(0,sign2);
        return result;

    }
}
