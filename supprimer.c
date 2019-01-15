# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include"structures.h"

void supprimer(Liste *liste)
{
	int test=0;
	Element *element=malloc(sizeof(Element));
    element=liste->premier;
	int idesup;
	printf("L ide de la personne a supprimer :\n");
	scanf("%d",&idesup);
    if(liste->premier!=NULL && liste->premier->personne.identifiant!=idesup)
    {
        while(element->suivant!=NULL && element->suivant->personne.identifiant!=idesup)
        {
            element=element->suivant;
        }
        element->suivant=element->suivant->suivant;
        free(element);
        printf("La personne est bien supprimer\n");
    }
    else if(liste->premier!=NULL && liste->premier->personne.identifiant==idesup)
        {liste->premier=liste->premier->suivant;
        free(element);}
    else
        printf("L identifiant n existe pas");

    printf("Pour supprimer une autre personne (veuillez appuyez sur 1) :\n");
    scanf("%d",&test);
  	if (test==1)
   	{
  		supprimer(liste);
   	}
}
