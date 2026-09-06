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

        void insert_head(int value)
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
            }
        }

        void insert_at(int value, int pos)
        {
            Node* newNode = new Node(value);
            Node* temp = tail->next;

            if(pos == 0)
            {
                insert_head(value);
            }
            else
            {
                for(int i=0 ; i<pos-1; i++)
                {
                    temp = temp->next;
                    if (temp == tail->next)
                    {
                        return;
                    }
                }

                if(temp == tail)
                {
                    insert_end(value);
                    return;
                }

                newNode->next = temp->next;
                temp->next = newNode;
            }
        }

        void remove_first()
        {
            tail->next = tail->next->next;
        }

        void remove_last()
        {
            Node* temp = tail->next;

            while(temp->next != tail)
            {
                temp = temp->next;
            }

            temp->next = tail->next;
            tail = temp;
        }

        void remove_at(int pos)
        {
            Node* temp = tail->next;

            if(pos == 0)
            {
                remove_first();
            }
            else
            {
                for(int i=0 ; i<pos-1 ; i++)
                {
                    temp = temp->next;
                    if(temp == tail)
                    {
                        return;
                    }
                }

                if(temp->next == tail)
                {
                    remove_last();
                    return;
                }

                temp->next = temp->next->next;
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

            cout << endl;
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



    //====================To Test insert_head Function========
    // L1.insert_head(0);
    // L1.insert_head(1);
    // L1.insert_head(2);
    // L1.insert_head(3);
    // L1.display();


    //===================To test insert_at Function===========
    // L1.insert_head(0);
    // L1.insert_head(1);
    // L1.insert_head(2);
    // L1.insert_head(3);
    // L1.insert_at(200,2);
    // L1.display();


    //===================To Test all remove Functions=========
    // L1.insert_head(0);
    // L1.insert_head(1);
    // L1.insert_head(2);
    // L1.insert_head(3);
    // L1.insert_head(4);
    // L1.insert_head(5);
    // L1.display();
    // L1.remove_first();
    // L1.display();
    // L1.remove_last();
    // L1.display();
    // L1.remove_at(2);
    // L1.display();
    return 0;
}