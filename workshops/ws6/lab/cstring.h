
// cstring.h

#ifndef SDDS_CSTRING_H_
#define SDDS_CSTRING_H_
namespace sdds
{
   int strLen(const char* s);
   void strCpy(char* des, const char* src);
   void strCat(char* des, const char* src);
}
#endif // !SDDS_CSTRING_H_
