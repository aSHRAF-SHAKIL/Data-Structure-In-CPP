#include<iostream>

using namespace std;

class node {
public:
    int data;      // Data field to store the value of the node
    node* next;    // Pointer to the next node in the linked list

    node(int val) {
        data = val;  // Initialize the data field with the given value
        next = NULL; // Initialize the next pointer to NULL
    }
};

// Function to insert a node at the head of the linked list
void insertAtHead(node* &head, int val) {
    node* n = new node(val);  // Create a new node with the given value
    n->next = head;           // Point the new node to the current head
    head = n;                 // Update the head to the new node
}

// Function to insert a node at the tail (end) of the linked list
void insertAtTail(node* &head, int val) {
    node* n = new node(val);  // Create a new node with the given value

    if (head == NULL) {       // If the list is empty
        head = n;             // The new node becomes the head of the list
        return;               // Exit the function
    }

    node* temp = head;        // Temporary pointer to traverse the list
    while (temp->next != NULL) { // Traverse to the last node
        temp = temp->next;    // Move to the next node
    }
    temp->next = n;           // Set the next pointer of the last node to the new node
}

// Function to search for a value in the linked list
bool search(node* head, int key) {
    node* temp = head;        // Temporary pointer to traverse the list
    while (temp != NULL) {    // Traverse until the end of the list
        if (temp->data == key) { // If the key is found, return true
            return true;
        }
        temp = temp->next;    // Move to the next node
    }
    return false;             // Return false if the key is not found
}

// Function to display the linked list
void display(node* head) {
    node* temp = head;        // Temporary pointer to traverse the list
    while (temp != NULL) {    // Traverse until the end of the list
        cout << temp->data << "->"; // Print the current node's data
        temp = temp->next;    // Move to the next node
    }
    cout << "NULL" << endl;   // Print NULL at the end of the list
}

int main() {
    node* head = NULL;        // Initialize the linked list as empty

    insertAtTail(head, 1);    // Insert value 1 at the tail
    insertAtTail(head, 2);    // Insert value 2 at the tail
    insertAtTail(head, 3);    // Insert value 3 at the tail
    insertAtTail(head, 4);    // Insert value 4 at the tail

    display(head);            // Display the linked list

    insertAtHead(head, 77);   // Insert value 77 at the head
    display(head);            // Display the linked list

    cout << search(head, 77) << endl; // Search for value 77 in the list
    cout << search(head, 5) << endl;  // Search for value 5 in the list

    return 0;
}
