#include <iostream>
#include <string>
#include <math.h>
#include "ExtensibleHashTable.h"
#include "Bucket.h"


using namespace std;


int ExtensibleHashTable::hash(int key)
{
    int index = key % directory_size;
    return index;
}

//Assumen the bucket is full.
//https://github.com/bokff/ExtensibleHashTable/blob/master/ExtensibleHashTable.cpp
void ExtensibleHashTable::split(int key)
{
    int index = hash(key);
    int i = global_depth;
    int j = bucketArr[index]->local_depth;
    Bucket* newBucket = new Bucket(bucket_size);
    newBucket->local_depth = j;

    if(j == i)
    {
        double_directory();//i++
        int newIndex = hash(key);//after double the directory, index will change.
        for (int i = 0; i < bucket_size; i++)
        {
            if (hash(bucketArr[index]->valueArr[i]) == newIndex)
            {
                newBucket->insert(bucketArr[index]->valueArr[i]);
                bucketArr[index]->remove(bucketArr[index]->valueArr[i]);
            }
        }

        newBucket->local_depth++;//new bucket j++
        bucketArr[newIndex] = newBucket;

        //old bucket j++
        int old_bucket;
        if(newIndex >= directory_size/2)
            old_bucket = newIndex - int(pow(2,global_depth-1)); 
        else
            old_bucket = newIndex + int(pow(2,global_depth-1)); 

        bucketArr[old_bucket]->local_depth++;

    }
    else if (j < i)//no need to double the directory
    {
        int newIndex;
        //find which one bucket need to split
        if(index >= directory_size/2)
            newIndex = index - int(pow(2,global_depth-1)); 
        else
            newIndex = index + int(pow(2,global_depth-1)); 

        for (int i = 0; i < bucket_size; i++){
            if (hash(bucketArr[index]->valueArr[i]) == newIndex){
                newBucket->insert(bucketArr[index]->valueArr[i]);
                bucketArr[index]->remove(bucketArr[index]->valueArr[i]);
            }   
        }
        newBucket->local_depth++;
        bucketArr[newIndex] = newBucket;
        bucketArr[index]->local_depth++;

    }

}

void ExtensibleHashTable::double_directory()
{
    Bucket **newArr = new Bucket* [2*(directory_size)];

    for (int i = 0; i < directory_size; i++)
    {
        newArr[i] = bucketArr[i];
        newArr[i+directory_size] = bucketArr[i];
    }

    bucketArr = newArr;

    global_depth++;
    directory_size *= 2;
}

int ExtensibleHashTable::get_bucket_size()
{
    return bucket_size;
}

int ExtensibleHashTable::get_directory_size()
{
    return directory_size;
}


int ExtensibleHashTable::get_global_depth()
{
    return global_depth;
}



ExtensibleHashTable::ExtensibleHashTable()
{
    global_depth = 1;
    bucket_size = 4;
    directory_size = 2;
    bucketArr = new Bucket* [directory_size];
    bucketArr[0] = new Bucket();
    bucketArr[1] = new Bucket();

}

ExtensibleHashTable::ExtensibleHashTable(int size){
    global_depth = 1;
    bucket_size = size;
    directory_size = 2;
    bucketArr = new Bucket* [directory_size];
    bucketArr[0] = new Bucket();
    bucketArr[1] = new Bucket();
}

ExtensibleHashTable::~ExtensibleHashTable(){
	this->global_depth = 0;
    this->bucket_size = 0;
    this->directory_size = 0;
    bucketArr = NULL;
    
}

bool ExtensibleHashTable::find(int key)
{
    int index = hash(key);
    for(int i = 0 ; i < bucket_size; i++ )
	{
		if (bucketArr[index]->valueArr[i] == key)
				return true;
	}
	return false;
}

void ExtensibleHashTable::insert(int key)
{
    int index = hash(key);
    //if full
    if (bucketArr[index]->count == bucket_size)
    {
        split(key);
        int newIndex = hash(key);
        bucketArr[newIndex]->insert(key);
    }       
    else //if not full
    	bucketArr[index]->insert(key);
}

bool ExtensibleHashTable::remove(int key){
    int index;
    index = hash(key);
    if (find(key))
    {
        bucketArr[index]->remove(key);
        return true;
    }
    return false;
}

void ExtensibleHashTable::print()
{
    for(int i = 0 ; i < directory_size ; i++ )
    {
    	if(bucketArr[i]->p == false)
    	{
        	cout << i << ": " << bucketArr[i] << " --> " << bucketArr[i]->print() << endl;
        	bucketArr[i]->p = true;
    	}
        else
        	cout << i << ": " << bucketArr[i] << " --> " << endl;
    }
}
















