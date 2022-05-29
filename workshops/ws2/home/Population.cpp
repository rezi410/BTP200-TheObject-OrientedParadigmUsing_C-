//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-01-27


#include <iostream>
#include "cstring.h"  
#include "Population.h"
#include "File.h"


using namespace std;
namespace sdds {

    int no;
    Population* residents;


    void sort() {
        int i, j;
        Population temp;
        for (i = no - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (residents[j].population_no > residents[j + 1].population_no) {
                    temp = residents[j];
                    residents[j] = residents[j + 1];
                    residents[j + 1] = temp;
                }
            }
        }
    }

    bool load(Population& pop)
    {
        bool ok = false;
        char post_code[100];
        int pop_no;

        if ( (read(post_code) && read(pop_no) ) == true )
        {

            int length = strLen(post_code) + 1;

            pop.postal_code = new char[length];

            strCpy(pop.postal_code, post_code);

            pop.population_no = pop_no;

            ok = true;
        }

        return ok;
    }

    bool load(const char *filename)
    {
        bool ok = false;
        int i = 0;
        if (openFile("PCpopulationsComplete.csv"))
        {
            no = noOfRecords();

            residents = new Population[no];

            for (i = 0; i < no; i++)
            {
                if (load(residents[i]) == true)
                {
                    ok = true;
                }
            }

            if (i == no)
            {
                ok = true;
            }
            else
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted";
                ok = false;
            }

            return ok;
        }

        else {
            cout << "Could not open data file: " << "PCpopulationsComplete.csv" << endl;
        }
        return ok;
    }

    void display(const Population& rePop)
    {
        cout << rePop.postal_code << ":  " << rePop.population_no;
    }


    void display()
    {
        int sum = 0;
        cout << "Postal Code: population" << "\n";
        cout << "-------------------------" << "\n";
        sort();

        for (int i = 0; i < no; i++)
        {
            cout << i + 1 << "- " << residents[i].postal_code << ":  " << residents[i].population_no << endl;
            sum += residents[i].population_no;
        }

        cout << "-------------------------" << "\n";
        cout << "Population of Canada: " << sum << endl;

    }

    void deallocateMemory()
    {
        for (int i = 0; i < residents[i].population_no; i++)
        {
            delete[] residents[i].postal_code;
        }

        delete[] residents;
    }



}