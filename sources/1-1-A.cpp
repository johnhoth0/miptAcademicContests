#include <cstdlib>
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <string>

const int DefaultBufferSize = 4;

class Stack {
public:
    Stack();
    Stack( const Stack& ) = delete;
    void operator=( const Stack& ) = delete;
    ~Stack();

    void push(int elem);
    int pop();
    int back();
    void clear();
    int getSize() const;
    bool empty() const;

private:

    int size = 0;

    struct Node {
        int data;
        Node *next;

        Node(int _data) : data(_data), next(nullptr) {}
        Node( const Node& ) = delete;
        void operator=( const Node& ) = delete;
        ~Node() {};
    };

    Node* head;
};



Stack::Stack():
    head(nullptr) {
}


Stack::~Stack()
{
    while (head != nullptr) {
        Node* nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
    }
}

void Stack::push(int elem)
{
    Node* newNode = new Node(elem);
    newNode->next = head;
    size += 1;
    head = newNode;
}

int Stack::pop()
{
    int returnValue = head->data;
    Node* nodeToDelete = head;
    head = head->next;
    delete nodeToDelete;
    size -= 1;
    return returnValue;
}

int Stack::back() {
    return head->data;
}

void Stack::clear() {
    while (head != nullptr) {
        Node* nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
        size -= 1;
    }
}

int Stack::getSize() const {
    return size;
}

bool Stack::empty() const
{
    return getSize() == 0;
}


int main()
{

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Stack st;
    std::string cmd = "banana";
    int num = 0;
    while (cmd != "exit") {
        std::cin >> cmd;
        if (cmd == "push") {
            std::cin >> num;
            st.push(num);
            std::cout << "ok" << std::endl;
        } else if (cmd == "pop") {
            if (st.empty()) {
                std::cout << "error" << std::endl;
            } else {
                std::cout << st.pop() << std::endl;
            }
        } else if (cmd == "back") {
            if (st.empty()) {
                std::cout << "error" << std::endl;
            } else {
                std::cout << st.back() << std::endl;
            }
        } else if (cmd == "size") {
            std::cout << st.getSize() << std::endl;
        } else if (cmd == "clear") {
            st.clear();
            std::cout << "ok" << std::endl;
        } else {
            break;
        }
    }

    std::cout << "bye" << std::endl;

    return 0;
}
