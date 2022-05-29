/* Citation and Sources...
Final Project Milestone 2
Module: Time, utils, Menu, IOAble
Filename: Time.h, Time.cpp, utils.h, utils.cpp, Menu.h, Menu.cpp, IOAble.h, IOAble.cpp, ms2Tester.cpp
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



#ifndef SDDS_MENU_H
#define SDDS_MENU_H


namespace sdds {
   class Menu {
      char* m_text; // holds the menu content dynamically
      int m_noOfSel;  // holds the number of options displayed in menu content
      void display()const;
   public:
      Menu(const char* MenuContent, int NoOfSelections);
      Menu(const Menu& menu);
      Menu& operator=(const Menu& menu);
      virtual ~Menu();
      int& operator>>(int& Selection);
      // add safe copying logic
   };


}

#endif