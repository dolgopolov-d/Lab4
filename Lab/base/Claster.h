#include <vector>
#include <string>
#include <time.h>
#include <random>
#include "program.h"
#include "queue.h"
const int MaxProgramsRunnig = 1000;
using namespace std;

class TClaster
{
	int f;
	int run_count = 0;                           //| Вспомогательные переменные для запущенных программ       
	TProgram running[MaxProgramsRunnig];         //|
	bool is_running[MaxProgramsRunnig];          //|
	int run_beginnig_tact[MaxProgramsRunnig];    //|
	TQueue q;
	double free_cores;
	double core_count;
	int tacts;
	int freaquency;
	int running_now = 0;
	int all_progs = 0;                           //|Кол-во всех программ
	int rejected_progs = 0;                      //|Кол-во отказов от выполнения
	int done_progs = 0;                          //|Кол-во сделанных программ
	int not_done_progs = 0;                      //|Кол-во несделаных программ
public:
	TClaster(double node = 2, double processor = 2, double core = 2, int _tacts = 0, int _freaquency = 50)
	{
		freaquency = _freaquency;
		tacts = _tacts;
		core_count = node * processor * core;
		free_cores = core_count;
		for (int i = 0; i < MaxProgramsRunnig; i++)
			is_running[i] = false;
	}
	bool ProgAppear();
	void DoTact();
	int GetAllProgs();
	int GetRunningNow();
	int GetRejected();
	int GetDone();
	int GetNotDone();
};