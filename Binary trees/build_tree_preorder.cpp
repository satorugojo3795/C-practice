#include<iostream>
#include<queue>

using namespace std;

class node{

    public:
    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;

    }
};

class binary_tree{
    int idx = -1;

    public:
    node* build_tree(int nodes[]){
        idx++;
        if(nodes[idx] == -1){
            return NULL;
        }
        node* newNode = new node(nodes[idx]);
        newNode->left = build_tree(nodes);
        newNode->right = build_tree(nodes);
        return newNode;
    }

    void preorder(node* root){
        if(root == NULL){
            // cout<<-1<<" ";
            return;
        }

        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
        return;
    }

    void inorder(node* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
        return;
    }
    void postorder(node* root){
        if(root == NULL){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
        return;
    }

    //level order travesal or breath first search
    void level_order(node* root){
        if(root == NULL){
            return;
        }

        queue<node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            node* n = q.front();
            q.pop();
            if(n!=NULL){
                cout<<n->data<<" ";
                if(n->left){
                    q.push(n->left);
                }
                if(n->right){
                    q.push(n->right);
                }

            }
            else if(!q.empty()){
                q.push(NULL);
            }
        }
    }

    int height(node* root){
        if(root == NULL){
            return 0;
        }

        int lh = height(root->left);
        int rh = height(root->right);
        return max(lh,rh) + 1;
    }

    int count(node* root){
        if(root == NULL){
            return 0;
        }

        int lc = count(root->left);
        int rc = count(root->right);
        return lc+rc+1;
    }

    int sum_of_nodes(node*root){
        if(root == NULL){
            return 0;
        }
        int ls = sum_of_nodes(root->left);
        int rs = sum_of_nodes(root->right);
        return ls+rs+root->data;
    }
    
};

int main(){
    int nodes[] = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    binary_tree bt;
    node* root = bt.build_tree(nodes);
    cout<<endl<<root->data<<endl;
    bt.preorder(root);
    cout<<endl;
    bt.inorder(root);
    cout<<endl;
    bt.postorder(root);
    cout<<endl;
    bt.level_order(root);
    cout<<endl;
    cout<<bt.height(root);
    cout<<endl;
    cout<<bt.count(root);
    cout<<endl;
    cout<<bt.sum_of_nodes(root);
    return 0;
}