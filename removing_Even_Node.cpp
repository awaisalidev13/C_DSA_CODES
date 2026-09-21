#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};


class List{
    Node* head;

    public:
        List()
        {
            head = nullptr;
        }

        void add_head(int value)
        {
            Node* newNode = new Node(value);
            if(head == nullptr)
            {
                head = newNode;
            }
            else
            {
                newNode->next = head;
                head = newNode;
            }
        }


        void display()
        {
            Node* temp = head;

            while(temp != nullptr)
            {
                cout << temp->data << "  ";
                temp = temp->next;
            }

            cout << endl;
        }

        //Adding custom fucntion of removing even nodes

        void remove_even_nodes()
        {
            Node* temp = head;

            while(temp != nullptr)
            {
                if((temp->data % 2) == 0 && temp == head)
                {
                    head = head->next;
                    delete temp;
                    temp = head;
                }
                else if ((temp->next->data % 2 ) == 0 && temp->next->next == nullptr)
                {
                    Node* rm = temp->next;
                    temp->next = nullptr;
                    delete rm;
                    rm = nullptr;
                    break;
                    
                }
                else if ((temp->next->data % 2 ) == 0)
                {
                    Node* rm = temp->next;
                    temp->next = rm->next;
                    delete rm;
                    rm = nullptr;
                }
                else
                {
                    temp = temp->next;
                }
            }

        }
};

int main()
{
    List L;

    L.add_head(8);
    L.add_head(7);
    L.add_head(6);
    L.add_head(5);
    L.add_head(2);
    L.add_head(2);
    L.add_head(2);
    L.add_head(2);
    L.display();


    L.remove_even_nodes();
    L.display();


    return 0;
}