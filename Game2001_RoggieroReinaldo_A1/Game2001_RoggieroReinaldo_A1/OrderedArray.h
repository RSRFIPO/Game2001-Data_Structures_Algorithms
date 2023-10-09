#pragma once
#include "Array.h"
#include <cassert>

template<class T>
class OrderedArray : public Array<T>
{
public:
	
	OrderedArray(int size, int growBy = 1, bool noDuplicate = false) : Array<T>(size, growBy), m_noDuplicate(noDuplicate) {}

	~OrderedArray()
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
			Array<T>::Expand();
		}

		int i, k;	
		
		for (i = 0; i < Array<T>::m_numElements; i++)
		{
			if (Array<T>::m_array[i] > val)
			{
				break;
			}
		}

		for (i = 0; i < Array<T>::m_numElements; i++) {
			if (!m_noDuplicate && Array<T>::m_array[i] == val) {
				return; 
			}
			if (Array<T>::m_array[i] > val) {
				break;
			}
		}

		
		for (k = Array<T>::m_numElements; k > i; k--)
		{
			Array<T>::m_array[k] = Array<T>::m_array[k - 1];
		}

		
		Array<T>::m_array[i] = val;

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
			
			if (i + 1 < Array<T>::m_numElements)
			{
				Array<T>::m_array[i] = Array<T>::m_array[i + 1];
			}
		}
		Array<T>::m_numElements--;
	}


	int search(T searchKey)
	{
		return binarySearch(searchKey, 0, Array<T>::m_numElements - 1);
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

	int binarySearch(T searchKey, int lowerBound, int upperBound)
	{
		assert(Array<T>::m_array != nullptr);
		assert(lowerBound >= 0);
		assert(upperBound < Array<T>::m_numElements);

		int current = (lowerBound + upperBound) >> 1;

		
		if (Array<T>::m_array[current] == searchKey)
		{
			
			return current;
		}
		 
		else if (lowerBound > upperBound)
		{
			
			return -1;
		}
		
		else
		{
			if (Array<T>::m_array[current] < searchKey)
			{
				
				return binarySearch(searchKey, current + 1, upperBound);
			}
			else
			{
				
				return binarySearch(searchKey, lowerBound, current - 1);
			}
		}

		return -1;
	}


	bool m_noDuplicate;
};