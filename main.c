#include <stdio.h>
#include <stdlib.h>

struct musica {
  int id;
  char artist_name[100];
  char name;
  int value;
};

int main() {
  FILE *my_file = fopen("musicas", "r");
  struct my_record records[100];
  size_t count = 0;
  for (; count < sizeof(records) / sizeof(records[0]); ++count) {
    int got =
        fscanf(my_file, "%c,%d", &records[count].name, &records[count].value);
    if (got != 2)
      break;
  }
  fclose(my_file);

  return 0;
}
