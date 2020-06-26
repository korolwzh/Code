#include <iostream>
#include <string>
#include <math.h>
#include "ExtensibleHashTable.h"
#include "Bucket.h"
#include "ExtensibleHashTable.cpp"
#include "Bucket.cpp"


using namespace std;

int main()
{
	ExtensibleHashTable a;
	a.insert(0);
	a.insert(2);
	a.insert(4);
	a.insert(6);
	a.insert(8);
	a.insert(10);
	a.insert(12);
	a.insert(14);
	a.insert(16);
	a.insert(18);
	a.insert(20);
	a.insert(22);
	a.insert(24);
	a.insert(26);
	a.insert(28);
	a.insert(30);
	a.insert(0);
	a.insert(2);
	a.insert(4);
	a.insert(6);
	a.insert(8);
	a.insert(10);
	a.insert(12);
	a.insert(14);
	a.insert(16);
	a.insert(18);
	a.insert(20);
	a.insert(22);
	a.insert(24);
	a.insert(26);
	a.insert(28);
	a.insert(30);
	a.insert(1);
	a.insert(3);
	a.insert(5);
	a.insert(7);
	a.insert(9);
	a.print();
	

}