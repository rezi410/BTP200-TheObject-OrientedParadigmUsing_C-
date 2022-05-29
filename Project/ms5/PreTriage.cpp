/* Citation and Sources...
Final Project Milestone 4
Module: Time, utils, Patient, Ticket, IOAble, CovidPatient
Filename: Time.h, Time.cpp, utils.h, utils.cpp, Patient.h, Patient.cpp, Ticket.h, Ticket.cpp
IOAble.h, IOAble.cpp, CovidPatient.h, CovidPatient.cpp, TriagePatient.h, TriagePatient.cpp
Version 1.0
Author	Reziyemu Sulaiman
Revision History
-----------------------------------------------------------
Student Name:
Date      Reason
2020/3/26  Preliminary release
2020/5/15  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor and classmate provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------
-----------------------------------------------------------*/




#include <iostream>
#include <fstream>
#include <cstring>
#include "PreTriage.h"
#include "TriagePatient.h"
#include "CovidPatient.h"
#include "utils.h"



using namespace std;

namespace sdds 
{
	// this constructor will initilize the following objects:
	PreTriage::PreTriage(const char* dataFilename) :
		m_averCovidWait(15),  //call one argument constructor from Time class
		m_averTriageWait(5),	 //call one argument constructor from Time class
		m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),  //call two argument constuctor from Menu class
		m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)  // call two argument constructor from Menu class
		
	{
		this->m_dataFilename = new char[strlen(dataFilename) + 1];  // initilize dynamically allocated string m_dataFilename
		strcpy(this->m_dataFilename, dataFilename);
		load();          //import the Patient records from the data file
	}


	// the destructor will do the following:
	PreTriage::~PreTriage()
	{ 
		ofstream fout(m_dataFilename);   //connects m_dataFilename to fout for output
		if (fout.is_open()) {      // if file is open, overwrite the content of the file if exists
			//first line of file: write average covid wait time and average triage wait time, comma sepearted
			fout << this->m_averCovidWait << ',' << this->m_averTriageWait << endl;
			// then, on the screen write as follows:
			cout << "Saving Average Wait Times," << '\n';
			cout << "   COVID Test: " << this->m_averCovidWait << '\n';    
			cout << "   Triage: " << this->m_averTriageWait << '\n';
			cout << "Saving m_lineup..." << endl;
		}

		//all patients are written into file, comma seperated
		//important: set fileIO to true if patient is to be written into or read from a file
		//set fileIO to false if the patient object is to be written into or read from the console
		for (int i = 0; i < m_lineupSize; i++) {  
			m_lineup[i]->fileIO(true);   //patients are written into file
			cout << i + 1 << "- " << *m_lineup[i] << endl;  
			fout << *m_lineup[i] << endl;
		}
		//all the patients pointed by the elements of the m_lineup array are deleted
		for (int i = 0; i < m_lineupSize; i++) 
		{
			if (m_lineup[i]!=nullptr){
			delete m_lineup[i];
			m_lineup[i] = nullptr;
			}
		}
		//data file name is deleted
		delete[] m_dataFilename;

		//the confirmation message is printed
		cout << "done!" << endl;
	}

	

	//get the total estimated wait time for the patient (COVID or TRIAGE)
	const Time PreTriage::getWaitTime(const Patient& p) const
	{
		int value = 0;
		//find number of patients matching the type of the patient reference in the lineup
		for (int i = 0; i < m_lineupSize; i++) {   
			if (m_lineup[i]->type() == p.type())    //find a match between patients in m-lineup array and patient reference
				value++;   //count the matching patients
		}
		return Time(p) *= value;     // call *= opeator from class Time to get estimated wait time by number of patients
	  
	}



	//adjusts average wait time of that type of patient base on the admittance time of the patient
	void PreTriage::setAverageWaitTime(const Patient& p)
	{ 
		int time = Time(p);

		if (p == 'C')
			m_averCovidWait = ((getTime() - time) + (int(m_averCovidWait) * (p.number() - 1))) / p.number();
		else
			m_averTriageWait = ((getTime() - time) + (int(m_averTriageWait) * (p.number() - 1))) / p.number();
	}

	
	// removes a patient from the lineup at a specific index and also removes it from memory
	void PreTriage::removePatientFromLineup(int index)
	{
		removeDynamicElement<Patient>(m_lineup, index, m_lineupSize); // using template in utils.h
	}


	//find the index of first patient in line which matches type argument
	int PreTriage::indexOfFirstInLine(char type) const
	{
		int match = -1;
		for (int i = 0; i < m_lineupSize && match == -1; i++) {
			// if match is found, return the index of the loop, else return -1
			if (m_lineup[i]->type() == type)    
			{                        
				match = i;
			}
		}
		return match;             
	}


	//loads the average wait times and the patient records from the data file and 
	//stores them in the m_lineup array
	void PreTriage::load()
	{
		cout << "Loading data..." << '\n';  
		ifstream fin;
		fin.open(m_dataFilename);
		if (fin) {           
			fin >> this->m_averCovidWait;    //1. read covid avg wait time & ignore comma
			fin.ignore();                    
			fin >> this->m_averTriageWait;   //2. read triage avg wait time & ignore new line
			fin.ignore();                    

			char ch = '\0';                     // create single char
			Patient* p = nullptr;               // create temporary patient pointer
			                                //3. loop up to the max number of patients or EOF
			for (int i = 0; i < maxNoOfPatients && !fin.eof(); i++) { 				                              
				fin >> ch;        //read first char
				fin.ignore();     //ignore comma
				if (fin.good()) {             //4. instantiate Covid or traige patient as follows:
					if (ch == 'C') {           //if first character is 'C',
						p = new CovidPatient();  //instantiate a covid patient
					}
					else if (ch == 'T') {    //if the character is 'T',
						p = new TriagePatient();  //instantiate a triage patient
					}
					if (p != nullptr) {      //5. if instantiation happend 
						p->fileIO(true);      //set the patient to fileIO
						p->csvRead(fin);      //read the patient from the file
						p->fileIO(false);    //set the patient not to do fileIO
						this->m_lineup[i] = p;  //copy patient pointer to lineup array of pointers
						this->m_lineupSize++;   //increase lineup size
						p = nullptr;
					}
				}
			}
			//if there is still records left in the file, print this message
			if (fin && !fin.eof()) {  
				cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
			}
			if (m_lineupSize > 0) { 
				cout << this->m_lineupSize << " Records imported..." << endl << endl;
				fin.close();         
			}
			else //if no records were read, print this message        
				cout << "No data or bad data file!" << endl << endl;
		}
	}

	
	//registers a new patient
	void PreTriage::reg() {
		if (m_lineupSize >= maxNoOfPatients)  //if lineup size has reached maximum number of patient, print
			cout << "Line up full!" << '\n';		
		else {
			int select;
			m_pMenu >> select;   //display the m_pMenu and receives the selection

			switch (select) {
			case 1:      //if selection is 1, instantiate a Covid patient
				m_lineup[m_lineupSize] = new CovidPatient();
				break;
			case 2:     //if the selection is 2, instantiate a Triage patient
				m_lineup[m_lineupSize] = new TriagePatient();
				break;
			default:     //if selection is 0, terminate the function
				break;
			}

			m_lineup[m_lineupSize]->setArrivalTime();  //set patient's arrival time
			cout << "Please enter patient information: " << '\n';  //print
			m_lineup[m_lineupSize]->fileIO(false);   //set patient not to do fileIO
			m_lineup[m_lineupSize]->read(cin);     //extract the patient from cin
			cout << '\n';    
			cout << "******************************************" << '\n';
			m_lineup[m_lineupSize]->write(cout);   //insert the patient into cout
			cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << '\n'; //print return value of getWaitTime
			cout << "******************************************" << '\n' << endl;
			m_lineupSize++;
		}
	}


	//calls next patient in line to be admitted to the Covid test centre or Triage centre
	//dispkay the m_pMenu and receives the selection to determine the type of the patient to admit
	void PreTriage::admit() {
		int option;
		int i;
		char ch = '\0';

		m_pMenu >> option;   //display m_pMenu and receives the selection
		switch (option) {
		case 1:            //if selection is 1, the type is 'C'
			ch = 'C';
			break;
		case 2:           //if selection is 2, the type is 'T'
			ch = 'T';
			break;
		default:        //if selection is 0, terminate
			break;
		}

		i = indexOfFirstInLine(ch);   //find the index of next patient in the line for the type
		if (i != -1) {   //if no patient is found, terminate function
			cout << '\n';
			cout << "******************************************" << '\n';
			m_lineup[i]->fileIO(false);  //set patient not to do fileIO
			cout << "Calling for ";
			m_lineup[i]->write(cout);     //insert the patient into cout
			cout << "******************************************" << '\n' << endl;
			setAverageWaitTime(*m_lineup[i]);  //set average wait time for the patient
			removePatientFromLineup(i);   //remove patient from lineup
		}
	}


	//display m_appMenu to get the selection and repeat the selection
	void PreTriage::run(void) {
		int choose;

		while (m_appMenu >> choose) //display m_appMenu and get the selection
		{
			switch (choose) {
			case 1:        //if selection is 1, call the reg function
				reg();
				break;
			case 2:       //if selection is 2, call the admit function
				admit();
				break;
			default:     //if selection is zero, quit the function
				break;
			}
		}
	}

	
}




