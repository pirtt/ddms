#include <iostream>
#include "GlobalInstance.h"
using namespace std;

int main()
{
	int *x = GlobalInstance<int>::getInstance();


	getchar();
	return 0;
}