class Solution {
    
public:

    Node* LCA(Node* root, int a, int b) {

        if (root == NULL) return NULL;

        if (root->data == a || root->data == b) return root;

        Node* left =  LCA(root->left, a, b);
        Node* right = LCA(root->right, a, b);

        if (left != NULL && right != NULL) return root;

        if (left != NULL) return left;

        return right;
    }

    int bfs(Node* root, int target) {

        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            
            auto [node,dist]=q.front();
            q.pop();

            if (node->data == target)
                return dist;

            if (node->left)
                q.push({node->left, dist + 1});

            if (node->right)
                q.push({node->right, dist + 1});
        }

        return -1;
    }

    int findDist(Node* root, int a, int b) {

        Node* lca = LCA(root, a, b);

        int d1 = bfs(lca, a);
        int d2 = bfs(lca, b);

        return d1 + d2;
    }
};