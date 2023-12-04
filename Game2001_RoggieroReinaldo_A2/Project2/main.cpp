#include "List.h"

int main()
{
    PriorityQueue<int> PriorityT;

    std::cout << "Pushing the values to priority queue:" << std::endl;
    PriorityT.Push(12, 3);
    PriorityT.Push(25, 6);
    PriorityT.Push(63, 8);
    PriorityT.Push(42, 1);
    PriorityT.Push(50, 5);

    std::cout << "Front of the priority queue: " << PriorityT.Front() << std::endl;

    std::cout << "Popping the elements of the priority queue:" << std::endl;
    while (PriorityT.GetSize() > 0)
    {
        std::cout << "Popped value: " << PriorityT.Pop() << std::endl;
    }

    std::cout << "Testing Empty Lists. " << std::endl;
    system("PAUSE");
    std::cout << "Test empty List: " << PriorityT.Front() << std::endl;
    std::cout << "Test empty popping: " << PriorityT.Pop() << std::endl;


    return 0;
}
