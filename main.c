#include <stdio.h>
#include <stdlib.h>

struct musica {
  int id;
  char artist_name[100];
  char track_name[];
  release_date;
  genre;
  lyrics;
  len;
  dating;
  violence;
  world / life;
  night / time;
  "shake the audience";
  family / gospel;
  romantic;
  communication;
  obscene;
  music;
  movement / places;
  light / visual perceptions;
  family / spiritual;
  like / girls;
  sadness;
  feelings;
  danceability;
  loudness;
  acousticness;
  instrumentalness;
  valence;
  energy;
  topic;
  age;
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
