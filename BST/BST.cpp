#include <iostream>
#include <vector>

using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

void insert(BSTNode*& root, int value){
    if (root == nullptr){
        root = new BSTNode(value);
    }

    if (value < root->data ){
        insert(root->left, value);
    } 
    if (value > root->data ){
        insert(root->right, value);
    }

};

BSTNode* search(BSTNode*& root, int value){

    if (root == nullptr){
        return nullptr;
    }

    if (value < root->data ){
        insert(root->left, value);
    } 
    if (value > root->data ){
        insert(root->right, value);
    }

    return root;
}

void inorder(BSTNode*& root, vector<int>& result) {
    if (!root) return;
    inorder(root->left, result);           
    result.push_back(root->data);           
    inorder(root->right, result);           
};

void preorder(BSTNode* root, vector<int>& result) {
    if (!root) return;
    result.push_back(root->data);         // 1. Nodo actual
    preorder(root->left, result);         // 2. Subárbol izquierdo
    preorder(root->right, result);        // 3. Subárbol derecho
}

void postorder(BSTNode* root, vector<int>& result) {
    if (!root) return;
    postorder(root->left, result);        // 1. Subárbol izquierdo
    postorder(root->right, result);       // 2. Subárbol derecho
    result.push_back(root->data);         // 3. Nodo actual
}

BSTNode* minValueNode(BSTNode* root){
    if (!root) return nullptr;  

    while(true){
        root = root->left;
        if(!root->left){
            break;
        }
    }

    return root;
}

BSTNode* deleteNode(BSTNode* root, int value){
    if (!root) return nullptr;

    if (value < root->data){
        root->left = deleteNode(root->left, value);
    }

    else if(value > root->data){
        root->left = deleteNode(root->right, value);
    }

    else {
        if(!root->left){
            BSTNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right){
            BSTNode* temp = root->left;
            delete root;
            return temp;
        } else {
            
            BSTNode* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}




int main(){
    BSTNode* root = new BSTNode(17);

    insert(root, 12);
    insert(root, 18);
    insert(root, 8);
    insert(root, 7);
    insert(root, 6);
    insert(root, 5);

    vector<int> result;

    cout << "Árbol inorden antes de eliminar:" << endl;

    inorder(root, result);

    for (int val : result)
        cout << val << " ";
    cout << endl;

    // Prueba de eliminación
    root = deleteNode(root, 8);

    result.clear();
    cout << "Árbol inorden después de eliminar 8:" << endl;
    inorder(root, result);
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
