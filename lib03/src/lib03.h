#include <ctype.h>
#include <string>
#include <crtdefs.h>

typedef struct
{
 char* author;
 char* title;
 int year;
 //......

 } book;

enum class mm {sec, millis, micro, nano};

std::string time_s(mm);

// for export to python
extern "C" {

 void free_book(book* );
 book * gen_book(char*, char*, int);
 void swap(int*, int*);

 // wrapper function for time_s(mm)
 char* time_str(mm);
 // function for string deletion
 void rm_time_str(char*);

 double sum(double* arr, int N);
}
