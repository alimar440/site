#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Site..h"
#include "Document.h"

Site *creation_de_site() {
    Site *web = malloc(sizeof(Site));
    web->nbdoc = 0;
    web->docu = NULL;
    return web;
}

void Destruction_de_site(Site *web) {
    for (int i = 0; i < web->nbdoc; i++) {
        Document* doc = web->docu[i];
        free(doc->valeur);
        for (int j = 0; j < doc->nbmcle; j++) {
            free(doc->liste[j]);
        }
        free(doc->liste);
        free(doc);
    }
    free(web->docu);
    free(web);
}

void insertion_document(Site* web, Document* doc) {
    for (int i = 0; i < web->nbdoc; i++) {
        if ((doc->cle == web->docu[i]->cle) && (strcmp(doc->valeur, web->docu[i]->valeur) == 0)) {
            printf("Le document est déjà présent dans le site.\n");
            return;
        }
    }

    web->docu = (Document**)realloc(web->docu, (web->nbdoc + 1) * sizeof(Document*));
    web->docu[web->nbdoc] = doc;
    web->nbdoc++;
}

void suppression_de_document(Site *web , int id) {
    int indice = -1;
    for (int i = 0; i < web->nbdoc; i++) {
        if (id == web->docu[i]->cle) {
            indice = i;
            break;
        }
    }

    if (indice != -1) {
        Document* doc = web->docu[indice];
        free(doc->valeur);
        for (int i = 0; i < doc->nbmcle; i++) {
            free(doc->liste[i]);
        }
        free(doc->liste);
        free(doc);

        for (int i = indice; i < web->nbdoc - 1; i++) {
            web->docu[i] = web->docu[i+1];
        }
        web->nbdoc--;
        web->docu = (Document**)realloc(web->docu , web->nbdoc * sizeof(Document*));
    }
}

Document* recherche_de_document(Site* web , int id) {
    for (int i = 0; i < web->nbdoc; i++) {
        if (id == web->docu[i]->cle) {
            return web->docu[i];
        }
    }
    return NULL;
}

Site* union_de_deux_sites(Site* web1 , Site* web2) {
    Site* web_union = creation_de_site();

    for (int i = 0; i < web1->nbdoc; i++) {
        insertion_document(web_union , web1->docu[i]);
    }

    for (int i = 0; i < web2->nbdoc; i++) {
        insertion_document(web_union , web2->docu[i]);
    }

    return web_union;
}

Site* intersection_de_deux_sites(Site* web1 , Site* web2) {
    Site* web_intersection = creation_de_site();

    for (int i = 0; i < web1->nbdoc; i++) {
        if (recherche_de_document(web2, web1->docu[i]->cle) != NULL) {
            insertion_document(web_intersection, web1->docu[i]);
        }
    }

    return web_intersection;
}

Site* difference_entre_deux_sites(Site* web1 , Site* web2) {
    Site* web_diff = creation_de_site();

    for (int i = 0; i < web1->nbdoc; i++) {
        if (recherche_de_document(web2, web1->docu[i]->cle) == NULL) {
            insertion_document(web_diff, web1->docu[i]);
        }
    }

    return web_diff;
}

void affichage_site(Site* web) {
    for (int i = 0; i < web->nbdoc; i++) {
        Document* doc = web->docu[i];
        printf("Document cle: %d, valeur: %s\n", doc->cle, doc->valeur);
        printf("Mots-cles: ");
        for (int j = 0; j < doc->nbmcle; j++) {
            printf("%s ", doc->liste[j]);
        }
        printf("\n\n");
    }
}
