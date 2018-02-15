#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <windows.h>

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

// ������� ����������� �������� ������������� ���� (float), 
// ��������������� ��������� ������������� ����� � ������������� ������ � n ��������� ��� ����� �����, 
// ������� ���������� � ������ s. 
float Str2Float(char *s, int n) {
	float result = 0;
	int i, base = 1;

	i = n - 1;
	while (i < strlen(s)) {
		
		// � ������ ����������� ������������� ������� � ������ s ������� ������ ������� �� ����� ��������� �� ������ � ������� -1.
		if (s[i] != '0' && s[i] != '1') {
			std::cout << "������! � ������ '" << s << "' ��������� ������������ ������ '" << s[i] << "'!" << std::endl;
			return -1;
		}
		
		if (i <= n - 1) {  // ������� ����� �����:
			result += (s[i] - '0') * base;
			base *= 2;
			
			if (--i == -1) {  // ������� �� ������� ������� �����:
				i = n;
				base = 2;
			}
		
		} else if (i >= n) {  // ������� ������� �����:
			result += (s[i] - '0') * (1.0 / base);
			base *= 2;
			i++;
		}
		
	}
	
	return result;
}

int main(int argc, char** argv) {
	char *s = "1011101101";
	int n = 5;
	float result;
	
	cyrillic();
	
	result = Str2Float(s, n);
	if (result == -1) {
		system("pause");
		return EXIT_FAILURE;
	}
	
	std::cout << std::fixed << std::setprecision(5) << result << std::endl;  // 10111.01101 = (2^4) + (2^2) + (2^1) + (2^0) + (2^(-2)) + (2^(-3)) + (2^(-5)) = 23.40625
	
	system("pause");
	return EXIT_SUCCESS;
}

