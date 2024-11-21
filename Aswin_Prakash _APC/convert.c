#include "arithematic.h"

int convert(char *num)
{ 
    int lenght=strlen(num),i,n=0;                //finding the number of digits of number
    for(i=0;i<lenght;i++)
    {
         n=n*10+num[i]-'0';                     //updating the number
    }
    return n;                                   //returning the number
}