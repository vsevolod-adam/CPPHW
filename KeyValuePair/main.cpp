#include <iostream>
#include <iomanip>

#include "pair_kv.h"
#include "byte_tools.h"

void printVec(const std::vector<uint8_t>& v)
{
    for (auto b : v)
        std::cout << std::hex << (int)b << " ";
    std::cout << std::dec << "\n";
}

int main()
{
    PairKV<int, std::string> a(1, "One");
    a.show();

    PairKV<int, std::string> b(2, "Two");

    std::cout << a.getKey() << "\n";
    std::cout << a.getValue() << "\n";

    a.updateKey(10);
    a.updateValue("Ten");

    a.show();

    std::cout << std::boolalpha << a.sameAs(b) << "\n";

    PairKV<int, std::string> c(100, "Hundred");

    a.exchange(c);

    a.show();
    c.show();

    PairKV<std::string, double> d("Cost", 55.5);
    d.show();

    uint32_t x = 0x12345678;

    auto l = convertBytes(x, Endian::LittleEndian);
    auto g = convertBytes(x, Endian::BigEndian);

    printVec(l);
    printVec(g);

    std::cout << verifyBytes<uint32_t>(0x12345678, Endian::LittleEndian,
        {0x78, 0x56, 0x34, 0x12}) << "\n";

    std::cout << verifyBytes<uint16_t>(0x1234, Endian::BigEndian,
        {0x12, 0x34}) << "\n";

    return 0;
}