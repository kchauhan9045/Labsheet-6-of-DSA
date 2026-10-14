#include <iostream>
using namespace std;

#define MAX 5

class Queue {
    int q[MAX];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    void enqueue(int value) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (front == -1)
            front = 0;
        q[++rear] = value;
        cout << value << " inserted." << endl;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        cout << q[front] << " deleted." << endl;
        front++;
        if (front > rear)
            front = rear = -1;
    }

    void peek() {
        if (front == -1)
            cout << "Queue is Empty!" << endl;
        else
            cout << "Front element: " << q[front] << endl;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
            cout << q[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- QUEUE MENU ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n";
        cout << "4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "Program terminated." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}