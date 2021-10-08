#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Point
{
  double x;
  double y;
};

// typedef struct
// {
//   double x;
//   double y;
// } Point;

int main()
{
  // Point point = {0.5, 5, 9};
  // struct Point point = {0.5, 5.9};
  // struct Point p2 = {.y = 6.5, .x = 8.6};
  // printf("x: %f, y: %f\n", point.x, point.y);

  // In Heap
  struct Point *point = malloc(sizeof(struct Point));
  point->x = 6.4;
  point->y = 7.9;

  printf("x: %f, y: %f\n", point->x, point->y);

  free(point);
  return 0;
}