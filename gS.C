#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

class GS
{
     	double x;

	public:

	GS(): x(0.00) {}  //Constructor

	void input()
	{
		cout << " Enter a common ratio less than one " << endl;
		cin >> x;
	};

	double  gsum()
	{
		double  gs =0.0;
		for(int i=0;i<30;++i)
		{
			 gs += pow(x,i);
		}
		return gs;
	};

	double  actualSum()
	{
		double  aSum =0.0;
		aSum =(1/(1-x));
		return aSum;
	};

	void display(double  gs ,double  aSum)
	{
		cout << "sum of series is     " << gs << endl;
		cout << "actual sum is      " << aSum << endl;
		cout << "Difference is    " << abs( aSum - gs) << endl;
	};

};
void gS()
{
	GS obj;
	double gs1,aSum1;
	obj.input();
	gs1=obj.gsum();
	aSum1=obj.actualSum();
	obj.display(gs1,aSum1);
	return 0;
}
