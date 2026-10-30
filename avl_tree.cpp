#include <iostream>
using namespace std;


struct Node{
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

Node* findMin(Node* node)
{
    if(node == nullptr)
    {
        return nullptr;
    }
    if(node->left == nullptr)
    {
        return node;
    }
    else
    {
        return findMin(node->left);
    }
}

int height(Node* node)
{
    if(node == nullptr)
    {
        return 0;
    }
    
    return node->height;
}

int getBalance(Node* node)
{
    return (height(node->left) - height(node->right)); 
}

Node* rightRotate(Node* node)
{   
    Node* root = node->left;
    Node* temp = node->left->right;
    node->left->right = node;
    node->left = temp;

    node->height = 1 + max(height(node->left), height(node->right));
    root->height = 1 + max(height(root->left), height(root->right));

    return root;
}

Node* leftRotate(Node* node)
{
    Node* root = node->right;
    Node* temp = node->right->left;
    node->right->left = node;
    node->right = temp;

    node->height = 1 + max(height(node->left), height(node->right));
    root->height = 1 + max(height(root->left), height(root->right));

    return root;
}


Node* rebalance(Node* node)
{
    node->height = 1 + max(height(node->left) , height(node->right));
    int bf = getBalance(node);

    if(bf > 1)
    {
        if(getBalance(node->left) < 0)
        {
            node->left = leftRotate(node->left);
        }
        node = rightRotate(node);
    }
    else if(bf < -1)
    {
        if(getBalance(node->right) > 0)
        {
            node->right = rightRotate(node->right);
        }
        node = leftRotate(node);
    }

    return node;
}

Node* insert(Node* node , int value)
{
    if(node == nullptr)
    {
        return new Node(value);
    }

    if(value < node->data)
    {
       node->left = insert(node->left , value);
    }
    else if(value > node->data)
    {
        node->right = insert(node->right , value);
    }
    else if(value  == node->data)
    {
        return node;
    }

    return rebalance(node);
}

Node* deleteNode(Node* node , int value)
{
    if(node  == nullptr)
    {
        return nullptr;
    }
    else if(value < node->data)
    {
        node->left = deleteNode(node->left , value);
    }
    else if(value > node->data)
    {
        node->right = deleteNode(node->right , value);
    }
    else if(value == node->data)
    {
        if(node->left == nullptr && node->right == nullptr)
        {
            delete node;
            node = nullptr;
            return node;
        }
        else if(node->left == nullptr)
        {
            Node* temp = node->right;
            delete node;
            node = nullptr;
            return temp;
        }
        else if(node->right == nullptr)
        {
            Node* temp = node->left;
            delete node;
            node = nullptr;
            return temp;
        }
        else
        {
            Node* min = findMin(node->right);
            node->data = min->data;
            node->right = deleteNode(node->right , min->data);
        }
    }

    return rebalance(node);
}

void preorder(Node* node)
{
    if(node == nullptr) return;
    cout << node->data << "(h" << node->height << ") ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* node)
{
    if(node == nullptr) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int main()
{
    Node* root = nullptr;

    cout << "LL: ";
    root = nullptr;
    root = insert(root, 30); root = insert(root, 20); root = insert(root, 10);
    preorder(root); cout << endl;

    cout << "RR: ";
    root = nullptr;
    root = insert(root, 10); root = insert(root, 20); root = insert(root, 30);
    preorder(root); cout << endl;

    cout << "LR: ";
    root = nullptr;
    root = insert(root, 30); root = insert(root, 10); root = insert(root, 20);
    preorder(root); cout << endl;

    cout << "RL: ";
    root = nullptr;
    root = insert(root, 10); root = insert(root, 30); root = insert(root, 20);
    preorder(root); cout << endl;

    cout << "Insert 1 to 7: ";
    root = nullptr;
    for(int i = 1; i <= 7; i++) root = insert(root, i);
    preorder(root); cout << endl;

    cout << "Delete -> LL: ";
    root = nullptr;
    root = insert(root, 20); root = insert(root, 10); root = insert(root, 30); root = insert(root, 5);
    root = deleteNode(root, 30);
    preorder(root); cout << endl;

    cout << "Delete, child BF=0: ";
    root = nullptr;
    root = insert(root, 20); root = insert(root, 10); root = insert(root, 30);
    root = insert(root, 5);  root = insert(root, 15);
    root = deleteNode(root, 30);
    preorder(root); cout << endl;

    cout << "Delete two children (preorder): ";
    root = nullptr;
    int vals[] = {20, 10, 30, 5, 15, 25, 35};
    for(int v : vals) root = insert(root, v);
    root = deleteNode(root, 20);
    preorder(root); cout << endl;

    cout << "Delete two children (inorder):  ";
    inorder(root); cout << endl;

    return 0;
}