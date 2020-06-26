#include <iostream>
#include <string>

using namespace std;

#ifndef BUCKET_H
#define BUCKET_H

class Bucket {

	public:
		int local_depth;
		int size;
		int *valueArr;
		int count;//count the number of value in the bucket
		bool p;//determin whether the bucket is printed or not
		
		Bucket();
		Bucket(int size);

		void insert(int value);
		void remove(int value);


		string print();



};

#endif 