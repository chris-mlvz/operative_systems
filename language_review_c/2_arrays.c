#include <stdio.h>
#include <stdlib.h>

int main()
{
  int length = 8;
  int *array = malloc(sizeof(int) * length);
  for (int i = 0; i < length; i++)
  {
    array[i] = i + 1;
  }

  for (int i = 0; i < length; i++)
  {
    printf("Value of array[%i]: %i\n", i, array[i]);
  }

  // segmentation fault
  // array[10000000000] = 5;

  free(array);
  return 0;
}