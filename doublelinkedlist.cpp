#include <iostream>
#include <string>
using namespace std;

struct node
{
    int noMhs;
    string name;
    node* next;
    node* prev;

};

node* start = NULL;

void addNode() {
    node* newNode = new node(); //step1: create A NEW NODE
    cout << "\nEnter the roll number of the student:";
    cin >> newNode -> noMhs; // assign value to the data field of the new Node 
    cout << "\nEnter the name of the student:";
    cin >> newNode -> name; // assign value to the data field of the new Node 
}

