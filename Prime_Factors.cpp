// The Lowest divisor of any no is always a Prime no.

#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
vector<int>v;
for(int i=2;i*i<=n;i++){
    while(n%i==0){
        v.push_back(i);
        n/=i;
    }
}
if(n>1) v.push_back(n);
for(auto i: v) cout<<i<<" ";
cout<<endl;
return 0;
}