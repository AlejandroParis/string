#ifndef __p2String_H__
#define __p2String_H__

#include <string.h>

class p2String
{
public:

	// Constructors
	p2String()
	{
		Alloc(1);
		clear();
	}

	p2String(const p2String& string)
	{
		Alloc(string.length() + 1);
		strcpy_s(str, max_capacity, string.str);
	}

	p2String(const char *string)
	{
		if (string != nullptr)
		{
			Alloc(strlen(string) + 1);
			strcpy_s(str, max_capacity, string);
		}
		else
		{
			Alloc(1);
			clear();
		}
	}

	int length() const
	{
		return strlen(str);
	}

	void clear()
	{
		str[0] = '\0';
	}

	int capacity() const
	{
		return max_capacity;
	}

private:

	void Alloc(unsigned int required_memory)
	{
		max_capacity = required_memory;
		str = new char[max_capacity];
	}

private:

	char* str;
	int max_capacity;

};

#endif 
