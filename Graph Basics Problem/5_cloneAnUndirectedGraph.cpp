#include<iostream>
using namespace std;
#include<bits/stdc++.h>
struct Node {
     int val;
     vector<Node*> neighbors;

     Node() {
         val = 0;
         neighbors = vector<Node*>();
     }
     Node(int _val) {
         val = _val;
         neighbors = vector<Node*>();
     }
     Node(int _val, vector<Node*> _neighbors) {
         val = _val;
         neighbors = _neighbors;
     }
};

class Solution {
  public:
    void dfs(Node* node,Node* clone_node,unordered_map<Node*, Node*>&mp){
        
        for(auto nbr: node->neighbors){
            
            if(mp.find(nbr) == mp.end()){
                
                Node* clone= new Node(nbr->val);
                mp[nbr]=clone;
                clone_node->neighbors.push_back(clone);
                
                dfs(nbr,clone,mp);
                
            }else if(mp.find(nbr)!=mp.end()){
                
                clone_node->neighbors.push_back(mp[nbr]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        // code here
        if(node==NULL) return NULL;
        
        unordered_map<Node*, Node*>mp;// To keep clone of each node
        Node* clone_node= new Node(node->val);
        mp[node]=clone_node;
        
        dfs(node,clone_node,mp);
        
        return clone_node;
    }
};
