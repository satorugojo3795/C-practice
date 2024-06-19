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

void deleteAtHead(node* &head){
    node *todelete = head;
    head = head->next;

    delete todelete;
    return;
}



void deleteNode(node* &head, int val){
    /**
     * Deletes a node with a specific value from a linked list.
     *
     * @param head A reference to the head of the linked list.
     * @param val The value of the node to be deleted.
     *
     * @return void
     *
     * @throws None
     */

    if(head == NULL){
        cout<<"empty list"<<endl;
        return;
    }
    if(head->next == NULL){
        deleteAtHead(head);
        return;
    }

    node *temp = head;
    while(temp->next->data!=val){
        temp = temp->next;
    }
    node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    return;
}

node* reverse(node* &head){
    node* prev = NULL;
    node* curr = head;
    node* nextptr;

    while(curr!=NULL){
        nextptr = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextptr;
    }
    return prev;
}

int main(){
    node *head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);
    // insertAthead(head,0);
    // display(head);
    // cout<<search(head, 5);
    // deleteNode(head, 3);
    // display(head);
    // deleteAtHead(head);
    // display(head);

    node* newHead = reverse(head);
    display(newHead);
    return 0;
}