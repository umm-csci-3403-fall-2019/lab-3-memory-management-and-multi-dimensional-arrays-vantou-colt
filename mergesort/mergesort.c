#include "mergesort.h"
#include "stdlib.h"
#include "cstring"
bool needsSorting(int rangeSize){
       return rangeSize >= 2;
       }


void mergeRanges(int* array, int startIndex, int midPoint, int endPoint){
	int rangeSize = endPoint - startIndex;
	int* destination =  (int*)malloc(sizeof(int)*rangeSize);
	int firstIndex = startIndex;
	int secondIndex = midPoint;
	int copyIndex = 0;
	while(firstIndex < midPoint && secondIndex < endPoint){
	if(array[firstIndex] < array[secondIndex]){
		destination[copyIndex]=array[firstIndex];
		++firstIndex;
	}
	else{
		destination[copyIndex] = array[secondIndex];
		++secondIndex;
	}
	++copyIndex;
	}
	while(firstIndex < midPoint){
	destination[copyIndex] = array[firstIndex];
	++copyIndex;
	++firstIndex;
	}
	while(secondIndex < endPoint){
	destination[copyIndex] = array[secondIndex];
	++copyIndex;
	++secondIndex;
	}
	for(int i=0;i<rangeSize;++i){
	array[i+startIndex] = destination[i];
	}
	free(destination);

}


void mergesortRange(int* array, int startIndex, int endIndex){
	


  int rangeSize = endIndex - startIndex;
  if (needsSorting(rangeSize)) {
  	int midPoint = (startIndex + endIndex) / 2;
	int* temparray = (int*)malloc(sizeof(int)*rangeSize);
	memcpy(temparray,array,sizeof(int)*rangeSize);
  	mergesortRange(temparray, startIndex, midPoint);
	mergesortRange(temparray, midPoint, endIndex);
	mergeRanges(temparray, startIndex, midPoint, endIndex);
	//free(temparray);
	//replacing all instances of temparray with array will pass the tests
	//the problem is that we are not allocating enough memory in temparray
	//initilization
  }
}

void mergesort(int arrSize, int* array) {

  mergesortRange(array, 0, arrSize);
  }

