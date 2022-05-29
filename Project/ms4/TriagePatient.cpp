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



#include <cstring>
#include "TriagePatient.h"
#include "utils.h"

using namespace std;

namespace sdds {

   int nextTriageTicket = 1;    //global variable: to determine ticket number of next triage patient

   //default constructor: initilizes symptoms character pointer to null
   //sets the triage ticket number to global variable
   //increases global variable by one
   TriagePatient::TriagePatient() : Patient(nextTriageTicket)
   {
      this->m_symptoms = nullptr;
      nextTriageTicket++;
   }
   
   // identifies patient as triage by returning letter T
   char TriagePatient::type() const
   {
      return 'T';
   }

   //adds symptoms to the comma seperated patient
   std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const
   {
      Patient::csvWrite(ostr);  
      ostr << ',';
      ostr << this->m_symptoms;

      return ostr;

   }

   //read as a comma seperated record of triage patient
   //sets the global ticket number to next number after the patient's ticket number
   std::istream& TriagePatient::csvRead(std::istream& istr)
   {
      char* symptoms;                //create a local dynamically allocated Cstring

      if (this->m_symptoms != nullptr) {  //deletes the momory of symptoms
         delete[] this->m_symptoms;
         this->m_symptoms = nullptr;
      }
      Patient::csvRead(istr);   //reads comma seperated record from base class
      istr.ignore();         //ignore the character comma
     
      symptoms = getcstr(nullptr, istr, '\n');  //dynamically reads a Cstring up to '\n' and store it
      if (symptoms != nullptr) {     // if it is not null
         this->m_symptoms = new char[strlen(symptoms) + 1];   //allocate and make the copy
         strcpy(this->m_symptoms, symptoms);
         delete[] symptoms;
      }
      else {
         this->m_symptoms = nullptr;  
      }
      
      nextTriageTicket = Patient::number() + 1;  //sets global variable to next number

      return istr;
   }


   //based on return value of fileIO, either write patient record in a comma sepearetd format OR 
   //descriptive format for screen or ticket
   std::ostream& TriagePatient::write(std::ostream& ostr) const
   {
      if (fileIO())      //if fileIO returns true, write record in a comma sepearetd format
         csvWrite(ostr);   
      else {                      //otherwise, write record in a descriptive format as the following
         ostr << "TRIAGE" << '\n';  
         Patient::write(ostr);
         ostr << '\n' << "Symptoms: " << this->m_symptoms << endl;
      }
      return ostr;     
   }


   // if fileIO returns true, read patient record in a comma seperated format, else do the following
   std::istream& TriagePatient::read(std::istream& istr)
   {
      char* p_symptoms;

      if (fileIO())    // if fileIO returns true, read it in comma seperated format
         csvRead(istr);  
      else 
      {                                      // else: 
         if (this->m_symptoms != nullptr){    //deletes memory of dynamically allocated Cstring
           delete[] this->m_symptoms;
            this->m_symptoms = nullptr;
         }
         Patient::read(istr);      //reads record from base class

         p_symptoms = getcstr("Symptoms: ", istr, '\n');  //reads dynamically allocated Cstring up to '\n'
         if (p_symptoms != nullptr) {  //if dynamically allocated Cstring is not null, allocate and copy
            this->m_symptoms = new char[strlen(p_symptoms) + 1];
            strcpy(this->m_symptoms, p_symptoms);
            delete[] p_symptoms;
         }
         else {                          // else set symptoms pointer to null
            this->m_symptoms = nullptr;
         }        
      }
      return istr;     
   }

   //deletes dynamically allocated Cstring
   TriagePatient::~TriagePatient()
   {
      if (this->m_symptoms != nullptr) {
         delete[] this->m_symptoms;
         this->m_symptoms = nullptr;
      }
   }




}