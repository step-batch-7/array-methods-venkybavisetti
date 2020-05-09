#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int square(int num)
{
  return num * num;
}

void display_Array(Array *array)
{
  for (int i = 0; i < array->length; i++)
  {
    printf("%d ", array->array[i]);
  }
  printf("\n");
}

int main(void)
{
  Array *input_array = malloc(sizeof(Array));
  input_array->array = malloc(sizeof(int) * 4);
  input_array->length = 4;
  input_array->array[0] = 1;
  input_array->array[1] = 2;
  input_array->array[2] = 3;
  input_array->array[3] = 4;
  display_Array(input_array);
  display_Array(map(input_array, &square));
}