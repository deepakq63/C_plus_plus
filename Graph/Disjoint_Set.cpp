#include<bits/stdc++.h>
using namespace std;
class Disjoint{
    private: 
    vector<int>rank,parent;
public:
Disjoint(int n){
    rank.resize(n+1,0);
    parent.resize(n+1);
    for(int i=0;i<=n;i++) parent[i]=i;
}
int findParent(int node){                  //Ultimate Parent 
    if(node==parent[node]) return node;
    return parent[node]=findParent(parent[node]);
}
void UnionByrank(int u,int v){
    int ulp_u=findParent(u);
    int ulp_v=findParent(v);
    if(rank[ulp_u]>rank[ulp_v]){
     parent[ulp_v]=parent[ulp_u];
    }
    else if(rank[ulp_u]<rank[ulp_v]){
        parent[ulp_u]=parent[ulp_v];
    }
    else{
        parent[ulp_u]=parent[ulp_v];
        rank[ulp_u]++;
    }
}
};
int main(){
 Disjoint ds(7);
 ds.UnionByrank(1,2);
  ds.UnionByrank(2,3);
   ds.UnionByrank(4,5);
    ds.UnionByrank(6,7);
     ds.UnionByrank(5,6);
    //  check if 3 and 7 are in same component or not 
    if(ds.findParent(3)==ds.findParent(7)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
      ds.UnionByrank(3,7);
         //  check if 3 and 7 are in same component or not 
    if(ds.findParent(3)==ds.findParent(7)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
return 0;
}