#pragma once
#include "Node.h"
#include "Iterator.h"
#include <iostream>

template<class T>
class List
{
	Node<T>* first;
	Node<T>* last;
	Node<T>* endPoint = new Node<T>();
	int count = 0;
public:

	using Iterator = ListIterator<T>;

	List() : first(nullptr), last(nullptr)
	{
		endPoint->isEndPoint = true;
		endPoint->next = nullptr;
		endPoint->prev = last;
		count = 0;
	}

	List(const int count) : count(count)
	{
		endPoint->isEndPoint = true;
		endPoint->next = nullptr;
		endPoint->prev = last;

		T* tmp = new T();
		for (int i = 0; i < count; ++i)
			this->pushBack(*tmp);
		delete tmp;
	}

	List(const int count, const T& val) : count(count)
	{
		endPoint->isEndPoint = true;
		endPoint->next = nullptr;
		endPoint->prev = last;

		for (int i = 0; i < count; ++i)
			this->pushBack(val);
	}

	List(Iterator begin, Iterator end)
	{
		endPoint->isEndPoint = true;
		endPoint->next = nullptr;
		endPoint->prev = last;

		while (begin != end)
		{
			this->pushBack(*begin);
			++begin;
		}
	}

	List(List<T>& list)
	{
		endPoint->isEndPoint = true;
		endPoint->next = nullptr;
		endPoint->prev = last;

		for (auto i = list.begin(); i != list.end(); ++i)
		{
			this->pushBack(*i);
		}
	}

	List(std::initializer_list<T> list)
	{
		endPoint->isEndPoint = true;
		endPoint->next = nullptr;
		endPoint->prev = last;

		auto pos = list.begin();
		while (pos != list.end())
		{
			this->pushBack(*pos);
			++pos;
		}
	}

	~List()
	{
		this->clear();
	}

	Iterator begin()
	{
		Iterator iter(first);
		return iter;
	}

	Iterator end()
	{
		Iterator iter(endPoint);
		return iter;
	}

	void pushBack(const T& elem)
	{
		auto p = new Node<T>(elem);

		p->next = endPoint;
		p->value = elem;

		if (first)
		{
			p->prev = last;
			last->next = p;
			last = p;
			++count;
		}
		else
		{
			p->prev = nullptr;
			first = last = p;
			++count;
		}
	}

	void pushFront(const T& elem)
	{
		auto p = new Node<T>(elem);
		p->prev = nullptr;
		p->value = elem;

		if (first)
		{
			p->next = first;
			first->prev = p;
			first = p;
			++count;
		}
		else
		{
			p->next = nullptr;
			first = last = p;
			++count;
		}
	}

	void popBack()
	{
		if (first)
		{
			auto p = last->prev;
			delete last;
			p->next = endPoint;
			last = p;
			--count;
		}
	}

	void popFront()
	{
		if (first)
		{
			auto p = first->next;
			delete first;
			p->prev = nullptr;
			first = p;
			--count;
		}
	}

	void clear()
	{
		auto del = first;
		auto way = first;

		while (way)
		{
			way = way->next;
			delete del;
			del = way;
		}
		first = last = way;
		count = 0;
	}

	bool empty()
	{
		return count == 0 ? true : false;
	}

	int size() const { return count; }

	Iterator& insert(Iterator pos,const T& elem)
	{
		auto p = first;
		while (p != pos.iter)
			p = p->next;
		auto left = p->prev;
		auto ins = new Node<T>(elem);
		ins->next = p;
		ins->prev = left;
		left->next = ins;
		p->prev = ins;
		++count;
		return pos;
	}

	Iterator& insert(Iterator pos, Iterator begin, Iterator end)
	{
		auto p = first;
		while (p != pos.iter)
			p = p->next;
		List<T> mergeList;
		auto way = first;
		while (way != begin.iter)
			way = way->next;
		Iterator result(way);
		while (way != end.iter)
		{
			mergeList.pushBack(way->value);
			way = way->next;
		}
		auto left = p->prev;
		mergeList.first->prev = left;
		left->next = mergeList.first;
		this->count += mergeList.count;
		mergeList.last->next = p;
		p->prev = mergeList.last;
		return pos;
	}

	void erase(Iterator pos)
	{

		auto p = first;
		while (p != pos.iter)
			p = p->next;
		auto right = p->next;
		auto left = p->prev;
		left->next = right;
		right->prev = left;
		delete p;
		--count;
	}

	void resize(int num)
	{
		if (num > this->count)
		{
			count = num;
			T* tmp = new T();
			for (int i = 0; i < num; ++i)
			{
				this->pushBack(tmp);
			}
			delete tmp;
		}
		else if (num < this->count)
		{
			for (int i = 0; i < num; ++i)
			{
				this->popBack();
			}
		}
	}
	void print()
	{
		Node<T>* p = first;

		while (!p->isEndPoint)
		{
			std::cout << p->value << " ";
			p = p->next;
		}
		std::cout << std::endl;
	}

};

