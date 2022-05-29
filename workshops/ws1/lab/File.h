//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-01-17


#ifndef SDDS_FILE_H     // replace with relevant names
#define SDDS_FILE_H
// your header file content goes here
#include "ShoppingRec.h"

namespace sdds
{

	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);

}


#endif

