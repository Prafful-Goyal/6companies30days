//PROBLEM STATEMENT
/*
A kingdom consists of a king, his children, his grandchildren, and so on. Every once in a while, someone in the family dies or a child is born.

The kingdom has a well-defined order of inheritance that consists of the king as the first member. Let's define the recursive function Successor(x, curOrder), which given a person x and the inheritance order so far, returns who should be the next person after x in the order of inheritance.

Successor(x, curOrder):
    if x has no children or all of x's children are in curOrder:
        if x is the king return null
        else return Successor(x's parent, curOrder)
    else return x's oldest child who's not in curOrder
For example, assume we have a kingdom that consists of the king, his children Alice and Bob (Alice is older than Bob), and finally Alice's son Jack.

In the beginning, curOrder will be ["king"].
Calling Successor(king, curOrder) will return Alice, so we append to curOrder to get ["king", "Alice"].
Calling Successor(Alice, curOrder) will return Jack, so we append to curOrder to get ["king", "Alice", "Jack"].
Calling Successor(Jack, curOrder) will return Bob, so we append to curOrder to get ["king", "Alice", "Jack", "Bob"].
Calling Successor(Bob, curOrder) will return null. Thus the order of inheritance will be ["king", "Alice", "Jack", "Bob"].
Using the above function, we can always obtain a unique order of inheritance.

Implement the ThroneInheritance class:

ThroneInheritance(string kingName) Initializes an object of the ThroneInheritance class. The name of the king is given as part of the constructor.
void birth(string parentName, string childName) Indicates that parentName gave birth to childName.
void death(string name) Indicates the death of name. The death of the person doesn't affect the Successor function nor the current inheritance order. You can treat it as just marking the person as dead.
string[] getInheritanceOrder() Returns a list representing the current order of inheritance excluding dead people.
*/
//CODE
class ThroneInheritance {
private:
    struct Tree{//Structure of N-ary Tree
        string name;//Storing names
        vector<Tree*> childrens;//storing childrens
    };
public:
    Tree* root;
    unordered_map<string,Tree*> mp;//HashMap to mark dead peoples
    ThroneInheritance(string kingName) {
        root=new Tree();
        root->name=kingName;
        mp[kingName]=root;
    }
    
    void birth(string parentName, string childName) {
        Tree* child=new Tree();
        child->name=childName;
        mp[parentName]->childrens.push_back(child);//Making Link from parent to newborn child
        mp[childName]=child;
    }
    
    void death(string name) {
        mp[name]=NULL;//Marking Dead peoples
    }
    void dfs(Tree* root,vector<string>& ans){//DFS call to get the inheritance order
        if(mp[root->name]!=NULL)    ans.push_back(root->name);//Checking if current people is dead, if dead then not including that person in our inheritance order
        for(int i=0;i<root->childrens.size();i++){//Childrens will be present in inheritance order doesn't matter if their parent is dead or alive
            dfs(root->childrens[i],ans);
        }
        return;
    }
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(root,ans);
        return ans;
    }
};
