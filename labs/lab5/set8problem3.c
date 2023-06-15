#include <stdio.h>

#define STUDENTNUM 5
#define NAMELIMIT 25

struct Student{
    int studentId;
    int score;
    char name[NAMELIMIT];
};

int main() {
   struct Student students[STUDENTNUM];
   
   return 0;
}
