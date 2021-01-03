#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void esecuzione(FILE* fp_in, int N);

int main()
{
    FILE* fp_in;
    int massimo;

    //APERTURA + CONTROLLO FILE
    fp_in= fopen("Scacchiera.txt", "r");
    if(fp_in==NULL)
    {
        printf("ERRORE APERTURA FILE");
        return -2;
    }

    //LETTURA DIMENSIONE SCACCHIERA + CONTROLLO
    fscanf(fp_in, "%d", &massimo);
    if(massimo>MAX)
    {
        printf("ERRORE DIMENSIONE SCACCHIERA");
        return -2;
    }

    //ESECUZIONE
    esecuzione(fp_in, massimo);

    //CHIUSURA
    fclose(fp_in);
    return 0;
}

void esecuzione(FILE* fp_in, int N)
{
    int r;
    int c;
    int r_tmp;
    int c_tmp;
    int r_max;
    int c_max;
    int finito;
    int somma;
    int somma_max;
    int scacchiera[MAX][MAX];

    //LETTURA + SCRITTURA MATRICE
    for(r=0; r<N; r++)
    {
        for(c=0; c<N; c++)
            fscanf(fp_in, "%d", &scacchiera[r][c]);
    }

    //CALCOLO
    somma= 0;
    somma_max= 0;
    for(r=0; r<N; r++)
    {
        for(c=0; c<N; c++)
        {
            if(scacchiera[r][c]==0)
            {
                //DIAGONALE ALTO SINISTRO
                finito= 0;
                r_tmp= r;
                c_tmp= c;
                while(finito!= 1)
                {
                    r_tmp--;
                    c_tmp--;
                    if((r_tmp<0)||(c_tmp<0))
                        finito= 1;
                    if(finito!=1)
                        somma= somma + scacchiera[r_tmp][c_tmp];
                }

                //DIAGONALE BASSO SINISTRO
                finito= 0;
                r_tmp= r;
                c_tmp= c;
                while(finito!= 1)
                {
                    r_tmp++;
                    c_tmp--;
                    if((r_tmp>=N)||(c_tmp<0))
                        finito= 1;
                    if(finito!=1)
                        somma= somma + scacchiera[r_tmp][c_tmp];
                }

                //DIAGONALE ALTO DESTRO
                finito= 0;
                r_tmp= r;
                c_tmp= c;
                while(finito!= 1)
                {
                    r_tmp--;
                    c_tmp++;
                    if((r_tmp<0)||(c_tmp>=N))
                        finito= 1;
                    if(finito!=1)
                        somma= somma + scacchiera[r_tmp][c_tmp];
                }

                //DIAGONALE BASSO DESTRO
                finito= 0;
                r_tmp= r;
                c_tmp= c;
                while(finito!= 1)
                {
                    r_tmp++;
                    c_tmp++;
                    if((r_tmp>=N)||(c_tmp>=N))
                        finito= 1;
                    if(finito!=1)
                        somma= somma + scacchiera[r_tmp][c_tmp];
                }

                if(somma>somma_max)
                {
                    somma_max= somma;
                    r_max= r;
                    c_max= c;
                }
                somma= 0;
            }
        }
    }

    //OUTPUT
    c_max= c_max + 65; //INIZIO DA "A"
    r_max= N - r_max;
    printf("Posizione migliore: %c%d", (char)c_max, r_max);
    printf("\nSomma diagonali: %d", somma_max);
}
