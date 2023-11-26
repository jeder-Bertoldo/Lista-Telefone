#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct n {
    char palavra[200];
    struct n *prev, *next;
} *Nodo;

typedef struct l {
    struct n *head;
} *Lista;

// aloca a lista
Lista new_list() {
    return (Lista) malloc(sizeof(struct l));
}

// aloca o nó
Nodo new_node(char *s) {
    Nodo n  = (Nodo) malloc(sizeof(struct n));
    n->prev = n->next = NULL;
    strcpy(n->palavra, s);

    return n;
}

// inserção ordenada de um nó na lista
void insert_node(Nodo n, Lista l) {

    // lista vazia
    if(!l->head) {
        l->head = n;
        return;
    }

    if(strcmp(n->palavra, l->head->palavra) != 0) {

        // inserção na cabeça
        if(strcmp(n->palavra, l->head->palavra) < 0) {
            n->next = l->head;
            l->head->prev = n;
            l->head = n;
            return;
        }

        // percorre a lista
        Nodo aux = l->head;
        while(aux->next && strcmp(n->palavra, aux->next->palavra) > 0)
            aux = aux->next;

        // inserção da cauda
        if(!aux->next) {
            aux->next = n;
            n->prev = aux;
            return;
        }

        // descarte(palavra repetida)
        if(strcmp(n->palavra, aux->next->palavra) == 0)
            return;

        // inserção ordenada
        n->next = aux->next;
        n->prev = aux;
        aux->next->prev = n;
        aux->next = n;
    }

    return;
}

// imprime a lista
void print_list(Lista l) {
    Nodo aux = l->head;
    while(aux->next) {
        printf("%s\n", aux->palavra);
        aux = aux->next;
    }
    printf("%s\n", aux->palavra);
    return;
}

// destrói a lista(libera a memória)
void destroy_list(Lista l) {
    Nodo aux = l->head;

    while(aux->next) {
        aux = aux->next;
        free(aux->prev);
    }

    free(aux);
    free(l);
    return;
}

int main() {
    char c, str[2000000];
    Lista L = new_list();
    int i = 0;
    Nodo n;
	printf("|=====COLOQUE AS PALAVRAS QUE DESEJAS: ");
    while(scanf("%c", &c) != EOF) {
        if(isalpha(c)) {
            str[i++] = tolower(c);
            continue;
        }

        if(i) {
            n = new_node(str);
            insert_node(n ,L);
            memset(str, '\0', sizeof(str)); //limpa a string str;
            i = 0;
        }
		printf("|===NOVA LISTA DE PALAVRAS==| \n"); 
	   print_list(L);

    }
	    destroy_list(L);
  
   

    return 0;
}
