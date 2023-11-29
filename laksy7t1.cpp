
#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
    static const int MAX_SIZE = 100; 
    T elements[MAX_SIZE]; 
    int top; 

public:
    Stack() : top(-1) {} 

    void push(const T& item) {
        if (top >= MAX_SIZE - 1) {
            throw std::overflow_error("Ylivuoto");
        }
        elements[++top] = item;
    }

    T pop() {
        if (top < 0) {
            throw std::underflow_error("Alivuoto");
        }
        return elements[top--];
    }

    int size() const {
        return top + 1;
    }
};

int main() {
    // Testipääohjelma
    Stack<int> intStack;
    intStack.push(5);
    intStack.push(10);
    std::cout << "IntStackin koko: " << intStack.size() << std::endl;

    int poppedInt = intStack.pop();
    std::cout << "Poppattu integer: " << poppedInt << std::endl;
    std::cout << "IntStackin koko popin jalkeen: " << intStack.size() << std::endl;

    Stack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    std::cout << "Stringstackin koko: " << stringStack.size() << std::endl;

    std::string poppedString = stringStack.pop();
    std::cout << "Poks! " << poppedString << std::endl;
    std::cout << "Stringstackin koko popin jälkeen: " << stringStack.size() << std::endl;

    return 0;
}
