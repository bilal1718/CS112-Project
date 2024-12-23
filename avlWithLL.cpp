#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

struct Node {
    ListNode* keys;
    Node* left;
    Node* right;
    int height;

    Node(int val) : keys(new ListNode(val)), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(Node* node) {
    return node ? node->height : 0;
}

int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

void addToLinkedList(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;
}

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->keys->data) {
        root->left = insert(root->left, key);
    } else if (key > root->keys->data) {
        root->right = insert(root->right, key);
    } else {
        addToLinkedList(root->keys, key);
        return root;
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int balance = getBalance(root);

    if (balance > 1 && key < root->left->keys->data) {
        return rightRotate(root);
    }

    if (balance < -1 && key > root->right->keys->data) {
        return leftRotate(root);
    }

    if (balance > 1 && key > root->left->keys->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && key < root->right->keys->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left) current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->keys->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->keys->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->keys->next) {
            ListNode* temp = root->keys;
            root->keys = root->keys->next;
            delete temp;
            return root;
        }

        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->keys->data = temp->keys->data;
        root->right = deleteNode(root->right, temp->keys->data);
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printLinkedList(root->keys);
    cout << endl;
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);

    inorder(root);
    root = deleteNode(root, 10);
    cout << "After deletion:" << endl;
    inorder(root);

    return 0;
}
