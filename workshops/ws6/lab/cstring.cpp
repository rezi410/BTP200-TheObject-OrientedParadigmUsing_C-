//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NCC
// Workshop:       Workshop6_LAB
//==============================================
// cstring.cpp

#include "cstring.h"
namespace sdds
{
  // strLen: Calculate the length of the C-String in characters
  int strLen(const char *s)
  {
    // Declare Variable to store the length
    int length = 0;

    // Set the "while" loop to repeat until the corresponding index has a value
    while (s[length])
    {
      length++;
    }

    return length;
  }

  // strCpy: Cpies the srouce character string into the destination
  void strCpy(char *des, const char *src)
  {
    int i = 0;

    // Set the "while" loop to repeat until 'src' has a value the corresponding index
    while (src[i])
    {
      // Copy the String from 'src' to 'des'
      des[i] = src[i];
      i++;
    }

    // Set the last index to be NULL value
    des[i] = '\0';
  }

  // strCat: Concantinates "src" C-string to the end of "des"
  void strCat(char *des, const char *src)
  {
    int des_len = strLen(des);
    int counter = 0;

    // Infinitie "while" loop until 'src' has value
    while (src[counter])
    {
      // copy the characters from the last index of 'des'
      des[des_len] = src[counter];
      des_len++;
      counter++;
    }

    // Set the last index to be NULL value
    des[des_len] = '\0';
  }
}