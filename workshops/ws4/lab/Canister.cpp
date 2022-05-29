//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-02-10

// I have done all the coding by myself and only copied the code (about the logic of filling a canister to another)
// that my professor provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;

const double pi = 3.14159265;

namespace sdds {


    void Canister::setToDefault()
    {
        m_contentName = nullptr;
        m_hieght = 13.0;
        m_diameter = 10.0;
        m_contentVolume = 0.0;
        m_usable = true;
    }


    void Canister::setName(const char* Cstr)
    {
        if ((Cstr != nullptr) && (this->m_usable == true))
        {
            delete[] this->m_contentName;

            int length = strLen(Cstr) + 1;
            this->m_contentName = new char[length];
            strCpy(this->m_contentName, Cstr);     
        }
        
    }


    bool Canister::isEmpty()const
    {
        if (this->m_contentVolume < 0.00001)
        {
            return true;
        }
        else
        {
            return false;
        }
    }


    bool Canister::hasSameContent(const Canister& C)const
    {
        if ((this->m_contentName != nullptr) && (C.m_contentName != nullptr))
        {
            if (strCmp(this->m_contentName, C.m_contentName) == 0)
            {
                return true;
            }
        }
        return false;
    }


    Canister::Canister()
    {
        setToDefault();
    }


    Canister::Canister(const char* contentName)
    {  
        setToDefault();
        setName(contentName);       
    }


    Canister::Canister(double hieght, double diameter, const char* contentName)
    {
        setToDefault();
        if ( (hieght >= 10.0) && (hieght <= 40.0) && (diameter >= 10.0) && (diameter <= 30.0) )
        {
            this->m_hieght = hieght;
            this->m_diameter = diameter;
            this->m_contentVolume = 0.0;
            setName(contentName);
        }
        else 
        {
            this->m_usable = false;
        }
    }


    Canister::~Canister()
    {
        delete[] this->m_contentName;
    }


    Canister& Canister::setContent(const char* contentName)
    {
        if (contentName == nullptr)
        {
            this->m_usable = false;
        }
        else if (this->m_contentVolume == 0.0)
        {
            setName(contentName);
        }
        else if (strCmp(this->m_contentName, contentName) != 0)
        {
            this->m_usable = false;
        }

        return *this;
    }


    Canister& Canister::pour(double quantity)
    {
        if ( (this->m_usable == true)
            && (quantity > 0)
            && quantity + volume() <= capacity())
        {
             this->m_contentVolume += quantity;
        }
        else 
        {
            this->m_usable = false;
        }
            return *this;
    }


    Canister& Canister::pour(Canister& C)
    {
            setContent(C.m_contentName);

        if ( C.volume() > (this->capacity() - this->volume()) )
        {
            C.m_contentVolume -= this->capacity() - this->volume();
            this->m_contentVolume = this->capacity();
        }
        else
        {
            pour(C.m_contentVolume);
            C.m_contentVolume = 0.0;
        }

        if (hasSameContent(C.m_contentName) == false)
        {
            clear();
            this->m_usable = false;
        }


        return *this;      
    }


    double Canister::volume()const
    {
        return this->m_contentVolume;
    }


    std::ostream& Canister::display()const
    {
        cout.setf(ios::fixed);
        cout.precision(1);
        cout.width(7);
        cout << capacity();
        cout << "cc (";
        cout << this->m_hieght;
        cout << "x";
        cout << this->m_diameter;
        cout << ") Canister";

        if (this->m_usable == false)
        {
            cout << " of Unusable content, discard!";
        }
        else if (this->m_contentName != nullptr)
        {
            cout << " of ";
            cout.width(7);
            cout << this->m_contentVolume;
            cout << "cc   ";
            cout << this->m_contentName;
        }

        return cout;

    }


    double Canister::capacity()const
    {
        return pi * (this->m_hieght - 0.267) * (this->m_diameter / 2) * (this->m_diameter / 2);
    }


    void Canister::clear()
    {
        delete[] this->m_contentName;

        this->m_contentName = nullptr;
        this->m_contentVolume = 0.0;
        this->m_usable = true;
    }

   
}