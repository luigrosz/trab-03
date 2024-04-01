#include <stdio.h>

struct pilha_enc {
    long id;
    char artist_name[50];
    char track_name[200];
    long release_date;
    char genre[10];
    char lyrics[1750];
    long len;
    double dating;
    double violence;
    double world;     // changed
    double night;     // changed
    double shake;     // changed
    double gospel;    // changed
    double romantic;  // changed
    double communication;
    double obscene;
    double music;
    double movement;   // changed
    double light;      // changed
    double spiritual;  // changed
    double girls;      // changed
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
    struct pilha_enc *prox;
};

typedef struct pilha_enc node;

void empilha(node **pilha, long id, char *artist_name, char *track_name,
             long release_date, char *genre, char *lyrics, long len,
             double dating, double violence, double world, double night,
             double shake, double gospel, double romantic, double communication,
             double obscene, double music, double movement, double light,
             double spiritual, double girls, double sadness, double feelings,
             double danceability, double loudness, double acousticness,
             double instrumentalness, double valence, double energy,
             double topic, double age);
void desempilha(node **);

void empilha(node **pilha, long id, char *artist_name, char *track_name,
             long release_date, char *genre, char *lyrics, long len,
             double dating, double violence, double world, double night,
             double shake, double gospel, double romantic, double communication,
             double obscene, double music, double movement, double light,
             double spiritual, double girls, double sadness, double feelings,
             double danceability, double loudness, double acousticness,
             double instrumentalness, double valence, double energy,
             double topic, double age) {
    node *novo = (node *)malloc(sizeof(node));
    novo->id = id;
    strcpy(novo->artist_name, artist_name);
    strcpy(novo->track_name, track_name);
    novo->release_date = release_date;
    strcpy(novo->genre, genre);
    strcpy(novo->lyrics, lyrics);
    novo->len = len;
    novo->dating = dating;
    novo->violence = violence;
    novo->world = world;
    novo->night = night;
    novo->shake = shake;
    novo->gospel = gospel;
    novo->romantic = romantic;
    novo->communication = communication;
    novo->obscene = obscene;
    novo->music = music;
    novo->movement = movement;
    novo->light = light;
    novo->spiritual = spiritual;
    novo->girls = girls;
    novo->sadness = sadness;
    novo->feelings = feelings;
    novo->danceability = danceability;
    novo->loudness = loudness;
    novo->acousticness = acousticness;
    novo->instrumentalness = instrumentalness;
    novo->valence = valence;
    novo->energy = energy;
    novo->topic = topic;
    novo->age = age;

    if (*pilha == NULL) {
        novo->prox = NULL;
        *pilha = novo;
    } else {
        novo->prox = (*pilha);
        *pilha = novo;
    }
}

void desempilha(node **pilha) {
    node *aux;
    if (*pilha == NULL) {
        printf("[ERRO] A PILHA ESTA VAZIA");
    } else {
        aux = (*pilha);
        (*pilha) = (*pilha)->prox;
        free(aux);
    }
}