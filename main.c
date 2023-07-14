#include <stdio.h>

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

int main()
{

      


    return 0;
}