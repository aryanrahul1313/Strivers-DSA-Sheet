class NodeValue{
public:
    int maxNode, minNode, maxSum;
    // creating a constructor
    NodeValue(int minNode, int maxNode, int maxSum){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSum = maxSum;
    }
};

class Solution {
private:
    NodeValue BSThelper(TreeNode* root){
        // empty tree is BST with sum = 0
        if(!root){
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        // get the values from left and right subtree
        auto left = BSThelper(root->left);
        auto right = BSThelper(root->right);

        // check for BST
        if(left.maxNode < root->val && root->val < right.minNode){
            // it is a BST
            sum = max(sum, root->val + left.maxSum + right.maxSum);

            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode),
                                left.maxSum + right.maxSum + root->val);
        }

        // otherwise for not BST return [-inf, +inf]
        // so that poarent can't be valid BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSum, right.maxSum));
    }

public:
    int sum = 0;
    int maxSumBST(TreeNode* root) {
        BSThelper(root);
        return sum>0 ? sum : 0;
    }
};
