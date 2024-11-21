#include "arithematic.h"

void print(Dlist *head)
{
    Dlist *temp=head;
    if(head==NULL)                           //checking if list is empty
        printf("List is empty");
    else
        {
            while(head)
            {
                if(!(head->data==0 && head==temp && head->next!=NULL))
                    printf("%d",head->data);                           //printing the values
                head=head->next;
            }
              printf("\n");
        }
}