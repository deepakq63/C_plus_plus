
class Solution
{
    public:
 
    Node* lca(Node* root ,int n1 ,int n2 )
    {
      if(root==NULL) return root;
      if(root->data==n1||root->data==n2) return root;
      Node * left=lca(root->left,n1,n2);
      Node * right=lca(root->right,n1,n2);
      if(left and right) return root;
      if(left) return left;
      return right;
    }
};
