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
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertBegin(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void deleteNode(Node*& head, int val) {
    if (!head) return;
    Node* temp = head;
    while (temp && temp->data != val) {
        temp = temp->next;
    }
    if (!temp) return;
    if (temp == head) {
        head = temp->next;
        if (head) head->prev = nullptr;
    } else {
        temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
    }
    delete temp;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printReverse(Node* head) {
    if (!head) return;
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    while (temp) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertBegin(head, 5);

    cout << "Doubly Linked List: ";
    printList(head);

    deleteNode(head, 20);
    cout << "After deleting 20: ";
    printList(head);

    cout << "Reverse Traversal: ";
    printReverse(head);

    return 0;
}
