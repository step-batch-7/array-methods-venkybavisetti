#include <stdio.h>
#include <stdlib.h>
#include "array.h"

Array *map(Array *src, Mapper mapper)
{

  Array *new_array = malloc(sizeof(Array));
  new_array->array = malloc(sizeof(int) * src->length);
  new_array->length = src->length;
  for (int i = 0; i < new_array->length; i++)
  {
    new_array->array[i] = (*mapper)(src->array[i]);
  }
  return new_array;
}

Array *create_Array_from(int *values, int length)
{
  Array *array = (Array *)malloc(sizeof(Array));
  array->array = (int *)malloc(sizeof(int) * length);
  array->length = length;
  for (int i = 0; i < array->length; i++)
  {
    array->array[i] = values[i];
  }
  return array;
}

Array *filter(Array *src, Predicate predicate)
{
  int filtered_nums[src->length];
  int count = 0;
  for (int i = 0; i < src->length; i++)
  {
    if ((*predicate)(src->array[i]))
    {
      filtered_nums[count] = src->array[i];
      count++;
    }
  }
  return create_Array_from(filtered_nums, count);
}
