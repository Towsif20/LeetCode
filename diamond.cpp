#include <iostream>
using namespace std;

class A
{
    int x;
public:
    
    A(int x)
    {
        this->x = x;
        cout << "constructor A" << endl;
    }

    void f1()
    {
        cout<<"f1"<<endl;
    }

    void print()
    {
        cout<<"A : "<<x<<endl;
    }
};

class B : virtual public A
{
public:
    B(int x): A(x)
    {
        cout << "constructor B" << endl;
    }

    void f2()
    {
        cout << "f2" << endl;
    }

    void print()
    {
        cout << "B : " << endl;
    }
};

class C : virtual public A
{
public:
    C(int x) : A(x)
    {
        cout << "constructor C" << endl;
    }

    void f3()
    {
        cout << "f3" << endl;
    }

    void print()
    {
        A::print();
        cout << "C : "<< endl;
    }
};

class D : public B, public C
{
public:
    D(int x) : B(x), C(x), A(x)
    {
        cout<<"constructor D"<<endl;
    }

    void f4()
    {
        cout << "f4" << endl;
    }

    void print()
    {
        A::print();
        cout << "D : " << endl;
    }
};

int main()
{
    D d(10);
    
    // d.f4();
    // d.f2();
    // d.f3();
    // d.B::f1();
    // d.C::f1();

    d.print();
    
    return 0;
}
