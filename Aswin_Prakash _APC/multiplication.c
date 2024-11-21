#include "arithematic.h"

int multiplication(char *n1,char *n2)
{
    int digit,res,carry=0,temp,s1=0,s2=0,rem=0,digitcount=0,count=0;
    Dlist *head1=NULL;
    Dlist *tail1=NULL;
    Dlist *head2=NULL;
    Dlist *tail2=NULL;
    Dlist *head3=NULL;
    Dlist *tail3=NULL;
    Dlist *head4=NULL;
    Dlist *tail4=NULL;
    if(n1[0]=='-')                                               //checking if n1 is negative
    {
        s1=1;
        for(int i=0;i<strlen(n1);i++)
        {
            n1[i]=n1[i+1];                                       //shifting every character to left
        }
    }
    if(n2[0]=='-')                                             //checking if n2 is negative
    {
        s2=1;
        for(int i=0;i<strlen(n2);i++)
        {
            n2[i]=n2[i+1];                                         //shifting every character to left
        }
    }
    int num1=convert(n1),num2=convert(n2);                       //converting character digit into integer
    if(s1!=s2)                                                   //checking if numbers are having different sign
    {
       printf("-");
    }
    if(num1<num2)                                                 //if num1 is smaller then swapping numbers
    {
        temp=num1;
        num1=num2;
        num2=temp;
    }
    while(num1)
    {
        digit=num1%10;
        insertfirst(&head1,&tail1,digit);                             //inserting digit by digit to list 1
        num1=num1/10;
    }
    while(num2)
    {
        digit=num2%10;
        insertfirst(&head2,&tail2,digit);                            //inserting digit by digit to list 2
        count++;
        num2=num2/10;
    }
    Dlist *temp1=tail1,*temp2=tail2;
    while(temp1)
    { 
        res=(temp1->data * temp2->data)+carry;                      //multiplying digit by digit
        if(res >9)
        {   
            carry=res/10;
            res=res%10;    
        }
        else
            carry=0;
        insertfirst(&head3,&tail3,res);                        //inserting result to list3
        if(temp1==head1 && carry!=0)
            insertfirst(&head3,&tail3,carry);
        temp1=temp1->prev;      
    }
    temp2=temp2->prev;
    while(--count || temp2)
    {
        digitcount++;                                //incrementing digit count
        temp1=tail1;                                 //reinitialising temp1
        carry=0;
        res=0;
        while(temp1)
        {
            res=(temp1->data * temp2->data)+carry;           //multiplying digit by digit
            if(res >9)                                       //checking if res is greater than 9
            {   
                carry=res/10;
                res=res%10;    
        }
        else
            carry=0;
        insertfirst(&head4,&tail4,res);
        if(temp1==head1 && carry!=0)
            insertfirst(&head4,&tail4,res+carry);               //inserting result to list 4
        temp1=temp1->prev;                                      //traversing through list 1
        }
    for(int i=0;i<digitcount;i++)
        insertlast(&head4,&tail4,0);                           //inserting 0 for digit count number of times
    res=0,carry=0;
    Dlist *temp3=tail3,*temp4=tail4;
    while (temp3 && temp4)
    {
        res=(temp3->data+carry) + temp4->data;                  //adding digits of list3 and list4
        if(res >9)
        {   
            carry=1;
            res=res%10;
        }
        else
            carry=0;
        temp3->data=res;                                            //updating temp3 data with res
        if(temp3->prev==NULL)
        {
            insertfirst(&head3,&tail3,0);                           //inserting zero at first position list3
        }
        if(temp3==head3 && carry!=0)
            insertfirst(&head3,&tail3,carry+res);                    //inserting the carry value at first position
        temp3=temp3->prev;
        temp4=temp4->prev;                                          //traversing throgh list3 and list4
    }
    Dlist *temp5=head4;
    while(temp5!=NULL)
    {
        temp5=temp5->next;             //traversing and freeing
        free(temp5);
    }
    free(head4);                   //freeing first node
    head4=NULL;
    tail4=NULL;                            //updating tail and head with NULL
    temp2=temp2->prev;                     //traversing through the list
    }
    print(head3);                          //printing result
    return SUCCESS;
}