# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include"structures.h"

Liste* lire()
{
    Liste *liste=malloc(sizeof(*liste));
    liste->premier=NULL;
    FILE * fichier;
    Element *element=malloc(sizeof(*element));
    fichier=fopen("data_base","r");
    if(fichier!=NULL){
    while(fread(&element->personne,sizeof(Personne),1,fichier)!= 0)
    {
        element->suivant=liste->premier;
        liste->premier=element;
        element=malloc(sizeof(*element));
    }
    fclose(fichier);
    }
    trie_ide(liste);
    return liste;
}
void Ecrire(Liste *liste)
{
    FILE * fichier=NULL;
    fichier=fopen("data_base","w+");
    Element *element=malloc(sizeof(Element));
    element=liste->premier;
    while(element!= NULL)
    {
        fwrite(&element->personne,sizeof(Personne),1,fichier);
        element=element->suivant;
    }
    fclose(fichier);
}
void enregistrer(Liste *liste)
{
    int choix;
    printf("\n\t#################################################################################");
    printf("\n\t#                                                                               #");
    printf("\n\t#       Voulez vous enregistrer les modifications saisie:                       #");
    printf("\n\t#                  1 - Oui                                                      #");
    printf("\n\t#                  2 - Non                                                      #");
    printf("\n\t#                                                                               #");
    printf("\n\t#################################################################################");
    printf("\n votre choix : ");
    scanf("%d",&choix);
    if(choix==1)
    		Ecrire(liste);
    else
    		liste=lire();

}
