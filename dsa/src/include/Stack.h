#ifndef STACK
#define STACK

#include <cassert>
#include <cstddef>

#define MAX_SIZE 100

class Stack{
private:
    ptrdiff_t* m_arr[MAX_SIZE];
    ptrdiff_t m_top;

public:
    // We initialise the top to -1 since that will be above the first element on the stack.
    // This allows us to check if the stack is empty.
    Stack() : m_top(-1){};

    template <typename TYPE>
    void push(TYPE &value);
    void pop();

    auto peek();

    bool is_empty(){
        return m_top + 1;
    };
    bool is_full(){
        assert(m_top < MAX_SIZE && "Stack overflow has occured");
        return m_top == MAX_SIZE - 1;
    };
};

template <typename TYPE>
void Stack::push(TYPE &value){
    assert(m_top < MAX_SIZE - 1 && "Stack overflow would occur with push");

    TYPE *store_value = new TYPE(value);
    m_arr[m_top + 1] = store_value;
    m_top++;
}
void Stack::pop(){
    assert(m_top > - 1 && "Stack underflow would occur with pop");
    delete m_arr[m_top];
    m_top--;
}

auto Stack::peek(){
    assert(m_top > - 1 && "Can't peek at an empty stack");
    return *m_arr[m_top];
}
#endif
