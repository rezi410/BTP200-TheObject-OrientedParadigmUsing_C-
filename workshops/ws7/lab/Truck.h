//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-03-27

// I have done all the coding by myself and only copied the code (logic)
// that my professor provided to complete my workshops and assignments.



#ifndef SDDS_TRUCK_H_
#define SDDS_TRUCK_H_

#include <iostream>
#include "MotorVehicle.h"

namespace sdds {
   class Truck : public MotorVehicle
   { 
      double m_capacity;   
      double m_cargoL;
   public:     
      Truck();
      Truck(const char* licenceP,const int year, const double capacity, const char* address);
      bool addCargo(double cargo);
      bool unloadCargo();
      std::ostream& write(std::ostream& os) const;
      std::istream& read(std::istream& in);

   };

   std::ostream& operator<<(std::ostream& os, const Truck& truck);
   std::istream& operator>>(std::istream& in, Truck& truck);

}

#endif;