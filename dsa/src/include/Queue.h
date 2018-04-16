#ifndef QUEUE
#define QUEUE

#include <cassert>
#include <cstddef>

#define MAX_SIZE 100

class Queue{
private:
    ptrdiff_t* m_arr[MAX_SIZE];
    ptrdiff_t m_front;
    ptrdiff_t m_back;
    int m_size(){
        return m_back - m_front;
    };

public:
    // We initialise the top to -1 since that will be above the first element on the stack.
    // This allows us to check if the stack is empty.
    Queue() :  m_front(-1), m_back(-1){};

    template <typename TYPE>
    void enqueue(TYPE &value);
    auto dequeue();

    auto peek();

    bool is_empty(){
        return m_size();
    };
    bool is_full(){
        return m_size() == MAX_SIZE;
    };
};

template <typename TYPE>
void Queue::enqueue(TYPE &value){
    if(m_size() < MAX_SIZE && m_back == MAX_SIZE - 1){
        ptrdiff_t* tmp_arr[MAX_SIZE];
        ptrdiff_t size = m_size();
        for(ptrdiff_t i = 0; i < size; ++i){
            tmp_arr[i] = m_arr[m_front + 1 + i];
        }
        m_front = -1;
        m_back  = size - 1;
        m_arr = tmp_arr;
    }

    assert(m_back < MAX_SIZE - 1 && "Queue overflow would occur with enqueue");
    TYPE *store_value = new TYPE(value);
    m_arr[m_back + 1] = store_value;
    m_back++;
}
auto Queue::dequeue(){
    assert(m_size() > 0 && "Queue underflow would occur with dequeue");
    auto tmp = *m_arr[m_front + 1];
    delete m_arr[m_front + 1];
    m_front++;
    return tmp;
}

auto Queue::peek(){
    assert(m_back > - 1 && "Can't peek at an empty Queue");
    return *m_arr[m_front + 1];
}


#endif
