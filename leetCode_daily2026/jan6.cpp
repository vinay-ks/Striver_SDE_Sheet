#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


/*
https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/submissions/1876208051/?envType=daily-question&envId=2026-01-06
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxLevelSum(TreeNode* root) {
    int currentLevel = 0;
    int sum = 0;
    int k = 0; // Contains number of nodes to be processed at that level
    queue<TreeNode*> q;
    vector<int> levelSum;

    q.push(root);

    while(!q.empty())
    {
        currentLevel++;
        k = q.size();
        sum = 0;
        
        while(k--){
            TreeNode* curr = q.front(); q.pop();
            sum += curr->val;

            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }

        levelSum.push_back(sum);
    }
    return max_element(levelSum.begin(), levelSum.end()) - levelSum.begin() + 1;
}


int main()
{
    // Test Case 1: root = [1,7,0,7,-8]
    // Level 1: 1, Level 2: 7, Level 3: -1. Max: Level 2
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(7);
    root1->right = new TreeNode(0);
    root1->left->left = new TreeNode(7);
    root1->left->right = new TreeNode(-8);
    cout << "Test Case 1: " << maxLevelSum(root1) << endl;

    // Test Case 2: root = [989,null,10250,98693,-89388,null,null,null,-32127]
    // Max sum is at Level 2 (10250)
    TreeNode* root2 = new TreeNode(989);
    root2->right = new TreeNode(10250);
    root2->right->left = new TreeNode(98693);
    root2->right->right = new TreeNode(-89388);
    root2->right->right->right = new TreeNode(-32127);
    cout << "Test Case 2: " << maxLevelSum(root2) << endl;

    return 0;
}
