#include "../array.h"
#include "test.h"
#include "test_code.h"
#include "test_functions.h"

int sum(int total, int num)
{
  return total + num;
}

void test_reduce_func(Result *result)
{
  char msg[] = "should add all positive numbers";
  int input[4] = {1, 2, 3, 4};
  Array array = {input, 4};

  int actual = reduce(&array, 0, &sum);
  is_equal(actual, 10)
      ? result->passing++
      : result->falling++;
  print_result(msg, is_equal(actual, 10));
}
