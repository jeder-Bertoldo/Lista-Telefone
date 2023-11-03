#include <cstdio>
#include <cstdlib>
#include <cstring>

// tamanho maximo da minha string exigida pelo URI
#define MAX 1000001

struct data{
    char data;
    struct data* next, *last;
};

struct list{
    int qt;
    struct data* head, *tail;
};

typedef struct data DATA;
typedef struct list LIST;

LIST* listcreate(){
    LIST* temp = (LIST *) malloc(sizeof(LIST));

    temp->head = temp->tail = NULL;
    temp->qt   = 0;

    return temp;
}

int qtlist(LIST* L){return L->qt;}

int insertinit(LIST* L, char x){

    if (L == NULL) return -1;

    DATA* temp =  (DATA*) malloc(sizeof(DATA));

    if (L->head == NULL && L->tail == NULL){
        temp->data   = x;
        temp->last = L->head;
        temp->next = L->tail;
        L->head    = L->tail  = temp;
        L->qt++;

        return 1;
    }else{
        temp->data    = x;
        temp->next = L->head;
        temp->last = NULL;
        L->head->last = temp;
        L->head    = temp;
        L->qt++;

        return 1;
    }
}

int insertfinal(LIST* L, char x){

    if (L == NULL) return -1;

    DATA* temp = (DATA*) malloc(sizeof(DATA));

    temp->data = x;

    if (L->tail != NULL){
        temp->last = L->tail;
        temp->next = NULL;
        L->tail->next = temp;
        L->tail     = temp;
        L->qt++;
        return 1;
    }else {
        temp->last = L->tail;
        temp->next = NULL;
        L->tail     = temp;
        L->head     = L->tail;
        L->qt++; 
        return 1;
    }

    return 1;

}

int insertmeans(LIST* L,unsigned int p, char x){

    DATA* j = L->head;

    DATA* k = (DATA*) malloc(sizeof(DATA));
    k->data = x;

    if (p > 0){
        while (--p) j = j->next;
    }

    k->next = j->next;
    k->last = j;
    j->next = k;

    L->qt++;

    return 1;

}

void clearlist(LIST* L){
    if (L != NULL){
        DATA* temp = L->head;
        DATA* x;

        while (temp != NULL){
           x  = temp;
            temp = temp->next;
            free(x);
            L->qt--;
        }
    }
    L->head = L->tail = NULL;

}

void freelist(LIST* L){

    if (L != NULL){
        DATA* temp = L->head;
        DATA* x;

        while (temp != NULL){
           x  = temp;
            temp = temp->next;
            free(x);
        }
        free(L);    
    }
}

void printlist(LIST* L){

    unsigned int i, size = (unsigned int) L->qt;

    DATA* temp = L->head;

    for (i = 0; i < size; i++){
        printf("%c", temp->data);
        temp = temp->next;
    }
}

int main (){

    char string[MAX];
    unsigned i, j, k, size;
    LIST* l = listcreate();

    // lendo o texto ate o fim do arquivo 
    while (scanf("%s", string) != EOF){

            size    = (unsigned int) strlen(string);

            j = 0;
            k = 0;
            for (i = 0; i < size; i++){
                if (string[i] == '[') {
                        j = 1;
                        k = 0;
                }
                if (string[i] == ']') j = 0;

                if (string[i] != '[' && string[i] != ']'){
                    if (j == 1 && qtlist(l) != 0){
                       if (k == 0) insertinit(l, string[i]);
                       else insertmeans(l, k, string[i]);
                       k++;
                    }else{
                       insertfinal(l, string[i]);
                    }
                }
            }

            printlist(l);
            printf("\n");
            clearlist(l);
    }

    freelist(l);

    return 0;
}
