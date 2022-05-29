//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-01-27



#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"


namespace sdds
{

	// returns the lenght of the C-string in characters
	int strLen(const char* s)
	{
		int i = 0;
		while (s[i] != '\0')
			i=i+1;

		return i;
	}

	// Copies the srouce character string into the destination
	void strCpy(char* des, const char* src)
	{
		
			for (int i = 0; i < strLen(src)+1; i++)
			{
				des[i] = src[i];
		    }
	}

//	{
//
//		while (*src) {
//			*des = *src;
//			src++;
//			des++;
//		}
//		*des = '\0';
//	}





	// Copies the source character string into the destination upto "len"
	// characters. The destination will be null terminated only if the number
	// of the characters copied is less than "len"
	void strnCpy(char* des, const char* src, int len)
	{	
		  for (int i = 0; i < len; i++)
		  {
				des[i] = src[i];
		  }
	}




	// Compares two C-strings 
	// returns 0 i thare they are same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strCmp(const char* s1, const char* s2)
	{
		for (int i = 0; i < strLen(s1); i++)
		{
			if (s1[i] != s2[i])
			{
				if (s1[i] > s2[i])
				{
					return 1;
				}
				if (s1[i] < s2[i])
				{
					return -1;
				}
			}
		}
		return 0;
	}


	// returns 0 if they are the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strnCmp(const char* s1, const char* s2, int len)
	{
		for (int i = 0; i < len; i++)
		{
			if (s1[i] != s2[i])
			{
				if (s1[i] > s2[i])
				{
					return 1;
				}
				if (s1[i] < s2[i])
				{
					return -1;
				}
			}
		}
		return 0;
	}

	// returns the address of first occurance of "str2" in "str1"
	// returns nullptr if no match is found
	const char* strStr(const char* str1, const char* str2)
	{
		
		auto len = strLen(str2);
		for (int i = 0; i < strLen(str1); i++)         
		{
			
			if (strnCmp(&str1[i], str2, len) == 0)      
			{                                           
				return &str1[i];                         
			}                                          
                   
		}                                  
		return nullptr; 

	}

	   // Concantinates "src" C-string to the end of "des"
	void strCat(char* des, const char* src)
	{
		while (*des != '\0')
		{
			des++;
		}
		while (*src != '\0')
		{
			*des = *src;
			des++;
			src++;
		}
		*des = '\0';
	}
}
	












