#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/submissions/1880059870/?envType=daily-question&envId=2026-01-09
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// returns {subtree_root_with_all_deepest, depth}
pair<TreeNode*, int> dfs(TreeNode* root) {
    if (!root) return {nullptr, 0};

    auto left = dfs(root->left);
    auto right = dfs(root->right);

    // If left subtree is deeper
    if (left.second > right.second) {
        return {left.first, left.second + 1};
    }
    // If right subtree is deeper
    if (right.second > left.second) {
        return {right.first, right.second + 1};
    }

    // If both depths are equal, current node is the answer
    return {root, left.second + 1};
}

TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    return dfs(root).first;
}


int main()
{
    // Test Case 1: root = [3,5,1,6,2,0,8,null,null,7,4]
    // Deepest nodes are 7 and 4. Their LCA is 2.
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(0);
    root1->right->right = new TreeNode(8);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);

    TreeNode* result1 = subtreeWithAllDeepest(root1);
    cout << "Test Case 1: " << (result1 ? result1->val : -1) << endl;

    // Test Case 2: root = [0,1,3,null,2]
    // Deepest node is 2. Result is 2.
    TreeNode* root2 = new TreeNode(0);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(2);

    TreeNode* result2 = subtreeWithAllDeepest(root2);
    cout << "Test Case 2: " << (result2 ? result2->val : -1) << endl;

    return 0;
}
