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
I have done all the coding by myself by reading course notes and watching the lectures.
-----------------------------------------------------------
-----------------------------------------------------------*/




#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
   
   bool debug = false;  // made global in utils.h
   int getTime() {
      int mins = -1;
      if (debug) {
         Time t(0);
         cout << "Enter current time: ";
         do {
            cin.clear();
            cin >> t;   // needs extraction operator overloaded for Time
            if (!cin) {
               cout << "Invlid time, try agian (HH:MM): ";
               cin.clear();
            }
            else {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }

   

   int getInt(const char* prompt)
   {
      //updated implementation:
      int value;
      int valid;

      if (prompt != nullptr) {
         cout << prompt;
      }

      valid = 1;
      while (valid == 1) {
         cin >> value;

         if (cin.fail()) {
            cerr << "Bad integer value, try again: ";
            cin.clear();
            cin.ignore(2000, '\n');
         }
         else if (char(cin.get()) != '\n') {
            cerr << "Enter only an integer, try again: ";
            cin.ignore(2000, '\n');
         }
         else {
            valid = 0;
         }

      }
      return value;

   }

   /*
   * perious implementation:
      string input;
      bool valid = false;
      int i = 0;

      if (prompt != nullptr) {
         cout << prompt;
      }

      
      while (!valid) {
         getline(cin, input);
         if (!isdigit(input[0])) {
            cout << "Bad integer value, try again: ";
            cin.clear();
            cin.ignore(2000, '\n');
         }
         else {
            valid = true;
         }

         for (i = 1; i < input.length(); i++)
         {
            if (!isdigit(input[i]))
            {
               cout << "Enter only an integer, try again: ";
               break;
            }
         }

      }

      return(stoi(input));
   
   */



   
   int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
   {
      //updated implementation
      int value;
      int valid;

      if (prompt != nullptr) {
         cout << prompt;
      }

      valid = 1;
      while (valid == 1) {
         cin >> value;

         if (cin.fail()) {
            cerr << "Bad integer value, try again: ";
            cin.clear();
            cin.ignore(2000, '\n');
         }
         else if (char(cin.get()) != '\n') {
            cerr << "Enter only an integer, try again: ";
         }
         else if (value >= min && value <= max) {
            valid = 0;
         }
         else {
            if (errorMessage != nullptr) {
               cerr << errorMessage;
            }
            if (showRangeAtError) {
               cerr << "[" << min << " <= value <= " << max << "]: ";
            }
         }
         
      }

      return value;

   }

      /*perious implementation:
      string input;
      bool valid = false;
      int i = 0;
      int number = stoi(input);

      if (prompt != nullptr) {
         cout << prompt;
      }


      while (!valid) 
      {
         getline(cin, input);
         if (!isdigit(input[0])) {
            cout << "Bad integer value, try again: ";
            cin.clear();
            cin.ignore(2000, '\n');
         }


         for (i = 1; i < input.length(); i++)
         {
            if (!isdigit(input[i]))
            {
               cout << "Enter only an integer, try again: ";
               break;
            }
         }

         if (number >= min && number <= max) {
            valid = true;
         }
         else
         {
            if (errorMessage != nullptr) {
               cout << errorMessage;
            }
            if (showRangeAtError) {
               cout << "[" << min << " <= value <= " << max << "]: ";
            }
         }

         return number;

      }
      */
   

   char* getcstr(const char* prompt, std::istream& istr, char delimiter)
   {   

      string str;
      char* m_char = nullptr;

      if (prompt != nullptr) {
         cout << prompt;
      }

      if (getline(istr, str, delimiter)) {
         m_char = new char[str.length() + 1];
         strcpy(m_char, str.c_str());
      }
      else {
         istr.clear();
         istr.ignore(2000, '\n');
      }
      

      return m_char;   

   }


}





