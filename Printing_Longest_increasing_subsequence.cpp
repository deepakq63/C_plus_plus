#include<bits/stdc++.h>
using namespace std;
   vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
       vector<int>dp(n+1,1);
       int maxi=0;
       int last_ind=0;
       vector<int>hash(n);
       for(int i=0;i<n;i++){
           hash[i]=i;
           for(int j=0;j<i;j++){
               if(arr[i]>arr[j]&&((1+dp[j])>dp[i])){
               dp[i]=1+dp[j];
               hash[i]=j;
               }
           }
         if(maxi<dp[i]){
             last_ind=i;
             maxi=dp[i];
         }
       }
       vector<int>lis;
       lis.push_back(arr[last_ind]);
    
       while(hash[last_ind]!=last_ind){
           last_ind=hash[last_ind];
           lis.push_back(arr[last_ind]);
       }
       reverse(lis.begin(),lis.end());
       return lis;
       
    }
int main(){
int n;
cin>>n;
vector<int> v(n);
for(int i=0;i<n;i++) cin>>v[i];
vector<int>temp=longestIncreasingSubsequence(n,v);
for(auto i: temp) cout<<i<<" ";
cout<<endl;

return 0;
}