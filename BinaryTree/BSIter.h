#pragma once



template<typename PtrType>
class Iterator
{
protected:
	PtrType m_ptr;
public:

	Iterator(PtrType ptr) : m_ptr(ptr) {}
	virtual bool isDone() = 0;
	virtual void next() = 0;
	virtual void curr() = 0;
};



template<typename PtrType>
class SimpleIterator : Iterator<PtrType>
{

public:

	SimpleIterator(PtrType ptr) : Iterator(ptr) {}
	virtual bool isDone();
	virtual void next();
	virtual void curr();
};