#pragma once

#include <vector>
#include <cstdint>
#include <type_traits>
#include <cstring>
#include <algorithm>

enum class Endian
{
    LittleEndian,
    BigEndian
};

template<typename T>
std::vector<uint8_t> convertBytes(T value, Endian type)
{
    static_assert(std::is_integral<T>::value, "Only integers allowed");

    std::vector<uint8_t> buffer(sizeof(T));

    std::memcpy(buffer.data(), &value, sizeof(T));

    if (type == Endian::BigEndian)
    {
        std::reverse(buffer.begin(), buffer.end());
    }

    return buffer;
}

template<typename T>
bool verifyBytes(T value, Endian type, const std::vector<uint8_t>& expected)
{
    return convertBytes(value, type) == expected;
}