#ifndef __p2String_H__
#define __p2String_H__
#include <string.h>
#include <assert.h>
class String
{
public:

	// Constructors
	String()
	{
		Alloc(1);
		clear();
	}

	String(const String& string)
	{
		assert(string.str);
		if (string.str != nullptr)
		{
			Alloc(string.length() + 1);
			strcpy_s(str, max_capacity, string.str);
		}
	}

	String(const char* string)
	{
		assert(string != nullptr);
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

	~String() 
	{
		if (str != nullptr)
		{
			delete[] str;
			str = nullptr;
			max_capacity = 0;
		}
	}

	const char* operator=(const char* string) 
	{
		assert(string != nullptr);
		if (string != nullptr)
		{
			if (strlen(string) >= max_capacity)
			{
				delete[] str;
			}
			Alloc(strlen(string) + 1);
			strcpy_s(str, max_capacity, string);
		}
		return string;
	}

	char* getString()
	{
		return str;
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
