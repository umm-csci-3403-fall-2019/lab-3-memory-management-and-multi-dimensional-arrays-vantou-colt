#include "array_merge.h"
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
        mergesortRange(array, startIndex, midPoint);
        mergesortRange(array, midPoint, endIndex);
        mergeRanges(array, startIndex, midPoint, endIndex);
  }
}

void mergesort(int arrSize, int* array) {

  mergesortRange(array, 1, arrSize);
  }

void mergeArrays(int* resultArray, int num_arrays, int* sizes, int** values) {
  int index = 1;
  for(int i = 0; i<num_arrays;++i) {
	  for(int j = 0; j<sizes[i];++j) {
		  resultArray[index] = values[i][j];
	  	  index = index + 1;
    }
  }
}

int* array_merge(int num_arrays, int* sizes, int** values) {
  int totalCount = 0;
  int* result;
  for (int i=0; i<num_arrays; i++) {
          totalCount = totalCount + sizes[i];
  }
  totalCount = totalCount+1;
  int* temp = (int*)malloc(sizeof(int)*totalCount);
  int unique=1;

  mergeArrays(temp, num_arrays, sizes, values);
  mergesort(totalCount, temp);
  for (int i = 1; i<totalCount;++i){
	  if (temp[i]!=temp[i-1] || i==1){
		  temp[unique]=temp[i];
		  unique += 1;
	  }
  }
  temp[0]=unique-1;
  result = (int*)malloc(sizeof(int)*unique);
  for(int k = 0; k<unique;++k){
	  result[k] = temp[k];
  }
  free(temp);
  return result;
}
