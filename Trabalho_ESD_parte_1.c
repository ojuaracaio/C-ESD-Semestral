#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct musica {
    int id;
    char titulo[200];
    char artista[200];
    char album[200];
    int duracao; //segundos
} musica;

typedef struct musica_no {
    musica *musica;
    struct musica_no *ant;
    struct musica_no *prox;
} musica_no;

typedef struct playlist_no {
    musica *musica;
    struct playlist_no *prox;
} playlist_no;

typedef struct lplaylists_no {
    int id;
    char nome[200];
    playlist_no *musicas;
    struct lplaylists_no *prox;
} lplaylists_no;

musica_no *p;

//musica cabeca = {.id = 1, .titulo="MC Poze nos anos 80", .artista="Paulo Moreira", .album="Genérico", .duracao=170 };
//musica_no id1 = {.ant= 0,.prox=0,.musica= &cabeca };

int Identificao = 1;
//musica_no *ultima_musica = &id1;

//############################
//#         funções          #
//############################
void imprime(musica_no *ini);
int horas(int segundos);
int minutos(int segundos);
int segundos(int segundos);


void imprime(musica_no *ini) {
    musica_no *p;
    p = ini;
    while (p) {
        printf("Id: %d\nTitulo: %s\nArtista: %s\nAlbum: %s\nDuracao: %02d:%02d:%02d\n----------------------------------------\n", p->musica->id,p->musica->titulo,p->musica->artista,p->musica->album,horas(p->musica->duracao),minutos(p->musica->duracao),segundos(p->musica->duracao));
        p = p->prox;
    }
}

int horas(int segundos) {
    return segundos/3600;
}

int minutos(int segundos) {
    int minutos = segundos - (horas(segundos)*3600);
    return minutos/60;
}

int segundos(int segundos) {
    return (segundos-(minutos(segundos)*60))-horas(segundos)*3600;
}

void inserirMusica(musica_no *ini) {
    //musica_no *ini = ultima_musica;
    musica_no *novo = (musica_no*)malloc(sizeof(musica_no)); // cria um novo nó
    //musica *nova_musica = (musica*)malloc(sizeof(musica));
    printf("Insira o nome da música: ");
    scanf("%c",(novo->musica->titulo));
    printf("Insira o nome do artista: ");
    scanf("%c",(novo->musica->artista));
    printf("Insira o nome do album: ");
    scanf("%c",(novo->musica->album));
    printf("Insira a duracao (em segundos): ");
    scanf("%d",&novo->musica->duracao);
    novo->musica->id = Identificao;
    Identificao++;

    musica_no *p;
    p = ini;

    if(ini->prox == NULL) { // a lista está vazia
        novo->prox = NULL;
        ini->prox = novo;
        novo->ant = ini;
    } else {
        while (ini) {
            ini = ini->prox;
        }
        novo->prox = NULL;
        ini->prox = novo;
        novo->ant = ini;

    }
}

int main() {

    imprime(p);
    inserirMusica(p);
    imprime(p);

    return 0;
}
