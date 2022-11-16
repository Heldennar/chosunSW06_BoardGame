#include <stdio.h>
#include <stdlib.h> 

class A
{
public:
	A();
	int* asd;
	int num = 5;
	void wat();
};
A::A()
{
	asd = (int*)malloc(sizeof(int)*num);
}
void A::wat(){
	for (int i = 0; i < sizeof(asd); i++)
	{
		asd[i] = i;
		printf("%d / ", asd[i]);
	}
}
int main()
{
	A aaa;
	aaa.wat();
}