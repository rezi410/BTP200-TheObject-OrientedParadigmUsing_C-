//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-02-17

// I have done all the coding by myself and only copied the code (about moving funds from one to another)
// that my professor provided to complete my workshops and assignments.


// why use iostream here???


#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>                   

namespace sdds {
   class Account {
      int m_number;              // account number
      double m_balance;          // balance of the account
      void setEmpty();                       // account state: 1) invalid
   public:
      Account();                             // account state: 2) new
      Account(int number, double balance);   // set values if receive valid arguments, otherwise set it empty state
      std::ostream& display()const;         // print account
      operator bool() const;                 // check account is valid or invalid 
      operator int() const;                  // return account number
      operator double() const;               // return account balance
      bool operator~() const;                // return true if account is new, false otherwise
      Account& operator=(const int acc_num);
      Account& operator=(Account& other);
      Account& operator+=(const double add_val);
      Account& operator-=(const double reduce_val);
      Account& operator<<(Account& right); 
      Account& operator>>(Account& other_right);
   };

      double operator + (const Account& first, const Account& second);
      double operator += (double& lo, const Account& ro);
   
   
}
#endif // SDDS_ACCOUNT_H_