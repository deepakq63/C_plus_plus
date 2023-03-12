#include<bits/stdc++.h>
using namespace std;
class data{
    public: 
    int val,apos,vpos;
    data(int v,int ap,int vp){
        val=v;
        apos=ap;
        vpos=vp;
    }
};
struct mycomp{
    bool operator()(data&d1,data&d2){
        return d1.val>d2.val;
    }
};
   vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
  priority_queue<data,vector<data>,mycomp> pq;
  for(int i=0;i<k;i++){
      data d(arr[i][0],i,0);
      pq.push(d);
  }
  vector<int> ans;
  while(!pq.empty()){
      data curr = pq.top();
      pq.pop();
      ans.push_back(curr.val);
      int ap=curr.apos;
      int vp=curr.vpos;
      if(vp+1<arr[ap].size()){
          data d(arr[ap][vp+1],ap,vp+1);
          pq.push(d);
      }
      
  }
  return ans;
      
    }
int main(){
    int k; 
    cin>>k;
    vector<vector<int>> arr(k,vector<int>(k));
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            cin>>arr[i][j];
        }
    }
    vector<int> ans=mergeKArrays(arr,k);
    for(auto& it: ans){
        cout<<it<<"  ";
    }
    cout<<endl;

return 0;
}