#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Document.h"

Document *creation_de_document(int id , char* titre , char** motcle , int nb){
     Document *doc = (Document*)malloc(sizeof(Document));

    doc->cle = id ;
    doc->nbmcle = nb ;
    doc->liste = (char**)malloc(nb * sizeof(char*));

    for (int i = 0; i < nb; i++) {
        doc->liste[i] = strdup(motcle[i]);
    }
    doc->valeur = strdup(titre);

    return doc ;

}

void ajout_mot_cle(Document *doc , char* mot){
    doc->liste = (char**)realloc(*doc->liste , (doc->nbmcle + 1) * sizeof(char*)) ;
    doc->liste[doc->nbmcle] = strdup (mot) ;
    doc->nbmcle++ ;
}

