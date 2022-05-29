//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-03-27

// I have done all the coding by myself and only copied the code (logic)
// that my professor provided to complete my workshops and assignments.


#ifndef SDDS_MotorVehicle_H_
#define SDDS_MotorVehicle_H_

#include <iostream>


namespace sdds {

   class MotorVehicle
   {
      char m_licenceP[9];
      char m_address[64];
      int m_year;
      MotorVehicle& setToBeDefault(const char* licenceP, const int year);
      void setEmpty();
   public:
      MotorVehicle();
      MotorVehicle(const char* licenceP, const int year);
      void moveTo(const char* address);
      std::ostream& write(std::ostream& os) const;
      std::istream& read(std::istream& in);

   };

   std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle);
   std::istream& operator>>(std::istream& in, MotorVehicle& vehicle);



}
#endif;