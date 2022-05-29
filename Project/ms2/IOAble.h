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


#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H

#include <iostream>

namespace sdds {
   class IOAble          // abstract base class
   {
   public:
      virtual std::ostream& csvWrite(std::ostream&)const = 0;
      virtual std::istream& csvRead(std::istream&) = 0;
      virtual std::ostream& write(std::ostream&)const = 0;
      virtual std::istream& read(std::istream&) = 0;
      virtual ~IOAble() {};

   };
   std::ostream& operator<<(std::ostream& out, const IOAble& io);
   std::istream& operator>>(std::istream& in, IOAble& io);



}

#endif
