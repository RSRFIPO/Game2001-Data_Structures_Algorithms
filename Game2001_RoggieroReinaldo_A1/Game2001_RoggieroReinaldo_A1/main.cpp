//Reinaldo Suarez Roggiero - 101369223
//A1 - DATA STRUCTURES & ALGORITMHS

#pragma once
#include <iostream>
#include "OrderedArray.h"
#include "UnorderedArray.h"
#include"Array.h"

int main()
{
    std::cout << "Reinaldo Suarez Roggiero - 101369223" << std::endl;
    std::cout << "A1 - DATA STRUCTURES & ALGORITMHS" << std::endl;

    OrderedArray<int> orderedArray(10, 2);

    orderedArray.push(8);
    orderedArray.push(24);
    orderedArray.push(16);
    orderedArray.push(16);  

    std::cout << "Arrays in ordered form: ";
    for (int i = 0; i < orderedArray.GetSize(); i++) 
    {
        std::cout << orderedArray[i] << " ";
    }
    std::cout << std::endl;


    UnorderedArray<int> unorderedArray(10, 2);

    unorderedArray.push(24);
    unorderedArray.push(8);
    unorderedArray.push(16);
    unorderedArray.push(36);

    std::cout << "Arrays in unordered form: ";
    for (int i = 0; i < unorderedArray.GetSize(); i++) {
        std::cout << unorderedArray[i] << " ";
    }
    std::cout << std::endl;

	return 0;
}