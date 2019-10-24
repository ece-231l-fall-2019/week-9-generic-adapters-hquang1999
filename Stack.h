#include<iostream>

template<typename T>
class Stack
{ 
  protected:
     List<T> c;
  
  public:
     T& top()
	 {
		return c.back(); 
     }

     const T& top() const
     {
		return c.back();		 
	 }
	 
	 void push(const T& value)
     {
		 c.push_back(value);
	 }
	 
	 void pop()
	 {
		 c.pop_back();
	 }

     size_t size() const
	 {
		 return c.size();
	 }

     bool empty() const
     {
		 return c.empty();
	 }

	 Stack<T>& operator=(const Stack<T>& other)
	 {
		 c = other.c;
		 return *this;
	 }
 	 template<typename V> friend bool operator==(const Stack<V>& a, const Stack<V>& b);
	 template<typename V> friend bool operator!=(const Stack<V>& a, const Stack<V>& b);

};

template<typename V>
inline bool operator==(const Stack<V>& a, const Stack<V>& b)
{
	return a.c == b.c;
}

template<typename V>
inline bool operator!=(const Stack<V>& a, const Stack<V>& b)
{
	return a.c != b.c;
}	


