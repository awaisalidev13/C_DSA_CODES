#include <iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class List{
    

    public:
        Node* tail;
        List()
        {
            tail = nullptr;
        }

        void insert_end(int value)
        {
            Node* newNode = new Node(value);
            if(tail == nullptr)
            {
                tail = newNode;
                tail->next = tail;
            }
            else
            { 
                newNode->next = tail->next;
                tail->next = newNode;
                tail = newNode; 
            }

        }

        void display()
        {
            Node* temp = tail->next;

            do
            {
                cout << temp->data << " ";
                temp = temp->next;
                
            }
            while(temp != tail->next);
        }
};

int main()
{
    List L1;

    

    //==================To Test The Display and insert_end Function===========
    // L1.insert_end(3);
    // L1.insert_end(2);
    // L1.insert_end(1);
    // L1.insert_end(0);
    // cout << endl;
    // L1.display();

    return 0;
}