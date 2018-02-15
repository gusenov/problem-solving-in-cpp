#ifndef MATRIX_LIB_HPP
#define MATRIX_LIB_HPP

// ��������� ������������� ������� ����� � ��������� ������ ������� �������� (��� double).
class Matrix {

private:
	
	// ������� ������� �� ��������� � �� �����������:
	unsigned ysize;  // ����� �����.
	unsigned xsize;  // ����� ��������.
	
	double *Array;  // ��������� �� ������ ������� � ������������ ������.

	// ������� ������ Matrix ����� ���������� �������������� � �������� ��������� � ��������� �����������:
	//     Matrix A, B, �;  // ��������� ��� ������� ������ Matrix.
	//     // ����� ��� ���� ����������� ����� ��������.
	//     C = A + B;  // ������� C ������������� �������� ����� �������� � � B.
	// ������� ���������� ������� operator+, � ����� ������� operator=.
	// ��� ������� �������� ������������ ������, �������������, ��� ����� �� ������ ���������.
	// ������� operator+ ���������� ��� ������� A, � �������� ��������� �� ���������� ������ B. 
	
	// ����� ��������� ����������� ������ � ����� ������������ ��� ��������� ����� �������, ���� �������� ���������� �� ������.
	
	// ������-��������� ��������� �������� operator+ � ������������ ������, � ������������ ������ �� ���� ������.
	// ���������� ������� ������� ������������ � ���, ����� �� �������� ������ �� ���������� ������������ ������.
	
	// ������� operator=  ������, ��������, ���������� ������-�������� ����� ����, ��� �� ����� �� �����������.
	// �� ����� ��������� ������� �� ������������, ��� ��� �� ������ ��������� ����������� �������-���������. 
	// ��������, ���� �� ����������� ������� C �������� ������� � (� = A),  ���������, �����������, �� ������ (� �� �����!)  ���� ���������. 
	// ������������ ������ ������ "���������" ������������ �������, ��������� �������� ������.
	
	// ��������, ����������� �������������� ��������� ������������ � ������ ������� ������ ���������� "���" �������-���������:
	int temporary;  // ���� "�����������".
	// ���� temporary != 0, ������ ��������� "���������" � ������ ���� ��������� ����� �������������.
	
public:

	// ��� ������ � ������������� ������� ����� �������� ������ ����� ������������ �������:
	Matrix(unsigned y=1, unsigned x=1, double v=0);  // �����������, ��������� ������� ��������� v.
	Matrix(Matrix & M);  // ����������� �����������.
	// ������������� �������� ������������.
	~Matrix();  // ����������.
	
	
	void show(void);  // "�����������" �����.
	
	double & operator()(unsigned n) const;  // ���������������� ������ � ��������.
		
	// ������� �������:
	unsigned getxsize(void);
	unsigned getysize(void);
	
	Matrix & operator % (Matrix &) const;  // ������� ���������� �������� "%" ��� ���������� ����������� ������ �� ���������.
};

#endif

