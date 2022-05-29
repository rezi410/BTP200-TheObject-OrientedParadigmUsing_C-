#ifndef SDDS_TICKET_H_
#define SDDS_TICKET_H_
#include "Time.h"
/* Citation and Sources...
Final Project Milestone 1
Module: Time, utils
Filename: Time.h, Time.cpp, utils.h, utils.cpp, PAtient.h, Patient.cpp, 
IOAble.h, IOAble.cpp, Ticket.h, Ticket.cpp
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
I have done all the coding by myself by reading course notes and watching the lectures,
some of the code used from course notes (for dynamicly allocated user input part)
-----------------------------------------------------------
-----------------------------------------------------------*/


#include "IOAble.h"
namespace sdds {
   class Ticket:public IOAble{
      Time m_time;   // the time of the ticket was issued
      int m_number;   // ticket number
   public:
      Ticket(int number);
      operator Time()const;
      int number()const;
      void resetTime();
      std::ostream& csvWrite(std::ostream& ostr)const;
      std::istream& csvRead(std::istream& istr);
      std::ostream& write(std::ostream& ostr )const;
      std::istream& read(std::istream& istr);
   };
}
#endif // !SDDS_TICKET_H_
