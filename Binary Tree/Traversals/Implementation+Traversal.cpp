/*                                                            1
                                                            /   \
                                                           3     5
                                                         /   \  /
                                                        7    11 17                                                                                                     */

#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
node* buildTree(node* root){
    // cout<<"Enter the data for the node"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1)
    return NULL;
    // cout<<"Enter the data for left node of "<<data<<endl;
    root->left=buildTree(root->left);
    // cout<<"Enter the data for the right node of the "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
    
}
void levelOrder(node* root){
    if(root==NULL) return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        cout<<temp->data<<"     ";
        if(q.empty()) cout<<endl;
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}
int inorderTraversal(node* root){
    if(root==NULL)
    return 0;
    int sum=0;
   int a= inorderTraversal(root->left);
    
 int b=   inorderTraversal(root->right);
 
 
sum+=a+b;
    return sum;
}
void preorderTraversal(node*root){
    if(root==NULL)
    return;
    cout<<root->data<<"     ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main(){
    node*root=NULL;
    root=buildTree(root);
    // levelOrder(root);
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// int ans=inorderTraversal(root);
// cout<<ans<<endl;
levelOrder(root);


return 0;
}