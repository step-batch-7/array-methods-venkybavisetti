#include <stdlib.h>
#include "array_void.h"

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr new_array = malloc(sizeof(ArrayVoid));
  new_array->array = malloc(sizeof(Object) * src->length);
  new_array->length = src->length;
  for (int i = 0; i < new_array->length; i++)
  {
    new_array->array[i] = (*mapper)(src->array[i]);
  }
  return new_array;
}

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate)
{
  Object filtered_values[src->length];
  int count = 0;
  for (int i = 0; i < src->length; i++)
  {
    if ((*predicate)(src->array[i]))
    {
      filtered_values[count] = src->array[i];
      count++;
    }
  }

  ArrayVoid_ptr array = (ArrayVoid_ptr)malloc(sizeof(ArrayVoid));
  array->array = (Object *)malloc(sizeof(Object) * count);
  array->length = count;
  for (int i = 0; i < array->length; i++)
  {
    array->array[i] = filtered_values[i];
  }
  return array;
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer)
{
  for (int i = 0; i < src->length; i++)
  {
    init = (*reducer)(init, src->array[i]);
  }

  return init;
}
