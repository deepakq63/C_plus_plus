#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int>&arr, int N, int i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
  
    
    if (l < N && arr[l] > arr[largest])
        largest = l;
  
    
    if (r < N && arr[r] > arr[largest])
        largest = r;
  
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
  
       
        heapify(arr, N, largest);
    }
}
    void makeHeap(vector<int> &arr, int n){
   int idx=n/2-1;
   for(int i=idx;i>=0;i--)
   heapify(arr,n,i);
   return ;
    }
int main(){
int n;
cin>>n;
vector<int>arr(n);
for(int i=0;i<n;i++) cin>>arr[i];
makeHeap(arr,n);
for(auto i: arr) cout<<i<<" ";
cout<<endl;

return 0;
}