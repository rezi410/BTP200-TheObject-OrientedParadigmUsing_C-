//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-03-27

// I have done all the coding by myself and only copied the code (logic)
// that my professor provided to complete my workshops and assignments.


#include "Truck.h"

#include <iostream>

namespace sdds {

   Truck::Truck()
   {
      m_capacity = 0.0;
      m_cargoL = 0.0;
   }

   Truck::Truck(const char* licenceP, const int year, const double capacity, const char* address) : MotorVehicle(licenceP, year)
   {
         this->m_cargoL = 0;
         this->m_capacity = capacity;
         MotorVehicle::moveTo(address);
      
   }

   bool Truck::addCargo(double cargo)
   { 
      bool flag = false;
      // check if can add anything
      if (this->m_cargoL < this->m_capacity)
      { 
         // check if add whole cargo
         if (this->m_cargoL + cargo <= this->m_capacity) {
             this->m_cargoL += cargo;
         }
         // add some cargo
         else {
             this->m_cargoL = this->m_capacity;
         }
         flag = true;
      }
      return flag;
   }

   bool Truck::unloadCargo()
   {
      bool flag = false;
      if (this->m_cargoL == this->m_capacity)
      {
         this->m_cargoL = 0;
         flag = true;
      }  
      return flag;
   }

   std::ostream& Truck::write(std::ostream& os) const
   {
      MotorVehicle::write(os);
      os << " | " << this->m_cargoL << "/" << this->m_capacity;
      return os;
   }

   std::istream& Truck::read(std::istream& in)
   {
      double capacity;
      double cargo;

      MotorVehicle::read(in);

      std::cout << "Capacity: ";
      in >> capacity;

      std::cout << "Cargo: ";
      in >> cargo;

      if (in.good()) {
         this->m_capacity = capacity;
         this->m_cargoL = cargo;
      }
      else {
         in.clear();
         in.ignore(2000, '\n');
      }
      return in;
   }


   std::ostream& operator<<(std::ostream& os, const Truck& truck)
   {
      truck.write(os);
      return os;
   }

   std::istream& operator>>(std::istream& in, Truck& truck)
   {
      truck.read(in);
      return in;
   }

}
