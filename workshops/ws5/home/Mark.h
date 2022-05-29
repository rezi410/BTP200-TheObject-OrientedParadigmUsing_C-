//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-02-17

// I have done all the coding by myself and only copied the code (about if else statement in operator double)
// that my professor provided to complete my workshops and assignments.




#ifndef SDDS_MARK_H
#define SDDS_MARK_H
#include <iostream>

namespace sdds {
	class Mark   {
            int m_mark;  
            void setEmpty();                         // invalid empty state

        public:
            Mark();                                 // if mark not provided
            Mark(int mark);                         // sets the value of the mark
            operator int();                        // return mark
            Mark& operator+=(const int add_val);   // add mark
            operator double();    
            Mark& operator=(const int mark_num);
            operator char();
           friend int operator += (int& value, const Mark& other);

         
	};


}

#endif // SDDS_MARK_H
