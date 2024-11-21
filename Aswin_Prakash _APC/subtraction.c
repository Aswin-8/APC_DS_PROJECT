#include "arithematic.h"

int subtraction(char *n1,char *n2)
{
    int digit,temp,borrow=0,res,s1=0,s2=0,largest;
    Dlist *head1=NULL;
    Dlist *tail1=NULL;
    Dlist *head2=NULL;
    Dlist *tail2=NULL;
    Dlist *head3=NULL;
    Dlist *tail3=NULL;
    if(n1[0]=='-')              //checking if n1 is negative
    {
        s1=1;
        for(int i=0;i<strlen(n1);i++)
        {
            n1[i]=n1[i+1];                 //shifting every character to left
        }
    }
     if(n2[0]=='-')               //checking if n2 is negative
    {
        s2=1;
        for(int i=0;i<strlen(n2);i++)
        {
            n2[i]=n2[i+1];                       //shifting every character to left
        }
    }
    int num1=convert(n1),num2=convert(n2);             //functing to convert character digit to integer
    largest=num1>num2?num1:num2;
    if(s1!=s2)                                         //checking if sign of numbers are different
    {
        if(s1==1 && largest==num1 )
            printf("-");
        if(s1==1 && largest==num2 && num1!=num2)
            printf("-");  
        addition(n1,n2);                                //calling addition function
        return SUCCESS;
    }
    if(num1<num2)               //checking num1 is smaller than num2
    {
        temp=num1;
        num1=num2;                                    //swapping numbers
        num2=temp;
    }
    while(num1)
    {
        digit=num1%10;
        insertfirst(&head1,&tail1,digit);                        //inserting digit by digit
        num1=num1/10;
    }
    while(num2)
    {
        digit=num2%10;
        insertfirst(&head2,&tail2,digit);                               //inserting digit by digit
        num2=num2/10;
    }
    Dlist *temp1=tail1,*temp2=tail2;
    while( temp1 && temp2)
    {
        temp1->data=temp1->data-borrow;                           //substracting digit by digit
        if(temp1->data<temp2->data)
        {
            res=(temp1->data + 10) - temp2->data;               //adding ten if the digit is smaller than num2 digit
            borrow=1;
        }
        else
        {
            res=temp1->data - temp2->data;
            borrow=0;   
        }
        insertfirst(&head3,&tail3,res);                           //inserting res to list3
        if(temp2->prev==NULL)
        {
            insertfirst(&head2,&tail2,0);                          //inserting 0 to num2 if there is no digit
        }
        temp1=temp1->prev;
        temp2=temp2->prev;
    } 
    if(s1==1 && largest==num1)                         //checking num1 is negative and is the greatest
        printf("-");
    print(head3);
    return SUCCESS;
}
