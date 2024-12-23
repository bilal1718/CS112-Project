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
        newNode->next = head;
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head; 
}

void insertBegin(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        newNode->next = head; 
        return;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

void deleteNode(Node*& head, int val) {
    if (!head) return;
    
    if (head->data == val) {
        Node* temp = head;
        if (head->next == head) {
            head = nullptr;
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            head = head->next;
            last->next = head;
        }
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != head && temp->next->data != val) {
        temp = temp->next;
    }

    if (temp->next && temp->next->data == val) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
}

bool search(Node* head, int val) {
    if (!head) return false;

    Node* temp = head;
    do {
        if (temp->data == val) {
            return true;
        }
        temp = temp->next;
    } while (temp != head);

    return false;
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

int main() {
    Node* head = nullptr;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertBegin(head, 5);

    cout << "Circular Linked List: ";
    printList(head);

    cout << "Searching for 20: " << (search(head, 20) ? "Found" : "Not Found") << endl;
    cout << "Searching for 15: " << (search(head, 15) ? "Found" : "Not Found") << endl;

    deleteNode(head, 20); 
    cout << "After deleting 20: ";
    printList(head);

    return 0;
}
