#include <bits/stdc++.h>
using namespace std;

// structure to define a node of the doubly linked list
struct node{

    // part which will store data
    char data;   // The data type can be changed to any other data type
    // pointer to the previous node
    node *prev;
    // pointer to the next node
    node *next;

};

// function to search given target
void search(node** head, char target){

    // node to traverse the linked list
    node* temp = (*head);

    // variable to store index
    int index = 1;

    // loop over the list
    while(temp != NULL){

        // if target is found
        if(temp->data == target){
            cout<<"Found the target at node "<<index<<endl;
            return;
        }

        // go to next node
        index++;
        temp = temp->next;
    }

    // node wasn't found
    cout<<"Target not found"<<endl;
}

int main() {

    // we will create a doubly linked list of size 3
    // create a pointer to the head node
    node *head = NULL;

    // create a pointer to end node
    node *end = NULL;

    // create the first node of the doubly linked list
    node* first_node = new node();
    // assign data to the first node
    first_node->data = 'E';
    // assign prev pointer to the first node
    first_node->prev = NULL;

    head = first_node;

    // create the second node of the doubly linked list
    node* second_node = new node();
    // assign data to the second node
    second_node->data = 'D';
    // assign prev pointer to the second node
    second_node->prev = first_node;
    // assign next pointer to the second node
    second_node->next = NULL;

    // assign this node to first node's next
    first_node->next = second_node;

    // create the third node of the doubly linked list
    node* third_node = new node();
    // assign data to the third node
    third_node->data = 'C';
    // assign prev pointer to the third node
    third_node->prev = second_node;
    // assign next pointer to the third node
    third_node->next = NULL;

    // assign this node to second node's next
    second_node->next = third_node;

    // search in a doubly linked list
    search(&head, 'A');

    // search another node
    search(&head, 'E');

    return 0;
}

