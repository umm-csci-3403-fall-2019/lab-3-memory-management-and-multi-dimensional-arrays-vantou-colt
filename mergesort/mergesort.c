#include "mergesort.h"
#include "stdlib.h"

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

}


void mergesortRange(int* array, int startIndex, int endIndex){
  
  int rangeSize = endIndex - startIndex;
  if (needsSorting(rangeSize)) {
  	int midPoint = (startIndex + endIndex) / 2;
  	mergesortRange(array, startIndex, midPoint);
	mergesortRange(array, midPoint, endIndex);
	mergeRanges(array, startIndex, midPoint, endIndex);
  }
}

void mergesort(int arrSize, int* array) {
  // This obviously doesn't actually do any *sorting*, so there's
  // certainly work still to be done.
  mergesortRange(array, 0, arrSize);
  }

