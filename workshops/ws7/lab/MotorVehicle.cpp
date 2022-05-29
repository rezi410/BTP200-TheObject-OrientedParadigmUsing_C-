//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-03-27

// I have done all the coding by myself and only copied the code (logic)
// that my professor provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "MotorVehicle.h"
#include "cstring.h"

using namespace std;

namespace sdds {

   MotorVehicle::MotorVehicle()
   {
      setToBeDefault("", 0);
   }

   MotorVehicle::MotorVehicle(const char* licenceP, const int year)
   {   
      setToBeDefault(licenceP, year);
   }

   MotorVehicle& MotorVehicle::setToBeDefault(const char* licenceP, const int year)
   {
      this->m_year = year;

      strCpy(m_licenceP, licenceP);

      strCpy(m_address, "Factory");

      return *this;
   }

   void MotorVehicle::setEmpty()
   {
      this->m_licenceP[0] = '\0';
      this->m_year = -1;
      this->m_address[0] = '\0';
   }


   void MotorVehicle::moveTo(const char* address)
   {
      cout << "|";
      cout.width(8);
      cout << this->m_licenceP << "| |";
      cout.width(20);
      cout << this->m_address;
      cout << " ---> ";
      cout.width(20);
      cout.setf(ios::left);
      cout << address << "| ";
      cout.unsetf(ios::left);
      cout << endl;
      
      if (strCmp(this->m_address, address) != 0)
      {
         strCpy(this->m_address, address);
      }

   }

   std::ostream& MotorVehicle::write(std::ostream& os)const
   {
      os << "| " << this->m_year << " | " << this->m_licenceP << " | " << this->m_address;
      
      return os;
   }

   std::istream& MotorVehicle::read(std::istream& in)
   {
      int yearr;
      char licensee[9];
      char addresss[64];
      cout << "Built year: ";
      in >> yearr;
      in.ignore();

      cout << "License plate: ";
      in.getline(licensee, 9, '\n');

      cout << "Current location: ";
      in.getline(addresss, 64, '\n');

      if (in.good())
      {
         this->m_year = yearr;
         strCpy(this->m_licenceP, licensee);
         strCpy(this->m_address, addresss);
      }
      else {
         in.clear(); //clear the errors for cin
         in.ignore(2000, '\n');
        
      }
      return in;
   }


   std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle)
   {
      vehicle.write(os);
      return os;
   }

   std::istream& operator>>(std::istream& in, MotorVehicle& vehicle)
   {
      vehicle.read(in);
      return in;
   }

}
