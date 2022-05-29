//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-02-10

// I have done all the coding by myself and only copied the code (about the logic of filling a canister to another)
// that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CANISTER_H
#define SDDS_CANISTER_H

#include <iostream>

namespace sdds {
   class Canister {
      char* m_contentName;                    // pointes to a dynamically acllocated Cstring
      double m_diameter;                      // in centimeters 
      double m_hieght;                        // in centimeters
      double m_contentVolume;                 // in CCs
      bool m_usable;                          // a flag to indentify if the canister is usable or unusable
      void setToDefault();
      void setName(const char* Cstr);
      bool isEmpty()const;
      bool hasSameContent(const Canister& C)const;
   public:
      Canister();
      Canister(const char* contentName);
      Canister(double hieght, double diameter, const char* contentName = nullptr);
      ~Canister();
      Canister& setContent(const char* contentName);
      Canister& pour(double quantity);
      Canister& pour(Canister& C);
      double volume()const;
      std::ostream& display()const;
      double capacity()const;
      void clear();
   };
}

#endif // !SDDS_BOX_H
