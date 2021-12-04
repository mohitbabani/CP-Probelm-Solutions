#include<bits/stdc++.h>

class MyCircularQueue {
public:
    int front=0,rear=0,count=0;
    vector<int> arr;
    int k;
    MyCircularQueue(int k) {
        this->k=k;
        arr.resize(k,-1);
    }
    
    bool enQueue(int value) {
        if(count==k)return false;
        arr[rear] = value;
        rear = (rear+1)%k;
        count++;
        return true;
    }
    
    bool deQueue() {
        if(count==0)
            return false;
        arr[front]=-1;
        front = (front+1)%k;
        count--;
        return true;
    }
    
    int Front() {
        return arr[front];
    }
    
    int Rear() {
        return arr[(rear-1+k)%k];
    }
    
    bool isEmpty() {
        return count==0;
    }
    
    bool isFull() {
        return count==k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */