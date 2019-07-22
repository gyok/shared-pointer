#include <iostream>
#include "SharedPointer.h"
using namespace std;

void tst() {
	SharedPointer<int> sp(new int(10));
	{
		auto bp = sp;
	}
	auto bp = sp;
}

int main() {
	tst();
	system("pause");
	return 0;
}