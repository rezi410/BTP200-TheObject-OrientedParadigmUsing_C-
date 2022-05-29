//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-01-26


#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"

using namespace std;
namespace sdds {

    int noOfEmployees;
    Employee* employees;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
       /* if reading of employee number, salay and name are successful
               allocate memory to the size of the name + 1
               and keep its address in the name of the Employee Reference

               copy the name into the newly allocated memroy

               make sure the "ok" flag is set to true
          end if
       */
    bool load(Employee& emp)
    {
        bool ok = false;
        char name[128];
        int empNo;
        double empsalary;

        if ((read(empNo) && read(empsalary)) && (read(name)) == true)
        {

            int length = strLen(name) + 1;

            emp.m_name = new char[length];

            strCpy(emp.m_name, name);

            emp.m_empNo = empNo;

            emp.m_salary = empsalary;

            ok = true;
        }

        return ok;
    }


    // TODO: Finish the implementation of the 0 arg load function 
            /*
             Set the noOfEmployees to the number of recoreds in the file.
             dyanamically allocated an array of employees into the global
             Employee pointer; "employees" to the size of the noOfEmployees.

             In a loop load the employee records from the file into
             the dynamic array.

             If the number of the records does not match the number of reads
                print the message
               "Error: incorrect number of records read; the data is possibly corrupted"
             Otherwise
                set the ok flag to true
             End if

             close the file
             */

    bool load()
    {
        bool ok = false;
        int i = 0;
        if (openFile(DATAFILE))
        {
            noOfEmployees = noOfRecords();

            employees = new Employee[noOfEmployees];

            for (i = 0; i < noOfEmployees; i++)
            {
                if (load(employees[i]) == true)
                {
                    ok = true;
                } 
            }

            if (i == noOfEmployees)
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
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }

    // TODO: Implementation for the display functions go here
    void display(const Employee& reEmp)
    {
        cout << reEmp.m_empNo << ": " << reEmp.m_name << " " << reEmp.m_salary;
    }


    void display()
    {
        cout << "Employee Salary report, sorted by employee number" << "\n";
        cout << "no- Empno, Name, Salary" << "\n";
        cout << "------------------------------------------------" << "\n";
        sort();

        for (int i = 0; i < noOfEmployees; i++)
        {
            cout << i + 1 << "- " << employees[i].m_empNo << ": " << employees[i].m_name << ", " << employees[i].m_salary << endl;
        }

    }

    // TODO: Implementation for the deallocateMemory function goes here
    void deallocateMemory()
    {
        for (int i = 0; i < noOfEmployees; i++)
        {
            delete[] employees[i].m_name;
        }

        delete[] employees;

    }

}