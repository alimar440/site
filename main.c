#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Site..h"
#include "Document.h"

int main() {
    Site *web = creation_de_site();
    int choix;

    do {
        printf("1. Ajouter un document\n");
        printf("2. Supprimer un document\n");
        printf("3. Rechercher un document\n");
        printf("4. Afficher le site\n");
        printf("5. Creation site\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: {
                int id;
                char titre[100];
                int nbMotsCles;

                printf("Saisir l'identifiant du document : ");
                scanf("%d", &id);
                printf("Saisir le titre du document : ");
                scanf("%s", titre);
                printf("Saisir le nombre de mots-clés : ");
                scanf("%d", &nbMotsCles);

                char** motsCles = (char**)malloc(nbMotsCles * sizeof(char*));
                printf("Saisir les mots-clés :\n");
                for (int i = 0; i < nbMotsCles; i++) {
                    motsCles[i] = (char*)malloc(100 * sizeof(char));
                    scanf("%s", motsCles[i]);
                }

                Document* doc = creation_de_document(id, titre, motsCles, nbMotsCles);
                insertion_document(web, doc);

                printf("Document ajouté avec succès.\n");
                break;
            }
            case 2: {
                int id;

                printf("Saisir l'identifiant du document à supprimer : ");
                scanf("%d", &id);

                suppression_de_document(web, id);

                printf("Document supprimé avec succès.\n");
                break;
            }
            case 3: {
                int id;

                printf("Saisir l'identifiant du document à rechercher : ");
                scanf("%d", &id);

                Document* doc = recherche_de_document(web, id);
                if (doc != NULL) {
                    printf("Document trouvé :\n");
                    printf("Identifiant : %d\n", doc->cle);
                    printf("Titre : %s\n", doc->valeur);
                    printf("Mots-clés : ");
                    for (int i = 0; i < doc->nbmcle; i++) {
                        printf("%s ", doc->liste[i]);
                    }
                    printf("\n");
                } else {
                    printf("Aucun document trouvé avec l'identifiant donné.\n");
                }
                break;
            }
            case 4:
                printf("Contenu du site :\n");
                affichage_site(web);
                break;
            case 5:
                Site *web2 = creation_de_site();
                int nb ;
                printf("donner le nombre de document\n");
                scanf("%d",&nb)
                break;
            case 6 :

            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }

        printf("\n");
    } while (choix != 5);

    Destruction_de_site(web);

    return 0;
}
