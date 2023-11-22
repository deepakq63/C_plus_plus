class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        int n = nums.size();
        int m = 0;
        for(int i=0;i<n;i++){
            m = max(m,(int)nums[i].size());
        }
        vector<vector<int>>temp(n+m);
        for(int i=0;i<n;i++){
            for(int j=0;j<nums[i].size();j++){
                temp[i+j].push_back(nums[i][j]);
            }
        }
        for(int i=0;i<n+m;i++) reverse(temp[i].begin(),temp[i].end());
          for(int i=0;i<n+m;i++){
              for(int j=0;j<temp[i].size();j++){
                  ans.push_back(temp[i][j]);
              }
          }
          return ans;
    }
};