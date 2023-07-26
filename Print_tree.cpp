#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int value;
        Node* left;
        Node* right;
        Node(int value)
        {
            this->value=value;
            this->left=NULL;
            this->right=NULL;
        }
};
Node* input_tree()
{
    int val;
    cin >> val;
    Node* root;
    if (val == -1)
    {
        root = NULL;
    }
    else
    {
        root = new Node(val);
    }
    queue<Node*> q;
    if (root)
    {
        q.push(root);
        while (!q.empty())
        {
            Node* p = q.front();
            q.pop();
            int l, r;
            cin >> l >> r;
            if (l != -1)
            {
                p->left = new Node(l);
                q.push(p->left);
            }
            if (r != -1)
            {
                p->right = new Node(r);
                q.push(p->right);
            }
        }
    }
    return root;
}
void level_order(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* f = q.front();
        q.pop();
        cout << f->value << " ";
        if (f->left)
        {
            q.push(f->left);
        }
        if (f->right)
        {
            q.push(f->right);
        }
    }
}
void post_order(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    post_order(root->left);
    post_order(root->right);
    cout<<root->value<<" ";
}
int main()
{
    Node* root = input_tree();
    level_order(root);
    post_order(root);
    return 0;
}