# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include "structures.h"
													
void modifier(Liste *liste)
{
	int ide,test,i,nv_nbr;
	char nv_info[CMAX];
	printf("Entrer l identifient de la personne a modifier :\n");
	scanf("%d",&ide);
    Element *element=malloc(sizeof(Element));
    element=liste->premier;
	while( element!=NULL && element->personne.identifiant!=ide )
	{
		element=element->suivant;
	}
	if (element==NULL || ide!=element->personne.identifiant)
	{
		printf("L element a modifier n existe pas\n");
	}
	else
	{
		printf("L element a modifier existe (pour afficher ses info taper 1) :\n");
        scanf("%d",&test);
		if (test==1)
		{
			printf("Le nom est : %s\n",element->personne.pr_nom);
			printf("Le prenom est : %s\n",element->personne.pr_prenom);
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
			if (element->personne.sexe==0)
			{
				printf("Homme\n");
			}
			else{printf("Femme\n");}
			printf("Le CIN est : %s\n",element->personne.CIN);
			printf("L identifiant est : %d\n",element->personne.identifiant);
			printf("Le nombre d enfants est : %d\n",element->personne.nbr_d_enfant);
			if(element->personne.nbr_d_enfant!=0)
			{
				printf("Les identifiants des enfant sont :\n");
			}
			for (i = 0; i < element->personne.nbr_d_enfant; ++i)
			{
				printf("   L ide de l enfant %d est : %d \n",(i+1),element->personne.enfant_ide[i]);
			}
		}
		test=0;
		printf("Vous voulez modifier :\n(1)Nom\n(2)Prenom\n(3)Date de naissance\n(4)Le sexe\n(5)CIN\n(6)Le nombre d enfant\n");
        scanf("%d",&test);
		switch(test)
		{
			case 1:
			{
				printf("Entrer le nouveau nom :\n");
				scanf("%s",nv_info);
				strcpy(element->personne.pr_nom,nv_info);
				break;
			}
			case 2:
			{
				printf("Entrer le nouveau prenom :\n");
				scanf("%s",nv_info);
				strcpy(element->personne.pr_prenom,nv_info);
				break;
			}
			case 3:
			{
				printf("Entrer la nouvelle date de naissance\n");
				for (i = 0; i < 3; i++)
				{
					switch(i+1)
					{
						case 1:
						{
							printf("    Le jour :\n\t");
							break;
						}
						case 2:
						{
							printf("    Le mois :\n\t");
							break;
						}
						case 3:
						{
							printf("    L annee :\n\t");
							break;
						}
					}
					scanf("%d",&element->personne.date_de_naissance[i]);
				}
				break;
			}
			case 4:
			{
				unsigned int nv_sexe;
				printf("Entrer le nouveau sexe :\n");
				scanf("%d",&nv_sexe);
				element->personne.sexe=nv_sexe;
				break;
			}
			case 5:
			{
				printf("Entrer le nouveau CIN :\n");
				scanf("%s",nv_info);
				strcpy(element->personne.CIN,nv_info);
				break;
			}
			case 6:
			{
				printf("Entrer le nouveau nombre d enfant :\n");
				scanf("%d",&nv_nbr);
				element->personne.nbr_d_enfant=nv_nbr;
			    element->personne.enfant_ide[nv_nbr-1]=liste->premier->personne.identifiant+1;
				break;
			}
		}
	}
	test=0;
	printf("Modifier une autre personne ? (Veuillez appuyez sur 1):\n");
    scanf("%d",&test);
	if (test==1)
	{
		modifier(liste);
	}

}

void modifier_enfants(Personne *personne)
{
	int nv_nbr;
	printf("Entrer l identifiant de l enfant que tu veux ajouter :\n");
	scanf("%d",&nv_nbr);
    personne->enfant_ide[personne->nbr_d_enfant]=nv_nbr;
    personne->nbr_d_enfant+=1;

}
