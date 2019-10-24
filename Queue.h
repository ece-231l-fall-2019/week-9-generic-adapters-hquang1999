template<typename T>

class Queue
{
  protected:
     List<T> c;
  public:
     T& front()
     {
		 c.front();
	 }
	 
	 T& back()
	 {
		 c.back();
	 }
     
	 const T& front() const
     {
		 c.front();
	 }

	 const T& back() const
     {
		 c.back();
	 }
	 
	 void push(const T& value)
	 {
		 c.push_back(value);
	 }

     void pop()
     {
		 c.pop_back;
	 }
	 
	 size_t size() const
     {
		 return c.size();
	 }

	 bool empty() const
     {
		 return c.empty();
	 }
	 
	 Queue<T>& operator=(const Queue<T>& other)
	 {
		 c = other.c;
	 }

	 template<typename V> friend bool operator==(const Queue<V>& a, const Queue<V>& b);	
	 template<typename V> friend bool operator!=(const Queue<V>& a, const Queue<V>& b);	
};

template <typename V>
inline bool operator==(const Queue<V>& a, const Queue<V>& b)
{
	return a.c == b.c;
}

template <typename V>
inline bool operator!=(const Queue<V>& a, const Queue<V>& b)
{
	return a.c != b.c;
}
