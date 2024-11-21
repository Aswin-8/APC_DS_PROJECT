#include <stdio.h>
#include <string.h>
#include "arithematic.h"

int main(int argc,char **argv)
{
        int i=0,j=0,flag1=0,flag2=0;
        char num1[25],num2[25],op[2],opt;
        strcpy(num1,argv[1]);                                        //copying argv[1] to num1
        while(num1[i]!='\0')
        {
                if(!(num1[i]>='0' && num1[i]<='9' || num1[0]=='-'))                 //checking if it is a number or not
                {
                        flag1=1;
                        break;
                }
                i++;
        }
        if(flag1 || strlen(argv[1])==0)                          //checking if it is a number or if it is empty
        {
                printf("Error: enter a number\n");
                return FAILURE;
        }
        strcpy(op,argv[2]);                                         //copying argv[2] into op
        if((strcmp(op,"+") && strcmp(op,"-") && strcmp(op,"x") && strcmp(op,"/")))            //checking the operation type
        {
                printf("Enter a valid operation\n");
                return FAILURE;
        }
        strcpy(num2,argv[3]);                                        //copying argv[3] into num2
        while(num2[j]!='\0')
        {
                if(!(num2[j]>='0' && num2[j]<='9' || num2[0]=='-'))          //checking if it is a number or not
                {
                        flag2=1;
                        break;
                }
                j++;
        }
        if(flag2 || strlen(argv[3])==0)                               //checking if it is a number or it is empty
        {
                printf("Error: enter a number\n");
                return FAILURE;
        }
        opt=op[0];                                                     //storing the operator in character variable
        do
        {
                printf("Arithematic operation choosed is: ");
                switch(opt)
                {
                        case '+': printf("Addition\n");
                                  printf("%s + %s = ",argv[1],argv[3]);
                                  addition(argv[1],argv[3]);
                                  break;
                        case '-': printf("Substraction\n");
                                  printf("%s - %s = ",argv[1],argv[3]);                     //switch cases depending on operator
                                  subtraction(argv[1],argv[3]);
                                  break;
                        case 'x': printf("Multiplication\n");
                                  printf("%s x %s = ",argv[1],argv[3]);                     
                                  multiplication(argv[1],argv[3]);
                                  break;
                        case '/': printf("Division\n");
                                  printf("%s / %s = ",argv[1],argv[3]);                     
                                  division(argv[1],argv[3]);
                                  break;
                        default : printf("Invalid option");
                }
    }while(0);     
}