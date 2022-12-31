// agar longest common palindromic sub-sequence nikalna hai toh string ko reverse kar k dusere string k jagah daal do!
#include<bits/stdc++.h>
using namespace std;
int f(string s,string t,int idx1,int idx2,vector<vector<int>>&dp){
    if(idx1<0||idx2<0) return 0;

if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
    int left=-1e9,right=-1e9;
    if(s[idx1]==t[idx2]){
        left=1+f(s,t,idx1-1,idx2-1,dp);
    }
    else{
        right=max(f(s,t,idx1-1,idx2,dp),f(s,t,idx1,idx2-1,dp));
    }
    return dp[idx1][idx2]= max(left,right);
    
}
int lcs(string s, string t)
{
    int idx1=s.length();
    int idx2=t.length();
    vector<vector<int>>dp(idx1+1,vector<int>(idx2+2,-1));
    return f(s,t,idx1-1,idx2-1,dp);
}
int main(){
string s,t;
cin>>s>>t;
cout<<lcs(s,t)<<endl;
return 0;
}
