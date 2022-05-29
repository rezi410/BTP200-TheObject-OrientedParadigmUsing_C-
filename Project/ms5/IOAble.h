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

#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H

#include <iostream>

namespace sdds {
   class IOAble        // abstract base class contaning pure virtual functions
   {
   public:
      virtual std::ostream& csvWrite(std::ostream&)const = 0;
      virtual std::istream& csvRead(std::istream&) = 0;
      virtual std::ostream& write(std::ostream&)const = 0;
      virtual std::istream& read(std::istream&) = 0;
      virtual ~IOAble() {};

   };
   std::ostream& operator<<(std::ostream& out, const IOAble& io);
   std::istream& operator>>(std::istream& in, IOAble& io);



}

#endif
