#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class CQueue {
public:
    CQueue() {

    }

    void appendTail(int value) {
        s1.push(value);
    }

    int deleteHead() {
        if (s2.empty())
        {
            if (s1.empty()) return -1;
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
private:
    stack<int> s1;
    stack<int> s2;
};

int main()
{
    CQueue cqueue;
    cqueue.appendTail(1);
    cqueue.appendTail(2);
    cqueue.appendTail(3);
    int val = cqueue.deleteHead();
    cqueue.appendTail(4);
    val = cqueue.deleteHead();
}
