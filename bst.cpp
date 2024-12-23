#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val); 
    } else {
        root->right = insert(root->right, val); 
    }
    return root;
}

bool search(Node* root, int val) {
    if (root == nullptr) {
        return false; 
    }
    if (root->data == val) {
        return true; 
    }
    if (val < root->data) {
        return search(root->left, val); 
    } else {
        return search(root->right, val); 
    }
}

Node* findMin(Node* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int val) {
    if (root == nullptr) {
        return root; 
    }

    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->data) {
        root->right = deleteNode(root->right, val); 
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        } else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = findMin(root->right); 
            root->data = temp->data; 
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = nullptr; 
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 15);
    root = insert(root, 25);

    cout << "Inorder Traversal before deletion: ";
    inorderTraversal(root);
    cout << endl;

    root = deleteNode(root, 20);

    cout << "Inorder Traversal after deletion: ";
    inorderTraversal(root);
    cout << endl;

    int key = 15;
    if (search(root, key)) {
        cout << key << " is found in the BST." << endl;
    } else {
        cout << key << " is not found in the BST." << endl;
    }

    return 0;
}
