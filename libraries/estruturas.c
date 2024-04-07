#include <stdio.h>
#include <string.h>

struct struct_musica {
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
};

struct struct_lista_enc {
    struct struct_musica musica;
    struct struct_lista_enc *prox;
};

typedef struct struct_musica est_musica;
typedef struct struct_lista_enc node;

void insere_lista(node **lista, long id, char *artist_name, char *track_name,
                  long release_date, char *genre, char *lyrics, long len,
                  double dating, double violence, double world, double night,
                  double shake, double gospel, double romantic,
                  double communication, double obscene, double music,
                  double movement, double light, double spiritual, double girls,
                  double sadness, double feelings, double danceability,
                  double loudness, double acousticness, double instrumentalness,
                  double valence, double energy, double topic, double age) {
    node *novo = (node *)malloc(sizeof(node));
    novo->musica.id = id;
    strcpy(novo->musica.artist_name, artist_name);
    strcpy(novo->musica.track_name, track_name);
    novo->musica.release_date = release_date;
    strcpy(novo->musica.genre, genre);
    strcpy(novo->musica.lyrics, lyrics);
    novo->musica.len = len;
    novo->musica.dating = dating;
    novo->musica.violence = violence;
    novo->musica.world = world;
    novo->musica.night = night;
    novo->musica.shake = shake;
    novo->musica.gospel = gospel;
    novo->musica.romantic = romantic;
    novo->musica.communication = communication;
    novo->musica.obscene = obscene;
    novo->musica.music = music;
    novo->musica.movement = movement;
    novo->musica.light = light;
    novo->musica.spiritual = spiritual;
    novo->musica.girls = girls;
    novo->musica.sadness = sadness;
    novo->musica.feelings = feelings;
    novo->musica.danceability = danceability;
    novo->musica.loudness = loudness;
    novo->musica.acousticness = acousticness;
    novo->musica.instrumentalness = instrumentalness;
    novo->musica.valence = valence;
    novo->musica.energy = energy;
    novo->musica.topic = topic;
    novo->musica.age = age;

    if ((*lista) == NULL) {
        novo->prox = NULL;
        (*lista) = novo;
    } else {
        novo->prox = (*lista);
        (*lista) = novo;
    }
}

void imprime_lista(node *lista) {
    for (node *i = lista; i != NULL; i = i->prox) {
        printf("%s\n", i->musica.genre);
    }
}

void copiaParaLista(node *lista, node **novaLista) {
    int counter = 0;
    for (node *i = lista; i != NULL; i = i->prox) {
        if (i->musica.danceability >= 0.5) {
            counter++;
            node *novo = (node *)malloc(sizeof(node));
            if ((*novaLista) == NULL) {
                novo->prox = NULL;
                (*novaLista) = novo;
            } else {
                novo->prox = (*novaLista);
                (*novaLista) = novo;
            }
        }
    }
    printf("COUNTER HOW MANY NODES NEW LIST: %d\n", counter);
}

#define TAM 21

struct Noh {
    struct Noh *prox;
    int chave;
    struct struct_musica musica;
};
typedef struct Noh dado;

struct tipo_tabHash {
    dado **tabela;
    int capacidade;
};
typedef struct tipo_tabHash tabHash;

void InicializaTabHash(tabHash *Tab) {
    Tab->capacidade = TAM;
    Tab->tabela = (dado **)malloc(sizeof(dado *) * TAM);

    for (int i = 0; i < TAM; i++) Tab->tabela[i] = NULL;
}

int funcHash(tabHash *tab, int chave) { return chave % tab->capacidade; }

void copiaParaTabela(tabHash *tab, node *lista) {
    InicializaTabHash(tab);
    for (node *i = lista; i != NULL; i = i->prox) {
        if (i->musica.danceability >= 0.5) {
            int chave = i->musica.genre[0] + i->musica.genre[1];
            int indice = funcHash(tab, chave);
            dado *novo;
            novo = (dado *)malloc(sizeof(dado));
            novo->chave = chave;

            novo->musica.id = i->musica.id;
            strcpy(novo->musica.artist_name, i->musica.artist_name);
            strcpy(novo->musica.track_name, i->musica.track_name);
            novo->musica.release_date = i->musica.release_date;
            strcpy(novo->musica.genre, i->musica.genre);
            strcpy(novo->musica.lyrics, i->musica.lyrics);
            novo->musica.len = i->musica.len;
            novo->musica.dating = i->musica.dating;
            novo->musica.violence = i->musica.violence;
            novo->musica.world = i->musica.world;
            novo->musica.night = i->musica.night;
            novo->musica.shake = i->musica.shake;
            novo->musica.gospel = i->musica.gospel;
            novo->musica.romantic = i->musica.romantic;
            novo->musica.communication = i->musica.communication;
            novo->musica.obscene = i->musica.obscene;
            novo->musica.music = i->musica.music;
            novo->musica.movement = i->musica.movement;
            novo->musica.light = i->musica.light;
            novo->musica.spiritual = i->musica.spiritual;
            novo->musica.girls = i->musica.girls;
            novo->musica.sadness = i->musica.sadness;
            novo->musica.feelings = i->musica.feelings;
            novo->musica.danceability = i->musica.danceability;
            novo->musica.loudness = i->musica.loudness;
            novo->musica.acousticness = i->musica.acousticness;
            novo->musica.instrumentalness = i->musica.instrumentalness;
            novo->musica.valence = i->musica.valence;
            novo->musica.energy = i->musica.energy;
            novo->musica.topic = i->musica.topic;
            novo->musica.age = i->musica.age;
        }
    }
}