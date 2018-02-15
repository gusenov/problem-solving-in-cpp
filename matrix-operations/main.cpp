#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "matrixlib.hpp"

using namespace std;

// ������� �� ���������:
void cyrillic() {
	// ��� ������ ����� ��� ����������� ����������� ���������:
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	// ����� ���� �������� ����� � ������� �� Lucida Console.
	// ��� ������ ������ �������� ������ ������� �� ������� ���������� ������ ���� �������. 
	// � ����������� ���� ��������� ���������. 
	// � ����������� ���� ��������� ������� ������ � ��� ��������� �Lucida Console�. 
}

// ��������������� ������� ��� ���������� ������� ���������� �������:
void fillrandom(Matrix &M, int max=1) {
	int i, j, no;  // �������.
	double value;  // ���������� ��� �������� ���������������� ���������� ��������.
	
	for (i = 0; i < M.getysize(); i++) {
		for (j = 0; j < M.getxsize(); j++) {
			no = i * M.getxsize() + j + 1;  // ������ �������� ������� [i][j] � ���������������� ������� ����������.
			
			if (max == 1) {
				value = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);  // ��������� ���������� ������������� ����� � ��������� [0.0; 1.0].
			} else {
				value = static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / max));  // ��������� ���������� ������������� ����� � ��������� [0.0; max].
			}

			// ������� rand() ���������� ����� � ��������� �� 0 �� RAND_MAX.
			// RAND_MAX � ��� ���������, ����������� � ���������� <cstdlib>.
			// RAND_MAX = (2 ^ 15) - 1 = 32767, �� ��� ����� ���� � ������, � ����������� �� �����������.
			
			M(no) = value;
			// M2.Matrix::operator()(no) = value;
		}
	}
}

// ������� ���������� �������� "%" ��� ���������� ����������� ������ �� ���������:
Matrix & Matrix::operator % (Matrix &M) const {
	// ����� ��������� ����������� ������ � ����� ������������ ��� ��������� ����� �������, �������� M ���������� �� ������.
	
	int i, j = 1;

	// ������-��������� ��������� �������� operator% � ������������ ������, � ������������ ������ �� ���� ������.
	Matrix *result = new Matrix(this->ysize + M.ysize, this->xsize, 0);

	// �������� �������� ������� �������� � �������������� �������:
	for (i = 1; i <= this->ysize * this->xsize; i++) {
		if (this->temporary) {  // operator() �� �������� �� "���������" ��������, �������:
			result->Array[j - 1] = this->Array[i - 1];
		} else {
			(*result)(j) = (*this)(i);
		}
		j++;
	}
	
	// �������� �������� ������� �������� � �������������� �������:
	for (i = 1; i <= M.ysize * M.xsize; i++) {
		if (M.temporary) {  // operator() �� �������� �� "���������" ��������, �������:
			result->Array[j - 1] = M.Array[i - 1];
		} else {
			(*result)(j) = M.Matrix::operator()(i);
		}
		j++;
	}
	
	// �������� �������-������� ������������, ���� ��� "���������":
	if (this->temporary) {
		printf("�������. �������� �������-�������� �� ������: '%p'.\n", this);
		delete this;
	}
	if (M.temporary) {
		printf("�������. �������� �������-�������� �� ������: '%p'.\n", &M);
		delete &M;
	}

	printf("�������. ������� �������-���������� �� ������: '%p'.\n", result);

	result->temporary = 1;
	return (*result); // ��������� - ������ �� ����� "���������" �������.
	
	// ���������� ������� ������� ������������ � ���, ����� �� �������� ������ �� ���������� ������������ ������.
}

void test1(void) {
	cout << "������� �1 (������ �������):" << endl;
	Matrix M1(3, 4, 0);
	fillrandom(M1);  // ��������� ������� ���������� ���������� � ��������� [0.0; 1.0].
	M1.show();
	
	cout << endl << "������� �2 (������ �������):" << endl;
	Matrix M2(8, 4, 0);
	fillrandom(M2, 9.9);  // ��������� ������� ���������� ���������� � ��������� [0.0; 9.9].
	M2.show();
	
	cout << endl << "�������������� ������� (��������� �������� M1 % M2):" << endl;
	Matrix& result = M1 % M2;
	result.show();
	
	// delete &result;
	// �������� ���������� ��� result �� ����� ������ ��� ������ ������� show()
	
	cout << "�������. ����� ���������� ������� test1()" << endl;
}

void test2(void) {
	cout << "M1: " << endl;
	Matrix M1(1, 8, 0);
	fillrandom(M1);
	M1.show();
	
	cout << "M2: " << endl;
	Matrix M2(2, 8, 0);
	fillrandom(M2);
	M2.show();
	
	cout << "M3: " << endl;
	Matrix M3(3, 8, 0);
	fillrandom(M3);
	M3.show();
	
	cout << "M4: " << endl;
	Matrix M4(4, 8, 0);
	fillrandom(M4);
	M4.show();
	
	cout << endl << "��������� �������� (M1 % M2) % (M3 % M4): " << endl;
	Matrix& result = (M1 % M2) % (M3 % M4);
	result.show();
	
	cout << "�������. ����� ���������� ������� test2()" << endl;
}

int main(int argc, char** argv) {
	cyrillic();

	// ����� ������������� ����� � ��������� �� 2 ����� ����� �������:
	cout.setf(ios::fixed);
	cout.precision(2);
	
	srand(time(NULL));  // �������������� ������������ ���������� ��������� ����� (����� ������ �������� ������ ��������� �����).
	
	cout << "\t���� �1" << endl;
	test1();
	
	cout << "\t���� �2" << endl;
	test2();
	
	system("pause");
	return 0;
}

