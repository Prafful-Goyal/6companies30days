//PROBLEM STATEMENT
/*
You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.
Each minute, a node becomes infected if:
The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.
*/
//APPROACH => WE CONVERT BINARY TREE IN ADJACENCY LIST THE WE IMPLEMENT BFS TO COUNT MINUTES FOR INFECTION OF COMPLETE TREE
//CODE
/*
 T.C = O(N+N)(FOR BFS+DFS)
 S.C = O(N)(OVERALL)
 */
class Solution {
public:
    void convert(TreeNode* root,int parent,unordered_map<int,vector<int>>&graph)
    {
        if(root==NULL)
        {
            return;
        }
        if(parent!=0)
        {
            graph[root->val].push_back(parent);
        }
        if(root->left!=NULL)
        {
            graph[root->val].push_back(root->left->val);
        }
        if(root->right!=NULL)
        {
            graph[root->val].push_back(root->right->val);
        }
        convert(root->left,root->val,graph);
        convert(root->right,root->val,graph);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>graph;
        convert(root,0,graph);
        queue<int>q;
        q.push(start);
        unordered_set<int>visited;
        visited.insert(start);
        int minute = 0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int node = q.front();
                q.pop();
                for(int child:graph[node])
                {
                    if(visited.find(child)==visited.end())
                    {
                        visited.insert(child);
                        q.push(child);
                    }
                }
            }
            minute++;
        }
        return minute-1;
    }
};
