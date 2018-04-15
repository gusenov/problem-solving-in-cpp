#include <iostream>
#include <typeinfo>

using namespace std;

 int row = 0;

// Данный класс не является производным ни от кого другого:
class A {
    public:

    A() {
        cout << "Строка № " << ++row << ". Конструктор класса " << typeid(A).name() << "." << endl;
    }

    void f() {
        cout << "A";
    }
};

class B: public A {
    public:

    B() {
        cout << "Строка № " << ++row << ". Конструктор класса " << typeid(B).name() << "." << endl;
    }
    
    void f() {
        cout << "B";
    }
};

class C: public A {
    public:
        
    C() {
        cout << "Строка № " << ++row << ". Конструктор класса " << typeid(C).name() << "." << endl;
    }

    void f() {
        cout << "C";
    }
};

class E: public C {
    public:
    
    E() {
        cout << "Строка № " << ++row << ". Конструктор класса " << typeid(E).name() << "." << endl;
    }
        
    void f() {
        cout << "E";
    }
};

class D: public B, public virtual E {
    public:
        
    D() {
        cout << "Строка № " << ++row << ". Конструктор класса " << typeid(D).name() << "." << endl;
    }
    
    void f() {
        cout << "D";
    }
};

// Данный класс является выходным:
class F: public D, public virtual E {
    public:

    F() {
        cout << "Строка № " << ++row << ". Конструктор класса " << typeid(F).name() << "." << endl;
    }
};

int main(int argc, char** argv) {
    F object;
    object.f();

    cin.get();
    cin.get();
    return 0;
}
