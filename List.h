#ifndef __EE231_List_h__
#define __EE231_List_h__


#include <iostream>
#include <string>
#include <cstddef>

template<class T>
class List
{
	private:
	typedef struct llist 
	{
		T value;
		struct llist *next;
		struct llist *prev;
	} llist;

	size_t _size;
	llist *_front;
	llist *_back;

	void reccopy(const llist *ptr)
	{
		if (ptr)
		{
			reccopy(ptr->next);
			push_front(ptr->val);
		}
	}
	
	public:
	
	// default constructor
	List()
	{

		_size = 0;
		_front = 0;
		_back = 0;
	}

	// destructor	
	~List()
	{
		while(!empty())
		{
			pop_front();
		}
	}

	// copy constructor
	List(const List& other)
	{
		_size = 0;
		_front = 0;
		_back = 0;
		reccopy(other._front);
	}	
	
	// operator =
	List& operator=(const List& a)
	{
		for(const llist* b = a._front; b != 0; b = b -> next)
		{
			push_back(b -> value);
		}
	
		return *this;
	}

	// front
	T& front()
	{
		return _front -> value;
	}
	const T& front() const
	{
		return _front -> value;
	}

	// back
	T& back()
	{
		return _back -> value;
	}
	
	const T& back() const
	{
		return _back -> value;
	}	
	
	// size
	size_t size()
	{
		return _size;
	}
	
	size_t size() const
	{
		return _size;
	}

	// push_back
	void push_back(const T& value)
	{
		llist *newBackItem = new llist;
		newBackItem -> value = value;
		newBackItem -> prev = _back;
		newBackItem -> next = 0;
		
		if (_back != 0)
		{
			_back -> next = newBackItem;
		}		
		if (_front == 0)
		{
			_front = newBackItem;
		}
	
		_back = newBackItem;
		_size++;
	}

	// push_front
	void push_front(const T& value)
	{
		if (_front == 0)
		{
			llist *newNode = new llist;
			newNode -> value = value;
			newNode -> next = 0;
			newNode -> prev = 0;
			_front = newNode;
			_back = newNode;
		}
		else
		{
			llist *newFrontItem = new llist;
			newFrontItem -> value = value;
			newFrontItem -> next = _front;
			newFrontItem -> prev = 0;
			_front = newFrontItem;	
			newFrontItem -> next -> prev = newFrontItem;
		}
		_size++;
	}
	
	// pop_front
	void pop_front()
	{
		llist *saveFront = _front;
		_front = _front -> next;
		
		if (_front)
 		{
			_front -> prev = 0;
		}
		else
		{
			_back = 0;
		}
		
		delete saveFront;
		_size--;		
	}

	// pop_back
	void pop_back()
	{
		llist *saveBack = _back;
		_back = _back -> prev;
		
		if (_back)
		{
			_back -> next = _back -> next -> next;
		}
		else 
		{
			_front = 0;
		}
		
		delete saveBack;
		_size--;	
	}

	// empty
	bool empty() const
	{
		return (_front == 0 && _back == 0);
	}

	// reverse
	void reverse()
	{
		for (llist *z = _front; z != 0; z = z -> prev)
		{
			llist *temp = z -> next;
			z -> next = z -> prev;
			z -> prev = temp;
		}
		
		llist *save;
		save = _back;
		_back = _front;
		_front = save;
	}

	// unique
	void unique()
	{
		for (llist *i = _front; i != 0; i = i -> next)
		{
			while (i -> next != 0 && i -> str == i -> next -> str)
			{
				llist *save = i -> next;
				i -> next = save -> next;
				
				if (save -> next != 0)
				{
					save -> next -> prev = i;
					delete save;
				}
				else 
				{
					_back = i;
					delete save;
				}
				_size--;
			}
		}
	}
	
	// print
	void print() 
	{
		llist *temp = _front;
		while (temp != 0)
		{
			std::cout << temp -> value << " ";
			temp = temp -> next;
		}
		std::cout << std::endl;
	}
	
	//friends
	template<typename V> friend bool operator==(const List<V>& a, const List<V>& b);
	template<typename V> friend bool operator!=(const List<V>& a, const List<V>& b);
};

//operator==
template<typename V>
bool operator==(const List<V>& a, const List<V>& b)
{
	if (a.size() != b.size())
	{
		return false;
	}

	auto *aptr = a._front;
	auto *bptr = b._front;

	for (; aptr != 0 && bptr != 0; aptr = aptr -> next, bptr = bptr ->next)
	{
		if (aptr -> value != bptr -> value)
		{
			return false;
		}
	}
	return true;
}

//operator!=
template<typename V>
bool operator!=(const List<V>& a, const List<V>& b)
{
	if (a.size() != b.size())
	{
		return true;
	}

	auto *aptr = a._front;
	auto *bptr = b._front;

	for (; aptr != 0 && bptr != 0; aptr = aptr -> next, bptr = bptr ->next)
	{
		if (aptr -> value != bptr -> value)
		{
			return true;
		}
	}
	return false;
}
/*
template<typename V>
inline bool operator==(const List<V>& a, const List<V>& b)

	List x(a);
	List y(b);
	if (x.size == y.size)
	{
		while ((x.begin != NULL) && (y.being != NULL))
		{
			if (x -> value == y -> value)
			{
				x.begin++;
				y.begin++;
			}
			else
			{
				break;
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
*/

#endif // __EE231_List_h__
