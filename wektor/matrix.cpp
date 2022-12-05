#include "matrix.h"

// vect.cpp -- implementacje metod klasy Vector
#include <cmath>
#include "wektor.h"        // włącza plik nagłówkowy <iostream>
#include <iomanip>
using namespace std;
using std::cout;
namespace VECTOR
{

	// metody publiczne
	Matrix::Matrix()          // konstruktor domyślny
	{
	}
	Matrix::Matrix(Vector vect1, Vector vect2)          // konstruktor 
	{
		row1Vect = vect1;
		row2Vect = vect2;
		r1c1 = row1Vect.xval();
		r1c2 = row1Vect.yval();
		r2c1 = row2Vect.xval();
		r2c2 = row2Vect.yval();

	}

	Matrix::Matrix(double r1c1, double r1c2, double r2c1, double r2c2)          // konstruktor 
	{
		this->r1c1 = r1c1;
		this->r1c2 = r1c2;
		this->r2c1 = r2c1;
		this->r2c2 = r2c2;

		Vector vector1 = Vector(r1c1, r1c2);
		Vector vector2 = Vector(r2c1, r2c2);
		row1Vect = vector1;
		row2Vect = vector2;
	}
	Matrix::~Matrix()   // destruktor
	{
	}
	Matrix Matrix::operator+(const Matrix & b) const
	{
		return Matrix(row1Vect+ b.row1Vect, row2Vect + b.row2Vect);
	}

	// odejmowanie wektora b od wektora a
	Matrix Matrix::operator-(const Matrix& b) const
	{
		return Matrix(row1Vect - b.row1Vect, row2Vect - b.row2Vect);

	}
	// zmienia znak wektora
	Matrix Matrix::operator-() const
	{
		//Matrix x;
		//x.row1Vect = -this->row1Vect;
		//x.row2Vect = -this->row2Vect;

		return Matrix(-row1Vect,-row2Vect);
	}
	// mnoży wektor wywołujący przez n
	Matrix Matrix::operator*(double n) const
	{
		return Matrix(row1Vect *n,row2Vect *n);
	}
	// funkcje zaprzyjaźnione
	// mnoży n przez Matrix a
	//Matrix operator*(double n, const Matrix& a)
	//{
	//	return a * n;
	//}


	std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
	{
		os << "Wartosci macierzy:"<< endl;;

		os << right << setw(30) << "Kolumna 1";
		os << right << setw(20) << "Kolumna 2" << endl;
		os << endl;
		os << "Wiersz 1";
		os << right << setw(22) << matrix.r1c1;
		os << right << setw(20) << matrix.r1c2 << endl;

		os << "Wiersz 2";
		os << right << setw(22) << matrix.r2c1;
		os << right << setw(20) << matrix.r2c2 << endl;

		//os << "Matryca o nastepujacych wartosciach: \n" << "\twiersz 1 kolumna 1: = " << m.r1c1 << ", kolumna 2 : " << m.r1c2 << "\n"
		//	<< "\twiersz 2 kolumna 1: = " << m.r2c1 << ", kolumna 2: " << m.r2c2 << "\n";
		return os;
	}

	// wyświetla współrzędne wektora (prostokątne w trybie 'r',
	// biegunowe w trybie 'p'
} // koniec przestrzeni nazw VECTOR











