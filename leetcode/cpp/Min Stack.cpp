#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
	stack<int> data;
	stack<int> min;
public:
	void push(int x) {
		data.push(x);
		if (min.empty())
		{
			min.push(x);
		}
		else if (x <= min.top())
		{
			min.push(x);
		}
	}

	void pop() {
		if (data.top() == min.top())
		{
			min.pop();
		}
		data.pop();
	}

	int top() {
		return data.top();
	}

	int getMin() {
		return min.top();
	}
};

int main(int argc, char **argv)
{
	MinStack m;
	m.push(1);
	m.push(-1);
	m.push(5);
	m.push(-2);
	m.pop();
	m.pop();
	cout << m.getMin() << endl;
	return 0;
}
