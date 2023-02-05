#include<iostream>
//#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    
    //destructor
    ~Node(){
        int value=this->data;
        //memory free
        if(this->next !=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data: "<<value<<endl;
    }
};

void InsertAtHead(Node* &head, int data){
    //create new Node
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}

void InsertAtTail(Node* &tail,int data){
    Node * temp=new Node(data);
    tail->next=temp; 
    tail=temp;
}

void InsertAtPosition(Node* &head, Node* &tail, int pos, int data){
    //to insert at 1st position 
    if(pos==1){
        InsertAtHead(head,data);
        return;
    }
    
    //for traversal
    Node *temp=head;
    int count=1;
    
    //if node is inserted at last we have to update tail also 
    if(temp->next==NULL){
       InsertAtTail(tail,data);
       return;
    }
    
    //we have to traverse till prev node i.e n-1
    while(count<pos-1){
        temp=temp->next;
        count++;
    }
    //create a new Node
    Node* insertion_node=new Node(data);
    insertion_node->next=temp->next;
    temp->next=insertion_node; 
    
    
}

void DeleteNode(Node* &head, int pos,Node* &tail){
    //if we are deleting the first node 
    if(pos==1){
        Node* temp=head;
        head=head->next;
        //memory free (we'll be deleting using a destructor as memory has been allocated in heap)

        temp->next=NULL;  //so that temp does not point to any data 
        delete temp; 
    }
    //deleting any middle node or last node 
    else{
        Node* curr=head;
        Node* prev=NULL;
        
        int count=1;
        
        
        while(count<pos){
            prev=curr;
            curr=curr->next;
            count++;
        }
        
        //in case of last node we need to update tail
        if(curr->next==NULL){
            tail=prev;
        }
        prev->next=curr->next;
        curr->next=NULL;  // so that current does not point to any data 
        delete curr;
    }
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main()
{   
    //created new node 
    Node *node1=new Node(5);
    //head pointed to node1
    Node* head=node1;
    Node* tail=node1;
    print(head);
    
    /*InsertAtHead(head,10);
    InsertAtHead(head,15);
    InsertAtHead(head,20);*/
    
    InsertAtTail(tail,10);
    InsertAtTail(tail,15);
    //InsertAtTail(tail,20);
    print(head);
    InsertAtPosition(head,tail,3,12);
    print(head);
    InsertAtPosition(head,tail,1,2);
    print(head);
    
    //cout<<"head "<<head->data<<endl;
    //cout<<"tail "<<tail->data<<endl;÷
    
    DeleteNode(head,3,tail);
    print(head);
    
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    
    
    return 0;
}


