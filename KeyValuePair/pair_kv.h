#pragma once

#include <iostream>
#include <utility>

template<typename K, typename V>
class PairKV
{
private:
    K k;
    V v;

public:
    PairKV(K key, V value)
    {
        k = key;
        v = value;
    }

    K getKey() const
    {
        return k;
    }

    V getValue() const
    {
        return v;
    }

    void updateKey(K newKey)
    {
        k = newKey;
    }

    void updateValue(V newValue)
    {
        v = newValue;
    }

    bool sameAs(const PairKV<K, V>& other) const
    {
        return (k == other.k && v == other.v);
    }

    void exchange(PairKV<K, V>& other)
    {
        PairKV<K, V> temp = *this;
        k = other.k;
        v = other.v;
        other.k = temp.k;
        other.v = temp.v;
    }

    void show() const
    {
        std::cout << "[" << k << " -> " << v << "]\n";
    }
};