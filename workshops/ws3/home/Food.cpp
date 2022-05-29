//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-02-05




#include <iostream>
#include "cstring.h"
#include "Food.h"

using namespace std;

namespace sdds
{
    void Food::setName(const char* name)
    {
        strnCpy(foodName, name, 30);
  //      foodName[30] = '\0';
    }


    void Food::setEmpty()
    {
        foodName[0] = '\0';
        calorieNum = 0;
        time_consum[0] = '\0';
    }


    void Food::set(const char* name, int calorie, int time)
    {

        if ( (name == nullptr) || (calorie < 0) || (calorie > 3000) )
        {
            if ( (time != 1) && (time != 2) && (time != 3) && (time != 4) )
            {
                setEmpty();
            }
        }
        else
        {
            calorieNum = calorie;
            setName(name);
            setTime(time);
        }
    }


    void Food::display() const
    {
        if (isValid() == true)
        {
            cout << "| ";
            cout.setf(ios::left);
            cout.fill('.');
            cout.width(30);
            cout << foodName;
            cout.unsetf(ios::left);
            cout.fill(' ');


            cout << " | ";
            cout.width(4);
            cout << calorieNum;
            cout << " | ";

            cout.width(10);
            cout.setf(ios::left);
            cout << time_consum;
            cout.unsetf(ios::left);
            cout << " |";
            cout << "\n";

        }

        else
        {
            cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |";
            cout << "\n";
        }

    }


    bool Food::isValid() const
    {

        if ( (calorieNum != 0) && (foodName[0] != '\0') && (time_consum[0] != '\0') )
        {
            return true;
        }
        else
        {
            return false;
        }

    }


    int Food::cals() const
    {
        return calorieNum;
    }


    void Food::setTime(const int time)
    {

        if ( time == 1 )
        {
            strnCpy(time_consum, "Breakfast", 14);
        }
        if (time == 2)
        {
            strnCpy(time_consum, "Lunch", 14);
        }
        if (time == 3)
        {
            strnCpy(time_consum, "Dinner", 14);
        }
        if (time == 4)
        {
            strnCpy(time_consum, "Snack", 14);
        }

    }
}