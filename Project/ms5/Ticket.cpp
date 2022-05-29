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


#include "Ticket.h"
namespace sdds {

   //constructs a ticket by setting m_number to the incoming argument
   Ticket::Ticket(int number) {
      m_number = number;
   }

   //when ticket is casted to Time, return m_time
   Ticket::operator Time() const {
      return m_time;
   }

   // return the number of ticket
   int Ticket::number() const {
      return m_number;
   }

   //sets the ticket time to current time
   void Ticket::resetTime() {
      m_time.setToNow();
   }


   /*   virtual function overrides:    */

   //inserts a comma seperated ticket number and time into ostream
   std::ostream& Ticket::csvWrite(std::ostream& ostr) const {
      return ostr << m_number << "," << m_time;
   }

   //extracts a ticket number and time into in a comma seperated format
   std::istream& Ticket::csvRead(std::istream& istr) {
      istr >> m_number;        // get ticket number
      istr.ignore();          // ignore the comma
      return istr >> m_time;    // get time
   }

   //inserts a ticket into ostream to be displayed on console
   std::ostream& Ticket::write(std::ostream& ostr) const {
      return ostr << "Ticket No: " << m_number << ", Issued at: " << m_time;
   }

   //extracts a ticket information from istream same as csvRead
   std::istream& Ticket::read(std::istream& istr) {
      return csvRead(istr);
   }
}
