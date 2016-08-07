#ifndef _INSTANCE_H_
#define _INSTANCE_H_

void* operator new(unsigned, void* ptr)
{
	return ptr;
}

template<typename T, int N = 0>
struct Instance
{
	template<typename... Args>
	static T& CreateNoGuard(Args... args)
	{
		static byte data[sizeof(T)];
		return *new(data)T(args...);
	}

	template<typename... Args>
	static T& Create(Args... args)
	{
		/* 

		This code will create guard variable with 8 bytes size.
		I don't want to waste memory, so I use raw buffer & placement new operator.

		static T data(args...);
		return data;
		*/

		/*
		If I use boolean guard and buffer type casting, compiler shows me warning -Fstrict-alias.
		Pointer to data is type-safe, but needs one more byte.
		*/
		static T* ptr;
		static byte data[sizeof(T)];

		if (!ptr)
		{
			ptr = new(data)T(args...);
		}
		return *ptr;
	}
};

#endif

