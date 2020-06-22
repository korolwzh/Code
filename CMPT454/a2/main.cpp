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
	a.insert(64);
	a.insert(200);
	a.insert(153);
	a.insert(66);
	a.insert(218);
	a.insert(67);
	a.insert(13);
	a.insert(253);
	a.insert(109);
	a.remove(64);
	cout<<a.find(200)<<endl;
	cout<<a.find(64)<<endl;
	a.print();
	

}