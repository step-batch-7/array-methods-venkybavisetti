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