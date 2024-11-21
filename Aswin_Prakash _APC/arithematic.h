#ifndef ARITHEMATIC_H
#define ARITHEMATIC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 enum STATUS
{
    SUCCESS,
    FAILURE,
};

//double linked list
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}Dlist;

//function to insert element at last
int insertlast(Dlist **head,Dlist **tail,int data);

//function to insert element at first
int insertfirst(Dlist **head,Dlist **tail,int data);

//function to print
void print(Dlist *head);

//function to add two numbers
int addition(char *,char *);

//function to convert character digit to integer digit
int convert(char *num);

//function to substract two numbers
int subtraction(char *n1,char *n2);

//function to multiply two numbers
int multiplication(char *n1,char *n2);

//function to divide two numbers
int division(char *n1,char *n2);

#endif