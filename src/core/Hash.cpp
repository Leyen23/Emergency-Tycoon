
#include "core/Hash.hpp"
//kv (clave-valor)

namespace core
{
    template<typename Key, typename T>

    HashTable<Key, T>::HashTable(size_t bucketcount, double maxloadfactor)
    : buckets_(bucketcount), elementcount_(0), maxloadfactor_(maxloadfactor){}

//insert el vlor o actualiza para la clave
template<typename Key, typename T>

void HashTable<Key, T>::insert(const Key& key, const T& value) {
    
    if ((double)(elementcount_ + 1) / buckets_.size() > maxloadfactor_) 
        {
        rehash(buckets_.size() * 2);
    }
    size_t idx = bucketIndex(key);
    for (auto& kv : buckets_[idx]) {
        if (kv.first == key) {
            kv.second = value;
            return;
        }
    }
    buckets_[idx].emplace_back(key, value);
    ++elementcount_;
}

// Borra la entrada con la clave dada
template<typename Key, typename T>

void HashTable<Key, T>::erase(const Key& key) {
    size_t idx = bucketIndex(key);
    auto& bucket = buckets_[idx];
    
    for (auto it = bucket.begin(); it != bucket.end(); ++it) 
    {
        if (it->first == key) 
            {
            bucket.erase(it);
            --elementcount_;
            return;
        }
    }
    throw std::out_of_range("HashTable::erase: Key not found");
}

// Acceso con verificación de existencia
template<typename Key, typename T>

T& HashTable<Key, T>::at(const Key& key) 
    {
    size_t idx = bucketIndex(key);
    for (auto& kv : buckets_[idx]) 
            {
        if (kv.first == key) 
            {
            return kv.second;
        }
    }
    throw std::out_of_range("HashTable::at: Key not found");
}

template<typename Key, typename T>
//Verifica existencia
const T& HashTable<Key, T>::at(const Key& key) const 
    {
    size_t idx = bucketIndex(key);
    for (const auto& kv : buckets_[idx]) 
            {
        if (kv.first == key) 
            {
            return kv.second;
        }
    }
    throw std::out_of_range("HashTable::at: Key not found");
}

//si no existe, inserta un valor por defecto y lo retorna
template<typename Key, typename T>

T& HashTable<Key, T>::operator[](const Key& key)
    {
    size_t idx = bucketIndex(key);
    for (auto& kv : buckets_[idx]) 
        {
        if (kv.first == key) 
            {
            return kv.second;
        }
    }

    buckets_[idx].emplace_back(key, T{});
    ++elementcount_;
    
    if ((double)elementcount_ / buckets_.size() > maxloadfactor_) 
        {
        rehash(buckets_.size() * 2);
    }

    return buckets_[idx].back().second;
}

// Comprueba si existe la clave
template<typename Key, typename T>

bool HashTable<Key, T>::contains(const Key& key) const 
    {
    size_t idx = bucketIndex(key);
    for (const auto& kv : buckets_[idx]) 
        {
        if (kv.first == key) 
            {
            return true;
        }
        return false;
    }
}

// Número de elementos almacenados
template<typename Key, typename T>

size_t HashTable<Key, T>::size() const noexcept 
    {
    return elementcount_;
}

// True si no hay elementos
template<typename Key, typename T>

bool HashTable<Key, T>::empty() const noexcept 
    {
    return elementcount_ == 0;
}

// Vacía la tabla
template<typename Key, typename T>

void HashTable<Key, T>::clear() noexcept 
{
    for (auto& bucket : buckets_) bucket.clear();
    elementcount_ = 0;
}

// Calcula el índice del bucket para una clave
template<typename Key, typename T>

size_t HashTable<Key, T>::bucketIndex(const Key& key) const 
    {
    return std::hash<Key>{}(key) % buckets_.size();
}

// Rehasea la tabla a newBucketCount buckets
template<typename Key, typename T>

void HashTable<Key, T>::rehash(size_t newBucketCount) 
    {
    std::vector<std::list<std::pair<Key, T>>> newBuckets(newBucketCount);
    for (auto& bucket : buckets_) 
        {
        for (auto& kv : bucket) 
            {
            size_t idx = std::hash<Key>{}(kv.first) % newBucketCount;
            newBuckets[idx].emplace_back(std::move(kv));
        }
    }
    buckets_.swap(newBuckets);
}
template class core::HashTable<std::string, std::string>;

} 


