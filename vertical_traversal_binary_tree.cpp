/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode *root, int r, int c , unordered_map<int, vector<pair<int , int>>> &cache, int &minC, int &maxC){
        if(root == NULL) return;
        
        if(cache.count(c)) cache[c].push_back({r, root->val});
        else cache.insert({c, {{r, root->val}}});
        minC = min(minC , c);
        maxC = max(maxC, c);
        dfs(root->left, r+1, c-1, cache, minC, maxC);
        dfs(root->right, r+1, c+1, cache  , minC, maxC);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        
        unordered_map<int, vector<pair<int , int>>> cache;
        int minC = 0, maxC = 0;
        
        dfs(root, 0, 0, cache, minC, maxC);
        
        for(int c = minC; c<=maxC; c++){
            sort(cache[c].begin(), cache[c].end(), [](pair<int, int> &p1, pair<int, int> &p2){
                return (p1.first<p2.first) || ((p1.first == p2.first) && (p1.second < p2.second));
            });
            vector<int> col;
            for(auto p : cache[c])
                col.push_back(p.second);
            result.push_back(col);
        }
        return result;
        
    }
};
