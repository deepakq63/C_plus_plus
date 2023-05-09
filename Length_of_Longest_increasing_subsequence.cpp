#include<bits/stdc++.h>                     // Also has a Binary Search method for this 
using namespace std;
int f(vector<int>&v,int idx,int prev,vector<vector<int>>&dp){
    if(idx==v.size()) return 0;
    if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
 
  int  l=0+f(v,idx+1,prev,dp);
    if(prev==-1||v[idx]>v[prev]){
      
        l=max(l,1+f(v,idx+1,idx,dp));
    }
    return dp[idx][prev+1]=l;
}
int lis(vector<int>&nums){                                //O(N^2)
int n=nums.size();
  vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(nums,0,-1,dp);
}
    int lengthOfLIS(vector<int>& nums) {                 //O(N^2)
        int n=nums.size();
      
           vector<int>dp(n+1,1);
    int maxi=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
        maxi=max(maxi,dp[i]);
    }
    return maxi;
    }
int main(){
int n;
cin>>n;
vector<int>v(n);
for(int i=0;i<n;i++) cin>>v[i];
cout<<lengthOfLIS(v)<<endl;
return 0;
}
