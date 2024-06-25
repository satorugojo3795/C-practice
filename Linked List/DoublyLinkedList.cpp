#include<iostream>

using namespace std;

class node{

    public:
    int data;
    node* prev;
    node* next;

    node(int val){
        data = val;
        next = NULL;
        prev = NULL;

    }
};


void insertAtTail(node* &head, int val){
    /**
     * Inserts a new node at the end of a linked list.
     *
     * @param head A reference to the head of the linked list.
     * @param val The value to be inserted.
     *
     * @return void
     *
     * @throws None
     */
    node* n = new node(val);

    if(head == NULL){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void insertAthead(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    n->next = head;
    n->prev = NULL;
    head = n;
}

void display(node* head){
    node* temp = head;  
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}



int main(){
    node *head = NULL;
    insertAtTail(head,3);
    insertAtTail(head,2);
    insertAtTail(head,1);
    insertAtTail(head,5);
    insertAtTail(head,4);
    // insertAtTail(head,6);
    display(head);
    return 0;
}