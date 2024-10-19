#include <iostream>
using namespace std;

class CircularQueue {
    int *queue;
    int front, rear, size;
    int capacity;

public:
    CircularQueue(int n) {
        capacity = n;
        queue = new int[n];
        front = rear = -1;
        size = 0;
    }

    void enqueue(int x) {
        if (size == capacity) {
            cout << "Queue is full. Cannot enqueue " << x << endl;
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % capacity;
        queue[rear] = x;
        size++;
        cout << x << " enqueued to the queue" << endl;
    }

    int dequeue() {
        if (size == 0) {
            cout << "Queue is empty. Cannot dequeue" << endl;
            return -1;
        }
        int result = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        cout << result << " dequeued from the queue" << endl;
        return result;
    }
};

int main() {
    int n, q;
    cout << "Enter the size of the Circular Queue: ";
    cin >> n;
    CircularQueue cq(n);

    cout << "Enter the number of queries: ";
    cin >> q;

    for (int i = 0; i < q; i++) {
        int type;
        cout << "\nChoose an operation:\n1. Enqueue\n2. Dequeue\nEnter choice: ";
        cin >> type;
        if (type == 1) {
            int x;
            cout << "Enter the element to enqueue: ";
            cin >> x;
            cq.enqueue(x);
        } else if (type == 2) {
            cq.dequeue();
        } else {
            cout << "Invalid operation. Please enter 1 for Enqueue or 2 for Dequeue." << endl;
        }
    }

    cout << "prepared by 23CE140 Prince" << endl;

    return 0;
}
