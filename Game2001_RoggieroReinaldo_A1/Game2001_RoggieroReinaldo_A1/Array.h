#pragma once
#include <cassert>
template <class T>

class Array
{
public:
    Array(int size, int growBy = 1) :
        m_array(nullptr), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
        if (size > 0) 
        {
            m_maxSize = size;
            m_array = new T[m_maxSize];
            memset(m_array, 0, sizeof(T) * m_maxSize);
            m_growSize = (growBy > 0) ? growBy : 0;
        }
    }

    virtual ~Array()
	{
        if (m_array != nullptr) 
        {
            delete[] m_array;
            m_array = nullptr;
        }
    }

    virtual void push(T val) = 0;
    virtual void pop() = 0;
    virtual void remove(int index) = 0;
    virtual int search(T searchKey) = 0;
    virtual T& operator[](int index) = 0;
    virtual void clear() = 0;

    int GetSize() const
	{
        return m_numElements;
    }

    int GetMaxSize() const
	{
        return m_maxSize;
    }

    int GetGrowSize() const
	{
        return m_growSize;
    }

    void SetGrowSize(int val)
	{
        assert(val >= 0);
        m_growSize = val;
    }

protected:
    T* m_array;
    int m_maxSize;
    int m_growSize;
    int m_numElements;
};