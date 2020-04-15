#include <iostream>
using namespace std; 

#if 0
class Myclass{
public:
    Myclass(int a, int b, int c);
    void GetNumber();
    void GetSum();
private:
    int A, B, C;
public:
  static int Sum;
};
 
int Myclass::Sum = 0;
 
Myclass::Myclass(int a, int b, int c){
    A = a;
    B = b;
    C = c;
    Sum += A+B+C;
}
 
void Myclass::GetNumber(){
    cout<<"Number="<<A<<","<<B<<","<<C<<endl;
 }
 
void Myclass::GetSum(){
    cout<<"Sum="<<Sum<<endl;
 }
 
int main(){
    Myclass M(3, 7, 10),N(14, 9, 11);
    M.GetNumber();
    N.GetNumber();
    M.GetSum();
    N.GetSum();
}
#endif

#if 0
class A;
class B;

class A
{
	public:
                int n;
		B *b;
                
		A(B *b)//:b(b)    //init b method 1
		{
			this->b=b;//init b method 2
                        cout <<"A()"<<endl;
		}
                
                void output(void)
                {
                       // cout << b->output <<endl;//error! can not call members of CLASS B 
                }
                
	
};

class B
{
	public:
		int i;
		A a;
                B():
                  a(this),
                  i(50)
                {
                  cout <<"this:"<<this<<endl;
                  cout <<"B()"<<endl;
                }
                
		static B &instance(void)
		{
			static B b;
			cout <<&b<<endl;
			cout <<b.a.b<<endl;
			return b;
		}
                
                void output(void)
                {
                  cout <<"b output i="<<i<<endl;
                }
	
};

void f()
{
  B &b = B::instance();
  b.a.b->output();
}

int main()
{
	B &b = B::instance();
	f();
	cout<<B::instance().i<<endl;;
        cout<<B::instance().a.b->i<<endl;
         B::instance().a.b->output();
        B::instance().a.output();
	return 0;
}
#endif

#if 0
// ���� Shape
class Shape 
{
   public:
      void setWidth(int w)
      {
         width = w;
      }
      void setHeight(int h)
      {
         height = h;
      }
   protected:
      int width;
      int height;
};
 
// ���� PaintCost
class PaintCost 
{
   public:
      int getCost(int area)
      {
         return area * 70;
      }
};
 
// ������
class Rectangle: public Shape, public PaintCost
{
   public:
      int getArea()
      { 
         return (width * height); 
      }
};
 
int main(void)
{
   Rectangle Rect;
   int area;
 
   Rect.setWidth(5);
   Rect.setHeight(7);
 
   area = Rect.getArea();
   
   // �����������
   cout << "Total area: " << Rect.getArea() << endl;
 
   // ����ܻ���
   cout << "Total paint cost: $" << Rect.getCost(area) << endl;
 
   return 0;
}
#endif

#if 0
#include <iostream>

using namespace std;
//����

class D
{
public:
    D(){cout<<"D()"<<endl;}
    ~D(){cout<<"~D()"<<endl;}
protected:
    int d;
};

class B:virtual public D
{
public:
    B(){cout<<"B()"<<endl;}
    ~B(){cout<<"~B()"<<endl;}
protected:
    int b;
};

class A:virtual public D
{
public:
    A(){cout<<"A()"<<endl;}
    ~A(){cout<<"~A()"<<endl;}
protected:
    int a;
public:
    void seta(int a)
    {
      this->a = a;
    }
    int geta(void)
    {
      return a;
    }
};

class C:public B, public A
{
public:
    C(){cout<<"C()"<<endl;}
    ~C(){cout<<"~C()"<<endl;}
protected:
    int c;
public:
    void setc(int c)
    {
      this->c = c;
    }
    int getc(void)
    {
      return c;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    C c;   //D, B, A ,C
    c.setc(10);
    cout<<c.getc()<<endl;
    
    c.seta(20);
    cout<<c.geta()<<endl;
    
    cout<<sizeof(c)<<endl;
    return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;

class Base
{
private:
    int priData;
protected:
    int proData;
public:
    int pubData;
};

class D1:private Base//˽�м̳�
{
    void f1()
    {
        //priData=1;//����private��Ա���������в���ֱ�ӷ���
        proData=2;//�����protected��Ա����������Ϊprivate��������
        pubData=3;//�����public��Ա����������Ϊprivate��������
    }
};

class D2:protected Base//�����̳�
{
    void f2()
    {
        //priData=1;//����private��Ա���������в���ֱ�ӷ���
        proData=2;//�����protected��Ա����������Ϊprotected��������
        pubData=3;//�����public��Ա����������Ϊprotected��������
    }
};

class D3:public Base//���м̳�
{
    void f3()
    {
        //priData=1;//����private��Ա���������в���ֱ�ӷ���
        proData=2;//�����protected��Ա����������Ϊprotected��������
        pubData=3;//�����public��Ա����������Ϊpublic��������
    }
};

int main()
{
    Base obj;
    //obj.priData=1;//���󲻿ɷ���Base����private��Ա
    //obj.proData=2;//���󲻿ɷ���Base����protected��Ա
    obj.pubData=3;
    D1 objD1;
    //objD1.pubData=3;//private���ԣ����ɷ���
    D2 objD2;
    //objD2.pubData=3;//protected���ԣ����ɷ���
    D3 objD3;
    objD3.pubData=3;//public���ԣ����Է���
    return 0;
}
#endif

#if 0

class CCar
{
private:
    int price;
    friend class CDriver;  //���� CDriver Ϊ��Ԫ��
    CCar():price(50){}
};
class CDriver
{
public:
    CCar myCar;
    CDriver()
    {
      cout<< "CDriver()"<<endl;
    }
    void ModifyCar()  //��װ����
    {
        myCar.price += 1000;  //��CDriver��CCar����Ԫ�࣬�ʴ˴����Է�����˽�г�Ա
        cout << myCar.price <<endl;
    }
};
int main()
{
    CDriver cdr;
    cdr.ModifyCar();
    return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

template<typename T> void Swap(T *a, T *b){
    T temp = *a;
    *a = *b;
    *b = temp;
}

template<typename T> void SwapX(T *a, T *b){
    T temp = *a;
    *a = *b;
    *b = temp;
}

template<typename T> void Swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

int main(){
    //���� int ������ֵ
    int n1 = 100, n2 = 200;
    cout<<n1<<", "<<n2<<endl;
    
    SwapX(&n1, &n2);
    cout<<n1<<", "<<n2<<endl;
    
    Swap(n1, n2);
    cout<<n1<<", "<<n2<<endl;
   
    //���� float ������ֵ
    float f1 = 12.5, f2 = 56.93;
    Swap(&f1, &f2);
    cout<<f1<<", "<<f2<<endl;
   
    //���� char ������ֵ
    char c1 = 'A', c2 = 'B';
    Swap(&c1, &c2);
    cout<<c1<<", "<<c2<<endl;
   
    //���� bool ������ֵ
    bool b1 = false, b2 = true;
    Swap(&b1, &b2);
    cout<<b1<<", "<<b2<<endl;

    return 0;
}
#endif

#if 0

#include <iostream>
using namespace std;

//template <typename X, typename Y> class A
template <class X, class Y> class A
{
public:
  X x;
  Y y;
  X set(X x)
  {
    this->x=x;
    return this->x;
  }
  Y set(Y y)
  {
    this->y=y;
    return this->y;
  }
  
  Y sety(Y y)
  {
    this->y=y;
    return this->y;
  }
};

int main(void)
{
  A<string,int> a;
  
  cout <<a.set("agcdefg")<<endl;
  cout <<a.set(10)<<endl;
  cout <<a.sety("20")<<endl;
}

#endif

#if 1
#include <iostream>
#include <cstring>
using namespace std;
template <class T>
class CArray
{
    int size; //����Ԫ�صĸ���
    T *ptr; //ָ��̬���������
public:
    CArray(int s = 0);  //s��������Ԫ�صĸ���
    CArray(CArray & a);
    ~CArray();
    void push_back(const T & v); //����������β�����һ��Ԫ��v
    CArray & operator=(const CArray & a); //������������ĸ�ֵ
    T length() { return size; }
    T & operator[](int i)
    {//����֧�ָ����±��������Ԫ�أ���a[i] = 4;��n = a[i]���������
        return ptr[i];
    }
};
template<class T>
CArray<T>::CArray(int s):size(s)
{
     if(s == 0)
         ptr = NULL;
    else
        ptr = new T[s];
}
template<class T>
CArray<T>::CArray(CArray & a)
{
    if(!a.ptr) {
        ptr = NULL;
        size = 0;
        return;
    }
    ptr = new T[a.size];
    memcpy(ptr, a.ptr, sizeof(T ) * a.size);
    size = a.size;
}
template <class T>
CArray<T>::~CArray()
{
     if(ptr) delete [] ptr;
}
template <class T>
CArray<T> & CArray<T>::operator=(const CArray & a)
{ //��ֵ�ŵ�������ʹ"="��߶������ŵ����飬��С�����ݶ����ұߵĶ���һ��
    if(this == & a) //��ֹa=a�����ĸ�ֵ���³���
    return * this;
    if(a.ptr == NULL) {  //���a����������ǿյ�
        if( ptr )
            delete [] ptr;
        ptr = NULL;
        size = 0;
        return * this;
    }
     if(size < a.size) { //���ԭ�пռ乻�󣬾Ͳ��÷����µĿռ�
         if(ptr)
            delete [] ptr;
        ptr = new T[a.size];
    }
    memcpy(ptr,a.ptr,sizeof(T)*a.size);   
    size = a.size;
     return *this;
}
template <class T>
void CArray<T>::push_back(const T & v)
{  //������β�����һ��Ԫ��
    if(ptr) {
        T *tmpPtr = new T[size+1]; //���·���ռ�
    memcpy(tmpPtr,ptr,sizeof(T)*size); //����ԭ��������
    delete []ptr;
    ptr = tmpPtr;
}
    else  //���鱾���ǿյ�
        ptr = new T[1];
    ptr[size++] = v; //�����µ�����Ԫ��
}
int main()
{
    CArray<int> a;
    for(int i = 0;i < 5;++i)
        a.push_back(i);
    for(int i = 0; i < a.length(); ++i)
        cout << a[i] << " ";   
    return 0;
}
#endif