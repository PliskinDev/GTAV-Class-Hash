#include <cstdint>
#include <cstdio>
#include <typeinfo>

constexpr uint32_t joaat(const char* str, uint32_t hash = 0)
{
    while (*str)
    {
        hash += static_cast<unsigned int>(*str);
        hash += (hash << 10);
        hash ^= (hash >> 6);
        ++str;
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}

template<typename T>
constexpr uint32_t hash()
{
    return joaat(typeid(T).name());
}

class myClass {};

int main()
{
    constexpr uint32_t myclass_hash = hash<myClass>();
}