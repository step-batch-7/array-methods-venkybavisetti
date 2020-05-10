#include <stdio.h>
#include <stdlib.h>
#include "./array.h"
#include "array_void.h"

typedef void (*DisplayData)(Object);

int square(int num)
{
  return num * num;
}

Bool is_even(int num)
{
  return num % 2 == 0;
}

int sum(int total, int num)
{
  return total + num;
}

void display_Array(Array *array)
{
  for (int i = 0; i < array->length; i++)
  {
    printf("%d ", array->array[i]);
  }
  printf("\n");
}

//void display_ArrayVoid(ArrayVoid *array,void (*displayer)(Object))
void display_ArrayVoid(ArrayVoid *array, DisplayData displayer)
{
  for (int i = 0; i < array->length; i++)
  {
    (*displayer)(array->array[i]);
  }
  printf("\n");
}

void display_integer(Object value)
{
  printf("%d ", *(int *)value);
}

Object square_void(Object value)
{
  Object integer = malloc(sizeof(Object));
  *(int *)integer = (*(int *)value) * (*(int *)value);
  return integer;
}

Bool is_odd(Object value)
{
  return *(int *)value % 2 == 1;
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
  printf("input\n");
  display_Array(input_array);
  printf("\nsquares\n");
  display_Array(map(input_array, &square));
  printf("\neven numbers\n");
  display_Array(filter(input_array, &is_even));
  printf("\nsum of n nums\n");
  printf("%d\n", reduce(input_array, 0, &sum));

  ArrayVoid_ptr intput_void_array = malloc(sizeof(ArrayVoid));
  intput_void_array->array = malloc(sizeof(Object) * 4);
  intput_void_array->length = 4;
  int values[] = {1, 2, 3, 4};
  for (int i = 0; i < intput_void_array->length; i++)
  {
    intput_void_array->array[i] = &values[i];
  }
  printf("\nvoid input\n");
  display_ArrayVoid(intput_void_array, display_integer);

  printf("\nvoid squares\n");
  display_ArrayVoid(map_void(intput_void_array, &square_void), display_integer);

  printf("\nvoid odd numbers\n");
  display_ArrayVoid(filter_void(intput_void_array, &is_odd), display_integer);
}