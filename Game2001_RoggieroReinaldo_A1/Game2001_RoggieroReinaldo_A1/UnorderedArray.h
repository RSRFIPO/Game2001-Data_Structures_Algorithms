#pragma once
#include "Array.h"
#include <cassert>

template<class T>
class UnorderedArray : public Array<T>
{
public:

	UnorderedArray(int size, int growBy = 1) :
		Array<T>(size, growBy){}

	~UnorderedArray()
	{
		if (Array<T>::m_array != nullptr)
		{
			delete[] Array<T>::m_array;
			Array<T>::m_array = nullptr;
		}
	}
	
	void push(T val)
	{
		assert(Array<T>::m_array != nullptr); 

		if (Array<T>::m_numElements >= Array<T>::m_maxSize)	
		{
			Expand();
		}

		
		Array<T>::m_array[Array<T>::m_numElements] = val;
		Array<T>::m_numElements++;
	}
	
	void pop()
	{
		if (Array<T>::m_numElements > 0)
		{
			Array<T>::m_numElements--;	
		}
	}
	
	void remove(int index)
	{
		assert(Array<T>::m_array != nullptr);

		if (index >= Array<T>::m_numElements)
		{
			return;	
		}

		for (int i = index; i < Array<T>::m_numElements; i++)
		{
			
			{
				Array<T>::m_array[i] = Array<T>::m_array[i + 1];
			}
		}
		Array<T>::m_numElements--;
	}
	
	int search(T val)
	{
		assert(Array<T>::m_array != nullptr);

		
		for (int i = 0; i < Array<T>::m_numElements; i++)
		{
			if (Array<T>::m_array[i] == val)
			{
				return i;
			}
		}

		return -1;
	}

	T& operator[](int index)
	{
		assert(Array<T>::m_array != nullptr && index < Array<T>::m_numElements);
		return Array<T>::m_array[index];
	}
	
	void clear()
	{
		Array<T>::m_numElements = 0;
	}

private:

	
	bool Expand()
	{
		if (Array<T>::m_growSize <= 0)
		{
			return false;
		}

		
		T* temp = new T[Array<T>::m_maxSize + Array<T>::m_growSize];
		assert(temp != nullptr);

		memcpy(temp, Array<T>::m_array, sizeof(T) * Array<T>::m_maxSize);

		delete[] Array<T>::m_array;

		Array<T>::m_array = temp;
		temp = nullptr;

		Array<T>::m_maxSize += Array<T>::m_growSize;

		return true;
	}
};