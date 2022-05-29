//   Student Name:       Reziyemu Sulaiman
//   Seneca Student ID:  106-153-208
//   Seneca email:       rsulaiman2@myseneca.ca
//   Date of completion: 2021-02-05



#ifndef SDDS_FOOD_H
#define SDDS_FOOD_H

namespace sdds   
{
	class Food {
		char foodName[31];
		int  calorieNum;
      char time_consum[15];
      void setName(const char* name);
      void setTime(const int time);
    public:
        void setEmpty();
        void set(const char* name, int calorie, int time);
        void display()const;
        bool isValid()const;
        int cals()const;
        };

}
#endif // !SDDS_FOOD_H