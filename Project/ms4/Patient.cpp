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



#include <string>
#include <cstring>
#include "Patient.h"
#include "utils.h"


namespace sdds {

   //ticket number is to initialize member ticket object
   //fileIO is to initilize member file IO flag
   Patient::Patient(int ticketNum, bool fileIO)
   {
      m_ticket = ticketNum;
      m_flag = fileIO;
   }

   //deallocate dynamically allocated memory for patient name Cstring
   Patient::~Patient()
   {
      if (this->m_name != nullptr)
         delete[] this->m_name;
      this->m_name = nullptr;
   }

   //a query & wont modify current object 
   //returns member flag 
   const bool Patient::fileIO() const
   {
      return m_flag;
   }


   //modifier member function to set member flag
   void Patient::fileIO(bool val)
   {
      m_flag = val;
   }

   //compare current object with an incoming character, return true if same, false otherwise
   //(it wont modify current object)
   bool Patient::operator==(const char character) const
   {
      return type() == character;
   }

   //compare current object to another patient, return true is same, false otherwise
   //(it wont modify current object)
   bool Patient::operator==(const Patient& other) const
   {
      return this->type() == other.type();
   }

   //set the time of ticket to current time
   void Patient::setArrivalTime()
   {
      m_ticket.resetTime();
   }


   //if patient casted to Time type return the time of the ticket
   //(it wont modify current object)
   Patient::operator Time() const
   {
      return Time(m_ticket);
   }

   //return number of the ticket
   //(it wont modify current object)
   int Patient::number() const
   {
      return m_ticket.number();
   }

   //insert values to ostream in a comma seperated format
   std::ostream& Patient::csvWrite(std::ostream& ostr) const
   {
      ostr << type();
      ostr << ',' << this->m_name << ',' << this->m_ohip << ',';
      m_ticket.csvWrite(ostr);

      return ostr;
   }


   //extracts all values same as csvWrite function above
   std::istream& Patient::csvRead(std::istream& istr)
   {
      //updated implementation:

      char* p_name = getcstr(nullptr, istr, ','); //extraction with the name of patient with discarding delimiter comma

      if (this->m_name != nullptr) {  //name pointer is deleted before the allocation
         delete[] this->m_name;
         this->m_name = nullptr;
      }

      if (p_name != nullptr) { // check if the string is not null then allocated & copy
         this->m_name = new char[strlen(p_name) + 1];
         strcpy(this->m_name, p_name);
      }
      delete[] p_name;

      istr >> this->m_ohip;               //extract an integer
      istr.ignore();                      //discard the delimiter comma
      m_ticket.csvRead(istr);    //extract ticket number and time

      return istr;

   }

   /* perivious implementation:
   if (this->m_name != nullptr) {
      delete[] this->m_name;
      this->m_name = nullptr;
   }

   this->m_name = getcstr(nullptr,istr, ',');
   istr >> this->m_ohip;               //extract an integer
   istr.ignore();                      //discard the delimiter comma

   m_ticket.csvRead(istr);    //extract ticket number and time

   return istr;
   */


   /*
   { Perivious implementation:

      char m_char;
      std::string mystr;

      if (this->m_name != nullptr) {
         delete[] this->m_name;
         this->m_name = nullptr;
      }

      if (getline(istr, mystr, ',')) {

         m_name = new char[mystr.length() + 1];
         strcpy(m_name, mystr.c_str());
      }
      else {
         istr.clear();
         istr.ignore(2000, '\n');
      }

      istr >> m_ohip >> m_char;


      m_ticket.csvRead(istr);

      return istr;

   }
   */


   //inserts patient information into ostream to displayed on console
   std::ostream& Patient::write(std::ostream& ostr) const
   {
      // updated implementation:

      ostr << this->m_ticket << '\n';

      //insert name up to 25 characters
      if (strlen(this->m_name) <= 25)    //if length of string is less than 25
         ostr << this->m_name;           // display the string
      else
      {
         for (int i = 0; i < 25; i++) {  //otherwise, accept up to 25 characters, ignore the rest
            ostr << this->m_name[i];
         }
      }

      ostr << ", OHIP: " << this->m_ohip;

      return ostr;
   }

   /* perivious implementation:
   if (strlen(this->m_name) > 25) {
         for (int i = 0; i < 25; i++) {
            ostr << this->m_name[i];
         }
      }
      else ostr << this->m_name;

      ostr <<", OHIP: " << this->m_ohip;

      return ostr;
      */


      //extract ticket information from console as follows:
   std::istream& Patient::read(std::istream& istr)
   {
      char* name = getcstr("Name: ", istr, '\n');  //extraction with the name of patient with discarding delimiter '\n'

      if (this->m_name != nullptr) {  // delete the memory before allocation and copy
         delete[] this->m_name;
         this->m_name = nullptr;
      }

      if (name != nullptr) {    // if the name is not null, then allocate and copy
         this->m_name = new char[strlen(name) + 1];
         strcpy(this->m_name, name);
      }

      delete[] name;

      //extracts 9 digit OHIP number and validate it
      this->m_ohip = getInt(100000000, 999999999, "OHIP: ", "Invalid OHIP Number, ", true);

      return istr;
   }

   //perivious implementation:
/*
      if (this->m_name != nullptr) {  //name pointer is deleted before the allocation
         delete[] this->m_name;
         this->m_name = nullptr;
      }
      this->m_name = getcstr("Name: ", istr, '\n'); //extract name of patient up to '\n', discard '\n'

      getInt(100000000, 999999999, "OHIP: ", "Invalid OHIP Number, ", true);
      return istr;
*/





}

