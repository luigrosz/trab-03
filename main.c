#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct musica {
  int id;
  char artist_name[50];
  char track_name[200];
  int release_date;
  char genre[10];
  char lyrics[1750];
  int len;
  double dating;
  double violence;
  double world; // changed
  double night; // changed
  double shake; // changed
  double gospel; // changed
  double romantic; // changed
  double communication;
  double obscene;
  double music;
  double movement; // changed
  double light; // changed
  double spiritual; // changed
  double girls; // changed
  double sadness;
  double feelings;
  double danceability;
  double loudness;
  double acousticness;
  double instrumentalness;
  double valence;
  double energy;
  double topic;
  double age;
};

int main() {
  char linha_atual[10000];
  char *data;

  // FILE *arquivo = fopen("tcc_ceds_music.csv", "r");
  FILE *arquivo = fopen("musicas_teste.csv", "r");
  if(arquivo == NULL){
    printf("erro lendo arquivo");
    return 1;
  }

  // struct musica musicas[28500];

  unsigned int counter = 0;  
  while(fgets(linha_atual, sizeof(linha_atual), arquivo)){
    data = strtok(linha_atual,",");
    printf("%s\n", data);

    for (int i = 0; i < 30; i++){
      data = strtok(NULL,",");
      printf("%s\n", data);
    }
    counter++;
  }
  printf("counter: %d", counter);
  fclose(arquivo);

  return 0;
}