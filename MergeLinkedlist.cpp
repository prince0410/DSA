#include<iostream>
#include <bits/stdc++.h>
using namespace std; 
 
 struct node
{

    int data;
    struct node *next;

} *head1 = NULL , *head2=NULL;

struct node *createNode(int x)
{
   
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = x;

    newnode->next = NULL;

    return newnode;
}

void InsertFront(int x , node** head)
{

    struct node *n;

    n = createNode(x);

    if (*head == NULL)
        *head = n;

    else
    {
        n->next = *head;
        *head = n;
    }
}


void InsertLast(int x, node** head)
{

    struct node *n;
    n = createNode(x);
    if (*head == NULL)
        *head = n;
    else
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}


void DisplayLinkedlist(node** head)
{


    struct node *t = *head;

    while (t != NULL)
    {
        cout << t->data << " ";

        t = t->next;
    }

    cout << endl;

   
}

void MergeLikedlist(){



}


int main(){
 
  
  
InsertLast(10,&head1);
  
InsertLast(20,&head1);
  
InsertLast(30,&head1);


InsertLast(15,&head2);
  
InsertLast(35,&head2);
  
InsertLast(40,&head2);
  
InsertLast(50,&head2);

 cout << "First LinkedList: "; 
DisplayLinkedlist(&head1);


DisplayLinkedlist(&head2);

 
}