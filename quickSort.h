#ifndef __QUICK_SORT_H_
#define __QUICK_SORT_H_

typedef void *Element;

typedef struct
{
  Element *values;
  int length;
} ArrayVoid;

typedef ArrayVoid *ArrayVoid_ptr;

typedef enum
{
  Failure,
  Success
} Status;

typedef Status (*Matcher)(Element, Element);

void swap(ArrayVoid_ptr array, int first_index, int second_index);
int partition(ArrayVoid_ptr array, int start, int end, Matcher is_lesser);
ArrayVoid_ptr quick_sort(ArrayVoid_ptr array, int start, int end, Matcher matcher);

#endif