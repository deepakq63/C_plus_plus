#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
long long help(int x,int y){                 //T.C log(y);
    if(x==0) return 0;
    if(y==0) return 1;
    if(y==1) return x;
    long long ans = 1;
    if(!(y&1)){
        ans=help(x,y/2);
        ans*=ans;
        ans%=mod;
    }
    else{
        ans = help(x,y-1);
        ans*=x;
    }
    return ans%mod;
}
int main(){
int a,b;
cin>>a>>b;
cout<<help(a,b)<<endl;
return 0;
}