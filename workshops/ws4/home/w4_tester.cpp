// Workshop 4:
// Version: 0.9
// Date: 2021/02/04
// Author: Fardad Soleimanloo
// Description:
// This file tests the DIY section of your workshop
/////////////////////////////////////////////
#include <iostream>
#include "Label.h"
//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-02-13

// // I have done all the coding by myself and only copied the code (about the logic of filling a canister to another)
// that my professor provided to complete my workshops and assignments.




#include "LabelMaker.h"
using namespace sdds;
using namespace std;
int main() {
    int noOfLabels;
    // Create a lable for the program title:
    // and couple of empty ones
    Label
        theProgram("/-\\|/-\\|", "The Label Maker Program"),
        EmptyOne1,
        EmptyOne2("ABCDEFGH");
    cout << "EmptyOne1" << endl;
    EmptyOne1.printLabel() << endl;
    cout << "EmptyOne2" << endl;
    EmptyOne2.printLabel() << endl;
    theProgram.printLabel() << endl << endl;
    // ask for number of labels to get created
    cout << "Number of labels to create: ";
    cin >> noOfLabels;
    cin.ignore(10000, '\n');
    // Create a LabelMaker for the number of 
    // the labels requested
    LabelMaker lblMkr(noOfLabels);
    // Ask for the label texts
    lblMkr.readLabels();
    // Print the labels
    lblMkr.printLabels();
    return 0;
}