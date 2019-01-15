# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include"structures.h"

void menu_personne(Liste *liste)
{
  int choix,pop,search;

  Personne *p=malloc(sizeof(Personne));
  Element *element=malloc(sizeof(Element));
  liste=lire();
  do{

    printf("\n\t#################################################################################");
    printf("\n\t#   Bienvenue monsieur/madame!                                                  #");
    printf("\n\t#       Veuillez choisir une commande :                                         #");
    printf("\n\t#                                                                               #");
    printf("\n\t#    0 - pour sortir.                                                           #");
    printf("\n\t#    1 - pour ajouter une nouvelle personne.                                    #");
    printf("\n\t#    2 - pour modifier une personne.                                            #");
    printf("\n\t#    3 - pour supprimer une personne.                                           #");
    printf("\n\t#    4 - Afficher les personnes.                                                #");
    printf("\n\t#    5 - Retourner le nom de mere ou pere d une personne                        #");
    printf("\n\t#    6 - Chercher une personne.                                                 #");
    printf("\n\t#    7 - Retourner age d une personne.                                          #");
    printf("\n\t#    8 - Trier la liste des personnes.                                          #");
    printf("\n\t#    9 - Generer l acte d une personne .                                        #");
    printf("\n\t#                                                                               #");
    printf("\n\t#################################################################################\n");
    printf("\n\n\nVotre choix :");
    scanf("%d",&choix);
    system("cls");
    switch(choix){
      case 0 : {break;}
      case 1:{//ajouter des personnes
        system("cls");
      	ajouter(liste);
        enregistrer(liste);
        }break;
      case 2:{//modifier un personne
        system("cls");
      	modifier(liste);
        enregistrer(liste);
        }break;
      case 3:{ //supprimer un personne
        system("cls");
        printf("\n\t#############################################################################");
        printf("\n\t#                                                                           #");
        printf("\n\t#                   !! REMINDER !!                                          #");
        printf("\n\t#                   Etes-vous sur                                           #");
        printf("\n\t#                 d'effectuer cette                                         #");
        printf("\n\t#                    operation?                                             #");
        printf("\n\t#                                                                           #");
        printf("\n\t#                  1 - Confirmer                                            #");
        printf("\n\t#                  0 - Annuler                                              #");
        printf("\n\t#                                                                           #");
        printf("\n\t#############################################################################\n");
        printf("\n");
        scanf("%d",&pop);
        system("cls");
        if(pop==1){
                supprimer(liste);
          }
        enregistrer(liste);
        }break;
      case 4 :{//afficher des personnes
      	system("cls");
        consulter(liste);
        };break;
      case 5:{//chercher des parents
      	system("cls");
      	printf("\n\t#############################################################################");
        printf("\n\t#                                                                           #");
        printf("\n\t#             Voulez-vous chercher :                                        #");
        printf("\n\t#                                                                           #");
        printf("\n\t#               1 - le pere                                                 #");
        printf("\n\t#               2 - la mere                                                 #");
        printf("\n\t#                                                                           #");
        printf("\n\t#############################################################################\n");
      	scanf("%d",&search);
      	switch(search)
        {
          	case 1:
            {
                printf("Saisir l'identifiant de l'enfant : ");
                scanf("%d",&search);
                element=where_is_dad(liste, search);
            	break;
          	}
          	case 2:
          	{
                printf("Saisir l'identifiant de l'enfant : ");
                scanf("%d",&search);
            	element=where_is_mum(liste, search);
                break;
            }
        }
          p=&element->personne;
          if(p!=NULL)
          {
              printf("Le nom est : %s\n",p->pr_nom);
              printf("Le prenom est : %s\n",p->pr_prenom);
              printf("La date de naissance :\n");
              for (pop = 0; pop < 3; ++pop)
              {
                  switch(pop+1)
                  {
                      case 1:
                      {
                          printf("    Le jour : %d\n",element->personne.date_de_naissance[pop]);
                          break;
                      }
                      case 2:
                      {
                          printf("    Le mois : %d\n",element->personne.date_de_naissance[pop]);
                          break;
                      }
                      case 3:
                      {
                          printf("    L annee : %d\n",element->personne.date_de_naissance[pop]);
                          break;
                      }
                  }
              }
              printf("Le sexe est : %u\n",p->sexe);
              printf("Le CIN est : %s\n",p->CIN);
              printf("L identifiant est : %d\n",p->identifiant);
              printf("Le nombre d'enfants est : %d\n",p->nbr_d_enfant);
              for (pop = 0; pop < p->nbr_d_enfant; pop++)
              {
                  printf("   l'ide de l'enfant %d est : %d \n",pop+1,p->enfant_ide[pop]);
              }

          }
          else
              printf("Pas de parents");
          break;}
      case 6://Chercher une personne.
        {
          system("cls");
          printf("\n\t#############################################################################");
          printf("\n\t#                                                                           #");
          printf("\n\t#             voulez-vous recherche par:                                    #");
          printf("\n\t#                                                                           #");
          printf("\n\t#                 0 - Annuler                                               #");
          printf("\n\t#                 1 - identifiant                                           #");
          printf("\n\t#                 2 - nom                                                   #");
          printf("\n\t#                 3 - prenom                                                #");
          printf("\n\t#                 4 - CIN                                                   #");
          printf("\n\t#                                                                           #");
          printf("\n\t#############################################################################\n");
          scanf("%d",&pop);
          switch(pop)
          {
            case 1:
            {
              chercher_par_ide(liste);
              break;
            }
            case 4:
            {
              chercher_par_CIN(liste);
              break;
            }
            case 2:{
              chercher_par_nom(liste);
              break;
            }
            case 3:{
          		chercher_par_prenom(liste);
          		break;
          	}
          	case 0:{break;}
          }
        break;
        }
      case 7://Retourner l’age d’une personne
      {
      	system("cls");
      	   element=chercher_par_ide(liste);
        if (element==NULL)
        {
        	printf("\tLa personne n existe pas\n");
        }
        else
        {age(element->personne);}
        break;
      }
      case 8://Trier la liste des personnes
      {
      	system("cls");
      	int choice;
        printf("\n\t#############################################################################");
        printf("\n\t#                                                                           #");
        printf("\n\t#      voulez-vous Trier la liste selon:                                    #");
        printf("\n\t#                                                                           #");
        printf("\n\t#               1 - identifiant                                             #");
        printf("\n\t#               2 - nom                                                     #");
        printf("\n\t#               0 - Annuler                                                 #");
        printf("\n\t#                                                                           #");
        printf("\n\t#############################################################################\n");
        printf("\n\tVotre choix : ");
        scanf("%d",&choice);
        switch(choice)
        {
        	case 0:break;
        	case 1:{
        		trie_ide(liste);
                consulter(liste);
                liste=lire();
        		break;
        	}
        	case 2:{
        		trie_nom(liste);
                consulter(liste);
                liste=lire();
        		break;
        	}
        }
        	break;
        }
      case 9://Imprimer données
        {
        	system("cls");
        	element = chercher_par_ide(liste);
          acte_generator(element,liste);
        	break;
        }
    }

  }while(choix!=0);
}
void menu_enfants(Liste *liste)
{
	int choix,ide;
    liste=lire();
  	Element *element=malloc(sizeof(Element));
  	do
  	{
      	printf("\n\t#############################################################################");
        printf("\n\t#                                                                           #");
        printf("\n\t#             Que voulez-vous ?                                             #");
        printf("\n\t#                                                                           #");
        printf("\n\t#     1 - Afficher les informations sur les enfants d une personne          #");
        printf("\n\t#     2 - Ajouter les enfants d une personne                                #");
        printf("\n\t#     0 - Sortir                                                            #");
        printf("\n\t#                                                                           #");
        printf("\n\t#############################################################################\n");
        printf("\nvotre choix :");
        scanf("%d",&choix);
        switch(choix)
        {
        	case 0:
        	{
        		enregistrer(liste);
        		break;
        	}
        	case 1:
        	{
                printf("\n\tDonner l'identifiant du parent :");
                scanf("%d",&ide);
        		afficher_enfants(ide,liste);
        		break;
        	}
        	case 2:
        	{
        		element=chercher_par_ide(liste);
                if (element==NULL)
                {
                    printf("la personne n'existe pas !!\n");
                }
                else
        		{modifier_enfants(&(element->personne));}
        		break;
        	}
        }
  	} while (choix!=0);
}

void menu(Liste *liste)
{
    int choix;
    do
    {
        printf("\n\t#############################################################################");
        printf("\n\t#                                                                           #");
        printf("\n\t#          Veuillez choisir l'une des deux commandes :                      #");
        printf("\n\t#                                                                           #");
        printf("\n\t#               1 - Gestion des Personnes.                                  #");
        printf("\n\t#               2 - Gestion des enfants d'une personne.                     #");
        printf("\n\t#               0 - Sortir.                                                 #            ");
        printf("\n\t#                                                                           #");
        printf("\n\t#############################################################################\n");
		printf("Donner votre choix :");
        scanf("%d",&choix);
        switch(choix)
        {
            case 0 :
            {
                break;
            }
            case 2 :
            {
                menu_enfants(liste);
                break;
            }
            case 1 :
            {
                menu_personne(liste);
                break;
            }
        }
    } while (choix!=0);
}
