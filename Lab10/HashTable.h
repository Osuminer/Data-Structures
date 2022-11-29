#pragma once

#include <vector>

template <typename KeyType, typename DataType>
class HashTable {
    public:
        /// @brief No default constructor
        HashTable() = delete;

        /// @brief Constructor for max size input
        /// @param maxSize The max size of the table
        HashTable(int maxSize) {
            m_maxSize = maxSize;
            m_table.resize(m_maxSize);
        }

        ~HashTable() {}

        /// @brief Return the int hash of the key
        /// @param key The key value
        /// @return 
        int Hash(KeyType& key) {
            int retVal = (int)key % m_maxSize;
            return retVal;
        }

        /// @brief Bad hash function that only returns 0
        /// @param key The key value
        /// @return 
        int BadHash(KeyType& key) {
            return 0;
        }

        /// @brief Add an item into the hash table via linear probing
        /// @param item Item to add
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

        /// @brief Bad way to add item(hash is always 0)
        /// @param item Item to add
        void BadAddItem(DataType& item) {
            int place = BadHash(item.key);
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

        /// @brief Returns pointer to the item from the hash table
        /// @param item The item to find
        /// @return 
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

        /// @brief Returns the number of items in the hash table
        /// @return 
        int Contains() {
            return m_size;
        }

    private:
        int m_size = 0;
        int m_maxSize;
        std::vector<DataType> m_table;
};
