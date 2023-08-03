/*-------------------------------------------------------------------------
 *              UNIFAL - Universidade Federal de Alfenas.
 *                BACHARELADO EM CIENCIA DA COMPUTACAO.
 * Trabalho...: Rotulacao de Componentes Conexos.
 * Disciplina.: Processamento de Imagens
 * Professor..: Luiz Eduardo da Silva
 * Aluno......: Lucas da Silva Justino
 * Data.......: 10/07/2021
 *-------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "imagelib.h"

void rotula(image In, image Out, int nl, int nc, int mn){
    image aux;
    int i;
    int rotulo = 0;
    int pInicial = (1 * nc) + 1;
    int equivalentes[10000];
    int qtdEquivalentes = 0;
   
    for(i = pInicial; i < nl * nc; i++){
        if(In[i] == 0 && i % nc != 0){
            if(In[i - 1] == mn && In[i - nc] == mn){  //QUANDO OS DOIS VIZINHOS SAO 0
                In[i] = ++rotulo;
                equivalentes[rotulo] = rotulo;
            }
            else if(In[i - 1] != mn && In[i - nc] != mn){ //QUANDO OS VIZINHOS SÃO DIFERENTE DE 0
                if(In[i - 1] != In[i - nc]){
                    if(equivalentes[In[i - 1]] != In[i - nc]){//VERIFICO SE NAO SAO EQUIVALENTES
                       equivalentes[In[i - 1]] = In[i - nc];
                       qtdEquivalentes++;       
                    }
                    In[i] = In[i - 1];  
                }
                else
                    In[i] = In[i - 1];
            }
            else if(In[i - 1] != mn || In[i - nc] != mn){ //QUANDO UM DOS VIZINHOS É ZERO E O OUTRO NÃO
                if(In[i - 1] != mn)
                    In[i] = In[i - 1];
                else
                    In[i] = In[i - nc];
            }
        }   
    }
    printf("\n#componentes= %d\n\n", rotulo - qtdEquivalentes);
}

void msg(char *s)
{
    printf("\nImage negative");
    printf("\n-------------------------------");
    printf("\nUsage:  %s  <IMG.PGM>\n\n", s);
    printf("    <IMG.PGM> is pgm image file \n\n");
    exit(1);
}

/*-------------------------------------------------------------------------
 * main function
 *-------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int OK, nc, nr, ml;
    char name[100];
    char command[110];
    image In, Out;
    if (argc < 2)
        msg(argv[0]);

    In = img_readpgm(argv[1], &nr, &nc, &ml);
    //printf("\nImage negative");
    //img_info(argv[1], nr, nc, ml);
    Out = img_alloc(nr, nc);

    /*-- transformation --*/
    rotula(In, Out, nr, nc, ml);

    sprintf(name, "%s-%s", argv[1], "horizontal.pgm");
    img_writepgm(Out, name, nr, nc, ml);
    //sprintf(command, "%s %s &", VIEW, name);
    system(command);
    img_free(In);
    img_free(Out);
    return 0;
}