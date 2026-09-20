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

        void insert_head(int value)
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
            if(head == nullptr)
            {
                cout << "list is empty" << endl;
            }
            Node* temp = head;

            while(temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }

        void remove_end(int index)
        {
            if(index == 0) return;
            
            if(head == nullptr)
            {
                cout << "List is empty" << endl;
            }
            else
            {
                bool is_head = false;
                bool is_tail = false;
                
                Node* temp = head;
                Node* preTemp = head;
                
                int it = 0;

                while(temp != nullptr)
                {
                    temp = temp->next;
                    if(it<=index)
                    {
                        it++;
                    }
                    else
                    {
                        preTemp = preTemp->next;
                    }
                }

                if(preTemp == head && it == index)
                {
                    cout << "HEAD EXECUTING" << endl;
                    head = head->next;
                    delete preTemp;
                    preTemp = nullptr;
                }
                else if(preTemp->next->next == nullptr  && it == index+1)
                {
                    cout << "TAIL EXECUTING" << endl;
                    Node* rm = preTemp->next;
                    preTemp->next = nullptr;
                    delete rm;
                    rm = nullptr;
                }
                else if(it == index+1)
                {
                    Node* rm = preTemp->next;
                    preTemp->next = preTemp->next->next;
                    delete rm;
                    rm = nullptr;
                }
                else
                {
                    cout << "Index is out of range" << endl;
                }
            }
        }
};


int main()
{
    List L1;

    L1.insert_head(9);
    L1.insert_head(8);
    L1.insert_head(7);
    L1.insert_head(6);
    L1.insert_head(5);
    L1.insert_head(4);
    L1.insert_head(3);
    L1.insert_head(2);
    L1.insert_head(1);
    L1.display();



    L1.remove_end(3);
    L1.display();
    L1.remove_end(1);
    L1.display();
    L1.remove_end(1);
    L1.display();


    L1.remove_end(3);
    L1.display();
    L1.remove_end(5);
    L1.display();
    return 0;
}