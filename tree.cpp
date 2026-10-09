#include <iostream>
#include <queue>
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
    private:

        Node* root;
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

            return false;

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
                    node->right = deleteNode(min->data , node->right);
                }
            }

            return node;
        }

        Node* findMin(Node* node)
        {   
            if(node == nullptr) return nullptr;
            if(node->left == nullptr) return node;
            return findMin(node->left);
        }

        void destroyTree(Node* node)
        {
            if(node == nullptr) return;

            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
            node = nullptr;
        }
    public:
        Tree()
        {
            root = nullptr;
        }
        ~Tree()
        {
            destroyTree(root);
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
        
        void insert(int value)
        {
            insert(value,root);
        }

        void preOrder()
        {
            preOrder(root);
        }

        void inOrder()
        {
            inOrder(root);
        }

        void postOrder()
        {
            postOrder(root);
        }

        bool search(int value)
        {
            return search(value , root);
        }

        void deleteNode(int value)
        {
            root = deleteNode(value , root);
        }

        Node* findMin()
        {
            return findMin(root);
        }

        void levelOrder()
        {
            queue<Node*> q;
            if(root == nullptr) return;
            
            Node* temp = root;
            q.push(temp);
            while(!q.empty())
            {
                Node* temp = q.front();
                q.pop();
                cout << temp->data << " ";
                if(temp->left != nullptr)
                {
                    q.push(temp->left);
                }
                if(temp->right != nullptr)
                {
                    q.push(temp->right);
                }

            }
        }

};


int main()
{
    Tree t;
    t.insert(10);
    t.insert(5);
    t.insert(20);
    t.insert(3);
    t.insert(7);
    t.insert(15);
    t.insert(25);

    t.deleteNode(3);
    t.inOrder();
    cout << endl;
    t.inOrder();
    cout << endl;
    t.postOrder();
    cout << endl;
    t.levelOrder();
    cout << endl;
    t.deleteNode(50);
    t.levelOrder();
}