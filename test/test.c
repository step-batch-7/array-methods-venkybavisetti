#include <stdio.h>
#include <stdlib.h>
#include "../array.h"
#include "test.h"
#include "test_functions.h"
#include "test_code.h"

void final_result(Result result)
{
  printf(GREEN "\n%d passing\n" RESET, result.passing);
  printf(RED "%d failing\n" RESET, result.falling);
}

void print_result(char *msg, Bool result)
{
  if (result)
  {
    printf(PASS "%s\n", msg);
    return;
  }
  printf(FAIL "%s\n", msg);
}

int main(void)
{
  Result result = {0, 0};

  test_reduce_func(&result);

  final_result(result);
  return 0;
}
