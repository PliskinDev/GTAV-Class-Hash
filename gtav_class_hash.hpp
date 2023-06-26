#pragma once

#include <cstdint>
#include <typeinfo>

class ClassHash
{
public:
    template<typename T>
    std::size_t operator()(const T& obj) const 
	{
        const std::type_info& m_type_info = typeid(obj);
        const std::size_t m_size_hash = m_type_info.hash_code();
        std::size_t hash = 0;
        const std::uint8_t* data = reinterpret_cast<const std::uint8_t*>(&obj);
        for (std::size_t i = 0; i < sizeof(obj); ++i) 
		{
            hash += data[i];
            hash += (hash << 10);
            hash ^= (hash >> 6);
        }
        hash += (hash << 3);
        hash ^= (hash >> 11);
        hash += (hash << 15);
        return hash ^ m_size_hash;
    }
};
