class Solution {
public:
int pathsum(TreeNode* root,int &maxi){
    if(root==NULL) return 0;
    int left=max(0,pathsum(root->left,maxi));
    int right=max(0,pathsum(root->right,maxi));
    maxi=max(maxi,left+right+root->val);
    return max(left,right)+root->val;
}
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int maxi=-1e9;
        int f=pathsum(root,maxi);
        return maxi;
        
    }
};