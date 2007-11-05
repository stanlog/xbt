#if !defined(AFX_MERKLE_TREE_H__3C33F874_B781_4D36_B51F_3251B71B96A5__INCLUDED_)
#define AFX_MERKLE_TREE_H__3C33F874_B781_4D36_B51F_3251B71B96A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "virtual_binary.h"

class Cmerkle_tree
{
public:
	static std::string compute_root(const_memory_range);
	void invalidate();
	const_memory_range root() const;
	void root(const_memory_range);
	int load(const Cvirtual_binary&);
	Cvirtual_binary save() const;
	std::ostream& operator<<(std::ostream& os) const;
	const_memory_range get(int i) const;
	std::string get(int i, int c) const;
	bool has(int i) const;
	void resize(int);
	void set(int i, const_memory_range);
	void set(int i, const_memory_range, const_memory_range);
	bool test(int i, const_memory_range, const_memory_range);
	bool test_and_set(int i, const_memory_range, const_memory_range);
	Cmerkle_tree();

	int size() const
	{
		return m_size;
	}
private:
	char* d(int);
	const char* d(int) const;
	const_memory_range get0(int) const;
	void set0(int, const_memory_range);

	Cvirtual_binary m_d;
	int m_size;
};

std::ostream& operator<<(std::ostream&, const Cmerkle_tree&);

#endif // !defined(AFX_MERKLE_TREE_H__3C33F874_B781_4D36_B51F_3251B71B96A5__INCLUDED_)
