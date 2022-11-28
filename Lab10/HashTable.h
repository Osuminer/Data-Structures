#pragma once

#include <vector>

template <typename KeyType, typename DataType>
class HashTable {
    public:
        HashTable() = delete;
        HashTable(int maxSize) {
            m_maxSize = maxSize;
            m_table.resize(m_maxSize);
        }

        ~HashTable();

        int Hash(KeyType& key) {
            return (int)key % m_maxSize;
        }

        void AddItem(DataType& item) {
            int place = Hash(item);
            while (m_table.at(place).data != item.data){
                place++;
            }
            m_table.at(place) = item;
        }
        DataType* GetItem(KeyType&);

        int Contains() {
            return m_size;
        }


    private:
        int m_size;
        int m_maxSize;
        std::vector<DataType> m_table;
};
