#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
Link
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int sum(TreeNode* root)
{
    if(root == NULL)
        return 0;

    return root->val + sum(root->left) + sum(root->right);
}

int sameNodeCount(TreeNode* root, int x)
{
    if(root == NULL)
        return 0;

    int count = 0;
    if(root->val == x)
        count++;

    count += sameNodeCount(root->left, x);
    count += sameNodeCount(root->right, x);

    return count;
}

long long postOrderDFS(TreeNode* root, long long totalSum, long long *maxProduct)
{
    if(root == NULL){
        return 0;
    }

    long long leftSum = 0, rightSum = 0, subtreeSum = 0, product = 0;

    leftSum = postOrderDFS(root->left, totalSum, maxProduct);
    rightSum = postOrderDFS(root->right, totalSum, maxProduct);

    subtreeSum = root->val + leftSum + rightSum;
    product = subtreeSum * (totalSum - subtreeSum);
    *maxProduct = max(*maxProduct, product);

    return subtreeSum;
}

int main()
{
    vector<int> res;
    long long prod = 0;

    // Test cases for checking binary trees
    // Test Case 1: Simple tree
    //     1
    //    / \
    //   2   3
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    cout << "Test Case 1 Sum: " << sum(root1) << endl;
    postOrderDFS(root1, sum(root1), &prod);
    cout<< "Test Case 1 maxProd: "<< prod << endl;

    // for(auto ele : res){
    //     cout<<ele<<" ";
    // }
    // cout<<"\n";


    cout<<"\n##############\n"<<endl;

    // Test Case 2: Larger tree
    //      10
    //     /  \
    //    5    15
    //   / \     \
    //  3   7     18
    TreeNode* root2 = new TreeNode(10);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(15);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(7);
    root2->right->right = new TreeNode(18);
    cout << "Test Case 2 Sum: " << sum(root2) << endl;

    res.clear();
    prod = 0;
    postOrderDFS(root2, sum(root2), &prod);
    cout<< "Test Case 2 maxProd: "<< prod << endl;

    // for(auto ele : res){
    //     cout<<ele<<" ";
    // }
    // cout<<"\n";

    cout<<"\n##############\n"<<endl;

    return 0;
}
