#include <iostream>
using namespace std;

struct ListNode {
    int value;
    ListNode* next;

    ListNode(int val) : value(val), next(nullptr) {}
};

struct BSTNode {
    int key;                
    ListNode* values;    
    BSTNode* left;
    BSTNode* right;

    BSTNode(int keyVal, int value) {
        key = keyVal;
        values = new ListNode(value);
        left = right = nullptr;
    }
};

ListNode* deleteFromLinkedList(ListNode* head, int value, bool& isEmpty) {
    if (head == nullptr) return nullptr;

    if (head->value == value) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) isEmpty = true; 
        return head;
    }

    ListNode* current = head;
    while (current->next != nullptr && current->next->value != value) {
        current = current->next;
    }

    if (current->next != nullptr) {
        ListNode* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    return head;
}

BSTNode* findMin(BSTNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

BSTNode* deleteFromBST(BSTNode* root, int key, int value) {
    if (root == nullptr) return nullptr;

    if (key < root->key) {
        root->left = deleteFromBST(root->left, key, value); 
    } else if (key > root->key) {
        root->right = deleteFromBST(root->right, key, value); 
    } else {
        bool isEmpty = false;
        root->values = deleteFromLinkedList(root->values, value, isEmpty);

        if (isEmpty) {
            if (root->left == nullptr) {
                BSTNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                BSTNode* temp = root->left;
                delete root;
                return temp;
            }

            BSTNode* temp = findMin(root->right);
            root->key = temp->key;
            root->values = temp->values;
            root->right = deleteFromBST(root->right, temp->key, temp->values->value);
        }
    }

    return root;
}

BSTNode* insert(BSTNode* root, int key, int value) {
    if (root == nullptr) {
        return new BSTNode(key, value); 
    }

    if (key < root->key) {
        root->left = insert(root->left, key, value); 
    } else if (key > root->key) {
        root->right = insert(root->right, key, value); 
    } else {
        ListNode* temp = root->values;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new ListNode(value); 
    }
    return root;
}

void search(BSTNode* root, int key) {
    if (root == nullptr) {
        cout << "Key " << key << " not found." << endl;
        return;
    }

    if (key < root->key) {
        search(root->left, key); 
    } else if (key > root->key) {
        search(root->right, key); 
    } else {
        cout << "Key " << key << " found. Values: ";
        ListNode* temp = root->values;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void inorderTraversal(BSTNode* root) {
    if (root == nullptr) return;

    inorderTraversal(root->left);
    cout << "Key " << root->key << ": ";
    ListNode* temp = root->values;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
    inorderTraversal(root->right);
}

int main() {
    BSTNode* root = nullptr;

    root = insert(root, 10, 100);
    root = insert(root, 5, 50);
    root = insert(root, 20, 200);
    root = insert(root, 10, 110); 
    root = insert(root, 5, 55);

    cout << "Inorder Traversal:" << endl;
    inorderTraversal(root);

    search(root, 10);
    search(root, 15);

    cout << "\nDeleting value 110 from key 10..." << endl;
    root = deleteFromBST(root, 10, 110);
    inorderTraversal(root);

    cout << "\nDeleting value 100 from key 10..." << endl;
    root = deleteFromBST(root, 10, 100);
    inorderTraversal(root);

    return 0;
}
