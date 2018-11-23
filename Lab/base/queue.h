#include "program.h"
const int MaxMemSize = 10;

class TQueue
{
	int begin;
	int end;
	int count;
	TProgram mem[MaxMemSize];
public:
	TQueue():begin(-1), end(0), count(0)
	{}
	bool IsEmpty()
	{
		return count == 0;
	}
	bool IsFull()
	{
		return count == MaxMemSize;
	}
	TProgram Pop()
	{
		if (IsEmpty())
			throw;
		count--;
		return mem[(begin++) % MaxMemSize];
	}
	TProgram FirstEl()
	{
		if (IsEmpty())
			throw;
		return mem[begin % MaxMemSize];
	}
	void Put(TProgram &v)
	{
		if (IsFull())
			throw;
		count++;
		mem[end] = v;
		end = (end + 1) % MaxMemSize;
	}
};