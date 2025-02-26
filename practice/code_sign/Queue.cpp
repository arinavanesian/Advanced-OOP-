#include <iostream>
using namespace std; 

class Queue { 
    int size; 
    int* queue;  
    static const int CAPACITY = 100;  

public:
    Queue() {
        size = 0;
        queue = new int[CAPACITY];
    }
    
    ~Queue() {  
        delete[] queue;
    }

    void remove() { 
        if (size == 0) { 
            cout << "Queue is empty" << endl; 
            return; 
        } 
        for (int i = 0; i < size - 1; i++) { 
            queue[i] = queue[i + 1]; 
        } 
        size--; 
    } 

    void print() { 
        if (size == 0) { 
            cout << "Queue is empty" << endl; 
            return; 
        } 
        for (int i = 0; i < size; i++) { 
            cout << queue[i] << " <- ";
        } 
        cout << endl;
    }

    void add(int num) { 
        if (size >= CAPACITY) {  
            cout << "Queue is full!" << endl;
            return;
        }
        
        queue[size] = num;  // Insert at the back (corrected)
        size++;  
    }
}; 

int main() { 
    Queue q; 
    q.add(42); q.add(2); q.add(8); q.add(1); 
    q.print();
    q.remove(); 
    q.add(128); 
    q.print(); 
    q.remove(); 
    q.remove(); 
    q.print(); 

    return 0; 
}

