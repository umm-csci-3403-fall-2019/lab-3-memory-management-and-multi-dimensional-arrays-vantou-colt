#include "mergesort.h"

void mergesort(int arrSize, int* array) {
  // This obviously doesn't actually do any *sorting*, so there's
  // certainly work still to be done.
  mergesortRange(array, 0, arrSize);
  }

void mergesortRange(int* array, int startIndex, int endIndex){
  
  int rangeSize = endIndex - startIndex;
  if (rangeSize > 1) {
  	int midPoint = (startIndex + endIndex) / 2;
  	mergesortRange(array, startIndex, midPoint);
	mergesortRange(array, midpoint + 1, endIndex);
	mergeRanges(array, startIndex, midPoint, endIndex);
  }
}

void mergeRanges(int* array, int startIndex, int midPoint, int endPoint){


}
}
