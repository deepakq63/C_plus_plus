// The Lowest divisor of any no is always a Prime no.

#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
vector<int>v;
    if(n%2==0) v.push_back(2);
    while(n%2==0) n/=2;
for(int i=3;i*i<=sqrt(n);i+2){
    if(n%i==0) v.push_back(i);
    while(n%i==0){
        
        n/=i;
    }
}
if(n>2) v.push_back(n);
for(auto i: v) cout<<i<<" ";
cout<<endl;
return 0;
}
