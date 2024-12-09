#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int data1, Node* next1 = NULL){
            data = data1;
            next = next1;
        }
};
Node* insertHead(Node* head, int val){
    Node *temp = new Node(val,head);
    return temp;
}

Node* middleNode(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* hare = head;
    Node* Tort = head;
    while(hare!=NULL and hare->next!=NULL){
        hare = hare->next->next;
        Tort = Tort->next;
    }
    return Tort;
}
void printLL(Node* head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ->  ";
        temp = temp->next;
    }
}
int main() {
    Node *head = new Node(10);
    head = insertHead(head,20);
    head = insertHead(head,30);
    head = insertHead(head,40);
    head = insertHead(head,50);
    // printLL(head);
    Node* midNode = middleNode(head);
    cout<<midNode->data<<endl;
    return 0;
}