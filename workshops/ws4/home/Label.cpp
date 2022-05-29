//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-02-13

// // I have done all the coding by myself and only copied the code (about the logic of filling a canister to another)
// that my professor provided to complete my workshops and assignments.





#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"  
#include "Label.h"
using namespace std;


namespace sdds {

    void Label::setToDefault()
    {
        this->contentOflabel = nullptr;
        strnCpy(this->frame, "+-+|+-+|", 8);
  //      frame[8] = '\0';
    }


    void Label::setName(const char* string)
    {
        if (isValid(string) == true)
        {
            delete[] this->contentOflabel;

            int length = strLen(string) + 1;
            this->contentOflabel = new char[length];
            strnCpy(this->contentOflabel, string, length);
            this->contentOflabel[length-1] = '\0';
        }
        else
        {
            setToDefault();
        }
    }



    bool Label::isValid(const char* check)
    {
        if ( (check != nullptr) && ( strLen(check) <= 70 ) )
        {
            return true;
        }

        return false;

    }



    Label::Label()
    {
        setToDefault();
    }



    Label::Label(const char* frameArg)
    {
        setToDefault();
        strnCpy(this->frame, frameArg, 8);
    }



    Label::Label(const char* frameArg, const char* content)
    {
        setToDefault();
        strnCpy(this->frame, frameArg, 8);
        setName(content);
    }


    Label::~Label()
    {
        delete[] this->contentOflabel;
    }


    void Label::readLabel()
    {
        char read[71];
        cin.getline(read, 71, '\n');
        setName(read);
  
    }


    std::ostream& Label::printLabel()const
    {     
        int height;              // height of frame
        int width;              // width of frame

        if ( (this->contentOflabel != nullptr))
        {
            int length = strLen(this->contentOflabel) + 3;


            for (height = 0; height < 5; height++)
            {
                for (width = 0; width < length; width++)
                {
                    if ( ( (height == 0)  || (height==4) ) &&  (width != 0)  )  
                    {
                        cout << this->frame[1];
                    }
                    if ( ( (height == 1) || (height == 2) || (height == 3) ) && ( (width == 0) ))
                    {
                        cout << this->frame[3];
                    } 
                    if (((height == 0) && (width == 0)) || ((height == 4) && (width == length - 1)))
                    {
                        cout << this->frame[0];
                    }
                    if (((height == 0) && (width == length - 1)) || ((height == 4) && (width == 0)))
                    {
                        cout << this->frame[2];
                    }
                    if ( ( (height == 1) || (height == 3)) && (width==length-1) )
                    {
                        cout.width(length);
                        cout << this->frame[3];
                    }

                }

                if (height == 2)
                {
                    cout << ' ' << this->contentOflabel << ' ' << this->frame[3];
                }

                if (height != 4)
                {
                    cout << '\n';
                }
            }

        }

            return cout;

    }


}