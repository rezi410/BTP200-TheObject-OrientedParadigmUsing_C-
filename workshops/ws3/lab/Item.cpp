//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-02-03

// I have done all the coding by myself and only copied the code that my professor 
// provided to complete my workshopsand assignments. 
// (Because I was experiencing headaches, my professor helped me to debug and complete my workshop.)

#include <iostream>
#include "cstring.h"
#include "Item.h"

using namespace std;

namespace sdds {

	void Item::setName(const char* name)
	{
        strnCpy(m_itemName, name, 20);
   //     m_itemName[20] = '\0';
	}


    void Item::setEmpty()
    {
        m_price = 0.0;
        m_itemName[0] = '\0';
    }


    void Item::set(const char* name, double price, bool taxed)
    {

        if ( (price < 0) || (name == nullptr) )
        {
            setEmpty();
        }
        else 
        {
        m_price = price;
        m_taxed = taxed;
        setName(name);
        }
    }


    void Item::display() const
    {
        if (isValid() == true)
        {
            cout << "| ";
            cout.setf(ios::left);
            cout.fill('.');
            cout.width(20);
            cout << m_itemName;
            cout.unsetf(ios::left);
            cout.fill(' ');


            cout << " | ";
            cout.width(7);
            cout.precision(2);
            cout.setf(ios::fixed);
            cout << m_price;
            cout << " | ";

            if (m_taxed == true)
            {
                cout << "Yes";
                cout << " |";
                cout << "\n";
            }
            else
            {
                cout << "No ";
                cout << " |";
                cout << "\n";
            }
        }

        else 
        {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |";
            cout << "\n";
        }

    }


    bool Item::isValid() const
    {
      
        if ((m_price != 0.0) && (m_itemName[0] != '\0'))
        {
            return true;
        }
        else 
        {
            return false;
        }        

    }


    double Item::price() const
    {
        return m_price;
    }


    double Item::tax() const
    {
        const double tax = 0.13;

        if (m_taxed == false)
        {
            return 0.0;
        }
        else 
        {
            return m_price * tax;
        }
    }

}
