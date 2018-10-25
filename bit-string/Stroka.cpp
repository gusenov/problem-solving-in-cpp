#include "Stroka.h"

// ����������� �� ���������:
Stroka::Stroka():
	razmer(0),
	simvoly(0)
{
}

// ����������� �� ����-��������������� ���������������� ������:
Stroka::Stroka(const char* in_stroka) :
	razmer(Stroka::dlina(in_stroka) + 1)  // +1 ��� ����-������� � �����.
{
	simvoly = new char[razmer];
	char* ptr = this->simvoly;

	while (*ptr++ = *in_stroka++);
	
	// ��� ������������� �������� �������������� �������� ���������� ������� ������������ � ���������, 
	// � ����� ������������� �� 1.
	
	// �� ������� ���������� ������ ����� ���������� ��������� �������:
	/*
	
	*ptr = *in_stroka
	while (*ptr)
	{
		ptr++;
		in_stroka++;
		*ptr = *in_stroka;
	}
	
	*/
}

// ����� ����������� �����������.
// ���������� ������ ������ ������ ������������ �����������:
//  - ����� ������ �������� ������������ ���������;
//  - ����� ������ ���������� (�������) �� �������� � �������� ���������;
//  - ����� ������ �������������� �� ������ ������� ������� (���� �� ������);
//  - ����� ���������� ���������� ��������� ������ (��� � ������ � ������ ������� ����; ��� ����� �������������� � �. �.).
Stroka::Stroka(const Stroka& stroka)
{
	this->razmer = stroka.razmer;
	this->simvoly = new char[this->razmer];
	if (this->simvoly != 0) {
		kopir(this->simvoly, stroka.simvoly, this->razmer);
	}
}

// ������� ��� ����������� kol ��������� � ������ stroka1 �� ������ stroka2:
void Stroka::kopir(char* const stroka1, char* const stroka2, int kol)
{
	for (int i = 0; i < kol; ++i)
	{
		stroka1[i] = stroka2[i];
	}
}

// ����������� �� ����� ������:
Stroka::Stroka(const int dlina):
	razmer(dlina + 1)  // +1 ��� ����-������� � �����.
{
	simvoly = new char[razmer];
	
	*this->simvoly = '\0';
	// � ������������� (*) ��������� ����, ��� � ������ �� ��������� (->).
	
	for (int i = 1; i <= dlina; ++i)
	{
		this->simvoly[i] = '\0';  // ��������� ������.
	}
}

Stroka::~Stroka()
{
	if (this->simvoly != 0) {
		delete[] this->simvoly;
	}
}


int Stroka::dlina_stroki() const
{    
    return Stroka::dlina(this->simvoly);
}

int Stroka::dlina(const char* stroka)
{
    const char* ptr = stroka;  // ��������� �� ������ ������.
    
    if (ptr == 0)
    {
    	return 0;
	}
    
    // �������� �� ����� ����-��������������� ������.
    // ������ ������ ��������� ������ ������������� ����������� ����-������.
    // ����-������ - ��� (NUL �� ���� ASCII, �� ��������� 0x00).
    
    while (*ptr != '\0') ptr++;
    
    return ptr - stroka;
}

// ��������������� ��������� ������������ = (�����):

Stroka& Stroka::operator=(const char* in_stroka)
{
	Stroka vr(in_stroka);  // �������� ��������� ������.
	
	// ����� ��������:
	char *ptr = this->simvoly;
	this->simvoly = vr.simvoly;
	vr.simvoly = ptr;
	
	int razmer = this->razmer;
	this->razmer = vr.razmer;
	vr.razmer = razmer;
	
	return *this;
}

Stroka& Stroka::operator=(const Stroka& stroka)
{
	Stroka vr(stroka.simvoly);  // �������� ��������� ������.
	
	// ����� ��������:
	char *ptr = this->simvoly;
	this->simvoly = vr.simvoly;
	vr.simvoly = ptr;
	
	int razmer = this->razmer;
	this->razmer = vr.razmer;
	vr.razmer = razmer;
	
	return *this;
}

// �������� ������������ ���� �����:
Stroka Stroka::operator+(const Stroka& stroka)
{
	int dlina1 = this->dlina_stroki(),
		dlina2 = stroka.dlina_stroki();
	
    Stroka vr(dlina1 + dlina2);  // �������� ��������� ������.
    
    for (int i = 0; i < dlina1; i++) {
    	vr.simvoly[i] = this->simvoly[i];
	}

    for (int j = 0; j < dlina2; j++) {
    	vr.simvoly[dlina1 + j] = stroka.simvoly[j];
	}
	
    return vr;
}

// ��������������� ��������� ���������� (���. � ����):

char& Stroka::operator[](int nomer)
{
	return this->simvoly[nomer];
}

// ������� ��� ��������� �����:
int Stroka::sr(const Stroka& stroka1, const Stroka& stroka2)
{
    int i = 0;
    while ( (stroka1.simvoly[i] != '\0') 
		||  (stroka2.simvoly[i] != '\0') )
    {
        if (stroka1.simvoly[i] > stroka2.simvoly[i])
        {
        	// ������ ������, ������� �� �������������
        	// ����� ������� �������� � stroka1, ��� � stroka2.
        	return 1;
		}
        
		if (stroka1.simvoly[i] < stroka2.simvoly[i])
		{
        	// ������ ������, ������� �� �������������
        	// ����� ������� �������� � stroka1, ��� � stroka2.
			return -1;
		}

        ++i;
    }
    return 0;  // ��� ������ �����.
}

// �������� ��������� ���� �����:

bool operator==(const Stroka& stroka1, const Stroka& stroka2)
{
	return Stroka::sr(stroka1, stroka2) == 0;
}

bool operator!=(const Stroka& stroka1, const Stroka& stroka2)
{
	return !(stroka1 == stroka2);
}

bool operator<(const Stroka& stroka1, const Stroka& stroka2)
{
	return Stroka::sr(stroka1, stroka2) < 0;
}

bool operator<=(const Stroka& stroka1, const Stroka& stroka2)
{
	return (stroka1 == stroka2) || (stroka1 < stroka2);
}

bool operator>(const Stroka& stroka1, const Stroka& stroka2)
{
	return Stroka::sr(stroka1, stroka2) > 0;
}

bool operator>=(const Stroka& stroka1, const Stroka& stroka2)
{
	return (stroka1 == stroka2) || (stroka1 > stroka2);
}

// ��������������� ��������� ��������������� <<:
// (����� ����� ����� ���� ������������ ������ ������ �������� � cout)
std::ostream& operator<<(std::ostream& stream, Stroka& stroka) 
{
	stream << stroka.simvoly;
	return stream;
}

// ��������������� ��������� ��������������� >>:
// (����� ����� ����� ���� ������������ ������ ������ �������� � cin)
std::istream& operator>>(std::istream& stream, Stroka& stroka)
{
	stream >> stroka.simvoly;
	return stream;
}

