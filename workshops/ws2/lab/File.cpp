//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-01-26


#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds 
{
   FILE* fptr;

   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }

   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }

   void closeFile() {
      if (fptr) fclose(fptr);
   }

//  TODO: read functions go here    

   bool read(char* otherName)
   {
       return fscanf(fptr, "%[^\n]\n", otherName) == 1;      
   }


   bool read(int& number)
   {
       return fscanf(fptr, "%d,", &number) == 1;
   }


   bool read(double& salary)
   {
       return fscanf(fptr, "%lf,", &salary) == 1;
   }

}