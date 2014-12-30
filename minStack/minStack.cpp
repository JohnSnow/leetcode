#include <stack>
#include <iostream>
#include <cassert>

class MinStack {
public:
    void push(int x) {
        _stack.push(x);
        if(_min_stack.empty() || x <= _min_stack.top()) {
            _min_stack.push(x);
        }
    }

    void pop() {
        int tp = _stack.top();
        _stack.pop();
        if (tp == _min_stack.top()) {
            _min_stack.pop();
        }
    }

    int top() {
        return _stack.top();
    }

    int getMin() {
        return _min_stack.top();
    }

private:
    std::stack<int> _stack;
    std::stack<int> _min_stack;
};


int main(int argc, char *argv[])
{
    MinStack *sk  = new MinStack();
    sk->push(2);
    sk->push(3);
    sk->push(1);
    sk->push(4);

    assert(1 == sk->getMin());
    sk->pop();
    sk->pop();
    assert(2 == sk->getMin());

    return 0;
}
