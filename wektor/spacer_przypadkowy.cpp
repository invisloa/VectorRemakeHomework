// test klasy Vector
// kompilowaæ  plikiem vect.cpp
#include <iostream>
#include <cstdlib>    // prototypy funkcji rand() i srand()
#include <ctime>      // prototyp funkcji time()
#include <iomanip>
#include <fstream>                  // plikowe wejœcie-wyjœcie

#include "wektor.h"
#include "matrix.h"

using namespace std;


void PrintMatrix();
void wypiszWartosci(VECTOR::Matrix matrix);
VECTOR::Matrix getMatrixValues();

int main()
{
	using namespace std;
	using VECTOR::Vector;
	// srand(time(0));   // inicjalizacja generatora liczb pseudolosowych,
	char end = 'N';

	while (end && toupper(end) != 'K')
	{
		VECTOR::Matrix Matrix1 = getMatrixValues();
		VECTOR::Matrix Matrix2 = getMatrixValues();

		cout << "Twoje macierze to: " << endl;
		cout << Matrix1;
		cout << Matrix2;


		cout << "Podaj jaka operacje chcesz wykonac na macierzach" << endl;
		cout << "(D)-dodawanie, (O)-odejmowanie, (M)-mnozenie przez liczbe" << endl;
		char dzialanie;
		cin >> dzialanie;

		if (toupper(dzialanie) == 'D')
		{
			cout << "Suma dodawania dwoch macierzy to:" << endl;
			VECTOR::Matrix Matrix3 = Matrix1 + Matrix2;
			cout << Matrix3 << endl;
		}
		else if (toupper(dzialanie) == 'O')
		{
			cout << "Iloczyn odejmowania dwoch macierzy to:" << endl;
			VECTOR::Matrix Matrix3 = Matrix1 - Matrix2;
			cout << Matrix3 << endl;
		}
		else if (toupper(dzialanie) == 'M')
		{
			cout << "Ktora macierz chcesz pomnozyc" << endl;
			int chooseMacierz;
			cin >> chooseMacierz;
			cout << "Przez jaka liczbe ma byc pomnozona" << endl;
			int przezCoMnozymy;
			cin >> przezCoMnozymy;
			if (chooseMacierz == 1)
			{
				cout << "Iloraz mnozenia macierzy to: " << endl;
				cout << Matrix1 * przezCoMnozymy << endl;
			}
			else
			{
				cout << "Iloraz mnozenia macierzy to: " << endl;
				cout << Matrix2 * przezCoMnozymy << endl;

			}
		}
		cout << "Aby zakonczyc dzialanie na macierzach nacisnij (K)";
		cin >> end;




	}

	return 0;
}

VECTOR::Matrix getMatrixValues()
{
	cout << "Podaj wartosci macierzy" << endl << "wiersz 1, kolumna 1: ";
	int w1c1;
	cin >> w1c1;
	cout << "Podaj wartosci macierzy" << endl << "wiersz 1, kolumna 2: ";
	int w1c2;
	cin >> w1c2;
	cout << "Podaj wartosci macierzy" << endl << "wiersz 2, kolumna 1: ";
	int w2c1;
	cin >> w2c1;
	cout << "Podaj wartosci macierzy" << endl << "wiersz 2, kolumna 2: ";
	int w2c2;
	cin >> w2c2;

	return VECTOR::Matrix(w1c1, w1c2, w2c1, w2c2);
}


