#include <iostream>
using namespace std;

#define SIZE 5

class Deque {
private:
    int arr[SIZE];
    int front;
    int rear;
    int count;

public:
    Deque() {
        front = -1;
        rear = -1;
        count = 0;
    }

    // Check if the deque is full
    bool isFull() {
        return count == SIZE;
    }

    // Check if the deque is empty
    bool isEmpty() {
        return count == 0;
    }

    // Add an element at the front of the deque
    void addFront(int x) {
        if (isFull()) {
            cout << "Deque is full. Cannot add at the front.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + SIZE) % SIZE;
        }
        arr[front] = x;
        count++;
    }

    // Add an element at the rear of the deque
    void addRear(int x) {
        if (isFull()) {
            cout << "Deque is full. Cannot add at the rear.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = x;
        count++;
    }

    // Delete an element from the front of the deque
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the front.\n";
            return;
        }
        cout << "Deleted element from front: " << arr[front] << "\n";
        if (front == rear) {
            front = rear = -1; // Reset to initial state when the deque becomes empty
        } else {
            front = (front + 1) % SIZE;
        }
        count--;
    }

    // Delete an element from the rear of the deque
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from the rear.\n";
            return;
        }
        cout << "Deleted element from rear: " << arr[rear] << "\n";
        if (front == rear) {
            front = rear = -1; // Reset to initial state when the deque becomes empty
        } else {
            rear = (rear - 1 + SIZE) % SIZE;
        }
        count--;
    }

    // Display the elements in the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }
        cout << "Deque elements: ";
        int i = front;
        for (int j = 0; j < count; j++) {
            cout << arr[i] << " ";
            i = (i + 1) % SIZE;
        }
        cout << "\n";
    }
};

int main() {
    Deque dq;
    dq.addRear(1);
    dq.addRear(2);
    dq.addFront(3);
    dq.addFront(4);
    dq.display();
    dq.deleteFront();
    dq.display();
    dq.deleteRear();
    dq.display();
    dq.addRear(5);
    dq.addFront(6);
    dq.display();

    return 0;
}