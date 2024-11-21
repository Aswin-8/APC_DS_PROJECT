#include "arithematic.h"

int addition(char *n1,char *n2)
{
    int digit,sum,carry=0,temp,s1=0,s2=0,largest;
    Dlist *head1=NULL;
    Dlist *tail1=NULL;
    Dlist *head2=NULL;
    Dlist *tail2=NULL;
    Dlist *head3=NULL;
    Dlist *tail3=NULL;
    if(n1[0]=='-')                        //checking if the number is negative
    {
        s1=1;
        for(int i=0;i<strlen(n1);i++)          //removing '-' from number
        {
            n1[i]=n1[i+1];
        }
    }
    if(n2[0]=='-')                        //checking if the number is negative
    {
        s2=1;
        for(int i=0;i<strlen(n2);i++)
        {
            n2[i]=n2[i+1];                  //removing '-' from number
        }
    }
    int num1=convert(n1),num2=convert(n2);         //calling convert function to convert number in char to int
    largest=num1>num2?num1:num2;                    //finding the largest number
    if(s1!=s2)
    {
        if(s1==1 && largest==num1)                 //if the largest number is negative printing output with -
            printf("-");
        if(s2==1 && largest==num2)
            printf("-");  
        subtraction(n1,n2);                          //caling subtract function if the numbers have different sign
        return SUCCESS;
    }
    if(num1<num2)                                      //if num1 is less than num2 swapping numbers
    {
        temp=num1;
        num1=num2;
        num2=temp;
    }
    while(num1)
    {
        digit=num1%10;
        insertfirst(&head1,&tail1,digit);                    //inserting digit by digit into a double linked list
        num1=num1/10;
    }
    while(num2)
    {
        digit=num2%10;
        insertfirst(&head2,&tail2,digit);                    //inserting digit by digit into a double linked list
        num2=num2/10;
    }
    Dlist *temp1=tail1,*temp2=tail2;
    while( temp1 && temp2)
    {
        sum=temp1->data+temp2->data+carry;                   //finding the sum of digits of both number starting from one's position
        if(sum >9)
        {
            sum=sum%10;                                     //updating sum with only one's place
            carry=1;                                         //updating carry with 1
        }
        else
            carry=0;
        insertfirst(&head3,&tail3,sum);                    //inserting sum to new double linked list
        if(temp1==head1 && carry==1)
            insertfirst(&head3,&tail3,1);                 //updating the carry at first position
        if(temp2->prev==NULL)
        {
            insertfirst(&head2,&tail2,0);                 //inserting zero if digits are not present in num2
        }
        temp1=temp1->prev;                            //traversing through every digit of num1
        temp2=temp2->prev;                             //traversing through every digit of num2
    }
    if(s1==1 && s2==1)                               //checking if both numbers are negative
        printf("-");
    print(head3);                                     //printing the list
    return SUCCESS;
}
