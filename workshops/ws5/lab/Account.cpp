//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-02-17

// I have done all the coding by myself and only copied the code (about moving funds from one to another)
// that my professor provided to complete my workshops and assignments.





#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;

namespace sdds {

    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }


    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }


    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
        
    }


    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }


    Account::operator bool() const
    {
        return (m_number >= 10000 && m_number <= 99999 && m_balance >= 0);
    }


        /*   Another way of implementation:
        if (m_number >= 10000 && m_number <= 99999 && m_balance >= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
        */
    


    Account::operator int() const
    {
        return m_number;
    }


    Account::operator double() const
    {
        return m_balance;
    }


    bool Account::operator~() const
    {
        return m_number == 0;
    }


    Account& Account::operator=(const int acc_num)
    {
       
        if ((acc_num < 10000) || (acc_num > 99999))
        {
            setEmpty();
        }
        if (m_number == 0)     // if new take action, if not new dont take action
        {
            m_number = acc_num;
        }

        return *this;
        
    }
    


    Account& Account::operator=(Account& other)
    {
        if ( (m_number == 0) && bool(other) )
        {
            m_number = other.m_number;
            m_balance = other.m_balance;

            other.m_number = 0;
            other.m_balance = 0;
        }
        return *this;

    }
        /* other way 1:
        if (other.m_balance >= 0)
        {
            m_balance = other.m_balance;
            other.m_balance = 0;
        }

        if ((m_number == 0) && (other.m_number >= 10000) && (other.m_number <= 99999))
        {
        m_number = other.m_number;
        other.m_number = 0;
        }

        return *this;
        */


        /*  other way 2:
        {

            if ((m_number == 0) && (other.m_number >= 10000) && (other.m_number <= 99999) && other.m_balance >= 0)
            {
                m_number = other.m_number;
                m_balance = other.m_balance;

                other.m_number = 0;
                other.m_balance = 0;
            }

            return *this;

        }
        */



Account& Account::operator+=(const double add_val)
{
    if ( bool(*this) && (add_val > 0) )
    {
        m_balance += add_val;
    }

    return *this;

}

    /* other way 1:
    if ( (m_number >= 10000) && (m_number <= 99999) && (m_balance > 0) && (add_val > 0) )
    {
        m_balance += add_val;
    }

    return *this;
    */



Account& Account::operator-=(const double reduce_val)
{
    if (bool(*this) && (reduce_val > 0) && (m_balance >= reduce_val))
    {
        m_balance -= reduce_val;
    }

    return *this;

}
    /* other way 1:
    if ((m_number >= 10000) && (m_number <= 99999) && (m_balance > 0) && (reduce_val > 0) 
        && (m_balance >= reduce_val))
    {
        m_balance -= reduce_val;
    }

    return *this;
    */



Account& Account::operator<<(Account& right) 
{

    if ((this != &right) && bool(*this) && bool(right))
    {        
        m_balance += right.m_balance;
        right.m_balance = 0.0;
    }

    return *this;
}


Account& Account::operator>>(Account& other_right) 
{
    other_right << *this;

    return *this;
}


/*    
if ((m_number >= 10000) && (m_number <= 99999)
        && (other_right.m_number >= 10000) && (other_right.m_number <= 99999)
        && (m_balance > 0) && (other_right.m_balance > 0))
    {       
        other_right.m_balance += m_balance;
        m_balance = 0.0;
    }
*/


double operator + (const Account& first, const Account& second)
{ 
    // outside function defenition as a stand alone helper
    double sum = 0.0;

    if (bool(first) && bool(second))
    {
        sum = first.operator double() + second.operator double();
    }
    else
    {
        sum = 0.0;
    }

    return sum;


}
    /* inside function implementation as a friend:
    
    if ( (first.m_number >= 10000) && (first.m_number <= 99999) 
        && (second.m_number >= 10000) && (second.m_number <= 99999)
        && (first.m_balance > 0) && (second.m_balance > 0) )
    {
        sum = first.m_balance + second.m_balance;
    }
    else
    {
        sum = 0.0;
    }

    return sum;
    */




double operator += (double& lo, const Account& ro)
{
    // outside fucntion implementation:
    return lo += ro.operator double();
}

    /*   inside function implementation as a friend 
    
    double total = 0.0;

    total = lo += ro.m_balance;
 
    return total;
    */












}



