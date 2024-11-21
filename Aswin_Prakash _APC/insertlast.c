#include "arithematic.h"

int insertlast(Dlist **head,Dlist **tail,int data)
{
    Dlist *new=malloc(sizeof(Dlist));                   //dynamically allocating memory
    if(new==NULL)
        return FAILURE;
    new->data=data;
    new->next=NULL;                                        //initialising new with data and links
    new->prev=NULL;
    if(*head==NULL)                                        //checking if list is empty
    {
        *head=new;
        *tail=new;                                        //updating head and tail with new
        return SUCCESS;
    }
    new->prev=*tail;                                     //storing tail in new->prev
    (*tail)->next=new;
    *tail=new;                                          ///updating tail
    return SUCCESS;    
}