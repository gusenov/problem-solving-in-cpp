#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <windows.h>

const char ARRAY_OF_VOWELS[] = { 'a', 'e', 'i', 'o', 'u' };
std::set<char> SET_OF_VOWELS(ARRAY_OF_VOWELS, ARRAY_OF_VOWELS + 5);  // ��������� ������� ����.

const char ARRAY_OF_CONSONANTS[] = { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z' };
std::set<char> SET_OF_CONSONANTS(ARRAY_OF_CONSONANTS, ARRAY_OF_CONSONANTS + 21);  // ��������� ��������� ����.

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

// ��������� ��� ����� ��������� �������� ������������� ������ ����-����:
void inputSize(const std::string& title, size_t& result) {
	std::cout << title;  // ����� �����������.
	std::cin >> result;  // ���� ��������.
}

// ��������� ��� ����� ���������� ��������:
void inputString(const std::string& title, std::string& result) {
	std::cout << title;  // ����� �����������.
	std::cin >> result;  // ���� ��������.
}

// ��������� ��� ������ ����������� ����� �� �����:
void printFile(const std::string& fileName) {
	std::cout << "���������� ����� '" << fileName << "':" << std::endl;
	
	std::string line;  // ��������� ������ � �����.
	std::ifstream file(fileName.c_str());
	if (file.is_open()) {
		while (getline(file, line)) {  // ���������� ������ �� �����.
			std::cout << line << '\n';  // ����� ��������� ������ �� �����.
		}
		file.close();  // �������� �����.
	} else {
		std::cout << "���������� ������� ����'" << fileName << "'!" << std::endl; 
	}

}

// ������� ��������� ���� �� N �����:
void createNewTextFile(size_t N, const std::string& fileName) {
	std::cin.ignore();
	
	std::ofstream file;
  	file.open(fileName.c_str());
  	
	std::string line;  // ��������� ������ � �����.
	for (size_t i = 1; i <= N; i++) {
		std::cout << "������� " << i << "-� ������ -> ";
		getline(std::cin, line);  // ������� ��� ������.
		file << line << std::endl;  // ������ �������� ������ � ����.
	}
	
	file.close();  // �������� �����.
}

// ���������� ��� �����, ������������ � �������/��������� �� ����� srcFileName � ���� dstFileName:
void rewriteWordsStartingWith(const std::string& srcFileName, const std::string& dstFileName, const std::set<char>& setOfChars) {
	std::ofstream dstFile;  // �������������� ����.
  	dstFile.open(dstFileName.c_str());
  	
  	std::string word;  // ��������� ����� � �����.
  	std::ifstream srcFile(srcFileName.c_str());
	if (srcFile.is_open()) {
	  	while (srcFile >> word) {  // ��������� �� ������ ����� ���� ��� ��������.
			if (word.length() > 0) {
				if (setOfChars.find(tolower(word.at(0))) != setOfChars.end()) {  // ��������, ������ �� 1-� ������ ����� � ��������� �������/��������� ����?
					dstFile << word << std::endl;
				}
			}
		}
		srcFile.close();  // �������� �����.
	} else {
		std::cout << "���������� ������� ����'" << srcFile << "'!" << std::endl; 
	}
  	
  	dstFile.close();  // �������� �����.
}

// ���������� �������� ������ ������� �� ����� srcFileName � ���� dstFileName:
void reverseLines(const std::string& srcFileName, const std::string& dstFileName) {
	std::ofstream dstFile;  // �������������� ����.
  	dstFile.open(dstFileName.c_str());
  	
	std::string line;  // ��������� ������ � �������� �����.
	std::ifstream srcFile(srcFileName.c_str());
	if (srcFile.is_open()) {
		while (getline(srcFile, line)) {  // ���������� ������ �� �����.
		
			std::string reversed_line(line);  // ������ ��������.
			std::reverse(reversed_line.begin(), reversed_line.end());  // ��������� ������ ��������.
			dstFile << reversed_line << std::endl;  // ������ ������ �������� � �������������� ����.
		
		}
		srcFile.close();  // �������� �����.
	} else {
		std::cout << "���������� ������� �������� ���� '" << srcFile << "'!" << std::endl; 
	}
	
	dstFile.close();  // �������� �����.
}

// �������� ���� ��� ������ ��������:
void showMenu(void) {
	size_t choice;  // ��������� ������������� ����� ����.
	
	size_t N;  // ���������� ����� � �����.
	std::string srcFileName;  // ��� ��������� �����.
	std::string dstFileName;  // ��� ��������������� �����.
	
	std::cout << "����:" << std::endl;
	std::cout << "\t1) ������� ��������� ���� �� N �����." << std::endl;
	std::cout << "\t2) ��� �����, ������������ � �������, ���������� � ���� ����� ����, � � ��������� - � ������ ����� ����." << std::endl;
	std::cout << "\t3) � ����� ���� ���������� ������  ������ ��������." << std::endl;
	std::cout << "\t4) �����." << std::endl;
	
	while (1) {
		
		std::cout << "������� ����� ������ ���� ��� ���������� �������� -> ";
		std::cin >> choice;
		
		switch (choice) {
			case 1:  // ������� ��������� ���� ��  N �����:
				inputSize("������� ���������� ����� � ����������� ����� -> ", N);			
				inputString("������� ��� ������������ ����� -> ", srcFileName);
				createNewTextFile(N, srcFileName);  // �������� �����.
				printFile(srcFileName);  // ����� ����������� ���������� �����.
				break;
			
			case 2:  // ��� �����, ������������ � �������, ���������� � ���� ����� ����, � � ��������� - � ������ ����� ����:
				inputString("������� ��� ��������� ����� -> ", srcFileName);
				
				inputString("������� ��� ����� ��� �������� � ���� ���� ����, ������������ � ������� -> ", dstFileName);
				rewriteWordsStartingWith(srcFileName, dstFileName, SET_OF_VOWELS);  // �������� �����.
				printFile(dstFileName);  // ����� ����������� ���������� �����.
				
				inputString("������� ��� ����� ��� �������� � ���� ���� ����, ������������ � ��������� -> ", dstFileName);
				rewriteWordsStartingWith(srcFileName, dstFileName, SET_OF_CONSONANTS);  // �������� �����.
				printFile(dstFileName);  // ����� ����������� ���������� �����.
				
				break;
			
			case 3:  // � ����� ���� ���������� ������  ������ ��������:
				inputString("������� ��� ��������� ����� -> ", srcFileName);
				inputString("������� ��� ��������������� ����� -> ", dstFileName);
				reverseLines(srcFileName, dstFileName);  // �������� �����.
				printFile(dstFileName);  // ����� ����������� ���������� �����.
				break;
				
			case 4:
				system("pause");  // ����� ����� ������� �� ���������.
				exit(EXIT_SUCCESS);
			
			default:
				continue;
		}
	}

	return;
}

// ����� ����� � ���������:
int main(int argc, char** argv) {
	cyrillic();  // ��������� ������� ����.
	showMenu();  // �������� ����.
	return EXIT_SUCCESS;  // �������� ���������� ���������.
}

