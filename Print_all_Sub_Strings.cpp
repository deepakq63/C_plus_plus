#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
cin>>s;
int n=s.size();
for(int i=0;i<n-1;i++){
    for(int j=1;j<=n-i;j++){
       cout<<s.substr(i,j)<<endl;
    }
}
return 0;
}
// O(n^3) T.C
