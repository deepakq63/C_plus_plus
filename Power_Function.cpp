//Time complexity for this is O(log(n)) this will also give the correct solution for -ve value of n
//pow function is also efficient but lets say if you have to do modulo or any other stuff then you can use this function

#include<bits/stdc++.h>
using namespace std;
double myPow(double x, int n) {
        long long g=n;
     bool flag=false;
     if(g<0){
         g=-g;
         flag=true;
     }
       if(n==0) return 1;
       double ans=myPow(x,g/2);
       ans*=ans;
       if(g%2) ans*=x;
    if(flag) return (double)1/ans;
       return ans; 
    }
int main(){
double x;
int n;
cin>>x>>n;
cout<<myPow(x,n)<<endl;
return 0;
}