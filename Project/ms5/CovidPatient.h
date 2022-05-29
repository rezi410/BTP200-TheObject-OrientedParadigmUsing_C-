/* Citation and Sources...
Final Project Milestone 4
Module: Time, utils, Patient, Ticket, IOAble, CovidPatient
Filename: Time.h, Time.cpp, utils.h, utils.cpp, Patient.h, Patient.cpp, Ticket.h, Ticket.cpp
IOAble.h, IOAble.cpp, CovidPatient.h, CovidPatient.cpp, TriagePatient.h, TriagePatient.cpp
Version 1.0
Author	Reziyemu Sulaiman
Revision History
-----------------------------------------------------------
Student Name:
Date      Reason
2020/3/26  Preliminary release
2020/5/15  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor and classmate provided to complete my workshops and assignments.
-----------------------------------------------------------
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



