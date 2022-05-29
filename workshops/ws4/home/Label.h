//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-02-13

// // I have done all the coding by myself and only copied the code (about the logic of filling a canister to another)
// that my professor provided to complete my workshops and assignments.




#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>


namespace sdds {
    class Label {
        char frame[8];                // frame is created by 8 chars
        char* contentOflabel;       // dynamically allocated cstring, max 70 chars
        void setToDefault();           // set default values
        void setName(const char* con_name);      // set dynamic content name for label
        bool isValid(const char* check);       // check if the string in a valid range
    public:
        Label();                       
        Label(const char* frameArg);
        Label(const char* frameArg, const char* content);
        ~Label();
        void readLabel();
        std::ostream& printLabel()const;
    };

}

#endif 