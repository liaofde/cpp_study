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
// 基类 Shape
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
 
// 基类 PaintCost
class PaintCost 
{
   public:
      int getCost(int area)
      {
         return area * 70;
      }
};
 
// 派生类
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
   
   // 输出对象的面积
   cout << "Total area: " << Rect.getArea() << endl;
 
   // 输出总花费
   cout << "Total paint cost: $" << Rect.getCost(area) << endl;
 
   return 0;
}
#endif

#if 0
#include <iostream>

using namespace std;
//基类

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

class D1:private Base//私有继承
{
    void f1()
    {
        //priData=1;//基类private成员在派生类中不可直接访问
        proData=2;//基类的protected成员在派生类中为private访问属性
        pubData=3;//基类的public成员在派生类中为private访问属性
    }
};

class D2:protected Base//保护继承
{
    void f2()
    {
        //priData=1;//基类private成员在派生类中不可直接访问
        proData=2;//基类的protected成员在派生类中为protected访问属性
        pubData=3;//基类的public成员在派生类中为protected访问属性
    }
};

class D3:public Base//公有继承
{
    void f3()
    {
        //priData=1;//基类private成员在派生类中不可直接访问
        proData=2;//基类的protected成员在派生类中为protected访问属性
        pubData=3;//基类的public成员在派生类中为public访问属性
    }
};

int main()
{
    Base obj;
    //obj.priData=1;//对象不可访问Base类中private成员
    //obj.proData=2;//对象不可访问Base类中protected成员
    obj.pubData=3;
    D1 objD1;
    //objD1.pubData=3;//private属性，不可访问
    D2 objD2;
    //objD2.pubData=3;//protected属性，不可访问
    D3 objD3;
    objD3.pubData=3;//public属性，可以访问
    return 0;
}
#endif

#if 0

class CCar
{
private:
    int price;
    friend class CDriver;  //声明 CDriver 为友元类
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
    void ModifyCar()  //改装汽车
    {
        myCar.price += 1000;  //因CDriver是CCar的友元类，故此处可以访问其私有成员
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
    //交换 int 变量的值
    int n1 = 100, n2 = 200;
    cout<<n1<<", "<<n2<<endl;
    
    SwapX(&n1, &n2);
    cout<<n1<<", "<<n2<<endl;
    
    Swap(n1, n2);
    cout<<n1<<", "<<n2<<endl;
   
    //交换 float 变量的值
    float f1 = 12.5, f2 = 56.93;
    Swap(&f1, &f2);
    cout<<f1<<", "<<f2<<endl;
   
    //交换 char 变量的值
    char c1 = 'A', c2 = 'B';
    Swap(&c1, &c2);
    cout<<c1<<", "<<c2<<endl;
   
    //交换 bool 变量的值
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
    int size; //数组元素的个数
    T *ptr; //指向动态分配的数组
public:
    CArray(int s = 0);  //s代表数组元素的个数
    CArray(CArray & a);
    ~CArray();
    void push_back(const T & v); //用于在数组尾部添加一个元素v
    CArray & operator=(const CArray & a); //用于数组对象间的赋值
    T length() { return size; }
    T & operator[](int i)
    {//用以支持根据下标访问数组元素，如a[i] = 4;和n = a[i]这样的语句
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
{ //赋值号的作用是使"="左边对象里存放的数组，大小和内容都和右边的对象一样
    if(this == & a) //防止a=a这样的赋值导致出错
    return * this;
    if(a.ptr == NULL) {  //如果a里面的数组是空的
        if( ptr )
            delete [] ptr;
        ptr = NULL;
        size = 0;
        return * this;
    }
     if(size < a.size) { //如果原有空间够大，就不用分配新的空间
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
{  //在数组尾部添加一个元素
    if(ptr) {
        T *tmpPtr = new T[size+1]; //重新分配空间
    memcpy(tmpPtr,ptr,sizeof(T)*size); //拷贝原数组内容
    delete []ptr;
    ptr = tmpPtr;
}
    else  //数组本来是空的
        ptr = new T[1];
    ptr[size++] = v; //加入新的数组元素
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