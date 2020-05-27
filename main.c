#include<stdio.h>
#include<stdlib.h>
#include "quickSort.h"

Status is_lesser(Element num1, Element num2) {
  return *(int *)num1 < *(int *)num2;
}

void display_int_array(ArrayVoid_ptr array) {
  for (int index = 0; index < array->length; index++)
  {
    printf("%d\n", *(int *)array->values[index]);
  }
}

ArrayVoid_ptr create_dynamic_array(int length) {
  ArrayVoid *array = malloc(sizeof(ArrayVoid));
  array->length = length;
  array->values = malloc(sizeof(Element) * array->length);
  return array;
}

int main(void) {
  ArrayVoid_ptr numbers = create_dynamic_array(5);
  int num1 = 899, num2 = 299, num3 = 999, num4 = 199, num5 = 123;
  numbers->values[0] = &num1;
  numbers->values[2] = &num2;
  numbers->values[1] = &num3;
  numbers->values[3] = &num4;
  numbers->values[4] = &num5;
  quick_sort(numbers, 0, numbers->length, &is_lesser);
  display_int_array(numbers);
  return 0;
}