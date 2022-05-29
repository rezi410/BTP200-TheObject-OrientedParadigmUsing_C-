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
2020/5/06  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------
-----------------------------------------------------------*/




#include "CovidPatient.h"

using namespace std;

namespace sdds {
   int nextCovidTicket = 1;  //global variable: used to determine ticket number of next patient


   // default constructor: sets the patient ticket number to the global variable then increase by one
   CovidPatient::CovidPatient() : Patient(nextCovidTicket)
   {
      nextCovidTicket++;
   }

   // identify patient object as Covid patient by returning letter C
   char CovidPatient::type() const
   {
      return 'C';
   }

   //reads a comma seperated record of patient
   //sets the global ticket number to next number after the patient's ticket number
   std::istream& CovidPatient::csvRead(std::istream& istr)
   {
      Patient::csvRead(istr);   //read comma seperated record
      nextCovidTicket = Patient::number() + 1;  //set the global ticket number to next number
      
      istr.ignore();     // ignore terminating '\n' character

      return istr;
   }


   //based on return value of fileIO, write the patient in comma seperated format OR 
   // descriptive format for screen or ticket
   std::ostream& CovidPatient::write(std::ostream& ostr) const
   {
      if (Patient::fileIO()) {         // if fileIO return true
         Patient::csvWrite(ostr);
      }
      else {                           // else otherwise
         ostr << "COVID TEST" << '\n';
         Patient::write(ostr);
         ostr << endl;
      }
      return ostr;
   }


   //based on return value of fileIO, read the patient in comma seperated format from file OR 
   // dperform full proof entry from the console
   std::istream& CovidPatient::read(std::istream& istr)
   {
      if (fileIO()) {csvRead(istr);}  //if fileIO returns true
      else {Patient::read(istr);}                       //else otherwise
      return istr;
   }




}