////////////////////////////////////////////////////////////////
// Get the longest length of its all symmetrical substrings
// Time needed is O(T^2)
////////////////////////////////////////////////////////////////

#include<stdio.h>
#include <stdlib.h>

int GetLongestSymmetricalLength_2(char* pString);

void main(){
     int length;
     printf("Please input the length of string:\n");
	 scanf("%d",&length);
	 char *s = (char*)malloc((length+1) * sizeof(char));
	 printf("Please input the string\n");
     scanf("%s",s);
	 int result = GetLongestSymmetricalLength_2(s);
	 printf("The longest length of its all symmetrical substrings = %d",result);
}

int GetLongestSymmetricalLength_2(char* pString)
{
       if(pString == NULL)
              return 0;
       int symmeticalLength = 1;
       char* pChar = pString;
       while(*pChar != '\0')
       { 
              // Substrings with odd length
              char* pFirst = pChar - 1;
              char* pLast = pChar + 1;
              while(pFirst >= pString && *pLast != '\0' && *pFirst == *pLast)
              {
                     pFirst--;
                     pLast++;
              }
 
              int newLength = pLast - pFirst - 1;
              if(newLength > symmeticalLength)
                     symmeticalLength = newLength;
 
              // Substrings with even length
              pFirst = pChar;
              pLast = pChar + 1;
              while(pFirst >= pString && *pLast != '\0' && *pFirst == *pLast)
              {
                     pFirst--;
                     pLast++;
              }
 
              newLength = pLast - pFirst - 1;
              if(newLength > symmeticalLength)
                     symmeticalLength = newLength;
 
              pChar++;
       }
 
       return symmeticalLength;
}