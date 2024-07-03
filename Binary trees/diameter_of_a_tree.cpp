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
    
    int height(node* root){
        if(root == NULL){
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        return max(lh,rh)+1;
    }

    int diameter(node* root){
        if(root == NULL){
            return 0;
        }
        int ld = diameter(root->left);
        int rd = diameter(root->right);
        int lh = height(root->left);
        int rh = height(root->right);
        if(ld>rd && ld>lh+rh+1){
            return ld;
        }
        else if(rd>ld && rd>lh+rh+1){
            return rd;
        }
        else{
            return lh+rh+1;
        }
    }

    int diameter2(node* root, int* height){

        if(root == NULL){
            *height = 0;
            return 0;
        }

        int lh = 0, rh = 0;
        int ld = diameter2(root->left, &lh);
        int rd = diameter2(root->right, &rh);

        int currD = lh+rh+1;
        *height = max(lh,rh)+1;
        return max(currD,max(ld,rd));
        
    }
};

int main(){
    int nodes[] = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    binary_tree bt;
    node* root = bt.build_tree(nodes);
    cout<<endl<<root->data<<endl;
    bt.preorder(root);
    cout<<endl;
    cout<<bt.diameter(root);
    return 0;
}