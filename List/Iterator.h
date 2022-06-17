#pragma once
#include "Node.h"

template<class T>
class ListIterator
{
public:
	Node<T>* iter;

	ListIterator() : iter(nullptr)
	{

	}

	ListIterator(const ListIterator<T>& iter)
	{
		this->iter = iter.iter;
	}

	ListIterator(Node<T>* pos) : iter(pos)
	{

	}

	T& operator*() const;

	ListIterator<T>& operator=(const ListIterator<T>& rhs);

	ListIterator<T>& operator++();
	ListIterator<T>& operator--();
	ListIterator<T> operator--(int);
	ListIterator<T> operator++(int);

	ListIterator<T>& operator+(int);
	ListIterator<T>& operator-(int);

	ListIterator<T>& operator+=(int);
	ListIterator<T>& operator-=(int);

	bool operator==(ListIterator<T> rhs)
	{

		return this->iter == rhs.iter;
	}

	bool operator!=(ListIterator<T> rhs)
	{
		if (rhs.iter == nullptr) return true;

		return !(*this == rhs);
	}

	operator T()const
	{
		return this->iter->value;
	}

	ListIterator<T>* operator->()
	{
		return this;
	}

	auto operator<=>(const ListIterator<T> rhs) const
	{
		return this->iter->value <=> rhs.iter->value;
	}


	~ListIterator() = default; // mi ne allociruem pamyat v iteratore

};

template<class T>
T& ListIterator<T>::operator*() const
{
	if (this->iter)
		return this->iter->value;
}

template<class T>
ListIterator<T>& ListIterator<T>::operator=(const ListIterator<T>& rhs)
{
	this->iter = rhs.iter;

	return *this;
}

template<class T>
ListIterator<T>& ListIterator<T>::operator++()
{
	if (this->iter && this->iter->next)
		iter = iter->next;
	return *this;
}

template<class T>
ListIterator<T>& ListIterator<T>::operator--()
{
	if (this->iter && this->iter->prev)
		iter = iter->prev;
	return *this;
}

template<class T>
ListIterator<T> ListIterator<T>::operator--(int)
{
	ListIterator<T> iter(*this);
	if (this->iter && this->iter->prev)
		this->iter = this->iter->prev;
	return iter;
}

template<class T>
ListIterator<T> ListIterator<T>::operator++(int)
{
	ListIterator<T> iter(*this);
	if (this->iter && this->iter->next)
		this->iter = this->iter->next;
	return iter;
}

template<class T>
ListIterator<T>& ListIterator<T>::operator+(int shift)
{
	for (int i = 0; i < shift && this->iter; ++i)
	{
		this->iter = this->iter->next;
	}

	return *this;
}

template<class T>
ListIterator<T>& ListIterator<T>::operator-(int shift)
{
	for (int i = 0; i < shift && this->iter; ++i)
	{
		this->iter = this->iter->prev;
	}

	return *this;
}

template<class T>
ListIterator<T>& ListIterator<T>::operator+=(int shift)
{
	return *this + shift;
}

template<class T>
ListIterator<T>& ListIterator<T>::operator-=(int shift)
{
	return *this - shift;
}