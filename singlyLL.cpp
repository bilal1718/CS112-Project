#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertBegin(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void deleteNode(Node*& head, int val) {
    if (!head) return;
    
    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    Node* temp = head;
    while (temp->next && temp->next->data != val) {
        temp = temp->next;
    }

    if (temp->next) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
}

bool search(Node* head, int val) {
    Node* temp = head;
    while (temp) {
        if (temp->data == val) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 10); 
    insertEnd(head, 20);  
    insertEnd(head, 30); 
    insertBegin(head, 5);

    cout << "Linked List: ";
    printList(head);

    cout << "Searching for 20: " << (search(head, 20) ? "Found" : "Not Found") << endl;
    cout << "Searching for 15: " << (search(head, 15) ? "Found" : "Not Found") << endl;

    deleteNode(head, 20);
    cout << "After deleting 20: ";
    printList(head);

    return 0;
}
