//P3201

#include <iostream>
#include <math.h>

using namespace std;

const int L=5;
typedef int iVector5 [L];

// Определение типа fVector3 длиной 3 из вещественных эдементов - координат вектора:
typedef float fVector3 [3];

typedef float iVector3 [3];

int Scalar (iVector5* , iVector5* );
void Outer (int [][L], iVector5, iVector5);

// Функция векторного умножения двух параметров типа iVector3:
void Cross(iVector3, iVector3, iVector3);

int main()
{
   cout <<  "P3201" << endl;

    int i, j, iVar1;
    iVector5 iVec1, iVec2, *Pnt1, *Pnt2;
    int iMtx [L][L];

    for (i=0; i<L; i++)
        iVec1[i] = iVec2[i] = i+1;
        Pnt1 =&iVec1;
        Pnt2 =&iVec2;
        iVar1 = Scalar(Pnt1, Pnt2);
        cout << "Scalar = "<< iVar1<< endl;
        Outer (iMtx, iVec1, iVec2);
        cout << "Outer = " << endl;
        for (i=0; i<L; i++, cout << endl)
            for (j=0; j<L; j++)
            cout << iMtx[i][j] << "  ";
        iVar1 = Scalar(Pnt1, Pnt1);
        cout << endl << " Vector length = " << sqrt(iVar1) << endl;

        // Демонстрация вызовов функции векторного умножения двух параметров типа iVector3:
        cout << endl << endl;

        iVector3 a, b, p;
        const int x = 0, y = 1, z = 2;

        a[x] = 1; a[y] = 2; a[z] = 3;
        b[x] = 2; b[y] = 1; b[z] = -2;
        Cross(a, b, p);

        // Векторы-параметры параллельны разным осям координат:
        a[x] = 1; a[y] = 0; a[z] = 0;
        b[x] = 0; b[y] = 1; b[z] = 0;
        Cross(a, b, p);
        // Векторное произведение двух векторов в трёхмерном евклидовом пространстве
        // — вектор, перпендикулярный обоим исходным векторам.

        // Векторы-параметры параллельны одной и той же оси координат:
        a[x] = 1; a[y] = 0; a[z] = 0;
        b[x] = 1; b[y] = 0; b[z] = 0;
        Cross(a, b, p);
        // Векторное произведение коллинеарных векторов
        // (в частности, если хотя бы один из множителей — нулевой вектор)
        // считается равным нулевому вектору.

        return 0;
}

int Scalar(iVector5* Pnt3, iVector5* Pnt4)
{
    int iTemp=0, i, *iVecA, *iVecB;
    iVecA = (int*)Pnt3;
    iVecB =(int*)Pnt4;
    for (i=0; i<L; i++)
        iTemp = iTemp + iVecA[i]*iVecB[i];
        return iTemp;
}
 void Outer (int Arr[L][L], iVector5 iVec3, iVector5 iVec4 )
 {
     int i, j;
     for (i=0; i<L; i++)
        for (j=0; j<L; j++)
     Arr[i][j] = iVec3[i] =iVec4[j];
      return;
 }

// Функция векторного умножения
// принимает три параметра типа iVector3 и использует один из них
// для передачи результата в вызывавшую функцию:
void Cross(iVector3 a, iVector3 b, iVector3 p)
{
    const int x = 0, y = 1, z = 2;

    p[x] = a[y] * b[z] - a[z] * b[y];
    p[y] = a[z] * b[x] - a[x] * b[z];
    p[z] = a[x] * b[y] - a[y] * b[x];

    // DEBUG:
    cout << endl << "{ " << a[x] << "; " << a[y] << "; " << a[z] <<
               " } x { " << b[x] << "; " << b[y] << "; " << b[z] <<
               " } = { " << p[x] << "; " << p[y] << "; " << p[z] << " }."  << endl;
}
