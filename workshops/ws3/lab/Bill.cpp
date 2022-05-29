//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-02-03

// I have done all the coding by myself and only copied the code that my professor 
// provided to complete my workshopsand assignments. 
// (Because I was experiencing headaches, my professor helped me to debug and complete my workshop.)


#include <iostream>
#include "cstring.h"
#include "Bill.h"

using namespace std;

namespace sdds {

    double Bill::totalTax() const
    {
        double total_tax = 0;

        for (int i = 0; i < m_noOfItems; i++)
        {
            if ( m_items[i].isValid() == true )
            {
                total_tax = total_tax + m_items[i].tax();
            }
        }

        return total_tax;
    }

    double Bill::totalPrice() const
    {
        double sum = 0;

        for (int i = 0; i < m_noOfItems; i++)
        {
            if ( m_items[i].isValid() == true )
            {
                sum = sum + m_items[i].price();
            }
        }

        return sum;
    }

    void Bill::Title() const
    {
        cout << "+--------------------------------------+" << "\n";

        if (isValid() == true)
        {
            cout << "| ";
            cout.width(36);
            cout.setf(ios::left);
            cout << m_title;
            cout.unsetf(ios::left);
            cout << " |";
            cout << "\n";
        }
        else
        {
            cout << "| Invalid Bill                         |" << "\n";
        }

        {
            cout << "+----------------------+---------+-----+" << "\n";
            cout << "| Item Name            | Price   + Tax |" << "\n";
            cout << "+----------------------+---------+-----+" << "\n";
        }
    }

    void Bill::footer() const
    {
        cout << "+----------------------+---------+-----+" << "\n";

        if (isValid() == true)
        {
            cout << "|                Total Tax: ";
            cout.width(10);
            cout.precision(2);
            cout.setf(ios::fixed);
            cout << totalTax();
            cout << " |";
            cout << "\n";

            cout << "|              Total Price: ";
            cout.width(10);
            cout.precision(2);
            cout.setf(ios::fixed);
            cout << totalPrice();
            cout << " |";
            cout << "\n";

            cout << "|          Total After Tax: ";
            cout.width(10);
            cout.precision(2);
            cout.setf(ios::fixed);
            cout << totalTax() + totalPrice();
            cout << " |";
            cout << "\n";

        }

        else 
        {
            cout << "| Invalid Bill                         |" << "\n";
        }

        cout << "+--------------------------------------+" << "\n";
    }

    void Bill::setEmpty()
    {
        m_title[0] = '\0';
 //       strnCpy(m_title, "", 1);

        m_items = nullptr;      
    }

    bool Bill::isValid() const
    {
        int value = 0;
        bool valid = true;

        if ( (m_title[0] != '\0') && (m_items != nullptr) )
        {
            for (int i = 0; i < m_noOfItems; i++)
            {
                if (m_items[i].isValid() == true)
                {
                    value++;
                }
            }

            if (value == m_noOfItems)
            {
                valid = true;
            }
            else
            {
                valid = false;
            }

            return valid;
        }     
    }

    void Bill::init(const char* title, int noOfItems)
    {
        
        if ( (title == nullptr) || (noOfItems <= 0) )
        {
            setEmpty();
        }

        else
        {
            strnCpy(m_title, title, 36);
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            m_items = new Item[m_noOfItems];
 
            for (int i = 0; i < m_noOfItems; i++)
            {
                m_items[i].setEmpty();
            }
        }
    }

    bool Bill::add(const char* item_name, double price, bool taxed)
    {   

       
        if (m_itemsAdded < m_noOfItems)
        {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded = m_itemsAdded + 1;

            return true;           
        }

        else 
        {
            return false;
        }

    }

    void Bill::display() const
    {       
        Title();

        for (int i = 0; i < m_noOfItems; i++)
        {
            m_items[i].display();            
        }

        footer();
    }

    void Bill::deallocate()
    {
        
        delete[] m_items;
       
    }


}
