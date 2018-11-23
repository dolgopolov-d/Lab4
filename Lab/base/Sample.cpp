#include "Claster.h"
#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	int tacts, nodes, processors, cores, freaquency;
	cout << "Введите количество узлов: " << endl;
	cin >> nodes;
	cout << "Введите количество процессоров в каждом узле: " << endl;
	cin >> processors;
	cout << "Введите количество ядер в каждом процессоре: " << endl;
	cin >> cores;
	cout << "Введите частоту появления программ от 0 до 100: " << endl;
	cin >> freaquency;
	cout << "Введите количество тактов: " << endl;
	cin >> tacts;
	TClaster clast(nodes, processors, cores, tacts, freaquency);
	clast.DoTact();
	cout << "Всего программ: " << clast.GetAllProgs() << endl;
	cout << "Выплнялись в момент прекращения работы: " << clast.GetRunningNow() << endl;
	cout << "Отказано в выполнении: " << clast.GetRejected() << endl;
	cout << "Не выполнено: " << clast.GetNotDone() << endl;
	cout << "Выполнено: " << clast.GetDone() << endl;
}