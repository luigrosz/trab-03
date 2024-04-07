#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "./libraries/estruturas.c"

int main() {
    char linha_atual[10000];
    char *token;
    char *ptr;
    int base = 10;
    clock_t t;

    node *lista;
    lista = NULL;

    t = clock();
    FILE *arquivo = fopen("tcc_ceds_music.csv", "r");
    if (arquivo == NULL) {
        printf("erro lendo arquivo");
        return 1;
    }

    fgets(linha_atual, sizeof(linha_atual), arquivo);  // pula primeira linha
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

        insere_lista(&lista, id, artist_name, track_name, release_date, genre,
                     lyrics, len, dating, violence, world, night, shake, gospel,
                     romantic, communication, obscene, music, movement, light,
                     spiritual, girls, sadness, feelings, danceability,
                     loudness, acousticness, instrumentalness, valence, energy,
                     topic, age);
    }
    fclose(arquivo);
    t = clock() - t;
    printf("tempo para carregar em memoria: %lf segundos\n",
           ((double)t) / CLOCKS_PER_SEC);

    // LISTA
    node *novaLista;
    novaLista = NULL;
    t = clock();
    copiaParaLista(lista, &novaLista);
    t = clock() - t;
    printf("tempo para separar danceability na lista: %lf segundos\n",
           ((double)t) / CLOCKS_PER_SEC);
    t = clock();
    contarGeneroLista(novaLista);
    t = clock() - t;
    printf("tempo para contar as que sao pop na lista: %lf segundos\n",
           ((double)t) / CLOCKS_PER_SEC);

    // TABELA HASH
    tabHash tabela;
    InicializaTabHash(&tabela);
    t = clock();
    copiaParaTabela(&tabela, lista);
    t = clock() - t;
    printf("tempo para separar danceability na tabela hash: %lf segundos\n",
           ((double)t) / CLOCKS_PER_SEC);
    t = clock();
    // consulte o indice do genero que voce quiser no arquivo hashing.txt
    contarGeneroTabela(tabela, 13);
    t = clock() - t;
    printf("tempo para contar as que sao pop na tabela hash: %lf segundos\n",
           ((double)t) / CLOCKS_PER_SEC);

    // imprime_lista(novaLista);
    // imprimeTabHash(tabela);

    return 0;
}