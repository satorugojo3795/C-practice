#include<iostream>
#include<stack>

using namespace std;

// 234. Palindrome Linked List
// Solved
// Easy
// Topics
// Companies
// Given the head of a singly linked list, return true if it is a 
// palindrome
//  or false otherwise.

 

// Example 1:


// Input: head = [1,2,2,1]
// Output: true
// Example 2:


// Input: head = [1,2]
// Output: false
 

// Constraints:

// The number of nodes in the list is in the range [1, 105].
// 0 <= Node.val <= 9
 

// Follow up: Could you do it in O(n) time and O(1) space?

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

bool palindrome(node* head){

    node* temp = head;
    node* temp2 = head;
    stack<int> st;
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }

    while(temp2!=NULL){
        if(temp2->data != st.top()){
            return false;
        }
        st.pop();
        temp2 = temp2->next;
    }
    return true;
}

int main(){
    node *head = NULL;
    insertAtTail(head,3);
    insertAtTail(head,2);
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    // insertAtTail(head,6);
    cout<<endl;
    display(head);
    cout<<palindrome(head);
    return 0;
}