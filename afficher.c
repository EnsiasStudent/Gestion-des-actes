# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include "structures.h"

void consulter(Liste *liste)
{
    int i;
    Personne personne;
    Element *element=malloc(sizeof(*element));
    element=liste->premier;
    while(element!=NULL)
    {
        personne=element->personne;
        printf("Le nom est : %s\n",personne.pr_nom);
        printf("Le prenom est : %s\n",personne.pr_prenom);
        printf("La date de naissance :\n");
		for (i = 0; i < 3; ++i)
		{
			switch(i+1)
			{
				case 1:
				{
					printf("    Le jour : %d\n",element->personne.date_de_naissance[i]);
					break;
				}
				case 2:
				{
					printf("    Le mois : %d\n",element->personne.date_de_naissance[i]);
					break;
				}
				case 3:
				{
					printf("    L annee : %d\n",element->personne.date_de_naissance[i]);
					break;
				}
			}
		}
        printf("Le sexe est :");
        if (personne.sexe==0)
        {
        	printf("Homme\n");
        }
        else
        {
        	printf("Femme\n");
        }
        printf("Le CIN est : %s\n",personne.CIN);
        printf("L identifiant est : %d\n",personne.identifiant);
        printf("Le nombre d enfants est : %d\n",personne.nbr_d_enfant);
        for (i = 0; i < personne.nbr_d_enfant; i++)
        {
            printf("   L ide de l enfant %d est : %d \n",i+1,personne.enfant_ide[i]);
        }
        printf("\n");

        element=element->suivant;
    }
}


void afficher_enfants(int ide,Liste *liste)
{
    int j;int test=0;
    if (where_are_my_kids(liste,ide,0)==NULL)
    {
        printf("La personne n'existe pas !!\n");
        exit(0);
    }
    else
    {   Personne p= where_are_my_kids(liste,ide,0)->personne;
        for(j=0;j<p.nbr_d_enfant;j++)
        {
            printf("\n\n\tL enfant %d est:\n",j);
            where_are_my_kids(liste,p.enfant_ide[j],1);
        }
    }
}