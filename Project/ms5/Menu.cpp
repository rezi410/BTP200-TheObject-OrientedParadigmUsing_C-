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


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "utils.h"
using namespace std;

namespace sdds{
   
   //dynamically allocates memory for m_text
   Menu::Menu(const char* MenuContent, int NoOfSelections)
   {
      m_noOfSel = NoOfSelections;   //assume NOOfSelectios is valid integer

      if (MenuContent != nullptr)    
      {
         m_text = new char[strlen(MenuContent) + 1];   //allocate
         strcpy(m_text, MenuContent);                 // copy
      }
      else {
         this->m_text = nullptr;
      }
   }

   //deallocates dynamically allocated memory
   Menu::~Menu()
   {
      if (this->m_text != nullptr) {
         delete[] this->m_text;
         this->m_text = nullptr;
      }
   }

   //copy constructor
   Menu::Menu(const Menu& menu)
   {
      *this = menu;
   }


   //copy assignment operator
   Menu& Menu::operator=(const Menu& menu)
   {
      if (this != &menu) {     // 1.check for self assignment

         m_noOfSel = menu.m_noOfSel;   // 2. shallow copy non-resource variables

         if (this->m_text != nullptr) {
            delete[] this->m_text;    //3.delete periously allocated memory
            this->m_text = nullptr;
         }

         if (menu.m_text != nullptr)    //4.allocate new memory and make copy
         {
            m_text = new char[strlen(menu.m_text) + 1];
            strcpy(m_text, menu.m_text);
         }
         else {
            this->m_text = nullptr;
         }
      }

      return *this;        // 5. return current object
   }


   //displays menu content
   void Menu::display() const
   {
      cout << this->m_text << '\n';
      cout << "0- Exit" << endl;
   }

   //recieves user selection
   int& Menu::operator>>(int& Selection)
   {
      display();

      Selection = getInt(0, m_noOfSel, "> ", "Invalid option ", true);   //call getInt to get valid integer

      return Selection;
   }


}
