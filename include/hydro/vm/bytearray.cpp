//
//                 __  __            __           
//                / / / /__  __ ____/ /_____ ____ 
//               / /_/ // / / // __  // ___// __ \
//              / __  // /_/ // /_/ // /   / /_/ /
//             /_/ /_/ \__, / \__,_//_/    \____/ 
//                    /____/                      
//
//              The Hydro Programming Language
//

#include "bytearray.hpp"

namespace hydro
{

// default constructor
bytearray::bytearray()
{
	mmBuffer = new uint8_t[1];
	m_capacity = 1;
	m_size = 0;
	mmPos = 0;
}

// copy constructor
bytearray::bytearray(const bytearray &bytes)
{
	m_capacity = bytes.m_capacity;
	m_size = bytes.m_size;
	mmBuffer = new uint8_t[m_capacity];
	mmPos = bytes.mmPos;

	// copy
	for (uint32_t i = 0; i < m_capacity; i++)
		mmBuffer = bytes.mmBuffer;
}

// move constructor
bytearray::bytearray(bytearray &&bytes)
{
	mmBuffer = bytes.mmBuffer;
	m_size = bytes.m_size;
	m_capacity = bytes.m_capacity;
	mmPos = bytes.mmPos;
}

// destructor
bytearray::~bytearray()
{
	delete[] mmBuffer;
}

void bytearray::resize(uint32_t newSize)
{
	if (newSize > m_capacity)
	{
		// ensure capacity
		reserve(newSize * 2);
	}

	m_size = newSize;
}

void bytearray::reserve(uint32_t newCapacity)
{
	if (newCapacity <= m_capacity)
		return;

	uint8_t *tmp = new uint8_t[newCapacity];
	uint32_t i;

	// copy
	for (i = 0; i < m_capacity; i++)
		tmp[i] = mmBuffer[i];

	// populate temporary bytes
	for (; i < newCapacity; i++)
		tmp[i] = 0; // default

	delete [] mmBuffer;
	mmBuffer = tmp;
	m_capacity = newCapacity;
}

void bytearray::put(uint8_t value)
{
	put(value, mmPos);
}

void bytearray::put(uint8_t value, uint32_t &pos)
{
	if (pos >= m_size)
		resize(pos + 1);

	mmBuffer[pos] = value;
	pos++;
}

void bytearray::putInt(int32_t value)
{
	putInt(value, mmPos);
}

void bytearray::putInt(int32_t value, uint32_t &pos)
{
    if(pos + 4 >= m_size)
        resize(pos + 4);

	// write byte from highest to lowest byte
	mmBuffer[pos++] = (uint8_t)((value >> (8 * 3)) & 0xff);
	mmBuffer[pos++] = (uint8_t)((value >> (8 * 2)) & 0xff);
	mmBuffer[pos++] = (uint8_t)((value >> (8 * 1)) & 0xff);
	mmBuffer[pos++] = (uint8_t)(value & 0xff);
}

uint8_t bytearray::get()
{
	return get(mmPos);
}

uint8_t bytearray::get(uint32_t &pos)
{
	if (pos < m_size)
		return mmBuffer[pos++];

	// out of bounds
	pos++;
	return 0;
}

int32_t bytearray::getInt()
{
	return getInt(mmPos);
}

int32_t bytearray::getInt(uint32_t &pos)
{
	if (pos + 4 <= m_size)
	{
		int32_t b1 = mmBuffer[pos++] & 0xff;
		int32_t b2 = mmBuffer[pos++] & 0xff;
		int32_t b3 = mmBuffer[pos++] & 0xff;
		int32_t b4 = mmBuffer[pos++] & 0xff;
		int32_t word = b1 << (8 * 3) | b2 << (8 * 2) | b3 << (8 * 1) | b4;
		return word;
	}

	// out of bounds
	pos += 4;
	return 0;
}

void bytearray::seek(uint32_t pos)
{
	mmPos = pos;
}

void bytearray::reset()
{
	mmPos = 0;
}

void bytearray::clear()
{
	delete[] mmBuffer;
	mmBuffer = new uint8_t[1];
	m_capacity = 1;
	m_size = 0;
	mmPos = 0;
}

void bytearray::freeUnusedMemory()
{
	if (m_size < m_capacity)
	{
		uint8_t *tmp = new uint8_t[m_size];

		// copy
		for (uint32_t i = 0; i < m_size; i++)
			tmp[i] = mmBuffer[i];

		delete mmBuffer;
		mmBuffer = tmp;
		m_capacity = m_size;
	}
}

bool bytearray::operator==(const bytearray &rhs) const
{
	if (rhs.m_size != m_size)
		return false; // fail

	// compare
	for (uint32_t i = 0; i < m_size; i++)
		if (mmBuffer[i] != rhs.mmBuffer[i])
			return false; // fail

	// success!
	return true;
}

bool bytearray::operator!=(const bytearray &rhs) const
{
	if (rhs.m_size != m_size)
		return true; // success!

	// compare
	for (uint32_t i = 0; i < m_size; i++)
		if (mmBuffer[i] != rhs.mmBuffer[i])
			return true; // success!

	// fail
	return false;
}

// copy assignment
bytearray &bytearray::operator=(const bytearray &rhs)
{
	delete[] mmBuffer; // free
	m_capacity = rhs.m_capacity;
	m_size = rhs.m_size;
	mmBuffer = new uint8_t[m_capacity];
	mmPos = rhs.mmPos;

	// copy
	for (uint32_t i = 0; i < m_capacity; i++)
		mmBuffer[i] = rhs.mmBuffer[i];

	return (*this);
}

// move assignment
bytearray &bytearray::operator=(bytearray &&rhs)
{
	delete[] mmBuffer; // free
	mmBuffer = rhs.mmBuffer;
	m_size = rhs.m_size;
	m_capacity = rhs.m_capacity;
	mmPos = rhs.mmPos;
	return (*this);
}

} // namespace hydro
