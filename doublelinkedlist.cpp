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


    //insert the nnew node in the list
    if (start == NULL || newNode->noMhs <= start->noMhs) {

        if (start != NULL && newNode->noMhs == start->noMhs) {
            cout << "\033[31mDuplicate roll numbers are not allowed\033[0m" <<endl;
            return;
        }
        // if the list is empty, make new
        newNode->next = start; // step 3
        if (start != NULL) {
            start-> prev = newNode; // step 4
        }
        newNode->prev = NULL; //step 5
        start = newNode; // step 6
    }
        else {
    // insert the new node in the middle or at the end
    node* current = start;
    node* previous = NULL;

    while (current != NULL && current->noMhs < newNode->noMhs) {
        previous = current;
        current = current->next;
    }
    newNode->next = current;
    newNode->prev = previous;

    if (current != NULL) {
        current->prev = newNode;
    }
    if (previous != NULL) {
        previous->next = newNode;
    }
    else {
        start = newNode;
    }
}

bool search(int rollNo, node** previous, node** current)
{
    if (start == NULL) {
        *previous = *current = NULL;
        return false; // Return false indicating the list is empty
    }

    *previous = NULL;
    *current = start;

    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current)->next;
    }

    // If current is NULL, roll number not found
    return (*current != NULL);
}

