// COMSC210 | Lab 17 | Majd Bohsali
// IDE used: Visual Studio Code
#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node*);

Node* addFront(Node*, int);
Node* addBack(Node*, int); 
Node* deleteNode(Node*, int);
Node* insertNode(Node*, int); 
Node* clearList(Node*);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);

    head = addFront(head, 150);
    cout << "Added 150 to front" << endl; 
    output(head); 

    head = addBack(head, 200);
    cout << "Added 200 to front" << endl; 
    output(head); 
    

    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    head = deleteNode(head, entry);

    cout << "Output with deleted node:" << endl;
    output(head); 

    Node * current = head;
    current = head;
    cout << "After which node to insert 10000? " << endl;
    cout << "Choice --> ";
    cin >> entry;

    head = insertNode(head, entry);
    cout << "Output with inserted node:" << endl;
    output(head);

    head = clearList(head);
    output(head);

    return 0;
}

void output(Node* hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node* current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

Node* addFront(Node* hd, int val) { 
    Node* newNode = new Node; 
    newNode->value = val; 
    newNode->next = hd; 
    return newNode;
}

Node* addBack(Node* hd, int val) { 
    Node* newNode = new Node; 
    newNode->value = val; 
    newNode->next = nullptr; 
    Node* current = hd; 
    while(current->next) { 
        current = current->next; 
    }
    current->next = newNode; 
    return hd; 
}

Node* deleteNode(Node* hd, int input) { 

    if (input == 1) { 
        Node* current = hd; 
        hd = current->next;
        delete current; 
        return hd; 
    }

    Node* current = hd;
    current = hd;
    Node* prev = hd;
    for (int i = 0; i < (input-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    if (current) {
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    return hd; 
}

Node* insertNode(Node* hd, int input) {
    Node* current = hd;
    Node* prev = hd;
    for (int i = 0; i < (input); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    Node* newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;

    return hd; 
}

Node* clearList(Node* hd) { 
    Node* current = hd; 
    while (current) { 
        hd = current->next; 
        delete current; 
        current = hd; 
    }
    return nullptr;
}