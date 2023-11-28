#include <stdio.h>
#include <stdlib.h>

typedef struct cartas
{
    int n;
    struct cartas *prox;
} cartas;

cartas *lista;
cartas *lista_descartadas;

void addLista_Descartadas (cartas **lista, int n)
{
    cartas *aux;
    aux = (cartas*)malloc(sizeof(cartas));

    aux->n = n;
    aux->prox = NULL;

    if (*lista == NULL)
    {
        *lista = aux;
    }

    else
    {
        cartas *p;
        p = *lista;
        while(p->prox)
        {
            p = p->prox;
        }
        p->prox = aux;
    }   
}

void addLista(cartas **lista, int n)
{
    cartas *aux;
    aux = (cartas*)malloc(sizeof(cartas));

    aux->n = n;
    aux->prox = NULL;

    if (*lista == NULL)
    {
        *lista = aux;
    }

    else
    {
        cartas *p;
        p = *lista;
        while(p->prox)
        {
            p = p->prox;
        }
        p->prox = aux;
    }
}

int main(int argc, char *argv[]) 
{
    int n;
    int i;
    int aux;
    lista = NULL;
    lista_descartadas = NULL;

    scanf("%d", &n);

    if(n<=0 || n>50) return 0;

    while(n>0 && n<=50)
    {       
        aux = 1;

        for (i=1;i<=n;i++)
        {
            addLista(&lista, i);
        }

        cartas *p;
        p = lista;

        while (p->prox)
        {
            if(aux%2 != 0)
            {
                addLista_Descartadas(&lista_descartadas, p->n);
            }

            else
            {
                addLista(&lista, p->n);  
            }

            aux++;
            p = p->prox;
        }

        int n2 = p->n;

        cartas *p2;
        p2 = lista_descartadas;

        printf("cartas descartadas: ");

        while(p2->prox)
        {
            printf("%d, ", p2->n);
            p2 = p2->prox;
        }

        printf("%d",p2->n);

        printf("\ncartas restantes: %d\n", n2);

        lista = NULL;
        lista_descartadas = NULL;

        scanf("%d", &n);
    } 

    return 0;
}
