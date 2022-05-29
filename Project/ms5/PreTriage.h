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



#ifndef SDDS_PRETRIAGE_H
#define SDDS_PRETRIAGE_H

#include "Time.h"
#include "Patient.h"
#include "Menu.h"

namespace sdds
{
   const int maxNoOfPatients = 100;   //a constant value to set the max number of patients (Covid&Triage)

   class PreTriage
   {
      Time                   /* Time object to hold average wait time */
         m_averCovidWait,    // for Covid test per patient
         m_averTriageWait;   // for Triage test per patient
     
      // An array of Patient pointers to hold COVID and Triage Patient lineups dynamically
      Patient* m_lineup[maxNoOfPatients]{}; 

      char* m_dataFilename = nullptr;  // A character pointer to hold the name of the data file dynamically
   
      int m_lineupSize = 0;  // Number of Patients in the lineup
   
      Menu 
         m_appMenu,   // Menu object to hold the main menu
         m_pMenu;     // Menu object to hold the COVID/Triage patient selection

      void reg();
      void admit();
      const Time getWaitTime(const Patient& p) const;
      void setAverageWaitTime(const Patient& p);
      void removePatientFromLineup(int index);
      int indexOfFirstInLine(char type) const;
      void load();

   public:
      PreTriage(const char* dataFilename);    
      ~PreTriage();
      void run(void);
   };

}

#endif