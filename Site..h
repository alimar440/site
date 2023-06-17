#ifndef SITE__H_INCLUDED
#define SITE__H_INCLUDED
#include "Document.h"

typedef struct {
    Document **docu ;
    int nbdoc ;
}Site ;

void Destruction_de_site(Site *web) ;
Site *creation_de_site() ;
void insertion_document(Site *web , Document* doc) ;
Document* recherche_de_document( Site* web , int id ) ;
Site* union_de_deux_sites(Site* web1 , Site* web2) ;
Site* intersection_de_deux_sites(Site *web1 , Site *web2) ;
Site*  difference_entre_deux_sites(Site *web1 , Site *web2) ;
void affichage_site(Site* web) ;
void suppression_de_document(Site *web , int id)  ;

#endif // SITE__H_INCLUDED
