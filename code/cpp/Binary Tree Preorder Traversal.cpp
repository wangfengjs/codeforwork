#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
// recursive version 1
class Solution {
private:
	vector<int> v;
public:
    vector<int> preorderTraversal(TreeNode *root) {
        if (root != NULL)
        {
			v.push_back(root->val);
			preorderTraversal(root->left);
			preorderTraversal(root->right);
        }
		return v;
    }
};

// recursive version 2
class Solution1 {
public:
	void preOrder(TreeNode *root, vector<int> &v)
	{
		if (root != NULL)
		{
			v.push_back(root->val);
			preOrder(root->left, v);
			preOrder(root->right, v);
		}
	}

	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> v;
		preOrder(root, v);
		return v;
	}
};

// iterative
class Solution2 {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> v;
		stack<TreeNode *> s;
		if (root)
		{
			s.push(root);
			while (!s.empty())
			{
				v.push_back(s.top()->val);
				s.pop();
				if (root->right)
				{
					s.push(root->right);
				}
				if (root->left)
				{
					s.push(root->left);
				}
			}
		}
		return v;
	}
};

int main(int argc, char **argv)
{
	int a;
	cout << a << endl;
	return 0;
}
