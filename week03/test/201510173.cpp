#include <iostream>

struct Node {
    int value;
    Node *next;

    explicit Node(int value) {
        this->value = value;
        this->next = nullptr;
    };
};

class List {
private:
    Node *head;
public:
    List();

    void append(int value);

    int pop();

    void add_front(int value);

    void print();

};

// append: [3,d1] -> [5,d2] -> [2,d3] -> [new_value, new_adress]
void List::append(int value) {
    Node *node = new Node(value);
    if (this->head == nullptr) {
        head = node;
    } else {
        Node *tmp = head;
        while (tmp->next != nullptr) {
            tmp->next;
        }
        tmp->next = node;
    };
}

// addfront: [new_value, new_adress] -> [3,d1] -> [5,d2] -> [2,d3]
void List::add_front(int value) {
    Node *node = new Node(value);
    node->next = head;
    head = node;
}

// pop: [3,d1] -> [5,d2] -> ([2,d3] deleted !!)
int List::pop() {
    if (head->next == nullptr) {
        int data = head->value;
        delete head;
        head = nullptr;
        return data;
    }

    Node *tmp = head;

    while (tmp->next->next != nullptr) {
        tmp = tmp->next;
    }

    int data = tmp->next->value;
    delete tmp->next;
    tmp->next = nullptr;
    return data;
}

void List::print(){
    std::cout << "HEAD:" << head->value;
    Node *tmp = head;
    while (tmp->next != nullptr) {
        std::cout << tmp->value;
        tmp = tmp->next;
    }
}

List::List() {
    head = nullptr;
}


// TEST
