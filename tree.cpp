#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class Tree{
    Node* root;

    public:
        Tree()
        {
            root = nullptr;
        }

        void createTree(int value , int left , int right)
        {
            Node* newRoot = new Node(value);
            Node* newLeft = new Node(left);
            Node* newRight = new Node(right);

            root = newRoot;
            root->left = newLeft;
            root->right = newRight;
        }

        void preOrder(Node* node)
        {
            if(node  == nullptr) return;
            cout << node->data << " ";

            preOrder(node->left);
            preOrder(node->right);

        }

        void inOrder(Node* node)
        {
            if(node == nullptr) return;
            inOrder(node->left);
            
            cout << node->data << " ";

            inOrder(node->right);
        }

        void postOrder(Node* node)
        {
            if(node == nullptr) return;

            postOrder(node->left);
            postOrder(node->right);

            cout << node->data << " ";
        }

        void insert(int value, Node*& node)
        {
            

            if(node == nullptr)
            {
                Node* newNode = new Node(value);
                node = newNode;
                return;
            }
 
            if(value < node->data)
            {
                if(node->left == nullptr)
                {
                    Node* newNode = new Node(value);
                    node->left = newNode;
                    return;
                }
                insert(value , node->left);
            }

            if(value > node->data)
            {
                if(node->right == nullptr)
                {
                    Node* newNode = new Node(value);
                    node->right = newNode;
                    return;
                }
                insert(value , node->right);
            }
            
        }

        bool search(int value , Node* node)
        {
            if(node == nullptr) return false;

            if(node->data == value)
            {
                return true;
            }
            else
            {
                if(value < node->data)
                {
                   return search(value , node->left);
                }
                else if(value > node->data)
                {
                   return search(value , node->right);
                }
            }

        }

        Node* deleteNode(int value , Node* node)
        {
            if(node == nullptr) return node;

            if(value < node->data)
            {
                node->left = deleteNode(value , node->left);
            }
            else if(value > node->data)
            {
                node->right = deleteNode(value , node->right);
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
                    delete min;
                    min = nullptr;
                }
            }
            else
            {
                return node;
            }
        }

        Node* findMin(Node* node)
        {   
            if(node == nullptr) return nullptr;
            if(node->left == nullptr) return node;
            return findMin(node->left);
        }
};