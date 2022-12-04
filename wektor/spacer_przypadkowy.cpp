#include "pch.h"
#include <iostream>
#include <cstdlib>    // prototypy funkcji rand() i srand()
#include <ctime>      // prototyp funkcji time()
#include "wektor.h"
using namespace std;
int main()
{ 
	using VECTOR::Vector;
	srand(time(0));   // inicjalizacja generatora liczb pseudolosowych
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;

	std::cout << "Podaj dystans do przej�cia (k aby zako�czy�): ";
	while (std::cin >> target)
	{

		std::cout << "Podasj dlugosc kroku: ";
		cout << "Podasj dlugosc kroku: ";
		if (!(cin >> dstep))
			break;

		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.set(dstep, direction, 'p');
			result = result + step;
			steps++;
		}
		cout << "Po " << steps << " krokach, delikwent "
			"osi�gn�� po�o�enie:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " czyli\n" << result << endl;
		cout << "�rednia d�ugo�� kroku pozornego = "
			<< result.magval() / steps << endl;
		steps = 0;
		result.set(0.0, 0.0);
		cout << "Podaj dystans do przej�cia (k aby zako�czy�): ";
	}
	cout << "Koniec!\n";
	return 0;
}
