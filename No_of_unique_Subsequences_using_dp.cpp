#include<bits/stdc++.h>
using namespace std;
int uniqueSubsequence(string&s){
    int n=s.size();
    vector<int>dp(n+1,0);// for storing no of sub sequence up to that index
    unordered_map<char,int>mp;
    dp[0]=1; //  because there is a sub sequence "";
    for(int i=1;i<=n;i++){
        dp[i]=2*dp[i-1];// beacuse next no. of sub sequence is 2*previous one
        if(mp.find(s[i-1])!=mp.end()){
            dp[i]-=mp[s[i-1]];//beacuse if the char repeat than no. of unique sub sequence will have to be deducted by no of sub sequence before the occurace of the char.
        }
        mp[s[i-1]]=dp[i-1];
    }
    return dp[n];
}
int main(){
string s;
cin>>s;
cout<<uniqueSubsequence(s)<<endl;
return 0;
}