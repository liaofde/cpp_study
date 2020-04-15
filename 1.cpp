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

#if 1

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