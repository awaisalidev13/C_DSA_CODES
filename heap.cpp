#include <iostream>
using namespace std;


void swap(int&a , int&b)
{
    int temp = a;
    a = b;
    b = temp;
}

struct MaxHeap{
    int* arr;
    int size;
    int capacity;

    MaxHeap(int cap)
    {
        arr = new int[cap];
        capacity = cap;
        size = 0;
    }
    ~MaxHeap()
    {
        delete[] arr;
        arr = nullptr;
    }

    int parent(int index)
    {
        return (index-1)/2;
    }
    
    int left(int index)
    {
        return (2*index+1);
    }

    int right(int index)
    {
        return (2*index+2);
    }

    void insert(int value)
    {
        if(size == capacity)
        {
            cout << "Size is full cannot insert! " << endl;
            return;
        }

        int i = size;
        arr[i] = value;
        size++;

        while(i>0 && arr[i] > arr[parent(i)])
        {
            swap(arr[i] , arr[parent(i)]);
            i = parent(i);
        }
    }

    int deleteRoot()
    {
        if(size == 0)
        {
            cout << "The heap is empty. " << endl;
            return -1;
        }
        int root = arr[0];
        arr[0] = arr[size-1];
        
        size--;

        int i=0;
        while(true)
        {
            int largest = i;
            int l = left(i);
            int r = right(i);

            if(l < size && arr[l] > arr[largest]) largest = l;
            if(r < size && arr[r] > arr[largest]) largest = r;

            if(largest == i) break;         

            swap(arr[i], arr[largest]);
            i = largest;
        }

        return root;
    }

    void display()
    {
        for(int i=0 ; i<size ; i++)
        {
            cout << arr[i];
            if(i != size-1)
            {
                cout << " - ";
            }
        }
        cout << endl;
    }
};

int main()
{
    cout << "Test 1" << endl;
    {
        MaxHeap h(100);
        int vals[] = {10, 20, 15, 30, 40};
        for(int v : vals) h.insert(v);
        cout << "Before:  "; h.display();
        cout << "Deleted: " << h.deleteRoot() << endl;
        cout << "After:   "; h.display();
    }

    cout << "\nTest 2 (sift down picks the RIGHT child)" << endl;
    {
        MaxHeap h(100);
        int vals[] = {10, 20, 15, 30, 40, 5};
        for(int v : vals) h.insert(v);
        cout << "Before:  "; h.display();
        cout << "Deleted: " << h.deleteRoot() << endl;
        cout << "After:   "; h.display();
    }

    cout << "\nTest 3 (node with only a left child)" << endl;
    {
        MaxHeap h(100);
        int vals[] = {10, 20, 15, 30};
        for(int v : vals) h.insert(v);
        cout << "Before:  "; h.display();
        cout << "Deleted: " << h.deleteRoot() << endl;
        cout << "After:   "; h.display();
    }

    cout << "\nTest 4 (delete until empty, then once more)" << endl;
    {
        MaxHeap h(100);
        h.insert(10); h.insert(20); h.insert(15);
        cout << "Before:  "; h.display();
        cout << "Deleted: " << h.deleteRoot() << endl;
        cout << "Deleted: " << h.deleteRoot() << endl;
        cout << "Deleted: " << h.deleteRoot() << endl;
        h.deleteRoot();   // heap is empty now
    }

    cout << "\nTest 5 (duplicates)" << endl;
    {
        MaxHeap h(100);
        h.insert(20); h.insert(20); h.insert(10);
        cout << "Before:  "; h.display();
        cout << "Deleted: " << h.deleteRoot() << endl;
        cout << "After:   "; h.display();
    }

    return 0;
}