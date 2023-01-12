// To generate any element at row = r and col = c we can use the formula ^rC_c = r!/c!*(r-c)!

#include<bits/stdc++.h>
using namespace std;
  vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);
        for(int i=0;i<numRows;i++){
            ans[i].resize(i+1);
            ans[i][0]=1;
            ans[i][i]=1;
            for(int j=1;j<i;j++){
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
            }
        }
        return ans;
    }
int main(){
int n; 
cin>>n;
vector<vector<int>>ans=generate(n);
for(auto i: ans){
    for(auto j: i) cout<<j<<" ";
    cout<<endl;
}

return 0;
}