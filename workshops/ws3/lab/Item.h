//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-02-03

// I have done all the coding by myself and only copied the code that my professor 
// provided to complete my workshopsand assignments. 
// (Because I was experiencing headaches, my professor helped me to debug and complete my workshop.)



#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

namespace sdds {
   class Item {
      char m_itemName[21];               // holds the item name up to 20 chars
      double m_price;
      bool m_taxed;
      void setName(const char* name);
   public:
      void setEmpty();
      void set(const char* name, double price, bool taxed);
      void display()const;
      bool isValid()const;
      double price()const;
      double tax()const;
   };
}

#endif // !SDDS_SUBJECT_H
