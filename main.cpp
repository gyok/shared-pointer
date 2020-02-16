#include <iostream>
#include <memory>
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
    shared_ptr<int> sp_i = std::make_shared<int>(10);
    tst();
//    std::cin.get();
	return 0;
}
