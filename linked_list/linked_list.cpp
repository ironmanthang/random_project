#include <iostream>
#include <stack>
using namespace std;
struct node{
    int data;
    node* next=nullptr;
};
void add_begin(node*& head,int var){
    node * newnode=new node;
    newnode->data=var;
    newnode->next=head;
    head=newnode;
}

void add_end(node*& head,int var){
    node* temp=head;
    node* newnode= new node;
    newnode->data=var;
    if(head==nullptr){
        head=newnode;
    }
    else{
    while(temp->next!=nullptr){
        temp=temp->next;
    }temp->next=newnode;
    }
}
void add_index(node*& head,int var,int index){
    node* newnode=new node;
    node* temp=head;
    newnode->data=var;
    if(head==nullptr){
        head=newnode;
    }else if(index==0){
        newnode->next=head;
        head=newnode;
    }else{
        node* ptr=head;
        int count=0;
        while (ptr!=nullptr)
        {
            ptr=ptr->next;
            count++;
        }
        if(count<index){
            cout<<"index out of range"<<endl;
            return;
        }
        for(int i=1;i<index;i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void display(node* head){
    int i=1;
    if(head==nullptr){
        cout<<"empty list";
    }
    else{
    while(head!=nullptr){
        cout<<"node "<<i<<": "<<head->data<<endl;
        head=head->next;
        i++;
    }
    }
}
int main() { 
    node*head=nullptr;
    add_end(head,1);
    add_end(head,2);
    add_end(head,3);
    add_index(head,50,4);
    display(head);

return 0;
}
