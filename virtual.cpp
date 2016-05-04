#include <iostream>

using namespace std;

class Base {
private:
		virtual void f(void) { cout<<"Base::f()"<<endl; }
};

class Derive:private Base {

};

typedef void (*Fun)(void);

int main()
{
   Base   b;
   cout<<"virtural table address: "<<(int *)&b<<endl;
   cout<<"first func in V-table: "<<(int *)*(int *)(&b)<<endl;

   Derive d;
   cout<<"virtural table address: "<<(int *)&d<<endl;
   cout<<"first func address in V-table: "<<(int *)*(int *)(&d)<<endl;

//   Base *b1 = &d;
//   b1->f();

   Fun pFunc = (Fun) *((int *)*(int *)(&d));
   pFunc();
   
   int **pVtab = (int **)&d;
   pFunc = (Fun)*(pVtab[0]);
   pFunc();
   cout<<"end"<<endl;
   return 0;  
}
