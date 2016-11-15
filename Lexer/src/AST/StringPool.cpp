#include "stdafx.h"

#include "StringPool.h"
#include <cassert>

CStringPool::CStringPool()
{

}

unsigned CStringPool::Insert(const std::string &str)
{
	if (m_mapping.size())
	{
		auto it = m_mapping.find(str);
		if (it != m_mapping.end())
		{
			return it->second;
		}
	}
	
	
    
	// TODO : see why not work map
    auto nextId = unsigned(m_pool.size());
    m_pool.push_back(str);
	m_mapping[str] = nextId;
    return nextId;
}

std::string CStringPool::GetString(unsigned id) const
{
    return m_pool[id];
}
