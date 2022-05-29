//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-02-13

// // I have done all the coding by myself and only copied the code (about the logic of filling a canister to another)
// that my professor provided to complete my workshops and assignments.





#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include <iostream>

namespace sdds {
	class LabelMaker {
		Label* m_label;
		int size;
	public:
		LabelMaker(int noOfLabels);

		~LabelMaker();

		void readLabels();

		void printLabels();

	};
   
}

#endif 