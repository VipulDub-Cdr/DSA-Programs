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
Node* deleteHead(Node *head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node *prev = head;
    head = head->next;
    prev->next = NULL;
    head->back = NULL;
    delete prev;
    return head;

}
Node* deleteTail(Node *head){
    if(head->next==NULL || head==NULL){
        return NULL;
    }
    Node *tail = head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node *newTail = tail->back;
    newTail->next = NULL;
    delete tail;
    return head;
}
//without using stack
Node *reverseDLL(Node *head){
    if(head->next==NULL || head==NULL){
        return head;
    }
    Node* current = head;
    Node* prev = NULL;
    while(current!=NULL){
        prev = current->back;
        current->next = prev;
        current->back = current->next;
        current = current->back;
    }
    return prev->back;
}
int main() {
    Node* head   = new Node(10);
    Node* second = new Node(15,NULL,head);
    head->next = second;
    Node* third  = new Node(20,NULL,second);
    second->next = third;
    Node* fourth = new Node(25,NULL,third);
    third->next = fourth;
    head = insertHead(head,5);
    head = deleteHead(head);
    head = deleteTail(head);
    printDLL(head);
    return 0;
}