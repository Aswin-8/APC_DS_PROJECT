#include "arithematic.h"

int division(char *n1,char *n2)
{
    int digit,count=0,temp,s1=0,s2=0,borrow=0,zerocount=0;
    Dlist *head1=NULL;
    Dlist *tail1=NULL;
    Dlist *head2=NULL;
    Dlist *tail2=NULL;
    Dlist *head3=NULL;
    Dlist *tail3=NULL;
    if(n1[0]=='-')                                                 //checking if the number is negative
    {
        s1=1;
        for(int i=0;i<strlen(n1);i++)
        {
            n1[i]=n1[i+1];                                           //shifting every character to left
        }
    }
    if(n2[0]=='-')                                              //checking if the number is negative
    {
        s2=1;
        for(int i=0;i<strlen(n2);i++)
        {
            n2[i]=n2[i+1];                                       //shifting every character to left
        }
    }
    int num1=convert(n1),num2=convert(n2);                           //converting character digits to integer digits
    if(num1<num2 || (num1==0 && num2!=0))                            //checking if num1 is smaller than num2
    {
        printf("%d\n",0);
        return SUCCESS;
    }
    if(num2==0 && num1!=0)                                   //checking if num2 is equal to zero
    {
        printf("infinite\n");
        return FAILURE;
    }
    if(num1==0 && num2==0)                              //checking if both numbers are zero
    {
        printf("Error\n");
        return FAILURE;
    }
    if(s1!=s2)                                         //checking if numbers are having different sign
    {
        printf("-");
    }
    while(num1)
    {
        digit=num1%10;
        insertfirst(&head1,&tail1,digit);                    //inserting digit by digit into the list
        count++;                                             //incrementing count
        num1=num1/10;
    }
    while(num2)
    {
        digit=num2%10;
        insertfirst(&head2,&tail2,digit);                    //inserting digit by digit into the list
        num2=num2/10;
    }
    Dlist *temp1=tail1,*temp2=tail2;
    insertfirst(&head3,&tail3,0);                              //initialising result list with zero
    while(count!=zerocount)
    {
        while (temp1 && temp2)
        {
            temp1->data=temp1->data-borrow;                        //substracting digit by digit
            if(temp1->data<temp2->data)                            //checking if num1 digit is smaller than num2 digit
            {
                temp1->data=(temp1->data + 10) - temp2->data;        //adding 10 num1 digit if it is smaller
                borrow=1;
            }
            else
            {
                temp1->data=temp1->data - temp2->data;
                borrow=0;   
            }
            if(temp2->prev==NULL)                                     //checking if temp2 has reached the first node 
            {
                insertfirst(&head2,&tail2,0);                           //inserting zero at first place num2 for substraction
            }
            temp1=temp1->prev;                                   //traversing temp1 and temp2 through their list
            temp2=temp2->prev;
        }    
        temp1=tail1;                                              //making temp1 and temp2 point to their initial position
        temp2=tail2;
        head3->data+=1;                                          //incrementing result list
        zerocount=0;
        while (temp1)                                            
        {
            if(temp1->data==0)                                   //checking if temp1 data is zero
            zerocount++;                                        //incrementing zero count
            temp1=temp1->prev;                                 //traversing through list
        }
        temp1=tail1;                                            //reinitialising temp1 with initial position
    }
    print(head3);                                              //printing the result
    return SUCCESS;
}
