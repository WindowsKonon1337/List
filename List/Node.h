#pragma once

template<class T>
struct Node
{
	Node<T>* next;
	Node<T>* prev;

	T value;

	Node() : next(nullptr), prev(nullptr)
	{
		
	};

	Node(const T data) : value(data)
	{
		Node();
	}

	~Node() = default;

	bool isEndPoint = false;
};