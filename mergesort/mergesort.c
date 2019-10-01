#include "mergesort.h"
#include "stdlib.h"

void mergeRanges(int* array, int startIndex, int midPoint, int endPoint){
	int rangeSize = endPoint = startIndex;
	int* destination =  (int*)malloc(sizeof(int)*sizeof(rangeSize));
	int firstIndex = startIndex;
	int secondIndex = midPoint;
	int copyIndex = 0;
	while(firstIndex < midPoint && secondIndex < endIndex){
	if(values[firstIndex] < values[secondIndex]){
		destination[copyIndex];
		++firstIndex;
	}
}



void mergesortRange(int* array, int startIndex, int endIndex){
  
  int rangeSize = endIndex - startIndex;
  if (rangeSize > 1) {
  	int midPoint = (startIndex + endIndex) / 2;
  	mergesortRange(array, startIndex, midPoint);
	mergesortRange(array, midPoint + 1, endIndex);
	mergeRanges(array, startIndex, midPoint, endIndex);
  }
}

void mergesort(int arrSize, int* array) {
  // This obviously doesn't actually do any *sorting*, so there's
  // certainly work still to be done.
  mergesortRange(array, 0, arrSize);
  }

