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
