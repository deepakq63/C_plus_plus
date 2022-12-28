#include<bits/stdc++.h>
using namespace std;
void permutation(string s,int l,int r,vector<string>&ans){
    if(l==r) ans.push_back(s);
    for(int i=l;i<=r;i++){
        swap(s[i],s[l]);
        permutation(s,l+1,r,ans);
        swap(s[i],s[l]);
    }
}
int main(){
string s; cin>>s;
vector<string> ans;
permutation(s,0,s.length()-1,ans);
for(auto &it: ans) cout<<it<<endl;
return 0;
}