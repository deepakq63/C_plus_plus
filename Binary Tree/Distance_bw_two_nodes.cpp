
class Solution{
    public:
    int solve(Node* root,int val){
        if(root==NULL) return 0;
        if(root->data==val) return 1;
        int a=solve(root->left,val);
        int b=solve(root->right,val);
        if(!a and !b) return 0;
        return a+b+1;
    }
    Node* lca(Node * root,int a,int b){
        if(root==NULL) return root;
        if(root->data==a||root->data==b) return root;
        Node* left=lca(root->left,a,b);
        Node* right=lca(root->right,a,b);
        if(left and right) return root;
        if(left) return left;
        return right;
        
    }
    int findDist(Node* root, int a, int b) {
      Node* l=lca(root,a,b);
      int x=solve(l,a);
      int y=solve(l,b);
      return x+y-2;
    }
};
