//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-01-17


#ifndef SDDS_SHOPPINGREC_H     // replace with relevant names
#define SDDS_SHOPPINGREC_H

// your header file content goes here
const int MAX_TITLE_LENGTH = 50;
const int MAX_QUANTITY_VALUE = 50;


namespace sdds
{
	struct ShoppingRec {
		char m_title[MAX_TITLE_LENGTH + 1];
		int m_quantity;
		bool m_bought;
	};

	ShoppingRec getShoppingRec();
	void displayShoppingRec(const ShoppingRec* shp);
	void toggleBoughtFlag(ShoppingRec* rec);
	bool isShoppingRecEmpty(const ShoppingRec* shp);

}





#endif



