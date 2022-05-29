/* Citation and Sources...
Final Project Milestone 1
Module: Time, utils
Filename: Time.h, Time.cpp, utils.h, utils.cpp
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


#include <string>
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {

   Time& Time::setToNow()
   {
      this->m_min = getTime();
      return *this;   
   }

   Time::Time(unsigned int min)
   {
      this->m_min = min;
   }

   std::ostream& Time::write(std::ostream& ostr) const
   {
      unsigned int hour = m_min / 60;
      unsigned int min = m_min % 60;

      if (hour < 10) {
         ostr << "0";
      }
         ostr << hour << ":";

      if (min < 10) {
         ostr << "0";
      }
         ostr << min;
      return ostr;

   }

   std::istream& Time::read(std::istream& istr)
   {
      string m_str;
      int hour;
      int min;

      istr >> m_str;
      for (int i = 0; m_str[i]!='\0'; i++) 
      {
         if (!isdigit(m_str[i]) && m_str[i] != ':') {
            istr.setstate(ios::failbit);
            return istr;
         }
      }
      hour = stoi(m_str.substr(0, m_str.find(':')));
      if (hour < 0) {
         istr.setstate(ios::failbit);
      }
      min = stoi(m_str.substr(m_str.find(':')+1 ));
      if (min < 0) {
         istr.setstate(ios::failbit);
      }
      this->m_min = hour * 60 + min;

      return istr;
   }

   Time& Time::operator-=(const Time& D)
   {
      int total = 24 * 60;
      int min1 = (int)(*this);
      int min2 = (int)(D);
      int value = ( ( (min1 - min2) % total) + total) % total;
      this->m_min = value;
      
      return *this;
   }

   Time Time::operator-(const Time& D) const
   {
      int total = 24 * 60;

      Time result;
      int min1 = (int)(*this);
      int min2 = (int)(D);
      int value = (((min1 - min2) % total) + total) % total;
      result.m_min = value;

      return result;
   }

   Time& Time::operator+=(const Time& D)
   {
      this->m_min += D.m_min;

      return *this;  
   }

   Time Time::operator+(const Time& D) const
   {
      return (this->m_min + D.m_min);
      
   }

   Time& Time::operator=(unsigned int val)
   {
      this->m_min = val;
      return *this;
   }

   Time& Time::operator*=(unsigned int val)
   {
      m_min *= val;
      return *this;
   }

   

   Time Time::operator*(unsigned int val) const
   {
      return (this->m_min * val);

   }

   Time Time::operator/(unsigned int val) const
   {
      return (this->m_min / val);
   }

   Time::operator unsigned int() const
   {
      return m_min;
   }

   Time::operator int() const
   {
      return (int)m_min;
   }

   Time& Time::operator/=(unsigned int val)
   {
      this->m_min /= val;
      return *this;
   }


   std::ostream& operator<<(std::ostream& ostr, const Time& D)
   {
      D.write(ostr);
      return ostr;
   }

   std::istream& operator>>(std::istream& istr, Time& D)
   {
      D.read(istr);
      return istr;
   }

}

