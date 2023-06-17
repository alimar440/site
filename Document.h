#ifndef DOCUMENT_H_INCLUDED
#define DOCUMENT_H_INCLUDED

typedef struct {
    int cle ;
    char* valeur ;
    char **liste ;
    int nbmcle ;
}Document ;
Document *creation_de_document(int id , char* titre , char** motcle , int nb);
void ajout_mot_cle(Document *doc , char* mot ) ;

#endif // DOCUMENT_H_INCLUDED
