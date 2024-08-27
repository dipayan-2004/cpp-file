#include<iostream>
using namespace std;
#define max 5

int c_queue[max];
int rear= -1;
int front =-1;

int isFull(){
    return (rear+1)%max == front;
}
int isEmpty(){
    return rear==-1&& front ==-1;
}
int add(int data){
    if(isFull()){
        cout<<"the queue is full"<<endl;
        return 0;
    }
    // for initial addition
     if(isEmpty()){
        front=(front%max)+1;
        }
    rear = (rear+1)%max;
    c_queue[rear]=data;
    return 1;
}
int peak(){
     if(isEmpty()){
        cout<<"the queue is empty"<<endl;
        return 0;
    }
    return c_queue[front];
}
int remove(){
     if(isEmpty()){
        cout<<"the queue is empty"<<endl;
        return 0;
    }
    int result =c_queue[front];
    front = (front+1)%max; // just increasing the front....
    return result;

}

int main(){
    add(1);
    add(2);
    add(3);
    add(4);
    add(5);
    //  now if we add something it can't bcz the queue is full..
    add(6);
    cout<<front<<endl;
   cout<<rear<<endl;
   cout<<remove()<<endl;

   cout<<front<<endl;
   cout<<rear<<endl;
   cout<<remove()<<endl;

   cout<<front<<endl;
   cout<<rear<<endl;
   cout<<remove()<<endl;

   cout<<front<<endl;
   cout<<rear<<endl;
   cout<<remove()<<endl;

   cout<<front<<endl;
   cout<<rear<<endl;
   cout<<remove()<<endl;
   cout<<front<<endl;
   cout<<rear<<endl;
   

    // now if we add more values it will promt the que is full..
    // add(6);
    
    cout<<peak()<<endl;;
    // this will display the first inserted element => 1

    return 0;
}