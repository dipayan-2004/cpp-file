#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node{
    int data;
    struct Node* next;

};
struct Node* head=NULL;
struct Node* createNode(int item){
    struct Node* ptr;
    ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=item;
    ptr->next=NULL;
    return ptr;
}
void addBeg(int item){
    struct Node* curr=createNode(item);
    curr->next=head;
    head=curr;
    return;
}
void addEnd(int item){
    struct Node* curr=createNode(item);
    if(head==NULL){
        cout<<"empty list\n";
        return;
    }
    struct Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=curr;
    return;
}
void display(){
    
    if(head==NULL){
        cout<<"empty list\n";
        return;
    }
    struct Node* temp=head;
    while(temp!=NULL){
        cout<<" "<<temp->data;
        temp=temp->next;
    }
    return;
}
void delBeg(){
    if(head==NULL){
        cout<<"empty list\n";
        return;
    }
//     struct Node* temp=head;
//     head=head->next; 
//     free(temp);
// for this code if there is only one node present, head=head->next line returns segmentation fault.
if(head->next==NULL){
    free(head);
    head=NULL;          // this if condition is for one node.... there is no need to take a arbitary temp pointer..
    return;
}
struct Node* temp=head;
    head=head->next; 
    free(temp);
    return;
}
void delEnd(){
    if(head==NULL){
        cout<<"empty list\n";
        return;
    }
    struct Node* temp=head,*prev;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
}
void reverse(){
    struct Node* temp=head,*q,*r=NULL;
    while(temp!=NULL){
        q=temp;
        temp=temp->next;
        q->next=r;
        r=q;
    }
    head=r;
}
void del(int item){
    struct Node* temp=head,*prev;
    while(temp!=NULL&&temp->data!=item){
        prev=temp;
        temp=temp->next;
    }
    if(head==NULL){
        cout<<"empty list\n";
        return;
    }else if(temp==head){
        head=head->next;
        free(temp);
        return;
    }else if(temp==NULL){
        cout<<"item not found\n";
        return;
    }else{
        prev->next=temp->next;
        free(temp);
        return;
    }

}
int countNode(){
    if(head==NULL){
        
        return 0;
    }
    int count=0;
    struct Node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
int largest(){
    if(head==NULL){
        return 0;
    }
    int max=0;
    struct Node* temp=head;
    while(temp!=NULL){
        if(max<temp->data){
            max=temp->data;
        }
        temp=temp->next;
    }
    return max;
}
int search(int item){
    if(head==NULL){
        return 0;
    }
    struct Node* temp=head;
    while(temp!=NULL){
        if(temp->data==item){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}
int main(void){
    while (1)
    { int ch;
    cout<<"\nwrite what to do.\n1.display list\n2.add from beggining\n3.add from end\n4.delete from beggining\n5.delete from end\n6.delete a specific node\n7.reverse list\n8.search element\n9.no. of nodes\n10.largest number\n11.exit\n";
    cin>>ch;
    if(ch==11){
        break;
    } 
    switch(ch){
        case 1:{
            display();
            break;
        }
        case 2:{
            int item;
            cout<<"write the element of the node\n";
            cin>>item;
            addBeg(item);
            break;
        }
        case 3:{
            int item;
            cout<<"write the element of the node\n";
            cin>>item;
            addEnd(item);
            break;
        }
        case 4:{
            delBeg();
            break;
        }
        case 5:{
            delEnd();
            break;
        }
        case 6:{
           int item;
            cout<<"write the element to delete\n";
            cin>>item;
            del(item);
            break;
        }
        case 7:{
            reverse();
            break;
        }
        case 8:{
             int item;
            cout<<"write the element\n";
            cin>>item;
            if(search(item)){
                cout<<"item found\n";
            }else{
                cout<<"item not found\n";
            }
            break;
        }
        case 9:{
            cout<<"the no of nodes is "<<countNode()<<endl;
            break;
        }
        case 10:{
            cout<<"the largest no is "<<largest()<<endl;
            break;
        }
        
    }  
}
    

    return 0;
}
