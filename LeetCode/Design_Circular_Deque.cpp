/*
 * Problem Name: Design Circular Deque
 * Problem Link: https://leetcode.com/problems/design-circular-deque/
 */

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
class MyCircularDeque {
private:
    vector<int> deque;
    int front;
    int back;
    int size;
    int max_size;

public:
    MyCircularDeque(int k) {
        front = size = 0;
        back = -1;
        max_size = k;
        deque = vector<int>(k, -1);
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + max_size) % max_size;
        deque[front] = value;
        size++;
        if (back == -1) back = front;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        back = (back + 1) % max_size;
        deque[back] = value;
        size++;
        if (front == -1) front = back;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        deque[front] = -1;
        front = (front + 1) % max_size;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        deque[back] = -1;
        back = (back - 1 + max_size) % max_size;
        size--;
        return true;
    }

    int getFront() {
        return deque[front];
    }

    int getRear() {
        return deque[back];
    }

    bool isEmpty() {
        return !size;
    }

    bool isFull() {
        return size == max_size;
    }
};

