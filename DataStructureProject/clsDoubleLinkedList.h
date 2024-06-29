#pragma once

template<class T>
class clsDoubleLinkedList
{
private:
    int _size = 0;  // Variable to keep track of the size of the list

public:
    // Nested Node class representing each element in the list
    class Node
    {
    public:
        T value;  // Value stored in the node
        Node* next;  // Pointer to the next node
        Node* prev;  // Pointer to the previous node
    };

    Node* head = NULL;  // Pointer to the head of the list

    // Function to print the entire list with "<-->" between elements
    void PrintLinkedList()
    {
        Node* current = head;

        std::cout << "NULL <--> ";
        while (current != NULL)
        {
            std::cout << current->value << " <--> ";
            current = current->next;
        }
        std::cout << "NULL\n";
    }

    // Function to print the values of the list in a single line
    void Print()
    {
        Node* current = head;
        while (current != NULL)
        {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    // Function to find the first node with a given value
    Node* Find(T value)
    {
        Node* current = head;
        while (current != NULL)
        {
            if (current->value == value)
                return current;

            current = current->next;
        }

        return NULL;
    }

    // Function to insert a new node at the beginning of the list
    void InsertAtBegining(T value)
    {
        Node* first_node = new Node();
        first_node->value = value;
        first_node->prev = NULL;
        first_node->next = head;

        if (head != NULL)
            head->prev = first_node;

        head = first_node;

        _size++;
    }

    // Function to insert a new node after a given node
    void InsertAfter(Node* current, T value)
    {
        Node* new_node = new Node();

        new_node->value = value;
        new_node->next = current->next;
        new_node->prev = current;

        if (current->next != NULL)
            current->next->prev = new_node;

        current->next = new_node;

        _size++;
    }

    // Function to insert a new node at the end of the list
    void InsertAtEnd(T value)
    {
        Node* last_node = new Node();
        last_node->value = value;
        last_node->next = NULL;

        if (head == NULL)
        {
            last_node->prev = NULL;
            head = last_node;
        }
        else
        {
            Node* current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }

            current->next = last_node;
            last_node->prev = current;
        }

        _size++;
    }

    // Function to delete a specific node
    void DeleteNode(Node*& node_to_delete)
    {
        if (head == NULL || node_to_delete == NULL)
            return;

        if (head == node_to_delete)
            head = node_to_delete->next;

        if (node_to_delete->next != NULL)
            node_to_delete->next->prev = node_to_delete->prev;

        if (node_to_delete->prev != NULL)
            node_to_delete->prev->next = node_to_delete->next;

        delete node_to_delete;

        _size--;
    }

    // Function to delete the first node in the list
    void DeleteFirstNode()
    {
        if (head == NULL)
            return;

        Node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;

        delete temp;

        _size--;
    }

    // Function to delete the last node in the list
    void DeleteLastNode()
    {
        if (head == NULL)
            return;

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node* current = head;
            while (current->next->next != NULL)
                current = current->next;

            Node* temp = current->next;
            current->next = NULL;
            delete temp;
        }

        _size--;
    }

    // Function to return the size of the list
    int Size()
    {
        return _size;
    }

    // Function to check if the list is empty
    bool IsEmpty()
    {
        return _size == 0;
    }

    // Function to clear the list
    void Clear()
    {
        while (_size > 0)
        {
            DeleteFirstNode();
        }
    }

    // Function to reverse the list
    void Reverse()
    {
        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr)
            head = temp->prev;
    }

    // Function to get a node by its index
    Node* GetNode(int index)
    {
        if (index > _size - 1 || index < 0)
            return NULL;

        Node* current = head;
        int counter = 0;
        while (current != NULL && current->next != NULL)
        {
            if (counter == index)
                break;

            current = current->next;
            counter++;
        }

        return current;
    }

    // Function to get the value of a node by its index
    T GetItem(int index)
    {
        Node* node = GetNode(index);

        if (node == NULL)
            return NULL;  // Return NULL if node is not found
        else
            return node->value;
    }

    // Function to update the value of a node by its index
    bool UpdateItem(int index, T new_value)
    {
        Node* node = GetNode(index);
        if (node != NULL)
        {
            node->value = new_value;
            return true;
        }
        else
            return false;
    }

    // Function to insert a new node after a node at a given index
    bool InsertAfter(int index, T value)
    {
        Node* node = GetNode(index);

        if (node == NULL)
            return false;
        else
        {
            InsertAfter(node, value);
            return true;
        }
    }
};
