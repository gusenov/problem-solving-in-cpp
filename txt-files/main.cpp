#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <windows.h>

const char ARRAY_OF_VOWELS[] = { 'a', 'e', 'i', 'o', 'u' };
std::set<char> SET_OF_VOWELS(ARRAY_OF_VOWELS, ARRAY_OF_VOWELS + 5);  // множество гласных букв.

const char ARRAY_OF_CONSONANTS[] = { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z' };
std::set<char> SET_OF_CONSONANTS(ARRAY_OF_CONSONANTS, ARRAY_OF_CONSONANTS + 21);  // множество согласных букв.

// Переход на кириллицу:
void cyrillic() {
	// Эти строки нужны для правильного отображения кириллицы:
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	// Также надо изменить шрифт в консоли на Lucida Console.
	// Для замены шрифта кликаете правой кнопкой на надписи «Командная строка» окна консоли. 
	// В открывшемся меню выбираете «Свойства». 
	// В появившемся окне выбираете вкладку «Шрифт» и там выбираете «Lucida Console». 
}

// Процедура для ввода числового значения обозначающего размер чего-либо:
void inputSize(const std::string& title, size_t& result) {
	std::cout << title;  // вывод приглашения.
	std::cin >> result;  // ввод значения.
}

// Процедура для ввода строкового значения:
void inputString(const std::string& title, std::string& result) {
	std::cout << title;  // вывод приглашения.
	std::cin >> result;  // ввод значения.
}

// Процедура для вывода содержимого файла на экран:
void printFile(const std::string& fileName) {
	std::cout << "Содержимое файла '" << fileName << "':" << std::endl;
	
	std::string line;  // очередная строка в файле.
	std::ifstream file(fileName.c_str());
	if (file.is_open()) {
		while (getline(file, line)) {  // считывание строки из файла.
			std::cout << line << '\n';  // вывод считанной строки на экран.
		}
		file.close();  // закрытие файла.
	} else {
		std::cout << "Невозможно открыть файл'" << fileName << "'!" << std::endl; 
	}

}

// Создать текстовый файл из N строк:
void createNewTextFile(size_t N, const std::string& fileName) {
	std::cin.ignore();
	
	std::ofstream file;
  	file.open(fileName.c_str());
  	
	std::string line;  // очередная строка в файле.
	for (size_t i = 1; i <= N; i++) {
		std::cout << "Введите " << i << "-ю строку -> ";
		getline(std::cin, line);  // считать всю строку.
		file << line << std::endl;  // запись введённой строки в файл.
	}
	
	file.close();  // закрытие файла.
}

// Переписать все слова, начинающиеся с гласных/согласных из файла srcFileName в файл dstFileName:
void rewriteWordsStartingWith(const std::string& srcFileName, const std::string& dstFileName, const std::set<char>& setOfChars) {
	std::ofstream dstFile;  // результирующий файл.
  	dstFile.open(dstFileName.c_str());
  	
  	std::string word;  // очередное слово в файле.
  	std::ifstream srcFile(srcFileName.c_str());
	if (srcFile.is_open()) {
	  	while (srcFile >> word) {  // считывать по одному слову пока это возможно.
			if (word.length() > 0) {
				if (setOfChars.find(tolower(word.at(0))) != setOfChars.end()) {  // проверка, входит ли 1-й символ слова в множество гласных/согласных букв?
					dstFile << word << std::endl;
				}
			}
		}
		srcFile.close();  // закрытие файла.
	} else {
		std::cout << "Невозможно открыть файл'" << srcFile << "'!" << std::endl; 
	}
  	
  	dstFile.close();  // закрытие файла.
}

// Переписать наоборот каждую строчку из файла srcFileName в файл dstFileName:
void reverseLines(const std::string& srcFileName, const std::string& dstFileName) {
	std::ofstream dstFile;  // результирующий файл.
  	dstFile.open(dstFileName.c_str());
  	
	std::string line;  // очередная строка в исходном файле.
	std::ifstream srcFile(srcFileName.c_str());
	if (srcFile.is_open()) {
		while (getline(srcFile, line)) {  // считывание строки из файла.
		
			std::string reversed_line(line);  // строка наоборот.
			std::reverse(reversed_line.begin(), reversed_line.end());  // получение строки наоборот.
			dstFile << reversed_line << std::endl;  // запись строки наоборот в результирующий файл.
		
		}
		srcFile.close();  // закрытие файла.
	} else {
		std::cout << "Невозможно открыть исходный файл '" << srcFile << "'!" << std::endl; 
	}
	
	dstFile.close();  // закрытие файла.
}

// Показать меню для выбора действия:
void showMenu(void) {
	size_t choice;  // выбранный пользователем пункт меню.
	
	size_t N;  // количество строк в файле.
	std::string srcFileName;  // имя исходного файла.
	std::string dstFileName;  // имя результирующего файла.
	
	std::cout << "МЕНЮ:" << std::endl;
	std::cout << "\t1) Создать текстовый файл из N строк." << std::endl;
	std::cout << "\t2) Все слова, начинающиеся с гласных, переписать в один новый файл, а с согласных - в другой новый файл." << std::endl;
	std::cout << "\t3) В новый файл переписать каждую  строку наоборот." << std::endl;
	std::cout << "\t4) Выход." << std::endl;
	
	while (1) {
		
		std::cout << "Введите номер пункта меню для выполнения действия -> ";
		std::cin >> choice;
		
		switch (choice) {
			case 1:  // создать текстовый файл из  N строк:
				inputSize("Введите количество строк в создаваемом файле -> ", N);			
				inputString("Введите имя создаваемого файла -> ", srcFileName);
				createNewTextFile(N, srcFileName);  // создание файла.
				printFile(srcFileName);  // вывод содержимого созданного файла.
				break;
			
			case 2:  // все слова, начинающиеся с гласных, переписать в один новый файл, а с согласных - в другой новый файл:
				inputString("Введите имя исходного файла -> ", srcFileName);
				
				inputString("Введите имя файла для переписи в него всех слов, начинающихся с гласных -> ", dstFileName);
				rewriteWordsStartingWith(srcFileName, dstFileName, SET_OF_VOWELS);  // создание файла.
				printFile(dstFileName);  // вывод содержимого созданного файла.
				
				inputString("Введите имя файла для переписи в него всех слов, начинающихся с согласных -> ", dstFileName);
				rewriteWordsStartingWith(srcFileName, dstFileName, SET_OF_CONSONANTS);  // создание файла.
				printFile(dstFileName);  // вывод содержимого созданного файла.
				
				break;
			
			case 3:  // в новый файл переписать каждую  строку наоборот:
				inputString("Введите имя исходного файла -> ", srcFileName);
				inputString("Введите имя результирующего файла -> ", dstFileName);
				reverseLines(srcFileName, dstFileName);  // создание файла.
				printFile(dstFileName);  // вывод содержимого созданного файла.
				break;
				
			case 4:
				system("pause");  // пауза перед выходом из программы.
				exit(EXIT_SUCCESS);
			
			default:
				continue;
		}
	}

	return;
}

// Точка входа в программу:
int main(int argc, char** argv) {
	cyrillic();  // настроить русский язык.
	showMenu();  // показать меню.
	return EXIT_SUCCESS;  // успешное завершение программы.
}

