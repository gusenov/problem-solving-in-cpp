#include <iostream>
#include <string>
#include <cstddef>
#include <windows.h>

using namespace std;

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

// Функция для определения, является ли символ буквой.
// Возвращает true, если является и false в ином случае.
bool isletter(char ch) {
  return isalpha(ch)
    || (ch >= 'а' && ch <= 'я') || (ch >= 'А' && ch <= 'Я');
}

// Функция для поиска слов в строке.
// Возвращает true, если слово найдено и false в ином случае.
// Вход:
//  str    - строка в которой надо искать слова.
//  start  - индекс с которого надо начинать поиск.
//  finish - индекс дальше которого искать не нужно.
// Выход:
//  word_start_idx - индекс первой буквы слова.
//  word_end_idx   - индекс последней буквы слова.
bool find_word(string const& str, size_t start, size_t finish, size_t& word_start_idx, size_t& word_end_idx) {
  size_t len = str.length();
  bool word_start = false;
  bool word_end = true;

  for (size_t i = start; i <= finish && i >= 0 && i < len; ++i) {
    char ch = str.at(i);

	// Захват первой буквы слова:
    if (word_end && isletter(ch)) {
      word_start_idx = i;
      word_start = true;
      word_end = false;
    }

	// Захват последней буквы слова:
    if (word_start) {
      if (isspace(ch) || ispunct(ch) || iscntrl(ch)) {
        word_end_idx = i - 1;
        word_end = true;
      } else if (isletter(ch) && i == len - 1) {
        word_end_idx = i;
        word_end = true;
      }
    }

	// Если есть первая и последняя буквы слова, то возвращаем результат:
    if (word_start && word_end) {
      word_start = false;
      return true;
    }
  }

  return false;
}

// Функция переводит символ в нижний регистр:
char to_lower_letter(char ch) {
  if (ch >= 'а' && ch <= 'я') {
  	return ch;
  } else if (ch >= 'А' && ch <= 'Я') {
  	return 'а' + (ch - 'А');
  } else {
  	return tolower(ch);
  }
}

// Функция для проверки равенства строк, независимо от их регистра.
bool iequals(const string& a, const string& b) {
  unsigned int sz = a.size();
  if (b.size() != sz)
    return false;
  for (unsigned int i = 0; i < sz; ++i)
    if (to_lower_letter(a[i]) != to_lower_letter(b[i]))
      return false;
  return true;
}

// Функция для подсчёта количества раз, которое слово встречается в строке.
size_t count_word(string const& str, size_t start, size_t finish, string const& word) {
  size_t cnt = 0;         // количество раз, которое слово встречается в строке.
  size_t word_start_idx;  // индекс первой буквы слова.
  size_t word_end_idx;    // индекс последней буквы слова.

  // Обход в цикле всех слов:
  while (find_word(str, start, finish, word_start_idx, word_end_idx)) {
  	
  	// Извлечение слова из строки:
    string next_word = str.substr(word_start_idx, word_end_idx - word_start_idx + 1);

	// Сравнение очередного слова с заданным словом:
    if (iequals(word, next_word)) {
      ++cnt;
    }

    start = word_end_idx + 1;  // передвижение вперёд левой границы поиска слов.
  }

  return cnt;
}

// Функция для удаления одинаковых слов.
string delete_same_words(string const& str) {
  string result;  // переменная в которой будет конечный результат.

  size_t len = str.length();  // длина строки.

  size_t start = 0;         // индекс с которого надо начинать поиск слов.
  size_t finish = len - 1;  // индекс дальше которого искать слова не нужно.
  size_t word_start_idx;    // индекс первой буквы слова.
  size_t word_end_idx;      // индекс последней буквы слова.

  string word;  // слово.
  size_t cnt;   // количество раз, которое слово встречается в строке.

  bool skip_word = false;  // флаг пропуска слова.

  size_t i = 0;
  
  // Обход в цикле всех слов:
  while (find_word(str, start, finish, word_start_idx, word_end_idx)) {
    
	if (skip_word) {
      i = word_start_idx;
    }

    // Вывод символов перед найденным словом:
    while (i < word_start_idx) {
      result += str.at(i++);
    }

    // Извлечение слова из строки:
    word = str.substr(word_start_idx, word_end_idx - word_start_idx + 1);
    
    // Подсчёт количества встреч слова в строке:
	cnt = count_word(str, 0, len - 1, word);

    if (cnt == 1) {  // если слово встречается только 1 раз, то:
      result.append(word);  // добавляем его в результирующую строку.
      skip_word = false;  // опускаем флаг пропуска слова.
    } else {
      skip_word = true;  // поднимае флаг пропуска слова.
    }

    start = word_end_idx + 1;  // передвижение вперёд левой границы поиска слов.
    i = start;
  }

  // Вывод всего, что осталось за последним словом:
  while (i < len) {
    result += str.at(i++);
  }

  return result;
}

// Главная функция:
int main(int argc, char** argv) {
  cyrillic();  // переход на кириллицу.

  // Заголовок программы:
  cout << "// Удаление из предложения слов, которые встретились в нём более 1 раза.\n\n";

  // Ввод входной строки:
  string str = "";
  cout << "Пожалуйста, введите предложение:\n>";
  getline(cin, str);
  cout << "Вы ввели строку: \"" << str << "\"\n\n";  // проверка ввода.

  cout << "Результат:\n" << delete_same_words(str) << endl << endl;

  system("pause");  // пауза перед выходом из программы.
  return 0;
}

