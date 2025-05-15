#include <iostream>
#include <vector>
using namespace std;

struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

// Utilidades
int getHeight(AVLNode* node) {
    return node ? node->height : 0;
}

int getBalance(AVLNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Rotaciones
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    // Rotar
    x->right = y;
    y->left = T2;

    // Actualizar alturas
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // Rotar
    y->left = x;
    x->right = T2;

    // Actualizar alturas
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

// Inserción AVL
AVLNode* insert(AVLNode* node, int value) {
    if (!node)
        return new AVLNode(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    else
        return node; // No duplicados

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    // Casos de desbalance
    if (balance > 1 && value < node->left->data)
        return rightRotate(node); // LL
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);  // RR
    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left); // LR
        return rightRotate(node);
    }
    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right); // RL
        return leftRotate(node);
    }

    return node;
}

// Búsqueda
AVLNode* search(AVLNode* root, int value) {
    if (!root || root->data == value)
        return root;

    if (value < root->data)
        return search(root->left, value);
    return search(root->right, value);
}

// Nodo mínimo (para delete)
AVLNode* minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current && current->left)
        current = current->left;
    return current;
}

// Eliminación AVL
AVLNode* deleteNode(AVLNode* root, int value) {
    if (!root)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        if (!root->left || !root->right) {
            AVLNode* temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        } else {
            AVLNode* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (!root) return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    // Balancear
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root); // LL
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left); // LR
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root); // RR
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right); // RL
        return leftRotate(root);
    }

    return root;
}

// Inorden
void inorder(AVLNode* root, vector<int>& result) {
    if (!root) return;
    inorder(root->left, result);
    result.push_back(root->data);
    inorder(root->right, result);
}

int main() {
    AVLNode* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    vector<int> result;
    inorder(root, result);

    cout << "Inorden del AVL: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    AVLNode* found = search(root, 25);
    if (found)
        cout << "Encontrado: " << found->data << endl;
    else
        cout << "No encontrado." << endl;
    
    root = deleteNode(root, 30);

    result.clear();
    inorder(root, result);
    cout << "Inorden después de eliminar 30: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
