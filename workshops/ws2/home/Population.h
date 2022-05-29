//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-01-27
           
                                           


#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

#define DATAFILE "PCpopulationsComplete.csv"


namespace sdds {

	struct Population {
		char* postal_code;
		int population_no;
	};

    
    void sort();

   
    bool load(Population& pop);

    
    bool load(const char *filename);

    
    void display(const Population& rePop);

    
    void display();

    
    void deallocateMemory();



}
#endif // SDDS_POPULATION_H_