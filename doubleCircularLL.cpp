#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

void insertEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
        return;
    }
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = head;
    head->prev = newNode;
}

void insertBegin(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
        return;
    }
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void deleteNode(Node*& head, int val) {
    if (!head) return;
    Node* temp = head;
    while (temp->next != head && temp->data != val) {
        temp = temp->next;
    }
    if (temp->data != val) return;
    if (temp == head && temp->next == head) {
        delete temp;
        head = nullptr;
        return;
    }
    if (temp == head) {
        head = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

void printList(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void printReverse(Node* head) {
    if (!head) return;
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    do {
        cout << temp->data << " ";
        temp = temp->prev;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertBegin(head, 5);

    cout << "Doubly Circular Linked List: ";
    printList(head);

    deleteNode(head, 20);
    cout << "After deleting 20: ";
    printList(head);

    cout << "Reverse Traversal: ";
    printReverse(head);

    return 0;
}
