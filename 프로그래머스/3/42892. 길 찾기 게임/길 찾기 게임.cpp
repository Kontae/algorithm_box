#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Node
{
    int x,y,idx;
    Node* left;
    Node* right;
};

vector<int> preV,postV;

bool cmp(Node& a, Node& b)
{
    if(a.y==b.y) return a.x<b.x;
    return a.y>b.y;
}

void setTree(Node* node, Node* parent)
{
    if(node->x<parent->x)
    {
        if(parent->left==NULL)
        {
            parent->left=node;
            return;
        }
        setTree(node,parent->left);
    }
    else
    {
        if(parent->right==NULL)
        {
            parent->right=node;
            return;
        }
        setTree(node,parent->right);
    }
}

void preOrder(Node* root)
{
    if(root==NULL) return;
    preV.push_back(root->idx);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root)
{
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    postV.push_back(root->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    vector<Node> tree;
    for(int i=0;i<nodeinfo.size();i++)
    {
        tree.push_back({nodeinfo[i][0],nodeinfo[i][1],i+1,NULL,NULL});
    }
    sort(tree.begin(),tree.end(),cmp);
    
    Node* root=&tree[0];
    
    for(int i=1;i<tree.size();i++)
    {
        setTree(&tree[i],root);
    }
    preOrder(root);
    postOrder(root);
    answer.push_back(preV);
    answer.push_back(postV);
            
    return answer;
}