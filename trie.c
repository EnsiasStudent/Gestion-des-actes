# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include"utility.h"
# include "structures.h"

void trie_ide(Liste *liste)
{
    Element *ptr=malloc(sizeof(Element));
    int i ,j=1;

    ptr=liste->premier;
    while(ptr != NULL && j==1)
    {
        j=0;
        while( ptr->suivant!=NULL)
        {
            if(ptr->personne.identifiant >  ptr->suivant->personne.identifiant)
            {
                char_permute(ptr->personne.pr_nom,ptr->suivant->personne.pr_nom);
                char_permute(ptr->personne.pr_prenom,ptr->suivant->personne.pr_prenom);
                char_permute(ptr->personne.CIN,ptr->suivant->personne.CIN);
                int_permute(&ptr->personne.identifiant,&ptr->suivant->personne.identifiant);
                int_permute(&ptr->personne.nbr_d_enfant,&ptr->suivant->personne.nbr_d_enfant);
                int_permute(&ptr->personne.sexe,&ptr->suivant->personne.sexe);
                int_permute(&ptr->personne.date_de_naissance[1],&ptr->suivant->personne.date_de_naissance[1]);
                int_permute(&ptr->personne.date_de_naissance[2],&ptr->suivant->personne.date_de_naissance[2]);
                int_permute(&ptr->personne.date_de_naissance[0],&ptr->suivant->personne.date_de_naissance[0]);
                for(i=0;i<10;i++)
                {
                   int_permute(&ptr->personne.enfant_ide[i],&ptr->suivant->personne.enfant_ide[i]);
                }
                j=1;
            }
            ptr = ptr->suivant;
        }
        ptr = liste->premier;
    }
}

void trie_nom(Liste *liste)
{

    Element *ptr=malloc(sizeof(Element));
    int i,j=1;
    ptr=liste->premier;

    while(ptr != NULL&&j==1)
    {
        j=0;

        while(ptr->suivant!=NULL)
        {
            if(strcmp(ptr->personne.pr_nom,ptr->suivant->personne.pr_nom)>0)
            {
                char_permute(ptr->personne.pr_nom,ptr->suivant->personne.pr_nom);
                char_permute(ptr->personne.pr_prenom,ptr->suivant->personne.pr_prenom);
                char_permute(ptr->personne.CIN,ptr->suivant->personne.CIN);
                int_permute(&ptr->personne.identifiant,&ptr->suivant->personne.identifiant);
                int_permute(&ptr->personne.nbr_d_enfant,&ptr->suivant->personne.nbr_d_enfant);
                int_permute(&ptr->personne.sexe,&ptr->suivant->personne.sexe);
                int_permute(&ptr->personne.date_de_naissance[1],&ptr->suivant->personne.date_de_naissance[1]);
                int_permute(&ptr->personne.date_de_naissance[2],&ptr->suivant->personne.date_de_naissance[2]);
                int_permute(&ptr->personne.date_de_naissance[0],&ptr->suivant->personne.date_de_naissance[0]);
                for(i=0;i<10;i++)
                {
                    int_permute(&ptr->personne.enfant_ide[i],&ptr->suivant->personne.enfant_ide[i]);
                }
                j=1;

            }
            else if(strcmp(ptr->personne.pr_nom,ptr->suivant->personne.pr_nom)==0)
                 {  if(strcmp(ptr->personne.pr_prenom,ptr->suivant->personne.pr_prenom)>0){
                    char_permute(ptr->personne.pr_nom,ptr->suivant->personne.pr_nom);
                    char_permute(ptr->personne.pr_prenom,ptr->suivant->personne.pr_prenom);
                    char_permute(ptr->personne.CIN,ptr->suivant->personne.CIN);
                    int_permute(&ptr->personne.identifiant,&ptr->suivant->personne.identifiant);
                    int_permute(&ptr->personne.nbr_d_enfant,&ptr->suivant->personne.nbr_d_enfant);
                    int_permute(&ptr->personne.sexe,&ptr->suivant->personne.sexe);
                    int_permute(&ptr->personne.date_de_naissance[1],&ptr->suivant->personne.date_de_naissance[1]);
                    int_permute(&ptr->personne.date_de_naissance[2],&ptr->suivant->personne.date_de_naissance[2]);
                    int_permute(&ptr->personne.date_de_naissance[0],&ptr->suivant->personne.date_de_naissance[0]);
                    for(i=0;i<10;i++)
                    {
                    int_permute(&ptr->personne.enfant_ide[i],&ptr->suivant->personne.enfant_ide[i]);
                    }
                    j=1;
                    }
            }
            ptr = ptr->suivant;
        }
        ptr = liste->premier;
    }


}
