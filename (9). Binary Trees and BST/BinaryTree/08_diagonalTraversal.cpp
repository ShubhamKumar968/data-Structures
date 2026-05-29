#include <iostream>
using namespace std;
#include <bits/stdc++.h>


class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


class Solution {
  public:
  //For Diagonal Traversal, think of it in terms of a Diagonal Distance (DD):The root starts at DD = 0.
  //When you go Right: You stay on the same diagonal line. So, the distance does not change.
  //When you go Left:  You drop down to the next diagonal line. So, the distance increases by 1.
  
    vector<int> diagonal(Node *root) {
        //TC=O(n*logD) where, D=no.of diagonal
        vector<int>res;
        if (root == NULL) return res;
        
       // STEP 1: Use map to group nodes by their diagonal distance (dd), (keys) sorted automatically.
        map<int,vector<int>>mp;
        
       // STEP 2: Use an iterative DFS stack to track pairs of {Node*, diagonal_distance}.
        stack<pair<Node*, int>> st;
        st.push({root, 0});
        
        while(!st.empty()){
            auto curr = st.top();
            st.pop();
            
            int dd = curr.second;
            Node* node = curr.first;
            // STEP 3: Map the node data to its calculated diagonal distance index.
            mp[dd].push_back(node->data);
            
            //STEP 4: CRITICAL LIFO ORDERING FOR DFS Pushing 'right' first means it sits at the bottom of the current stack frame.
            if(node->right){
                st.push({node->right, dd});
            }
            if(node->left){
                st.push({node->left, dd + 1});
            }
            
        }
        // STEP 5: Flatten the sorted map groups sequentially into the final 1D result vector.
        for(auto &it: mp){
            for(auto &ele:it.second){
                 res.push_back(ele);
            }
        }
        
        return res;
    }
};