#include "Baseball.h"

ComNumber::ComNumber()
{
      iNumberArray = iCreateNumber();
}

int* ComNumber::iCreateNumber()
{
      int iNum =0;
      int* iArray= new int[MAX_LENGTH];
      int   iDone = 0;

      do{
            iDone = 0;
            iNum = rand() %900 +100;

            for ( int i = 0; i < MAX_LENGTH; i++)
            {
                  iArray[i] = iNum %10;
                  iNum = iNum / 10;
            }

            for (int i  =  0 ; i <MAX_LENGTH ; i++)
                        if (iArray[i] == iArray[ (MAX_LENGTH+i-1)%MAX_LENGTH] ||
                              iArray[i] == iArray[ (MAX_LENGTH+i-2)%MAX_LENGTH]  )
                        {
                              iDone =1;
                              break;
                        }

      } while(iDone != 0);

      return iArray;
}

int ComNumber::iBallCount(int iUserInput)
{
      int* iUserInputArray = SplitNumber(iUserInput);

      int iBallCnt = 0;
      for (int i  = 0 ; i <MAX_LENGTH; i++ )
            if(iUserInputArray[i] ==  iNumberArray[( i + MAX_LENGTH-1)%MAX_LENGTH] ||
            iUserInputArray[i] ==  iNumberArray[(i + MAX_LENGTH-2)%MAX_LENGTH] )
                  iBallCnt ++;
      return iBallCnt;      
}

int* ComNumber::SplitNumber(int iNumber)
{   
      int* iUserInputArray = new int[MAX_LENGTH] ;

      for (int i  = 0 ; i <MAX_LENGTH; i++ )
      {
            iUserInputArray[i] = iNumber %10;
            iNumber /=10;
      }
      return iUserInputArray;

}

int ComNumber::iStrikeCount(int iUserInput)
{
      int* iUserInputArray= SplitNumber(iUserInput);

      int iStrikeCnt = 0;
      for (int i  = 0 ; i <MAX_LENGTH; i++ )
            if(iUserInputArray[i] ==  iNumberArray[i] )
                  iStrikeCnt ++;
      return iStrikeCnt;            
}

void ComNumber::Reset()
{
      iNumberArray = iCreateNumber();
}

int ComNumber::iGetNumber()
{
      return iNumberArray[0]+iNumberArray[1]*10+iNumberArray[2]*100;
}
