//PROBLEM STATEMENT
/*
Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/
//CODE
/*
 T.C = O(N) WHERE N IS THE NUMBER OF NODES IN BST
 S.C = O(H) WHERE H IS THE HEIGHT OF THE TREE
*/
 class NodeValue{
     public:
     int minNode,maxNode,maxSum;
     NodeValue(int minNode,int maxNode,int maxSum)
     {
         this->minNode = minNode;
         this->maxNode = maxNode;
         this->maxSum = maxSum;
     }
 };
class Solution {
public:
    int sum = 0;
    NodeValue maxSumBSThelper(TreeNode*root)
    {
        if(!root)
        {
            return NodeValue(INT_MAX,INT_MIN,0);
        }
        NodeValue lf = maxSumBSThelper(root->left);
        NodeValue rt = maxSumBSThelper(root->right);
        if(lf.maxNode<root->val&&root->val<rt.minNode)
        {
            sum = max(sum,root->val+lf.maxSum+rt.maxSum);
            return NodeValue(min(root->val,lf.minNode),max(root->val,rt.maxNode),root->val+lf.maxSum+rt.maxSum);
        }
        return NodeValue(INT_MIN,INT_MAX,max(lf.maxSum,rt.maxSum));
    }
    int maxSumBST(TreeNode* root) {
        maxSumBSThelper(root);
        return sum>0?sum:0;
    }
};
