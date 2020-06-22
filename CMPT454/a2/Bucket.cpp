#include <iostream>
#include <string>
#include <sstream>
#include "Bucket.h"

using namespace std;

Bucket::Bucket()
{
    local_depth = 1;
    size = 4;
    valueArr = new int[size];
    //keys are non-nagative
    //if there is no key, valueArr[i] = -1
    for(int i = 0 ; i < size; i++)
    {
    	valueArr[i] = -1;
    }
}

Bucket::Bucket(int size)
{
    local_depth = 1;
    this->size = size;
	valueArr = new int[size];
	for(int i = 0 ; i < size; i++)
    {
    	valueArr[i] = -1;
    }

}

void Bucket::insert(int value)
{
	for(int i = 0 ; i < size; i++ )
	{
		if (valueArr[i] == -1) 
		{
			valueArr[i] = value;
			count++;
			break;
		}
	}
}

void Bucket::remove(int value)
{
	for(int i = 0 ; i < size; i++ )
	{
		if (valueArr[i] == value)
		{
			valueArr[i] = -1;
			count--;
			break;
		}
	}
}


string Bucket::print()
{
	string s;
	s = "[";

	//add first (size-1) value to string s
	for(int i = 0; i< (size-1);i++ )
	{
		if(valueArr[i] == -1)
			s += string("-") + ",";
		else 
			s += string(to_string(valueArr[i])) + ",";
	}

	//add the last value to string s
	if(valueArr[size-1] == -1)
		s += string("-") + "]";
	else 
		s += string(to_string(valueArr[size-1])) + "]";
	
	//close the array and add local depth
	s += string(" (") + string(to_string(local_depth)) + string(")");
	return s;
}













