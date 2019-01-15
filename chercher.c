# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include "structures.h"

Element* chercher_par_ide(Liste *liste)
{
	Element *element=malloc(sizeof(Element));
	int ide,test,i;
	printf("Entrer l identifiant de la personne rechercher :\n");
	scanf("%d",&ide);
	element=liste->premier;
	while(element!=NULL&&(ide!=element->personne.identifiant) )
	{
		element=element->suivant;
	}
	if (element==NULL || ide!=element->personne.identifiant)
	{
        return NULL;
	}
	else
	{
		printf("L element rechercher existe pour afficher ses informations (Veuillez taper touche 1) :\n");
        scanf("%d",&test);
		if (test==1)
		{
			printf("Le nom est : %s\n",element->personne.pr_nom);
			printf("Le prenom est : %s\n",element->personne.pr_prenom);
			printf("La date de naissance : \n");
			for (i = 0; i < 3; ++i)
			{
			switch(i+1)
			{
				case 1:
				{
					printf("    \tLe jour : %d\n\t",element->personne.date_de_naissance[i]);
					break;
				}
				case 2:
				{
					printf("    \tLe mois : %d\n\t",element->personne.date_de_naissance[i]);
					break;
				}
				case 3:
				{
					printf("    \tL annee : %d\n\t",element->personne.date_de_naissance[i]);
					break;
				}
			}
			}
			printf("Le sexe est : \n");
			if (element->personne.sexe==0)
			{
				printf("Homme\n");
			}
			else
			{
				printf("Femme\n");
			}
			printf("Le CIN est : %s\n",element->personne.CIN);
			printf("L identifiant est : %d\n",element->personne.identifiant);
			printf("Le nombre d enfants est : %d\n",element->personne.nbr_d_enfant);
			if (element->personne.nbr_d_enfant!=0)
			{
				printf("Les identifiant des enfants sont :\n");
			}
			for (i = 0; i < element->personne.nbr_d_enfant; ++i)
			{
				printf("   L ide de l enfant %d est : %d \n",(i+1),element->personne.enfant_ide[i]);
			}
		}
	}
	return element;
}

Element* chercher_par_CIN(Liste *liste)
{
	int test,i;
    char C[CMAX];
	printf("Entrer le CIN de la personne rechercher :\n");
	scanf("%s",C);
    Element *element=malloc(sizeof(Element));
    element=liste->premier;;
	while(element!=NULL && (strcmp(C,element->personne.CIN))!=0)
	{
		element=element->suivant;
	}
	if (element==NULL || (strcmp(C,element->personne.CIN))!=0)
	{
        return NULL;
	}
	else
	{
		printf("L element rechercher existe (Pour l'afficher taper 1) :\n");
        scanf("%d",&test);
		if (test==1)
		{
			printf("Le nom est : %s\n",element->personne.pr_nom);
			printf("Le prenom est : %s\n",element->personne.pr_prenom);
			printf("La date de naissance : \n");
			for (i = 0; i < 3; ++i)
			{
			switch(i+1)
			{
				case 1:
				{
					printf("    \tLe jour : %d\n",element->personne.date_de_naissance[i]);
					break;
				}
				case 2:
				{
					printf("    \tLe mois : %d\n",element->personne.date_de_naissance[i]);
					break;
				}
				case 3:
				{
					printf("    \tL annee : %d\n",element->personne.date_de_naissance[i]);
					break;
				}
			}
			}
			printf("Le sexe est : \n");
			if (element->personne.sexe==0)
			{
				printf("Homme\n");
			}
			else
			{
				printf("Femme\n");
			}
			printf("L identifiant de la personne est : %d\n",element->personne.identifiant);
			printf("L identifiant est : %d\n",element->personne.identifiant);
			printf("Le nombre d'enfants est : %d\n",element->personne.nbr_d_enfant);
			if (element->personne.nbr_d_enfant!=0)
			{
				printf("Les identifiant des enfant sont :\n");
			}
			for (i = 0; i < element->personne.nbr_d_enfant; ++i)
			{
				printf("   L ide de l enfant %d est : %d \n",(i+1),element->personne.enfant_ide[i]);
			}
		}
	}
	return element;
}

Element* chercher_par_nom(Liste *liste)
{
	Element *element=malloc(sizeof(Element));
	int test,i;
	char re_nom[CMAX];
	printf("Entrer le nom de la personne rechercher :\n");
	scanf("%s",re_nom);
	element=liste->premier;
	do
	{
		while((element!=NULL) && strcmp(re_nom,element->personne.pr_nom)!=0)
		{
			element=element->suivant;
		}
		if (element==NULL || strcmp(re_nom,element->personne.pr_nom)!=0)
		{
            return NULL;
		}
		else
		{
			printf("La personne avec le nom rechercher est trouver ses informations sont les suivantes:\n");
			printf("Le prenom est : %s\n",element->personne.pr_prenom);
			printf("La date de naissance : \n");
			for (i = 0; i < 3; ++i)
			{
			switch(i+1)
			{
				case 1:
				{
					printf("    \tLe jour : %d\n",element->personne.date_de_naissance[i]);
					break;
				}
				case 2:
				{
					printf("    \tLe mois : %d\n",element->personne.date_de_naissance[i]);
					break;
				}
				case 3:
				{
					printf("    \tL annee : %d\n",element->personne.date_de_naissance[i]);
					break;
				}
			}
			}
			printf("Le sexe est : \n");
			if (element->personne.sexe==0)
			{
				printf("Homme\n");
			}
			else
			{
				printf("Femme\n");
			}
			printf("L identifiant de la personne est : %d\n",element->personne.identifiant);
			printf("L identifiant est : %d\n",element->personne.identifiant);
			printf("Le nombre d enfants est : %d\n",element->personne.nbr_d_enfant);
			if (element->personne.nbr_d_enfant!=0)
			{
				printf("Les identifiant des enfant sont :\n");
			}
			for (i = 0; i < element->personne.nbr_d_enfant; ++i)
			{
				printf("   L ide de l enfant %d est : %d \n",(i+1),element->personne.enfant_ide[i]);
			}
        }
		printf("Si la personne ne correspond pas a ce que vous voulez (Veuillez appuyez sur 1) :\n");
		scanf("%d",&test);
	} while (test==1);
	return element;
}

Element* chercher_par_prenom(Liste *liste)
{
	Element *element=malloc(sizeof(Element));
	int test,i;
	char re_prenom[CMAX];
	printf("Entrer le prenom de la personne rechercher :\n");
    fflush(stdin);      // Cette fonction permet de vider le Buffer avant toute opérations //
    scanf("%s",re_prenom);
    element=liste->premier;
	do
	{
		while(element!=NULL && strcmp(re_prenom,element->personne.pr_prenom)!=0)
		{
			element=element->suivant;
		}
		if (element==NULL || strcmp(re_prenom,element->personne.pr_prenom)!=0)
		{
			return NULL;
		}
		else
		{
			printf("La personne avec le prenom rechercher est trouver ses informations sont les suivantes:\n");
			printf("Le nom est : %s\n",element->personne.pr_nom);
			printf("La date de naissance : \n");
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
			printf("Le sexe est : \n");
			if (element->personne.sexe==0)
			{
				printf("Homme\n");
			}
			else
			{
				printf("Femme\n");
			}
			printf("L identifiant de la personne est : %d\n",element->personne.identifiant);
			printf("L identifiant est : %d\n",element->personne.identifiant);
			printf("Le nombre d'enfants est : %d\n",element->personne.nbr_d_enfant);
			if (element->personne.nbr_d_enfant!=0)
			{
				printf("Les identifiant des enfant sont :\n");
			}
			for (i = 0; i < element->personne.nbr_d_enfant; ++i)
			{
				printf("   L identifiant de l enfant %d est : %d \n",(i+1),element->personne.enfant_ide[i]);
			}

        }
		printf("Si la personne ne correspond pas a ce que vous voulez (veuillez appuyez sur 1) :\n");
		scanf("%d",&test);
	}while (test==1);
	return element;
}
Element* where_are_my_kids(Liste *liste,int ide,int test)
{
    Element *element=malloc(sizeof(Element));
    int i=0;
    element=liste->premier;
    while(element!=NULL&&(ide!=element->personne.identifiant) )
    {
        element=element->suivant;
    }
    if (element==NULL || ide!=element->personne.identifiant)
    {
        return NULL;
    }
    else
    {   if(test==1){
            printf("Le nom est : %s\n",element->personne.pr_nom);
            printf("Le prenom est : %s\n",element->personne.pr_prenom);
            printf("La date de naissance : \n");
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
            printf("Le sexe est : \n");
            if (element->personne.sexe==0)
            {
                printf("\tHomme\n");
            }
            else
            {
                printf("\tFemme\n");
            }
            printf("Le CIN est : %s\n",element->personne.CIN);
            printf("L identifiant est : %d\n",element->personne.identifiant);
            printf("Le nombre d enfants est : %d\n",element->personne.nbr_d_enfant);
            if (element->personne.nbr_d_enfant!=0)
            {
                printf("Les identifiants des enfants sont :\n");
            }
            for (i = 0; i < element->personne.nbr_d_enfant; ++i)
            {
                printf("   L ide de l enfant %d est : %d \n",(i+1),element->personne.enfant_ide[i]);
            }

      return element;}
      else if(test==0)return element;
    }

}

Element* where_is_mum(Liste *liste,int ide)
{
	Element *element=malloc(sizeof(Element));
	int i=0;

	element=liste->premier;


	while(element!=NULL)
	{
        if(element->personne.nbr_d_enfant==0)
             element=element->suivant;
        else if(element->personne.sexe==1)
        {
            if(ide==element->personne.enfant_ide[i])
                return element;
            else if (i==element->personne.nbr_d_enfant-1)
            {
                i=-1;
                element=element->suivant;
            }

            i++;
        }
        else element=element->suivant;

	}
	printf("\n\tCette personne a une mere non enregistrer dans la base de donnees \n");
	return NULL;
}
Element* where_is_dad(Liste *liste,int ide)
{
    Element *element=malloc(sizeof(Element));
    int i=0;

    element=liste->premier;
    while(element!=NULL)
    {   if(element->personne.nbr_d_enfant==0)
             element=element->suivant;
        else if(element->personne.sexe==0)
        {
            if(ide==element->personne.enfant_ide[i])
                return element;
            else if (i==element->personne.nbr_d_enfant-1)
            {
                i=-1;
                element=element->suivant;
            }

            i++;
        }
        else element=element->suivant;
    }
    printf("\n\tCette personne a un pere non enregistrer dans la base de donnees \n");
    printf("\n\tVeuillez l'ajouter dans notre base de donnees \n");
    return NULL;

}
