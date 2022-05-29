//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-03-27

// I have done all the coding by myself and only copied the code (logic)
// that my professor provided to complete my workshops and assignments.


#ifndef SDDS_CSTRING_H
#define SDDS_CSTRING_H


namespace sdds
{
	// Copies the srouce character string into the destination
	void strCpy(char* des, const char* src);

	// Compares two C-strings 
	// returns 0 i thare the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strCmp(const char* s1, const char* s2);

	// returns the lenght of the C-string in characters
	int strLen(const char* s);


}
#endif // !SDDS_CSTRING_H