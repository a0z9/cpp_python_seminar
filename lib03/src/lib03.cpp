#include "lib03.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstring>


using namespace std;

/**
 * C++ function return string
 */
string time_s(mm pr){

	 auto t = time(nullptr);
	 auto tm = *localtime(&t);

	 const auto now = chrono::system_clock::now();

	 stringstream ss;
     ss << put_time(&tm, "%Y_%m_%d__%H_%M_%S");


     if(pr == mm::micro){
    	  auto mks = chrono::duration_cast<chrono::microseconds>(now.time_since_epoch()) % 1000000;
    	  ss << "__"<< mks.count();
     }
     else if(pr == mm::millis){
    	  auto mks = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()) % 1000;
    	  ss << "__"<< mks.count();
     }
     else if(pr == mm::nano){
       	  auto mks = chrono::duration_cast<chrono::nanoseconds>(now.time_since_epoch()) % 1000000000;
       	  ss << "__"<< mks.count();
     }

     return ss.str();
}



extern "C" {

book* gen_book(char* a, char* t, int year)
{
  book* bk = new book {a, t, year};
  cout << "++ Book created on address: " <<  bk << endl;

  return bk;
}


void free_book(book* bk)
{   cout << "-- Book deleted from address: " <<  bk << endl;
	delete bk;	}


void swap(int * a,  int * b){
	int c = *a; *a = *b; *b = c;
}

// wrapper function for time_s(mm)
char* time_str(mm pr){
	 string s =  time_s(pr);
	 char * char_array = new char[s.length() + 1];
	 strcpy(char_array, s.c_str());
	 cout << "++ time_string created on address:" <<  (void*)char_array << endl;
     return char_array;

//   python import not works with 'const char*'
//   return  time_s(pr).c_str();
}

// function for string deletion
void rm_time_str(char* st){
	cout << "-- time_string deleted from address:" <<  (void*)st << endl;
	delete st;}


double sum(double* arr, int N)
{
   double s = 0;
   for(int i=0; i<N; i++) s += *(arr+i);
   return s;
}


}



