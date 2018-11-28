#ifndef __PROGRAM_H__
#define __PROGRAM_H__
#include <time.h>
#include <random>
using namespace std;

class TProgram
{
	int f;
	int tacts;
	int cores;
public:
	TProgram()
	{
		srand(time(0));
		tacts = rand() % 20 + 1;
		srand(time(0) + f);
		f += 100;
		cores = rand() % 10 + 1;
	}
	TProgram operator= (const TProgram&p)
	{
		this->tacts = p.tacts;
		this->cores = p.cores;
		return *this;
	}
	int GetTacts()
	{
		return tacts;
	}
	int GetCores()
	{
		return cores;
	}
};
#endif