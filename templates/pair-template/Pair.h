#ifndef PAIR_H
#define PAIR_H

// Параметр F - тип первого элемента пары.
// Параметр S - тип второго элемента пары (по умолчанию такой же как и F).
template <class F, class S = F>
class Pair
{
	public:
		Pair();  // пустой конструктор.
		Pair(const F, const S);  // конструктор с первым и вторым элементом пары.
		~Pair();  // деструктор.
		
		F getFirst();  // установить первый элемент пары.
		void setFirst(const F);  // получить первый элемент пары.
		
		S getSecond();  // получить второй элемент пары.
		void setSecond(const S);  // установить второй элемент пары.

		F getMax();  // получить максимальный элемент пары.
	private:
      F first;  // первый элемент пары.
      S second;  // второй элемент пары.
};

// Пустой конструктор:
template<class F, class S>
Pair<F, S>::Pair()
{
}

// Конструктор с первым и вторым элементом пары:
template<class F, class S>
Pair<F, S>::Pair(const F first, const S second): first(first), second(second)
{
}

// Деструктор:
template<class F, class S>
Pair<F, S>::~Pair()
{
}

// Установить первый элемент пары:
template<class F, class S>
inline F Pair<F, S>::getFirst()
{
   return first;
}

// Получить первый элемент пары:
template<class F, class S>
inline void Pair<F, S>::setFirst(F value)
{
   first = value;
}

// Получить второй элемент пары:
template<class F, class S>
inline S Pair<F, S>::getSecond()
{
   return second;
}

// Установить второй элемент пары:
template<class F, class S>
inline void Pair<F, S>::setSecond(S value)
{
   second = value;
}

// Получить максимальный элемент пары:
template<class F, class S>
F Pair<F, S>::getMax()
{
	throw "Ошибка! Максимум пока ещё не реализован для данных типов пары!";
}




// Специализация шаблона под пару целых чисел:

template <>
class Pair<int, int>
{
	public:
		Pair();
		Pair(const int first, const int second);
		~Pair();
		
		int getFirst();
		void setFirst(const int value);
		
		int getSecond();
		void setSecond(const int value);
		
		int getMax();
	private:
      int first;
      int second;
};

Pair<int, int>::Pair()
{
}

Pair<int, int>::Pair(const int first, const int second): 
	first(first), second(second)
{
}

Pair<int, int>::~Pair()
{
}

inline int Pair<int, int>::getFirst()
{
   return first;
}

inline void Pair<int, int>::setFirst(int value)
{
   first = value;
}

inline int Pair<int, int>::getSecond()
{
   return second;
}

inline void Pair<int, int>::setSecond(int value)
{
   second = value;
}

int Pair<int, int>::getMax()
{
	int retVal;
	retVal = first > second ? first : second;
	return retVal;
}

#endif
