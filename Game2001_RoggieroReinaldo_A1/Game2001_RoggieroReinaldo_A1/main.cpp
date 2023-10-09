#pragma once
#include <iostream>
#include "OrderedArray.h"
#include "UnorderedArray.h"
#include"Array.h"

int main()
{

    OrderedArray<int> orderedArray(10, 2);

    orderedArray.push(8);
    orderedArray.push(16);
    orderedArray.push(24);
    orderedArray.push(16);  

    std::cout << "Arrays in ordered form: ";
    for (int i = 0; i < orderedArray.GetSize(); i++) 
    {
        std::cout << orderedArray[i] << " ";
    }
    std::cout << std::endl;

	return 0;
}