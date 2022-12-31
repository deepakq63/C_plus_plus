#include<bits/stdc++.h>
using namespace std;
 int longestCommonSubstr (string s1, string s2, int n, int m)
    {
      vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
     for(int i=0;i<=n;i++) dp[i][0]=0;
     for(int i=0;i<=m;i++) dp[0][i]=0;
     int mi=0;
     for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
             if(s1[i-1]==s2[j-1]){
                 dp[i][j]=1+dp[i-1][j-1];
                 mi=max(mi,dp[i][j]);
             }
             else 
             dp[i][j]=0;
         }
     }
    
     return mi;
    }
int main(){
string s,t;
cin>>s>>t;
cout<<longestCommonSubstr(s,t,s.size(),t.size())<<endl;
return 0;
}