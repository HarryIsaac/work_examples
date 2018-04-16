#ifndef HASHTABLE
#define HASHTABLE

#include <algorithm>
#include <cassert>
#include <vector>

int* ptr(new int[10]);
class HashTable{
private:
    struct HashNode{
        int m_data;
        int m_key;
        int m_size;
        bool m_init;
        HashNode() : m_init(false){};
        HashNode(int value, int size) : m_data(value), m_size(size), m_init(true){
            m_key = m_data % size;
        };
        void rehash_key(int size){
            assert(m_init && "HashNode must be initialised before hash_key function can be called");
            m_key = m_data % size;
        }
    };

    int m_size(){return m_hashTable.size();};
    std::vector<HashNode> m_hashTable;
    int hash_key(int value){
        return value % m_size();
    }
public:
    HashTable(int size){
        m_hashTable = std::vector<HashNode>(size);
    }


    int  search(int value);
    void resize();
    void insert(int value);
    void remove(int value);
};



int HashTable::search(int value){
    int position = hash_key(value);
    while(m_hashTable.at(position).m_data != value && position <= m_size()){
        position++;
    }
    if(position == m_size()){
        this->resize();
        this->search(value);
    }
    return position;
}
void HashTable::resize(){
    int size_before = m_size();
    int size_after = 2 * size_before;
    std::vector<int> tmp(2 * size_before);

    for(ptrdiff_t i = 0; i < size_before; ++i){
        m_hashTable.at(i).rehash_key(size_after);
        
    }
}
void HashTable::insert(int value){}
void HashTable::remove(int value){}

#endif
