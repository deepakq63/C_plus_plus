#include<bits/stdc++.h>
using namespace std;
long long int m=1e9+7;

int findWaysUtil(int ind, int target, int * arr, vector<vector<int>> &dp){
  if(ind==-1){
     if(target==0) return 1;
     return 0;
  }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = findWaysUtil(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = findWaysUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= (notTaken + taken)%m;
}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
	    return findWaysUtil(n-1,sum,arr,dp);
      
	}
	  
int main(){
int n;
cin>>n;
int arr[n];
 for(int i=0;i<n;i++) cin>>arr[i];
 int sum;
 cin>>sum;
 cout<<perfectSum(arr,n,sum)<<endl;
return 0;
}