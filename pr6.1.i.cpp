#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

void Create(int* p, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		p[i] = Low + rand() % (High - Low + 1);
}

void Print(int* p, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << p[i];
	cout << endl;
}

int Count(const int p[], const int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (!(p[i] % 2 == 0 && i % 13 == 0))
		{
			count++;
		}
	}
	return count;
}

int Sum(int* p, const int size)
{
	int S = 0;
	for (int i = 0; i < size; i++) {
		if (!(p[i] % 2 == 0 && i % 13 == 0)) {
			S += p[i];
		}
	}
	return S;
}

// Функція заміни нулями елементів за критерієм
void Replace(int p[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!(p[i] % 2 == 0 && i % 13 == 0))
		{
			p[i] = 0;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	const int n = 25;       
	int p[n];
	int Low = 15;           
	int High = 94;          

	Create(p, n, Low, High);
	cout << "Started massiv:\n";
	Print(p, n);

	int totalCount = Count(p, n);
	int totalSum = Sum(p, n);

	cout << "Sum of elements = " << totalSum << endl;
	cout << "Count of elements = " << totalCount << endl;

	Replace(p, n);
	cout << "Modified massiv:\n";
	Print(p, n);

	return 0;
}