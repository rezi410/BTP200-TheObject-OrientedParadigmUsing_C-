/* Citation and Sources...
Final Project Milestone 1
Module: Time, utils
Filename: Time.h, Time.cpp, utils.h, utils.cpp
Version 1.0
Author	John Doe
Revision History
-----------------------------------------------------------
Name      Reziyemu Sulaiman
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

   //sets the time to the current time by calling getTime() function from utils module
   Time& Time::setToNow()    
   {
      this->m_min = getTime();  
      return *this;   
   }

   //construct time by setting number of minutes held in object
   Time::Time(unsigned int min)  
   {
      this->m_min = min;
   }

   //writes the time into stream in HH:MM format 
   //padding the spaces with zero if the numbers are single digit
   std::ostream& Time::write(std::ostream& ostr) const
   {
      
      unsigned int hour = m_min / 60;
      unsigned int min = m_min % 60;

      if (hour < 10) {
         ostr << '0';
      }
         ostr << hour << ":";

      if (min < 10) {
         ostr << '0'; 
      }
         ostr << min;
      return ostr;
      
   }


   //reads the time from stream in H:M format make sure that hours and minutes are greater than zero
   //and seperated by ":"
   std::istream& Time::read(std::istream& istr)
   {
      char colon;
      int hours;
      int minutes;

      istr >> hours >> colon >> minutes;   //reads the time as H:M format
      if ((hours < 0) || (colon != ':') || (minutes < 0)) { //if hours & minutes are negative & not sepeated by ":"
         istr.setstate(ios::failbit);
      }
      else this->m_min = hours * 60 + minutes;   

      return istr;

   }


   //calculate the time difference between current time and incoming argument
   Time& Time::operator-=(const Time& D)
   {
      int total = 24 * 60;    // total=24hours times by 60  minutes
      if (this->m_min > D.m_min)  this->m_min -= D.m_min;  
      else  this->m_min = this->m_min + (total * ((D.m_min / total) + 1)) - D.m_min;

      return *this;
   }


   //calculate the time difference between current time and incoming argument that wont modify current object
   Time Time::operator-(const Time& D) const
   {
      int total = 24 * 60;

      Time time;          //create a local object then do calculation
      if (this->m_min > D.m_min)   time.m_min = this->m_min - D.m_min;  
      else time.m_min = this->m_min + (total * ((D.m_min / total) + 1)) - D.m_min;

      return time;       //return local object
   }

   //add minute of coming object to the minute of current object
   Time& Time::operator+=(const Time& D)
   {
      this->m_min += D.m_min;

      return *this;  
   }

   //add minute of coming object to the minute of current object without modifying current object
   Time Time::operator+(const Time& D) const
   {
      return (this->m_min + D.m_min);   // returned the temporary object
      
   }

   //sets the minute of left operand to value of right operand
   Time& Time::operator=(unsigned int val)
   {
      this->m_min = val;
      return *this;
   }

   //multiply minutes of left operand by value of right operand
   Time& Time::operator*=(unsigned int val)
   {
      this->m_min *= val;
      return *this;
   }

   
   //multiply minutes of left operand by value of right operand
   Time Time::operator*(unsigned int val) const
   {
      return (this->m_min * val);    //returned temporary object

   }

   //devide minutes of left opearand by value of right operand without modifying left operand
   Time Time::operator/(unsigned int val) const
   {
      return (this->m_min / val);   //returned temporary object
   }

   //return minutes
   Time::operator unsigned int() const
   {
      return m_min;
   }

   //return minutes as an integer
   Time::operator int() const
   {
      return (int)m_min;
   }


   //devide minutes of left opearand by value of right operand
   Time& Time::operator/=(unsigned int val)
   {
      this->m_min /= val;
      return *this;
   }

   //overload insertion operator
   std::ostream& operator<<(std::ostream& ostr, const Time& D)
   {
      D.write(ostr);
      return ostr;
   }

   //overload extraction operator
   std::istream& operator>>(std::istream& istr, Time& D)
   {
      D.read(istr);
      return istr;
   }

}

