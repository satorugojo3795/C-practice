#include<iostream>

using namespace std;

class node{

    /**
 * Represents a simple node in a linked list.
 *
 * Contains an integer data value and a pointer to the next node.
 */

    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

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
void insertAtTail(node* &head, int val){
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
}

void insertAthead(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    n->next = head;
    head = n;
}


/**
 * Displays the data of each node in a linked list.
 *
 * @param head A pointer to the head of the linked list.
 *
 * @return void
 *
 * @throws None
 */
void display(node* head){
    node* temp = head;  
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

/**
 * Searches for a key in a linked list.
 *
 * @param head A pointer to the head of the linked list.
 * @param key The key to search for.
 *
 * @return true if the key is found, false otherwise.
 *
 * @throws None
 */
bool search(node* head, int key){
    node* temp = head;
    while(temp!=NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main(){
    node *head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);
    insertAthead(head,0);
    display(head);
    cout<<search(head, 5);
    return 0;
}