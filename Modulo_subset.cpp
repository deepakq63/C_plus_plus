#include<bits/stdc++.h>
using namespace std;
int func(vector<int>&arr,int k){
    int n = arr.size();
    vector<int> freq(k+1,0);
  int sum = 0;
    for(auto & it: arr) freq[it%k]++;
    if(!(k&1)) freq[k/2]=min(freq[k/2],1);
    freq[0]=min(freq[0],1);
  sum = freq[0];
  for(int i=1;i<=k/2;i++) sum += max(freq[i],freq[k-i]);

   return sum;
}
int main(){
int n,k;
cin>>n>>k;
vector<int> arr(n);
for(int i=0;i<n;i++) cin>>arr[i];
cout<<func(arr,k)<<endl;
return 0;
}