//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-01-27

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_


namespace sdds {

   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();


   bool read(char* name);

   bool read(int& number);


}
#endif // !SDDS_FILE_H_
