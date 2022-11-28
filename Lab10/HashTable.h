#pragma once

#include <vector>
#include <cstddef>

template <typename KeyType, typename DataType>
class HashTable {
    public:
        HashTable() = delete;
        HashTable(int maxSize) {
            m_maxSize = maxSize;
            m_table.resize(m_maxSize);
        }

        ~HashTable() {}

        int Hash(KeyType& key) {
            int retVal = (int)key % m_maxSize;
            return retVal;
        }

        void AddItem(DataType& item) {
            int place = Hash(item.key);
            while (m_table.at(place).data != item.data && m_table.at(place).key != -1){
                if (place >= m_maxSize) {
                    place = 0;
                } else {
                    place++;
                }
            }
            m_table.at(place) = item;
            m_size++;
        }

        DataType* GetItem(DataType& item) {
            int place = Hash(item.key);
            while (m_table.at(place).data != item.data && m_table.at(place).key != -1){
                if (place >= m_maxSize) {
                    place = 0;
                } else {
                    place++;
                }
            }

            return &m_table.at(place);
        }

        int Contains() {
            return m_size;
        }


    private:
        int m_size;
        int m_maxSize;
        std::vector<DataType> m_table;
};
