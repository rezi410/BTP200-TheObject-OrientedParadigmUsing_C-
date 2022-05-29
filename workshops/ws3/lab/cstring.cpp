//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-02-03

// I have done all the coding by myself and only copied the code that my professor 
// provided to complete my workshopsand assignments. 
// (Because I was experiencing headaches, my professor helped me to debug and complete my workshop.)


#include "cstring.h"
namespace sdds {

	void strnCpy(char* des, const char* src, int len)
	{
		int i;
		for (i = 0; i < len; i++)
		{
			des[i] = src[i];
		}
		des[i] = '\0';
	}

	int strLen(const char* s)
	{
		int i = 0;
		while (s[i] != '\0')
			i = i + 1;

		return i;
	}

}

