#include <iostream>

class Node
{
public:
    int data;   // Data of node
    Node *next; // Address of next node
};

class LinkedList
{
public:
    LinkedList()
    {
        head = nullptr; // Initialize head and tail to nullptr
        tail = nullptr;
        this->size = 0;
    }

    ~LinkedList()
    {
        // Destructor to clean up allocated memory
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    void display_list()
    {
        Node *ptr;
        ptr = this->head;
        while (ptr != nullptr)
        {
            std::cout << ptr->data << "->";
            ptr = ptr->next;
        }
    }

    int get_size() const
    {
        return this->size;
    }

    void add_last(int data)
    {
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next = nullptr;

        if (size == 0)
        {
            // Create New Node
            // Put head and tail to this
            // Increase Size
            this->head = new_node;
            this->tail = new_node;
        }
        else
        {
            // Create New Node
            // Put Current Node Ptr-> to new Node
            // Increase Size
            this->tail->next = new_node;
            this->tail = new_node;
        }
        this->size++;
    }

    void remove_first()
    {
        // If Empty List
        // If only 1 Element
        // If more than 1 element
        if (this->size == 0)
        {
            std::cout << "List is Empty";
        }
        else if (this->size == 1)
        {
            delete this->head;
            this->head = this->tail = nullptr;
            this->size--;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            this->size--;
        }
    }

    int get_first_node()
    {
        if (this->size == 0)
        {
            std::cout << "List is Empty";
            return -1;
        }
        return this->head->data;
    }

    int get_last_node()
    {
        if (this->size == 0)
        {
            std::cout << "List is Empty";
            return -1;
        }
        return this->tail->data;
    }

    int get_at(int index)
    {
        if (this->size == 0)
        {
            std::cout << "List is Empty";
            return -1;
        }

        if (index < 0 || index >= this->size)
        {
            std::cout << "Out of bound";
            return -1;
        }

        Node *temp = head;

        while (index)
        {
            temp = temp->next;
            index--;
        }

        return temp->data;
    }

    void add_first(int data)
    {
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next = this->head;
        this->head = new_node;
        if (this->size == 0)
        {
            this->tail = new_node;
        }
        this->size++;
    }

    void add_at(int index, int data)
    {
        if (index < 0 || index >= this->size)
        {
            std::cout << "Invalid Index";
            return;
        }
        else if (index == 0)
        {
            this->add_first(data);
        }
        else if (index == size - 1)
        {
            this->add_last(data);
        }
        else
        {
            Node *new_node = new Node;
            new_node->data = data;

            Node *temp = head;
            for (int ptr = 0; ptr < index - 1; ptr++)
            { // ELement BEfore index
                temp = temp->next;
            }

            new_node->next = temp->next;
            temp->next = new_node;

            this->size++;
        }
    }

    void remove_last()
    {
        if (this->size == 0)
        {
            std::cout << "List is Empty";
        }
        else if (this->size == 1)
        {
            Node *temp = this->head;
            delete temp;
            this->head = this->tail = nullptr;
            this->size--;
        }
        else
        {
            Node *temp = this->head;

            while (temp->next->next != nullptr)
            {
                temp = temp->next;
            }

            delete this->tail;
            this->tail = temp;
            this->tail = nullptr;
            this->size--;
        }
    }

    Node *get_node_at(int index)
    {
        Node *temp = head;

        while (index)
        {
            temp = temp->next;
            index--;
        }

        return temp; // Returning Pointer to Node
    }

    void reverse_data_iterative()
    {
        int left = 0;
        int right = size - 1;

        while (left < right)
        {
            Node *leftNode = get_node_at(left);
            Node *rightNode = get_node_at(right);

            int temp = leftNode->data;
            leftNode->data = rightNode->data;
            rightNode->data = leftNode->data;

            left++;
            right--;
        }
    }

private:
    Node *head;
    Node *tail;
    int size;
};

int main()
{
    LinkedList list;
    list.add_last(40);
    list.add_last(760);
    list.add_last(4450);
    list.add_last(1);
    list.add_last(2);
    list.add_last(1231);
    list.add_last(5546);
    list.display_list();
    std::cout << std::endl;
    std::cout << list.get_size();
    std::cout << std::endl;
    list.remove_first();
    list.display_list();
    std::cout << std::endl;
    std::cout << list.get_first_node();
    std::cout << std::endl;
    std::cout << list.get_last_node();
    std::cout << std::endl;
    std::cout << list.get_at(5);
    std::cout << std::endl;
    list.reverse_data_iterative();
    list.display_list();
    return 0;
}