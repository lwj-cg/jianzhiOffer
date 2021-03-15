#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() : min_val(INT_MAX) {

	}

	void push(int x) {
		min_val = std::min(x, min_val);
		s.push(x);
		min_s.push(min_val);
	}

	void pop() {
		if (!s.empty() && !min_s.empty()) {
			s.pop();
			min_s.pop();
			if (!min_s.empty() && min_val < min_s.top()) min_val = min_s.top();
			if (min_s.empty()) min_val = INT_MAX;
		}
	}

	int top() {
		return s.top();
	}

	int min() {
		return min_val;
	}
private:
	std::stack<int> s;
	std::stack<int> min_s;
	int min_val;
};

int main()
{
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	minStack.min();   //-- > ·µ»Ø - 3.
	minStack.pop();
	minStack.top();      //-- > ·µ»Ø 0.
	minStack.min();   //-- > ·µ»Ø - 2.
}