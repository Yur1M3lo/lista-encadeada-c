#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

struct No
{
    int info;
    struct No* Proximo;
};


struct Lista
{
    struct No* inicio;
    int tamanho;

};

struct Lista* criar()
{
    struct Lista* nova_lista = (struct Lista*) malloc(sizeof(struct Lista));
    if (nova_lista != NULL)
    {
        nova_lista->inicio = NULL;
        nova_lista->tamanho = 0;
    }
    
};

bool vazia(struct Lista* li)
{
    assert(li != NULL);
    if (li->inicio == NULL)
    {
        return true;

    } else 
    {
        return false;
    }
}

void inserir(struct Lista* li, int pos, int item)
{
    assert(li != NULL);
    assert(pos >= 0 && pos <= li->tamanho);
    struct No* novo_no = (struct No*) malloc(sizeof(struct No));
    novo_no->info = item;

    if (pos == 0)
    {
        novo_no->Proximo = li->inicio;
        li->inicio = novo_no;
    } else
    {
        struct No* aux = li->inicio;
        for (int i = 0; i < pos -1; i++)
        {
            aux = aux->Proximo;
        }
        novo_no->Proximo = aux->Proximo;
        aux->Proximo = novo_no;
        
    }
    li->tamanho++;
    
    
}

void imprimir(struct Lista* li)
{
    assert(li != NULL);
    printf("\nLista: ");
    struct No* aux = li->inicio;
    for (int i = 0; i < li->tamanho; i++)
    {
        printf(" %d ", aux->info);
        aux = aux->Proximo;
    }
    
}

int main()
{

    struct Lista* minha_lista = criar();
    inserir(minha_lista, 0, 5);
    inserir(minha_lista, 0, 3);
    inserir(minha_lista, 0, 6);
    inserir(minha_lista, 0, 8);
    inserir(minha_lista, 0, 10);
    imprimir(minha_lista);

    return 0;
}