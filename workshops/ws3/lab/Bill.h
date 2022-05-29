//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-02-03

// I have done all the coding by myself and only copied the code that my professor 
// provided to complete my workshopsand assignments. 
// (Because I was experiencing headaches, my professor helped me to debug and complete my workshop.)


#ifndef SDDS_BILL_H
#define SDDS_BILL_H

#include "Item.h"

namespace sdds {
   class Bill {
      char m_title[37];           // title of the shopping list
      Item* m_items;               // pointer to the dynamically allocated array of Items
      int m_noOfItems;             // size of the dynamically allocated array of Items
      int m_itemsAdded;              // number of the Items added by the add method
      double totalTax()const;         // returns the total tax applied to the items
      double totalPrice()const;       // returns the sum of prices of Items
      void Title()const;              // prints the title of the shopping list
      void footer()const;        // prints the footer containing total tax, price, and total price after tax
      void setEmpty();                // sets the bill to an empty state
      bool isValid()const;            // returns true if the bill and all of its Items are valid
   public:
      void init(const char* title, int noOfItems);
      bool add(const char* item_name, double price, bool taxed);
      void display()const;
      void deallocate();
   };
}
#endif // !SDDS_TRANSCRIPT_H
