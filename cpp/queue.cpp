#include<iostream>
using namespace std;
#define max 5
int queue[max];
int rear =-1;
int isFull(){
    return rear == max-1;
}
int isEmpty(){
    return rear==-1;
}
int add(int data){
    if(isFull()){
        cout<<"the queue is full"<<endl;
        return 0;
    }
    queue[++rear]=data;
    return 1;
}
int peak(){
     if(isEmpty()){
        cout<<"the queue is empty"<<endl;
        return 0;
    }
    return queue[0];
}
int remove(){
     if(isEmpty()){
        cout<<"the queue is empty"<<endl;
        return 0;
    }
    for(int i=0;i<rear;i++){
        queue[i]=queue[i+1];
    }
    rear--;
    return queue[rear];

}

int main(){
    add(1);
    add(2);
    add(3);
    add(4);
    add(5);

    // now if we add more values it will promt the que is full..
    add(6);
    
    cout<<peak()<<endl;;
    // this will display the first inserted element => 1

    return 0;
}