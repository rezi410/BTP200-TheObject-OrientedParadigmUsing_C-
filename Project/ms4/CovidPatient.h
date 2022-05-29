/* Citation and Sources...
Final Project Milestone 4
Module: Time, utils
Filename: Time.h, Time.cpp, utils.h, utils.cpp, PAtient.h, Patient.cpp, Ticket.h, Ticket.cpp
IOAble.h, IOAble.cpp
Version 1.0
Author	John Doe
Revision History
-----------------------------------------------------------
Name      Reziyemu Sulaiman
Student NUmber 106-153-208
Stduent Email  rsulaiman2@myseneca.ca
Date      Reason
2020/3/17  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself by reading course notes and watching the lectures.
-----------------------------------------------------------
-----------------------------------------------------------*/


#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_

#include <iostream>
#include "Patient.h"

namespace sdds { // this class does not add any member variables or properties to the base class
   class CovidPatient : public Patient {
   public:
      CovidPatient();
      char type() const;
      std::istream& csvRead(std::istream& istr);
      std::ostream& write(std::ostream& ostr)const;
      std::istream& read(std::istream& istr);


   };



}
#endif // !SDDS_COVIDPATIENT_H_



