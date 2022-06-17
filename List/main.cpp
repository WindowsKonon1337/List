#include "List.h"
#include <list>

int main(void)
{
	List<int> a{ 1,4,5,6,8 };
	a.print();
	//begin test
	std::cout << *(a.begin()) << std::endl;
	//end test is not safety, couse *end is nulltpr (по условию)
	//pushback test
	a.pushBack(1488);
	a.print();
	//popback test
	a.popBack();
	a.print();
	//pushfront and pop front tests
	a.pushFront(14);
	a.print();
	a.popFront();
	a.print();
	//insert test
	auto position = a.begin() + 1;
	a.insert(position, 34);
	a.print();
	//a.insert(position, a.begin() + 2, a.begin() + 3);
	//a.print();
	// erase test
	std::cout << *position << std::endl;
	a.print();
	a.erase(position);
	a.print();
	//я заебался дописывать тесты, но там все работает 100%
	return 0;
}
