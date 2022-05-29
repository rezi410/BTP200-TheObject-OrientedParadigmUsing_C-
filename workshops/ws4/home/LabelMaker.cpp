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
#include "LabelMaker.h"
using namespace std;


namespace sdds {

    LabelMaker::LabelMaker(int noOfLabels)
    {
        if (noOfLabels != 0)
        {
            size = noOfLabels;
            m_label = new Label[size];
        }
        else
        {
            size = 0;
            m_label = nullptr;
        }
    }
    

    LabelMaker::~LabelMaker()
    {     
          delete[] this->m_label;     
    }


    void LabelMaker::readLabels()
    {
        cout << "Enter " << this->size << " labels:" << '\n';
        for (int i = 0; i < this->size; i++)
        {
            cout << "Enter label number " << i+1 << '\n';
            cout << ">" << " ";
            m_label[i].readLabel();
        }

    }

    void LabelMaker::printLabels()
    {
        for (int i = 0; i < this->size; i++)
        {
            m_label[i].printLabel() << endl;
        }

    }


}