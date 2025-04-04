#include<iostream>
using namespace std;
#define max 5
      //  -----  we take stack size is 5  ------
      //  ----- if you want to change just change the macro statement  ------
int stack[max];
int top=-1;

int isFull(){return top==max-1;}
int isEmpty(){return top==-1;}
int peak(){return stack[top];}
void push(int data){
  if(isFull()){
    cout<<"the stack is already full nothing can be inserted...."<<endl;
    return;
  }
  stack[++top]=data;
}
int pop(){
  if(isEmpty()){
    printf("stack is empty");
    return -1;
  }
  return stack[top--];
}
void display(){
  for(int i=0;i<max;i++){
    cout<<" "<<stack[i];
  }
}
int main(){
  cout<<"write what to do.....\n 1. display \n 2. insert element \n 3. delete element \n 4. top element \n 5. empty check \n 6. stackfull check\n 7.exit"<<endl;

while(true){
  int n;
  cin>>n;
  if(n==7)break;

  switch(n){
    case 1:{
      display();
      break;
    }
    case 2:{
      cout<<"write the element to add"<<endl;;
      int number;
      cin>>number;
      push(number);
      break;
    }
    case 3:{
      if(pop()<0){
        break;
      }
      else{
        cout<<"successfully deleted"<<endl;;
      }
      break;
    }
    case 4:{
      cout<<"the top element is "<<peak()<<endl;
      break;
    }
    case 5:{
      if(isEmpty()){
        cout<<"stack is Empty..."<<endl;
      }
      break;
    }
    case 6:{
      if(isFull()){
        cout<<"stack is Full..."<<endl;;
      }
      break;
    }
    

  }

}
cout<<""<<endl;
return 0;
}
