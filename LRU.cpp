#include<bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
class node{
public:
int key,val;
node* next;
node* prev;
node(int key_,int val_){
    key = key_;
    val = val_;
}
};
node* head = new node(-1,-1);
node* tail = new node(-1,-1);
int cap;
unordered_map<int,node*> mp;
LRUCache(int capacity){
    cap = capacity;
    head->next = tail;
    tail->prev = head;
}
void addNode(node* newnode) {
    node* temp = head->next;
    newnode->next = temp;
    newnode->prev = head;
    head->next = newnode;
    temp->prev = newnode;

    if (temp != tail) {
        temp->prev = newnode;
    }
}

void deleteNode(node* delnode){
    node* next = delnode->next;
    node* prev = delnode->prev;
    prev->next = next;
    next->prev = prev;

}
int getKey(int key_) {
    if (mp.find(key_) != mp.end()) {
        node* res = mp[key_];
        mp.erase(key_);
        int val = res->val;
        deleteNode(res);
        addNode(res);
        mp[key_] = head->next;
        return val;
    }

    return -1;
}

void putKey(int key_,int val_){
    if(mp.find(key_)!=mp.end()){
        node* exist = mp[key_];
        mp.erase(key_);
        deleteNode(exist);
       
        
        
    }
   if(mp.size()==cap){
    node* delnode = tail->prev;
    int k = delnode->key;
    mp.erase(k);
    deleteNode(delnode);
  
   }
   node* n = new node(key_,val_);
   addNode(n);
   mp[key_]=head->next;
}
};

int main(){
LRUCache * obj = new LRUCache(2);
  obj->putKey(1,10);
  cout<<obj->getKey(1)<<endl;
  obj->putKey(2,20);
  obj->putKey(3,30);
  cout<<obj->getKey(1)<<endl;
return 0;
}