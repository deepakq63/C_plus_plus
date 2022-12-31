// minInsertion to make a string palindrome = length of the string - length of the longest palindromic sub-sequence
//because the for the rest of the characters we can reverse them and place them(insert)!

#include<bits/stdc++.h>
using namespace std;
int f(string &s,string &t,int a,int b,vector<vector<int>>&dp){
    if(a<0||b<0) return 0;
    if(dp[a][b]!=-1) return dp[a][b];
    int left=-1e9,right=-1e9;
    if(s[a]==t[b]) left=1+f(s,t,a-1,b-1,dp);
    else right=max(f(s,t,a-1,b,dp),f(s,t,a,b-1,dp));
    return dp[a][b]=max(left,right);
}
    int minInsertions(string s) {
        int n=s.length();
        string t=s;
        reverse(t.begin(),t.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int g=f(s,t,n-1,n-1,dp);
        return n-g;
    }
int main(){
string s;
cin>>s;
cout<<minInsertions(s)<<endl;
return 0;
}