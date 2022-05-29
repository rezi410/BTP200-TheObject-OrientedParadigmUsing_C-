//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-02-05



#ifndef SDDS_CALORIELIST_H
#define SDDS_CALORIELIST_H

#include "Food.h"

namespace sdds {

     class CalorieList {
           Food* m_items;               // pointer to the dynamically allocated array of food
           int m_noOfItems;             // size of the dynamically allocated array of foods
           int m_itemsAdded;              // number of the foods added by the add method
           int totalCalories()const;       // returns the sum of prices of foods
           void Title()const;              // prints the title
           void footer()const;            // prints the footer
           void setEmpty();                // sets to an empty state
           bool isValid()const;            // returns true if valid
        public:
           void init(int size);
           bool add(const char* item_name, int calories, int when);
           void display()const;
           void deallocate();
       };


 }





#endif // !SDDS_CALORIE_H
