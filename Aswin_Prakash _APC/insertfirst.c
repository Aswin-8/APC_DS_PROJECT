#include "arithematic.h"

int insertfirst(Dlist **head,Dlist **tail,int data)
{
    Dlist *new=malloc(sizeof(Dlist));                            //dynamically allocating memory
    if(new==NULL)
        return FAILURE;
    new->data=data;
    new->next=NULL;
    new->prev=NULL;                                                //initialising new node with data and links
    if(*head==NULL)
    {
        *head=new;
        *tail=new;                                              //if it is first node updating head and tail with new
        return SUCCESS;
    }
    new->next=*head;                                        //updating new->next with head
    (*head)->prev=new;
    *head=new;                                             //updating head with new
    return SUCCESS;    
}