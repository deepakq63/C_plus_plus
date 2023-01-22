class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int a=maxDepth(root->left);
        int b=maxDepth(root->right);
        return max(a,b)+1;
    }
};