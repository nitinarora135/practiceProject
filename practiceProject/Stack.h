#pragma once

template <typename T> class myStack {
private:
	T stack[100];
	int top = -1;

public:
	int push(T ele);
	int pop();
	T stackTop() { return stack[top]; }
	int size() { return top + 1; }
};


template <typename T> int myStack<T>::push(T ele)
{
	if (top >= 100)
	{
		cout << "ERROR:  stack is full";
		return -1;
	}
	stack[++top] = ele;
	return 0;
}

template <typename T> int myStack<T>::pop()
{
	if (top == -1)
	{
		cout << "Stack is empty";
		return -1;
	}
	top--;
	return 0;
}




