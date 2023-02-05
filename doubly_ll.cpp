#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //Constructor
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL; 
    }
};

// prints the entire linked list  
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl; 
}

// gives length of llinked list 
int getLength(Node* head){
    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len; 
}

// insertion operations

void insertAtHead(Node* &head, int data){
    Node* temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void insertAtTail(Node* &tail, int data){
     Node* temp=new Node(data);
     
}

int main(){
   
    Node* node1= new Node(10);
    Node* head=node1;

    print(head);
    //cout<<getLength(head)<<endl;
    insertAtHead(head,11);
    print(head);
    insertAtHead(head,13);
    print(head);
    insertAtHead(head,8);
    print(head);
    //cout<<getLength(head)<<endl;

    return 0;
}