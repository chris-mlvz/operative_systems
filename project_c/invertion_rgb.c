#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  unsigned char r;
  unsigned char g;
  unsigned char b;
  int last;
} RGB;

RGB new_rgb(int r, int g, int b)
{
  if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
  {
    printf("Error, You need to pas number between 0 - 255\n");
    exit(EXIT_FAILURE);
  }
  RGB rgb = {r, g, b};
  return rgb;
}

void rgb_invert(RGB *rgb)
{
  rgb->r = 255 - rgb->r;
  rgb->g = 255 - rgb->g;
  rgb->b = 255 - rgb->b;
}

char *rgb_str(RGB *rgb)
{
  char *str = malloc(sizeof(char) * 64);
  sprintf(str, "RGB: (%i, %i, %i)\nHEX: (0x%02x%02x%02x)", rgb->r, rgb->g, rgb->b, rgb->r, rgb->g, rgb->b);
  return str;
}

RGB *get_inverted_colors(const char *path)
{
  int limit = 4;
  // arrray of RGB
  RGB *inverted = malloc(sizeof(RGB) * limit);

  // file
  int line_size = 16;
  char *line = malloc(sizeof(char) * line_size);
  FILE *f = fopen(path, "r");

  int i = 0;
  while (fgets(line, line_size, f))
  {
    if (i >= limit - 1)
    {
      limit *= 2;
      inverted = realloc(inverted, sizeof(RGB) * limit);
    }
    int values[3];
    char *split = strdup(line);
    for (int i = 0; i < 3; i++)
    {
      values[i] = atoi(strsep(&split, " "));
    }
    free(split);

    RGB rgb = new_rgb(values[0], values[1], values[2]);
    rgb_invert(&rgb);
    inverted[i].last = 0;
    inverted[i] = rgb;

    i++;
  }

  inverted[i].last = 1;

  free(line);
  fclose(f);

  return inverted;
}

int main(int argc, char const *argv[])
{
  if (argc != 2)
  {
    printf("Error, You only need to pass a [file.txt] like argument\n");
    exit(EXIT_FAILURE);
  }

  RGB *inverted = get_inverted_colors(argv[1]);
  for (int i = 0; !inverted[i].last; i++)
  {
    char *s = rgb_str((&inverted[i]));
    printf("%s\n\n", s);
    free(s);
  }

  free(inverted);
  return EXIT_SUCCESS;
}
