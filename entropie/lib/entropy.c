#include "entropy.h"
#include <stdio.h>
#include <math.h>


void count_occurrences(FILE *file, int counts[]){
    int c ;

     //La fonction fgetc vous permettra de lire octet par octet dans le fichier ouvert
    c = fgetc(file);
    // Puis on compte le nombre d'occurance a chaque fois qu'il y a un caractere dans le fichier ouvert
    while (c != EOF){
        counts[c] = counts[c]+1 ;
        c = fgetc(file);
    }

}


struct file_stat entropy(int counts[]){

  //le nombre total de bits dans le fichier correspond à la somme des occurences présentes dans 
     //counts on calcul lentropie en utilisant la formule

   
    struct file_stat state;
    int N , i ;
    float s;
    i = 0;
    N = 0;
    s = 0;

    while( i < 256 ){
        N = N + counts[i];
        i++;
    }//N donne le nombre de caractères ou octet du fichier

    state.size = N;
    i = 0;

    while( i < 256){
        if (counts[i] != 0)
            s = s + ( counts[i] * log2f(counts[i]) ) ;
        i++;
    }

    state.entropy  = log2f(N) - (s / N);

    return state;

}