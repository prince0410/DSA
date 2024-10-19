#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{

    int data;
    struct node *next;

} *head = NULL;

int TotalNodes = 0;

struct node *createNode(int x)
{
    TotalNodes++;
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = x;

    newnode->next = NULL;

    return newnode;
}

void InsertFront(int x)
{

    struct node *n;

    n = createNode(x);

    if (head == NULL)
        head = n;

    else
    {
        n->next = head;
        head = n;
    }
}

void InsertLast(int x)
{

    struct node *n;
    n = createNode(x);
    if (head == NULL)
        head = n;
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

void DeleteFront()
{
    TotalNodes--;
    node *temp = head;
    head = head->next;
    delete temp;
}

void DeleteLast()
{

    TotalNodes--;
    node *temp = head;
    node *previous = head;
    while (temp->next != NULL)
    {
        previous = temp;
        temp = temp->next;
    }
    previous->next = NULL;
    delete temp;
}

void DeleteFromLast(int x)
{
    node *temp=head;
    node *previous=head;

    for(int i=0; i<TotalNodes-x; i++){

        previous = temp;
        temp = temp->next;
    }

    previous->next = temp->next;
    delete temp;

}

void DeleteAllNode()
{

    while (head != NULL)
        DeleteFront();
}

void DisplayLinkedlist()
{

    struct node *t = head;

    while (t != NULL)
    {
        cout << t->data << " ";

        t = t->next;
    }

    cout << endl;

    cout << "Total Nodes : " << TotalNodes << endl;
}

void ReverseLinkedList(){

node *temp = head;
node *previous = NULL;
node *next = NULL;

while(temp!=NULL){

        next = temp->next;
        temp->next = previous;
        previous = temp;
        temp = next;
}

head = previous;
TotalNodes--;

}

bool isPolidrom(){

node *start=head;
node *end=head;
node *preEnd=NULL;

while (end!=NULL)
{
    preEnd=end;
   end = end->next;
}

for(int i=0; i<TotalNodes/2; i++){

    if(start->data != end->data){   
        return false;
        }
        
        start=start->next;
        end = preEnd;


}


} 


int main()
{

    InsertFront(10);
    InsertFront(20);
    InsertFront(30);
    InsertLast(40);
    DeleteFront();
    InsertLast(60);
    InsertFront(50);
    
    DeleteFromLast(3);

    ReverseLinkedList();

    DisplayLinkedlist();
}