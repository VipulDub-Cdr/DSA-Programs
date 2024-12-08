#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* back;
        Node(int data1,Node* next1 = NULL, Node* back1 = NULL){
            data = data1;
            next = next1;
            back = back1;
        }
};
void printDLL(Node *head){
    Node *temp = head;
    while(temp->next!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    while(temp->back!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->back;
    }
    cout<<temp->data<<endl;
}
Node* insertHead(Node *head,int val){
    //here we update head by ourself rather than handling it in the function
    Node *temp = new Node(val,head);
    temp->back = NULL;
    return temp;
}
Node* insertTail(Node *head,int val){
    //here the only case in which we have to update the head is when Linked List is empty
    Node *newNode = new Node(30);
    if(head==NULL){
        return newNode;
    }
    Node* tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->back = tail;
    return head;
}
int main() {
    //hello
    Node* head   = new Node(10);
    Node* second = new Node(15,NULL,head);
    head->next = second;
    Node* third  = new Node(20,NULL,second);
    second->next = third;
    Node* fourth = new Node(25,NULL,third);
    third->next = fourth;
    head = insertHead(head,30);
    printDLL(head);
    return 0;
}