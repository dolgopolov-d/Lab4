#include "Claster.h"


	bool TClaster::ProgAppear()
	{
		int r;
		srand(time(0) + f);
		f += 10;
		r = rand() % 100;
		if (r < freaquency)
			return true;
		else
			return false;
	}
	void TClaster::DoTact()
	{
		int temp = 1;
		while (temp != tacts + 1)
		{
			for (int i = 0; i < MaxProgramsRunnig; i++)
			{
				if (is_running[i] == true)
					if (temp - run_beginnig_tact[i] == running[i].GetCores())
					{
						is_running[i] = false;
						free_cores += running[i].GetCores();
						run_count--;
						running_now--;
						done_progs++;
					}
			}
			if (ProgAppear())
			{
				TProgram p;
				all_progs++;
				if (p.GetCores() > core_count)
				{
					rejected_progs++;
					temp++;
					continue;
				}
				else
					if (q.IsFull())
					{
						rejected_progs++;
						temp++;
						continue;
					}
					else
						q.Put(p);


				if (q.FirstEl().GetCores() > free_cores)
				{
					temp++;
					continue;
				}
				else
				{
					TProgram tmp = q.Pop();
					running[run_count] = tmp;
					is_running[run_count] = true;
					run_beginnig_tact[run_count] = temp;
					run_count++;
					running_now++;
					free_cores = free_cores - tmp.GetCores();
				}

			}
			else
			{
				temp++;
				continue;
			}
			temp++;
		}
		while (!q.IsEmpty())
		{
			not_done_progs++;
			q.Pop();
		}
	}
	int TClaster::GetAllProgs()
	{
		return all_progs;
	}
	int TClaster::GetRunningNow()
	{
		return running_now;
	}
	int TClaster::GetRejected()
	{
		return rejected_progs;
	}
	int TClaster::GetDone()
	{
		return done_progs;
	}
	int TClaster::GetNotDone()
	{
		return not_done_progs;
	}