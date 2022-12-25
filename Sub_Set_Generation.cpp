#include<bits/stdc++.h>
using namespace std;
// void print(string s,int n){
// if(n==0) return;
// int sub_ct=1<<n;
// for(int i=0;i<sub_ct;i++){
// for(int j=0;j<n;j++){
//     if((i&(1<<j))!=0) cout<<s[j];
// }
// cout<<endl;
// }
// }
void rec_print(string s,int n,vector<char>&temp,vector<vector<char>>&ans,int j){
    ans.push_back(temp);
    for(int i=j;i<n;i++){
     temp.push_back(s[i]);
     rec_print(s,n,temp,ans,i+1);
     temp.pop_back();
    }
}


int main(){
string s;
cin>>s;
vector<vector<char>> ans;
vector<char> temp;
int n=s.length();
rec_print(s,n,temp,ans,0);
for(auto i: ans){
    for(auto j: i) cout<<j;
    cout<<endl;
}
return 0;
}