//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-02-17

// I have done all the coding by myself and only copied the code (about if else statement in operator double)
// that my professor provided to complete my workshops and assignments.





#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;


namespace sdds   {

    void Mark::setEmpty() {
        m_mark = -1;
        
    }


    Mark::Mark() {
        
         m_mark = 0;
     
    }


    Mark::Mark(int mark) {
        if ( (mark > 0) && (mark <= 100) )
        {
            m_mark = mark;
    
          
        }       
        else
        {
            setEmpty();
        }
    }



    Mark& Mark::operator+=(const int add_val)
    {
        if ( (add_val >=0) && (add_val <= (100-m_mark)) && (m_mark >= 0) && (m_mark<=100) )
        {
            m_mark += add_val;    
            
        }
        else
        {
            setEmpty();

        }

        return *this;
    }




    Mark::operator int() 
    {        
        if ((m_mark >= 0) && (m_mark <= 100))
        {
           return m_mark;
         
           
        }
        else
        {
            return 0;
        }
        
    }


   


    Mark& Mark::operator=(const int mark_num)
    {

        if ((mark_num < 0) || (mark_num > 100))
        {
            setEmpty();
        }
        else
        {
            m_mark = mark_num;
        }

        return *this;
        
    }
    


    Mark::operator double()  
    {     
        double m_grade;

        if ( (m_mark >= 0) && (m_mark < 50.0) )
        {
            m_grade = 0.0;
        }
        else if ( (m_mark >= 50.0) && (m_mark < 60.0) )
        {
            m_grade = 1.0;
        }
        else if ( (m_mark >= 60.0) && (m_mark < 70.0) )
        {
            m_grade = 2.0;
        }
        else if ( (m_mark >= 70.0) && (m_mark < 80.0) )
        {
            m_grade = 3.0;
        }

        else if ((m_mark >= 80.0) && (m_mark <= 100.0))
        {
            m_grade = 4.0;
        }
        else
        {
            m_grade = 0.0;
        }
       
        return m_grade;
    }

    


    Mark::operator char()
    {
        char m_scale;

        if ((m_mark >= 0) && (m_mark < 50))
        {
            m_scale = 'F';
        }
        else if ((m_mark >= 50) && (m_mark < 60))
        {
            m_scale = 'D';
        }
        else if ((m_mark >= 60) && (m_mark < 70))
        {
            m_scale = 'C';
        }
        else if ((m_mark >= 70) && (m_mark < 80))
        {
            m_scale = 'B';
        }
        else if ((m_mark >= 80) && (m_mark <= 100))
        {
            m_scale = 'A';
        }
        else
        {
            m_scale = 'X';
        }

        return m_scale;

    }



    int operator += (int& value, const Mark& other)
    {    
        if ( (other.m_mark>=0) && (other.m_mark<=100) )
        {
            return value += other.m_mark;
        }     
        else
        {
            return value;
        }

    }




    
}