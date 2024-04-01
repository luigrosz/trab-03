#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./libraries/pilha.c"

struct musica_struct {
    char id[6];
    char artist_name[50];
    char track_name[200];
    char release_date[5];
    char genre[10];
    char lyrics[1750];
    char len[4];
    char dating[25];
    char violence[25];
    char world[25];     // changed
    char night[25];     // changed
    char shake[25];     // changed
    char gospel[25];    // changed
    char romantic[25];  // changed
    char communication[25];
    char obscene[25];
    char music[25];
    char movement[25];   // changed
    char light[25];      // changed
    char spiritual[25];  // changed
    char girls[25];      // changed
    char sadness[25];
    char feelings[25];
    char danceability[25];
    char loudness[25];
    char acousticness[25];
    char instrumentalness[25];
    char valence[25];
    char energy[25];
    char topic[15];
    char age[25];
};

int main() {
    char linha_atual[10000];
    char *token;
    char *ptr;
    int base = 10;

    node *pilha;
    pilha = NULL;

    FILE *arquivo = fopen("tcc_ceds_music.csv", "r");
    // FILE *arquivo = fopen("musicas_teste.csv", "r");
    if (arquivo == NULL) {
        printf("erro lendo arquivo");
        return 1;
    }

    fgets(linha_atual, sizeof(linha_atual), arquivo);  // pula primeira linha
    int counter = 0;
    while (fgets(linha_atual, sizeof(linha_atual), arquivo)) {
        long id, release_date, len;
        char artist_name[50];
        char track_name[200];
        char genre[10];
        char lyrics[1750];
        double dating, violence, world, night, shake, gospel, romantic,
            communication, obscene, music, movement, light, spiritual, girls,
            sadness, feelings, danceability, loudness, acousticness,
            instrumentalness, valence, energy, topic, age;

        token = strtok(linha_atual, ",");
        id = strtol(token, &ptr, base);

        token = strtok(NULL, ",");
        strcpy(artist_name, token);

        token = strtok(NULL, ",");
        strcpy(track_name, token);

        token = strtok(NULL, ",");
        release_date = strtol(token, &ptr, base);

        token = strtok(NULL, ",");
        strcpy(genre, token);

        token = strtok(NULL, ",");
        strcpy(lyrics, token);

        token = strtok(NULL, ",");
        len = strtol(token, &ptr, base);

        token = strtok(NULL, ",");
        dating = strtod(token, &ptr);

        token = strtok(NULL, ",");
        violence = strtod(token, &ptr);

        token = strtok(NULL, ",");
        world = strtod(token, &ptr);

        token = strtok(NULL, ",");
        night = strtod(token, &ptr);

        token = strtok(NULL, ",");
        shake = strtod(token, &ptr);

        token = strtok(NULL, ",");
        gospel = strtod(token, &ptr);

        token = strtok(NULL, ",");
        romantic = strtod(token, &ptr);

        token = strtok(NULL, ",");
        communication = strtod(token, &ptr);

        token = strtok(NULL, ",");
        obscene = strtod(token, &ptr);

        token = strtok(NULL, ",");
        music = strtod(token, &ptr);

        token = strtok(NULL, ",");
        movement = strtod(token, &ptr);

        token = strtok(NULL, ",");
        light = strtod(token, &ptr);

        token = strtok(NULL, ",");
        spiritual = strtod(token, &ptr);

        token = strtok(NULL, ",");
        girls = strtod(token, &ptr);

        token = strtok(NULL, ",");
        sadness = strtod(token, &ptr);

        token = strtok(NULL, ",");
        feelings = strtod(token, &ptr);

        token = strtok(NULL, ",");
        danceability = strtod(token, &ptr);

        token = strtok(NULL, ",");
        loudness = strtod(token, &ptr);

        token = strtok(NULL, ",");
        acousticness = strtod(token, &ptr);

        token = strtok(NULL, ",");
        instrumentalness = strtod(token, &ptr);

        token = strtok(NULL, ",");
        valence = strtod(token, &ptr);

        token = strtok(NULL, ",");
        energy = strtod(token, &ptr);

        token = strtok(NULL, ",");
        topic = strtod(token, &ptr);

        token = strtok(NULL, ",");
        age = strtod(token, &ptr);

        empilha(&pilha, id, artist_name, track_name, release_date, genre,
                lyrics, len, dating, violence, world, night, shake, gospel,
                romantic, communication, obscene, music, movement, light,
                spiritual, girls, sadness, feelings, danceability, loudness,
                acousticness, instrumentalness, valence, energy, topic, age);

        counter++;
    }
    fclose(arquivo);
    printf("\ncounter: %d\n", counter);
    return 0;
}