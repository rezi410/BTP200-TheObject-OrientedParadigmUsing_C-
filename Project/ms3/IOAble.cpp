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



#include "IOAble.h"

namespace sdds {


   std::ostream& operator<<(std::ostream& out, const IOAble& io)
   {    
      io.write(out);
      return out;
   }

   std::istream& operator>>(std::istream& in, IOAble& io)
   {
      io.read(in);
      return in;
   }


}
