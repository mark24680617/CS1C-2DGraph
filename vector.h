/*
Completed by: Daniel Price
Reviewed by:
*/

#ifndef VECTOR_H_
#define VECTOR_H_

#include <algorithm> // std::copy
using std::copy;
// test
namespace myStd
{
template<typename T>
class vector
{
    /**
    vector of doubles much like stl vector container

    NOTE: elem[n] is vector component n for all n >= 0 AND n < size_v
          size_v = the number of items stored in the vector
          space = the available storage capacity of the vector where size_v <= space
          if size_v < space there is space for (space - size_v) doubles after elem[size_v-1]
    */
private:
    int size_v;   /// the size
    T *elem; /// pointer to the elements (or 0)
    int space;    /// number of elements plus number of free slots
public:
    vector() : size_v{0}, elem{new T[1]}, space{0} {} /// default constructor

    explicit vector(int s) : size_v{s}, elem{new T[s]}, space{s} /// alternate constructor
    {
        for (int i = 0; i < size_v; ++i)
            elem[i] = 0; // elements are initialized
    }

    vector(const vector &src) : size_v{src.size_v}, elem{new T[src.size_v]}, space{src.space} /// copy constructor
    {
        copy(src.elem, src.elem + size_v, elem); // copy elements - std::copy() algorithm
    }

    vector &operator=(const vector &src) /// copy assignment
    {
        T *p = new T[src.size_v];       // allocate new space
        copy(src.elem, src.elem + src.size_v, p); // copy elements - std::copy() algorithm
        delete[] elem;                            // deallocate old space
        elem = p;                                 // now we can reset elem
        size_v = src.size_v;
        return *this;  // return a self-reference
    }

    vector(vector&& src) : size_v{src.size_v}, elem{src.elem}, space{src.space} /// move constructor
    {
        src.size_v = 0;
        src.elem = nullptr;
        src.space = 0;
    }

    vector& operator=(vector&& src) ///opeartor = constructor
    {
        if (this == &src) // Check for self-assignment
        {
            return *this;
        }

        delete[] elem; // Deallocate existing memory

        size_v = src.size_v;
        elem = src.elem;
        space = src.space;

        src.size_v = 0;
        src.elem = nullptr;
        src.space = 0;

        return *this;
    }

    /// destructor
    ~vector() {
        delete[] elem;
    }

    /// access: return reference
    T &operator[](int n) {
        return elem[n];
    }

    /**
     * @brief operator [] return values
     * @param n number elements
     * @return return values
     */
    const T &operator[](int n) const {
        return elem[n];
    }

    /**
     * @brief size size of vector
     * @return size
     */
    int size() const {
        return size_v;
    }

    /**
     * @brief capacity total space of vector
     * @return space number
     */
    int capacity() const {
        return space;
    }

    /**
     * @brief resize vector space
     * @param newsize new size of vector
     */
    void resize(int newsize) // growth
    // make the vector have newsize elements
    // initialize each new element with the default value 0.0
    {
        reserve(newsize);
        for (int i = size_v; i < newsize; ++i)
        {
            elem[i] = 0; // initialize new elements
        }
        size_v = newsize;
    }

    /**
     * @brief push_back values to vector
     * @param d elements
     */
    void push_back(T d)
    // increase vector size by one; initialize the new element with d
    {
        if (space == 0)
            {reserve(8);}// start with space for 8 elements
        else if (size_v == space)
            {reserve(2 * space);} // get more space
        elem[size_v] = d;       // add d at end
        ++size_v;               // increase the size (size_v is the number of elements)
    }

    /**
     * @brief reserve enough space for vector
     * @param newalloc for vector
     */
    void reserve(int newalloc)
    {
        // never decrease allocation
        // allocate new space

        // copy old elements
        // deallocate old space
    	if (newalloc <= space)
    	{
    		return;
    	}
    	T* temp = new T[newalloc]();//T{newalloc};
    	for (int i = 0; i < size_v; i++)
    	{
    		temp[i] = elem[i];
    	}
    	delete [] elem;
    	elem = temp;
    	temp = nullptr;
    	space = newalloc;
    }

    using iterator = T*;
    using const_iterator = const T*;

    /**
     * @brief begin value of vector
     * @return iterator of begin
     */
    iterator begin() // points to first element
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }

    /**
     * @brief begin const value of vector
     * @return const iterator of begin
     */
    const_iterator begin() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }

    /**
     * @brief end value of vector
     * @return iterator of end
     */
    iterator end() // points to one beyond the last element
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }

    /**
     * @brief end value of vector
     * @return iterator of end
     */
    const_iterator end() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }

    /**
     * @brief insert value with a certain iterator
     * @param p iterator
     * @param val value
     * @return iterator of value
     */
    iterator insert(iterator p, const T &val) // insert a new element val before p
    {
        // make sure we have space
    	if (size_v == space)
    	{
    		reserve(space + 1);
    	}
        // the place to put value
    	for (iterator p2 = end(); p2 != p; --p2)
    	{
    		*p2 = *(p2 - 1);
    	}
        // copy element one position to the right
        // insert value
    	size_v++;
    	*p = val;
    	return p;
        //return nullptr; // temp remove & replace
    }

    /**
     * @brief erase value with certain iterator
     * @param p iterator
     * @return iterator deleted
     */
    iterator erase(iterator p) // remove element pointed to by p
    {
        if (p == end())
            return p;
        for (iterator pos = p + 1; pos != end(); ++pos)
        {
            *(pos - 1) = *pos; // copy element one position to the left
        }
        //delete (end() - 1);
        --size_v;
        return p;
    }
};
}

#endif /* VECTOR_H_ */
