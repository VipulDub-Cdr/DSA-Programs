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
//T.C - O(2N) and S.C - O(N)
Node* reverseLL1(Node *head){
    if(head==NULL or head->next==NULL){
        return head;
    }
    stack<int> stk;
    Node *temp = head;
    while(temp!=NULL){
        stk.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL){
        temp->data = stk.top();
        stk.pop();
        temp = temp->next;
    }
    return head;
}
//Without using stack
Node* reverseLL2(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* prev = NULL;
    Node* current = head;
    Node* front = current->next;
    while(current!=NULL){
        current->next = prev;
        prev = current;
        current = front;
        if(front!=NULL){
            front = front->next;
        }
    }
    return prev;
}

Node* reverseLL3(Node* head)
{
    if(head==NULL || head->next==NULL)
        return head;
    Node* newHead = reverseLL3(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

bool detectCycle(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast!=NULL and fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(slow==fast)
            return true;
    }
    return false;
}

Node* startingPoint1(Node* head){
    Node* ptr = head;
    unordered_map<Node*,int> umpp;
    while(ptr!=NULL and ptr->next!=NULL){
        if(umpp[ptr])
            return ptr;
        umpp[ptr] = 1;
        ptr = ptr->next;
    }
    return NULL;
}

//Optimized the solution by using tortoise and hare method
Node* startingPoint2(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast!=NULL and fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow)
            break;
    }
    slow = head;
    if(fast!=NULL){
        while(fast!=slow){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return fast;
}

void printLL(Node* head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ->  ";
        temp = temp->next;
    }
}
int main() {
    // Node *head = new Node(10);
    // head = insertHead(head,20);
    // head = insertHead(head,30);
    // head = insertHead(head,40);
    // head = insertHead(head,50);
    // printLL(head);
    // cout<<endl;
    
    // Node* midNode = middleNode(head);
    // cout<<midNode->data<<endl;

    // head = reverseLL1(head);
    // head = reverseLL2(head);
    // head = reverseLL3(head);
    // cout<<detectCycle(head);
    // printLL(head);

    //cycled LL with starting point Second Node with value 20
    Node* head = new Node(10,NULL);
    Node* second = new Node(20,NULL);
    head->next = second;
    Node* third = new Node(30,NULL);
    second->next = third;
    Node* fourth = new Node(40,NULL);
    third->next = fourth;
    fourth->next = second;

    cout<<startingPoint2(head)->data<<endl;
    return 0;
}