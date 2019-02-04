#ifndef PAIR_H
#define PAIR_H

// �������� F - ��� ������� �������� ����.
// �������� S - ��� ������� �������� ���� (�� ��������� ����� �� ��� � F).
template <class F, class S = F>
class Pair
{
	public:
		Pair();  // ������ �����������.
		Pair(const F, const S);  // ����������� � ������ � ������ ��������� ����.
		~Pair();  // ����������.
		
		F getFirst();  // ���������� ������ ������� ����.
		void setFirst(const F);  // �������� ������ ������� ����.
		
		S getSecond();  // �������� ������ ������� ����.
		void setSecond(const S);  // ���������� ������ ������� ����.

		F getMax();  // �������� ������������ ������� ����.
	private:
      F first;  // ������ ������� ����.
      S second;  // ������ ������� ����.
};

// ������ �����������:
template<class F, class S>
Pair<F, S>::Pair()
{
}

// ����������� � ������ � ������ ��������� ����:
template<class F, class S>
Pair<F, S>::Pair(const F first, const S second): first(first), second(second)
{
}

// ����������:
template<class F, class S>
Pair<F, S>::~Pair()
{
}

// ���������� ������ ������� ����:
template<class F, class S>
inline F Pair<F, S>::getFirst()
{
   return first;
}

// �������� ������ ������� ����:
template<class F, class S>
inline void Pair<F, S>::setFirst(F value)
{
   first = value;
}

// �������� ������ ������� ����:
template<class F, class S>
inline S Pair<F, S>::getSecond()
{
   return second;
}

// ���������� ������ ������� ����:
template<class F, class S>
inline void Pair<F, S>::setSecond(S value)
{
   second = value;
}

// �������� ������������ ������� ����:
template<class F, class S>
F Pair<F, S>::getMax()
{
	throw "������! �������� ���� ��� �� ���������� ��� ������ ����� ����!";
}




// ������������� ������� ��� ���� ����� �����:

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
