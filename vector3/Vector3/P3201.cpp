/*
//P3201

#include <iostream>
#include <math.h>

using namespace std;

const int L=5;
typedef int iVector5 [L];

int Scalar (iVector5* , iVector5* );
void Outer (int [][L], iVector5, iVector5);

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
*/
