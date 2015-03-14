// DFS
class Solution {
private:
	vector<vector<int> > ret;

public:
	void solve(int dep, TreeNode *root)
	{
		if (root == NULL)
			return;

		if (ret.size() > dep)
		{
			ret[dep].push_back(root->val);
		}
		else
		{
			vector<int> a;
			a.push_back(root->val);
			ret.push_back(a);
		}

		solve(dep + 1, root->left);
		solve(dep + 1, root->right);
	}

	vector<vector<int> > levelOrder(TreeNode *root) {
		ret.clear();
		solve(0, root);

		return ret;
	}
};

struct Node
{
	TreeNode *node;
	int level;
	Node(){}
	Node(TreeNode *n, int l):node(n), level(l){}
};

// BFS
class Solution {
public:
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > ret;
		ret.clear();

		if (root == NULL)
			return ret;

		queue<Node> q;

		q.push(Node(root, 0));

		vector<int> a;
		int curLevel = -1;

		while(!q.empty())
		{
			Node node = q.front();
			if (node.node->left)
				q.push(Node(node.node->left, node.level + 1));
			if (node.node->right)
				q.push(Node(node.node->right, node.level + 1));

			if (curLevel != node.level)
			{
				if (curLevel != -1)
					ret.push_back(a);
				curLevel = node.level;
				a.clear();
				a.push_back(node.node->val);                
			}
			else
				a.push_back(node.node->val);

			q.pop();
		}

		ret.push_back(a);

		return ret;
	}
};