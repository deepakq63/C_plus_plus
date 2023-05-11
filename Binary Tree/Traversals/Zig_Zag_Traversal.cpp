class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> ans;
    	if(root==NULL) return ans;
    	bool leftToright=true;
    	queue<Node*> q;
    	q.push(root);
    	while(!q.empty()){
    	    int size=q.size();
    	    vector<int> temp(size);
    	    for(int i=0;i<size;i++){
    	        int index=leftToright? i:size-i-1;
    	        Node* hello=q.front();
    	        temp[index]=hello->data;
    	        q.pop();
    	        if(hello->left) q.push(hello->left);
    	        if(hello->right) q.push(hello->right);
    	    }
    	    leftToright=!leftToright;
    	    for(auto i:temp)
    	    ans.push_back(i);
    	    
    	}
    	return ans;
    }
};