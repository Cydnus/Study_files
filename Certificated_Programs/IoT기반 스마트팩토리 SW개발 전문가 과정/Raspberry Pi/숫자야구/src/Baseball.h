#include <iostream>
#include <wiringPi.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH            3

using namespace std;

class ComNumber
{
      private :
            int* iNumberArray;
      public :
            int* iCreateNumber();
            ComNumber();
            int iBallCount(int iUserInput);
            int iStrikeCount(int iUserInput);
            int iGetNumber();
            int* SplitNumber(int iNumber);
            void Reset();

};
