#pragma once
#include <iostream>

template <typename T>
class Node
{
public:
    int priority;
    T data;
    Node* next;
    Node* prev;

    Node(int prio, T value) : priority(prio), data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class LinkedList
{
private:
    Node<T>* head;
    T front;

public:
    LinkedList() : head(nullptr) {}

    void Push(Node<T>* newNode)
	{
        if (!head || newNode->priority < head->priority) 
        {
            newNode->next = head;
            newNode->prev = nullptr;
            if (head) {
                head->prev = newNode;
            }
            head = newNode;
            front = head->data;
        }
        else 
        {
            Node<T>* current = head;
            while (current->next && current->next->priority <= newNode->priority) 
            {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next) 
            {
                current->next->prev = newNode;
            }
            current->next = newNode;

            if (newNode->next == nullptr) 
            {
                front = newNode->data;
            }
        }

    }

    T Pop()
	{
        if (!head) 
        {
            std::cerr << "Error: Cannot pop from an empty list." << std::endl;
            return T();
        }

        Node<T>* removedNode = head;
        T data = removedNode->data;

        head = head->next;
        if (head) 
        {
            head->prev = nullptr;
            front = head->data;
        }
        else 
        {
            front = T();
        }

        delete removedNode;
        return data;
    }


    T Front() const
	{
        if (head) 
        {
            return head->data;
        }
        else 
        {
            std::cerr << "Error: List is empty." << std::endl;
            return T();
        }
    }

    size_t GetSize() const
	{
        size_t size = 0;
        Node<T>* current = head;
        while (current) 
        {
            size++;
            current = current->next;
        }
        return size;
    }
};

template <typename T>
class PriorityQueue
{
private:
    LinkedList<T> list;
    T front;
    void UpdateFront()
    {
        if (list.GetSize() > 0)
        {
            front = list.Front();
        }
        else
        {
            front = T();
        }
    }
public:
    void Push(T data, int priority = 0)
    {
        Node<T>* newNode = new Node<T>(priority, data);
        list.Push(newNode);
    }

    T Pop()
    {
        return list.Pop();
    }

    T Front() const
    {
        return list.Front();
    }

    size_t GetSize() const
    {
        return list.GetSize();
    }
};