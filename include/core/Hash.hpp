#pragma once 

#include <vector>
#include <list>
#include <utility>
#include <stdexcept>
#include <functional>

namespace core
{
    template<typename Key, typename T>
    class HashTable 
    {
        public:
        //redimensiona la tabla si llega al limite de 0.75 del size actual
        explicit HashTable(size_t bucketCount = 16, double maxlodfactor = 0.75);
        
        //acceso de verificacion 
        T& at(const Key& key);
        const T& at(const Key& key) const;

        // inserta si no existe un valor
        T& operator [](const Key& key);

        void insert(const Key& key,const T& value);

        //borra la clave dada, arroja out range si no existe
        void erase(const Key& Key);

        // comprueba la existencia de la clave
        bool contains(const Key& key) const;
        
        //Vacia la lista
        bool empty() const noexcept;
        
        //numero de elementos 
        size_t size () const noexcept;

        void clear() noexcept;

        private:

        std::vector<std::list<std::pair<Key, T>>> buckets_;
        size_t elementcount_;
        double maxloadFactor_;

        size_t bucketIndex(const Key& key) const;

        //rehashea
        void rehash(size_t newbucketcount);
    };
}