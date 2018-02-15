#include <iostream>
#include <windows.h>

#define _USE_MATH_DEFINES
#include <cmath>

#ifndef M_PI
	#define M_PI (3.14159265358979323846)
#endif

#ifndef M_PIl
	#define M_PIl (3.14159265358979323846264338327950288)
#endif

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

using namespace std;

struct ThreeValues {
	float v1, v2, v3;
};

class Triangle {
	private:

	ThreeValues lengths;  // длины сторон по порядку: AB, ВС, СА.
	ThreeValues angles;  // углы при вершинах А, В, С.
	
	// Функция перевода радианов в градусы:
	static float radians2degrees(float x) {
		return x * 180.0 / M_PIl;
	}
	
	// Функция перевода градусов в радианы:
	static float degrees2radians(float y) {
		return y * M_PIl / 180.0;
	}
	
	public:
	
	// Построение треугольника по трем сторонам:
	// https://ru.wikipedia.org/wiki/Решение_треугольников#Три_стороны
	Triangle(ThreeValues ls = {1, 1, 1}) { //  конструктор.
		// Информация, содержащаяся в одной структуре, 
		// может быть присвоена другой структуре того же типа с помощью одиночного оператора присваивания, 
		// то есть не нужно присваивать значение каждого члена по отдельности.
		this->lengths = ls;
		
		float a = this->lengths.v2;  // BC
		float b = this->lengths.v3;  // CA
		float c = this->lengths.v1;  // AB
		
		float alpha = acos( (b*b + c*c - a*a) / (2 * b * c) );
		float beta = acos( (a*a + c*c - b*b) / (2 * a * c) );
		float gamma = degrees2radians ( 180 - ( radians2degrees(alpha) + radians2degrees(beta) ) );
		
		this->angles.v1 = alpha;
		this->angles.v2 = beta;
		this->angles.v3 = gamma;
	}
	
	// Перепостроение треугольника по одной стороне (AB) и двум прилегающим к ней углам:
	// https://ru.wikipedia.org/wiki/Решение_треугольников#Сторона_и_два_угла
	Build1(float ab, float anA, float anB) {
		float c = ab;		
		this->lengths.v1 = c;
		
		float alpha = degrees2radians(anA);
		this->angles.v1 = alpha;
		
		float beta = degrees2radians(anB);
		this->angles.v2 = beta;
		
		float gamma = degrees2radians( 180 - radians2degrees(alpha) - radians2degrees(beta) );  // вначале определяется третий угол.
		this->angles.v3 = gamma;
		
		// Далее обе неизвестные стороны находятся по теореме синусов:
		float a = c * (sin(alpha) / sin(gamma));
		this->lengths.v2 = a;
		
		float b = c * (sin(beta) / sin(gamma));
		this->lengths.v3 = b;
	}
	
	// Перепостроение треугольника по двум сторонам (AB и AC) и углу между ними:
	Build2(float ab, float ac, float anA) {
		float c = ab;
		this->lengths.v1 = c;
		
		float b = ac;
		this->lengths.v3 = b;
		
		float alpha = degrees2radians(anA);
		this->angles.v1 = alpha;
		
		// Для определения длины неизвестной стороны применяется теорема косинусов:
		float a = pow(b*b + c*c - 2*b*c*cos(alpha), 1./2.);
		this->lengths.v2 = a;
		
		// Далее ещё раз применяется теорема косинусов для нахождения второго угла:
		float gamma = acos( (b*b + a*a - c*c) / (2 * b *a) );
		this->angles.v3 = gamma;
		
		// Третий угол находится из теоремы о сумме углов треугольника:
		float beta = degrees2radians(180 - radians2degrees(alpha) - radians2degrees(gamma));
		this->angles.v2 = beta;
	}
	
	// Получить длины сторон:
	ThreeValues GetLengths(void) const {
		return this->lengths;  // в момент возврата будет создание копия lengths.
	}
	
	// Получить углы:
	ThreeValues GetAngles(void) const {
		ThreeValues result = this->angles;
		result.v1 = radians2degrees(this->angles.v1);
		result.v2 = radians2degrees(this->angles.v2);
		result.v3 = radians2degrees(this->angles.v3);
		return result;  // в момент возврата будет создание копия result.
	}
	
	void print(void) {
		ThreeValues l = GetLengths();
		cout << "a=" << l.v2 << " b=" << l.v3 << " c=" << l.v1 << endl;
		
		ThreeValues a = GetAngles();
		cout << "alpha=" << a.v1 << " beta=" << a.v2 << " gamma=" << a.v3 << endl;
	}
};

int main(int argc, char** argv) {
	float a = 8.94, b = 12.81, c = 14;
	float alpha = 38.66, beta = 63.43, gamma = 77.91;
	
	cyrillic();
	
	cout << "\tТест конструктора Triangle" << endl;
	cout << "ВХОД: " << endl;
		cout << "a=" << a << " b=" << b << " c=" << c << endl;
	cout << "ВЫХОД: " << endl;
		Triangle t1( { c, a, b } );
		t1.print();
	cout << endl;
	
	cout << "\tТест метода Build1" << endl;
	cout << "ВХОД: " << endl;
		cout << "AB=" << c << " alpha=" << alpha << " beta=" << beta << endl;
	cout << "ВЫХОД: " << endl;
		Triangle t2;
		t2.Build1(c, alpha, beta);
		t2.print();
	cout << endl;

	cout << "\tТест метода Build2" << endl;
	cout << "ВХОД: " << endl;
		cout << "AB=" << c << " AC=" << b << " alpha=" << alpha << endl;
	cout << "ВЫХОД: " << endl;
		Triangle t3;
		t3.Build2(c, b, alpha);
		t3.print();
	cout << endl;
	
	system("pause");
	return 0;
}

