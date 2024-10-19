#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int TotalNodes = 0;

struct node
{

    int data;
    struct node *next;
    struct node *previous;

} *l = NULL, *r = NULL;

struct node *CreateNode(int x)
{
    TotalNodes++;

    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = x;

    newnode->next = NULL;
    newnode->previous = NULL;

    return newnode;
}

void InsertFront(int x)
{

    struct node *temp;

    temp = CreateNode(x);

    if (l == NULL)
    {

        l = temp;
        r = temp;
    }
    else
    {
        temp->next = l;
        l->previous = temp;
        l = temp;
    }
}

void InsertLast(int x)
{

    struct node *temp;

    temp = CreateNode(x);

    if (r == NULL)
    {
        r = temp;
        l = temp;
    }
    else
    {
        r->next = temp;
        temp->previous = r;
        r = temp;
    }
}


void InsertNthNodeFront(int x, int data) {
    struct node* temp;
    struct node* past;
    struct node* newnode;

    temp = l;
    
    for(int i = 1; i < x-1; i++) {
        temp = temp->next;
        if(temp == NULL) {
            cout << "Position out of range" << endl;
            return;
        }
    }

    newnode = CreateNode(data);

    if(x == 1) {
        newnode->next = l;
        l->previous = newnode;
        l = newnode;
    } else {
        newnode->next = temp->next;
        newnode->previous = temp;
        temp->next->previous = newnode;
        temp->next = newnode;
    }
}


void DeleteFront()
{

    TotalNodes--;
    struct node *temp;
    temp = l;
    l = l->next;
    l->previous = NULL;

    delete temp;
}

void DeleteLast()
{

    TotalNodes--;
    struct node *temp;
    temp = r;
    r = r->previous;
    r->next = NULL;
}

void DeleteFromLast(int n)
{


}


void DeleteAllNode()
{
    struct node *temp;
    while (l != NULL)
    {
        temp = l;
        l = l->next;
        delete temp;
        TotalNodes--;
    }
}

void DisplayLinkedlist()
{

    struct node *t = l;

    while (t != NULL)
    {
        cout << t->data << " ";

        t = t->next;
    }

    cout << endl;

    cout << "Total Nodes : " << TotalNodes << endl;
}

int main()
{

    InsertLast(10);
    InsertLast(20);
    InsertLast(30);
    InsertLast(40);
    InsertLast(50);
    InsertLast(60);
    InsertNthNodeFront(3,100);

    // DeleteFromLast(2);

    // DeleteAllNode();
    DisplayLinkedlist();
}