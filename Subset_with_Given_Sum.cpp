#include<bits/stdc++.h>
using namespace std;
bool f(vector<int>&v,int sum,int idx,vector<vector<int>>&dp){
    if(sum==0) return true;
    if(idx==0) return v[0]==sum;
    if(dp[idx][sum]!=-1) return dp[idx][sum];
    bool left=f(v,sum,idx-1,dp);
    bool right=false;
    if(sum>v[idx]) right=f(v,sum-v[idx],idx-1,dp);
    return dp[idx][sum]= left||right;
 
}
    bool isSubsetSum(vector<int>arr, int sum){
    
    vector<vector<int>> dp(101,vector<int>(1e5+1,-1));
       return f(arr,sum,arr.size()-1,dp);
    }
int main(){
int n; cin>>n;
vector<int>v(n);
for(int i=0;i<n;i++) cin>>v[i];
int sum; cin>>sum;
vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
if(f(v,sum,n-1,dp)) cout<<"YES"<<endl;
else cout<<"NO"<<endl;
return 0;
}