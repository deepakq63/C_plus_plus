class Solution {
public:
int h(TreeNode* root,int &d){
    if(root==NULL) return 0;
    int a=h(root->left,d);
    int b=h(root->right,d);
    d=max(d,a+b);
    return max(a,b)+1;
}
    int diameterOfBinaryTree(TreeNode* root) {
       if(root==NULL) return 0;
       int d=0;
     int f=h(root,d);
     return d;
    }
};