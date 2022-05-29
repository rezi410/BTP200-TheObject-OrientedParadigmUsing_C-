//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-02-05



#include <iostream>
#include "cstring.h"
#include "CalorieList.h"

using namespace std;

namespace sdds {


    int CalorieList::totalCalories() const
    {
        int total = 0;

        for (int i = 0; i < m_noOfItems; i++)
        {
            if (m_items[i].isValid() == true)
            {
                total = total + m_items[i].cals();
            }
        }

        return total;
    }

    void CalorieList::Title() const
    {
            cout << "+----------------------------------------------------+" << "\n";

        if (isValid() == true)
        {
            cout << "|  Daily Calorie Consumption                         |" << "\n";
        }
        else
        {
            cout << "| Invalid Calorie Consumption list                   |" << "\n";
        }

        {
            cout << "+--------------------------------+------+------------+" << "\n";
            cout << "| Food name                      | Cals | When       |" << "\n";
            cout << "+--------------------------------+------+------------+" << "\n";
        }
    }

    void CalorieList::footer() const
    {
        cout << "+--------------------------------+------+------------+" << "\n";

        if (isValid() == true)
        {
            cout << "|    Total Calories for today: ";
            cout.width(8);
            cout << totalCalories();
            cout << " |";
            cout.width(13);
            cout.fill(' ');
            cout << " |";
            cout << "\n";

        }

        else
        {
            cout << "|    Invalid Calorie Consumption list                |" << "\n";
        }

        cout << "+----------------------------------------------------+" << "\n";
    }

    void CalorieList::setEmpty()
    {
        m_items = nullptr;
    }

    bool CalorieList::isValid() const
    {
        int value = 0;
        bool valid = true;

            if ( m_items != nullptr )
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

            }
            return valid;
    }

    void CalorieList::init(int size)
    {

        if ( size <= 0 )
        {
            setEmpty();
        }

        else
        {
            m_noOfItems = size;
            m_itemsAdded = 0;
            m_items = new Food[m_noOfItems];

            for (int i = 0; i < m_noOfItems; i++)
            {
                m_items[i].setEmpty();
            }
        }
    }

    bool CalorieList::add(const char* item_name, int calories, int when)
    {

        if (m_itemsAdded < m_noOfItems)
        {
            m_items[m_itemsAdded].set(item_name, calories, when);
            m_itemsAdded = m_itemsAdded + 1;

            return true;
        }

        else
        {
            return false;
        }

    }

    void CalorieList::display() const
    {
        Title();

        for (int i = 0; i < m_noOfItems; i++)
        {
            m_items[i].display();
        }

        footer();
    }

    void CalorieList::deallocate()
    {

        delete[] m_items;

    }
}