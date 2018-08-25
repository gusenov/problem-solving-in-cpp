#include <iostream>
#include <string>
#include <cstddef>
#include <windows.h>

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

// ������� ��� �����������, �������� �� ������ ������.
// ���������� true, ���� �������� � false � ���� ������.
bool isletter(char ch) {
  return isalpha(ch)
    || (ch >= '�' && ch <= '�') || (ch >= '�' && ch <= '�');
}

// ������� ��� ������ ���� � ������.
// ���������� true, ���� ����� ������� � false � ���� ������.
// ����:
//  str    - ������ � ������� ���� ������ �����.
//  start  - ������ � �������� ���� �������� �����.
//  finish - ������ ������ �������� ������ �� �����.
// �����:
//  word_start_idx - ������ ������ ����� �����.
//  word_end_idx   - ������ ��������� ����� �����.
bool find_word(string const& str, size_t start, size_t finish, size_t& word_start_idx, size_t& word_end_idx) {
  size_t len = str.length();
  bool word_start = false;
  bool word_end = true;

  for (size_t i = start; i <= finish && i >= 0 && i < len; ++i) {
    char ch = str.at(i);

	// ������ ������ ����� �����:
    if (word_end && isletter(ch)) {
      word_start_idx = i;
      word_start = true;
      word_end = false;
    }

	// ������ ��������� ����� �����:
    if (word_start) {
      if (isspace(ch) || ispunct(ch) || iscntrl(ch)) {
        word_end_idx = i - 1;
        word_end = true;
      } else if (isletter(ch) && i == len - 1) {
        word_end_idx = i;
        word_end = true;
      }
    }

	// ���� ���� ������ � ��������� ����� �����, �� ���������� ���������:
    if (word_start && word_end) {
      word_start = false;
      return true;
    }
  }

  return false;
}

// ������� ��������� ������ � ������ �������:
char to_lower_letter(char ch) {
  if (ch >= '�' && ch <= '�') {
  	return ch;
  } else if (ch >= '�' && ch <= '�') {
  	return '�' + (ch - '�');
  } else {
  	return tolower(ch);
  }
}

// ������� ��� �������� ��������� �����, ���������� �� �� ��������.
bool iequals(const string& a, const string& b) {
  unsigned int sz = a.size();
  if (b.size() != sz)
    return false;
  for (unsigned int i = 0; i < sz; ++i)
    if (to_lower_letter(a[i]) != to_lower_letter(b[i]))
      return false;
  return true;
}

// ������� ��� �������� ���������� ���, ������� ����� ����������� � ������.
size_t count_word(string const& str, size_t start, size_t finish, string const& word) {
  size_t cnt = 0;         // ���������� ���, ������� ����� ����������� � ������.
  size_t word_start_idx;  // ������ ������ ����� �����.
  size_t word_end_idx;    // ������ ��������� ����� �����.

  // ����� � ����� ���� ����:
  while (find_word(str, start, finish, word_start_idx, word_end_idx)) {
  	
  	// ���������� ����� �� ������:
    string next_word = str.substr(word_start_idx, word_end_idx - word_start_idx + 1);

	// ��������� ���������� ����� � �������� ������:
    if (iequals(word, next_word)) {
      ++cnt;
    }

    start = word_end_idx + 1;  // ������������ ����� ����� ������� ������ ����.
  }

  return cnt;
}

// ������� ��� �������� ���������� ����.
string delete_same_words(string const& str) {
  string result;  // ���������� � ������� ����� �������� ���������.

  size_t len = str.length();  // ����� ������.

  size_t start = 0;         // ������ � �������� ���� �������� ����� ����.
  size_t finish = len - 1;  // ������ ������ �������� ������ ����� �� �����.
  size_t word_start_idx;    // ������ ������ ����� �����.
  size_t word_end_idx;      // ������ ��������� ����� �����.

  string word;  // �����.
  size_t cnt;   // ���������� ���, ������� ����� ����������� � ������.

  bool skip_word = false;  // ���� �������� �����.

  size_t i = 0;
  
  // ����� � ����� ���� ����:
  while (find_word(str, start, finish, word_start_idx, word_end_idx)) {
    
	if (skip_word) {
      i = word_start_idx;
    }

    // ����� �������� ����� ��������� ������:
    while (i < word_start_idx) {
      result += str.at(i++);
    }

    // ���������� ����� �� ������:
    word = str.substr(word_start_idx, word_end_idx - word_start_idx + 1);
    
    // ������� ���������� ������ ����� � ������:
	cnt = count_word(str, 0, len - 1, word);

    if (cnt == 1) {  // ���� ����� ����������� ������ 1 ���, ��:
      result.append(word);  // ��������� ��� � �������������� ������.
      skip_word = false;  // �������� ���� �������� �����.
    } else {
      skip_word = true;  // �������� ���� �������� �����.
    }

    start = word_end_idx + 1;  // ������������ ����� ����� ������� ������ ����.
    i = start;
  }

  // ����� �����, ��� �������� �� ��������� ������:
  while (i < len) {
    result += str.at(i++);
  }

  return result;
}

// ������� �������:
int main(int argc, char** argv) {
  cyrillic();  // ������� �� ���������.

  // ��������� ���������:
  cout << "// �������� �� ����������� ����, ������� ����������� � �� ����� 1 ����.\n\n";

  // ���� ������� ������:
  string str = "";
  cout << "����������, ������� �����������:\n>";
  getline(cin, str);
  cout << "�� ����� ������: \"" << str << "\"\n\n";  // �������� �����.

  cout << "���������:\n" << delete_same_words(str) << endl << endl;

  system("pause");  // ����� ����� ������� �� ���������.
  return 0;
}

