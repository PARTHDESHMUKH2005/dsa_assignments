#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int front, rear;
    int arr[SIZE];

public:
    CircularQueue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == (rear + 1) % SIZE);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % SIZE;
        arr[rear] = x;
        cout << x << " enqueued.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << arr[front] << " dequeued.\n";
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, x;
    do {
        cout << "\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter element: "; cin >> x; q.enqueue(x); break;
            case 2: q.dequeue(); break;
            case 3: q.peek(); break;
            case 4: q.display(); break;
            case 5: break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 5);
    return 0;
}
