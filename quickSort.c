#include<stdio.h>
#include<stdlib.h>
#include "quickSort.h"

void swap(ArrayVoid_ptr array, int first_index, int second_index) {
  Element temp = array->values[first_index];
  array->values[first_index] = array->values[second_index];
  array->values[second_index] = temp;
}

int partition(ArrayVoid_ptr array, int start, int end, Matcher is_lesser) {
  Element pivot = array->values[start];
  int pivot_index = start;

  for (int index = start; index < end; index++) {
    if(is_lesser(array->values[index], pivot)) {
      pivot_index++;
      swap(array, pivot_index, index);
    }
  }
  swap(array, pivot_index, start);
  return pivot_index;
}

ArrayVoid_ptr quick_sort(ArrayVoid_ptr array, int start, int end, Matcher matcher) {
  if(start >= end) {
    return array;
  }

  int pivot_index = partition(array, start, end, matcher);
  quick_sort(array, start, pivot_index, matcher);
  quick_sort(array, pivot_index + 1, end, matcher);
  return array;
}

