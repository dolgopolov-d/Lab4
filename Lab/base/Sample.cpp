#include "Claster.h"
#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	int tacts, nodes, processors, cores, freaquency;
	cout << "������� ���������� �����: " << endl;
	cin >> nodes;
	cout << "������� ���������� ����������� � ������ ����: " << endl;
	cin >> processors;
	cout << "������� ���������� ���� � ������ ����������: " << endl;
	cin >> cores;
	cout << "������� ������� ��������� �������� �� 0 �� 100: " << endl;
	cin >> freaquency;
	cout << "������� ���������� ������: " << endl;
	cin >> tacts;
	TClaster clast(nodes, processors, cores, tacts, freaquency);
	clast.DoTact();
	cout << "����� ��������: " << clast.GetAllProgs() << endl;
	cout << "���������� � ������ ����������� ������: " << clast.GetRunningNow() << endl;
	cout << "�������� � ����������: " << clast.GetRejected() << endl;
	cout << "�� ���������: " << clast.GetNotDone() << endl;
	cout << "���������: " << clast.GetDone() << endl;
}