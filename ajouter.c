# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include "structures.h"


int gender_confirmed(Liste *liste,int ide,int sexe)
{
    int i;
    Element *element=malloc(sizeof(Element));
    element=liste->premier;
    while((element!=NULL))
    {
        if(element->personne.sexe==sexe)
        {
            for(i=0;i<element->personne.nbr_d_enfant;i++)
            {
                if(ide==element->personne.enfant_ide[i])
                    return 0;

            }
        }

        element=element->suivant;
    }

    return 1;
}

void ajouter(Liste *liste)
{
    int test=0,i;
    do
    {
        int ide;
        Personne nv_personne;
        Element *nv_element=malloc(sizeof(*nv_element));
        printf("Entrer le nom :\n");
        scanf("%s",nv_personne.pr_nom);
        printf("Entrer le prenom :\n");
        scanf("%s",nv_personne.pr_prenom);
        printf("Choisis ton sexe (0)#Homme (1)#Femme :\n");
        scanf("%d",&nv_personne.sexe);
        if (liste->premier==NULL) ide=1;
        else
            ide=liste->premier->personne.identifiant+1;
        nv_personne.identifiant=ide;
        printf("La date de naissance :\n");
        for (i = 0; i < 3; ++i)
        {
            switch(i)
            {
                case 0:
                {
                    printf("\tEntrer le jour :");
                    printf("\n\t");
                    break;
                }
                case 1:
                {
                    printf("\tEntrer le mois :");
                    printf("\n\t");
                    break;
                }
                case 2:
                {
                    printf("\tEnter l annee :");
                    printf("\n\t");
                    break;
                }
            }
            scanf("%d",&nv_personne.date_de_naissance[i]);
        }
        printf("Entrer votre CIN :\n");
        printf("\t");
        scanf("%s",nv_personne.CIN);
        nv_personne.identifiant=ide;
        printf("Entrer le nombre d enfant :\n");
        printf("\t");
        scanf("%d",&nv_personne.nbr_d_enfant);
        if (nv_personne.nbr_d_enfant!=0)
        {
            printf("Entrer l ide des enfants :\n\t");
        }
        for (i = 0;i < nv_personne.nbr_d_enfant; i++)
        {   
            scanf("%d",&ide);
            if (gender_confirmed(liste,ide,nv_personne.sexe)==1)
            {
                nv_personne.enfant_ide[i]=ide;

            }
            else
                i--;
        }
        nv_element->personne=nv_personne;
        nv_element->suivant=liste->premier;
        liste->premier=nv_element;

        printf("Si vous voulez ajouter autre Personne (appuyez sur 1) :\n");
        scanf("%d",&test);
    } while (test==1);
}
