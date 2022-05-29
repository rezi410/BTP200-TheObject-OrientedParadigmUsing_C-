/* Citation and Sources...
Final Project Milestone 1
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
I have done all the coding by myself by reading course notes and watching the lectures,
some of the code used from course notes (for dynamicly allocated user input part)
-----------------------------------------------------------
-----------------------------------------------------------*/



#ifndef SDDS_PATIENT_H
#define SDDS_PATIENT_H

#include <iostream>
#include "IOAble.h"
#include "Ticket.h"


namespace sdds {

   class Patient : public IOAble {
      char* m_name = nullptr;     // patient name
      int m_ohip;       // OHIP insurance number
      Ticket m_ticket=0;   // ticket of patient
      bool m_flag;      // return true if read from file OR return false if read from console
   public:
      //if ticket number is not provided, default value 0 is passed
      //if file IO flag is not provided, default value "false" is passed
      Patient(int ticketNum = 0, bool fileIO = false);

      //a patient can not be copied or assignned to another patient
      Patient(const Patient&) = delete;
      Patient& operator=(const Patient&) = delete;

      //deallocate dynamically allocated memory
      ~Patient();

      //pure virtual function & it won't modify current object
      virtual char type() const = 0;

      //a query & it  wont modify current object
      const bool fileIO() const;

      //modifier member function
      void fileIO(bool val);

      //character comparison
      bool operator==(const char character) const;

      //comparing to another patient
      bool operator==(const Patient& other) const;

      //set the time of ticket to current time
      void setArrivalTime();

      //Time cast operator overload
      operator Time() const;

      //return number of ticket
      int number()const;

      /*   pure virtual function overrides  */
      std::ostream& csvWrite(std::ostream& ostr)const;
      std::istream& csvRead(std::istream& istr);
      std::ostream& write(std::ostream& ostr)const;
      std::istream& read(std::istream& istr);




   };

}

#endif // ! 