#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int login(){

	char c;
	int i;
	char* mdp=(char*)malloc(sizeof(char));
	char* log_in=(char*)malloc(sizeof(char));
	while(mdp!=NULL&&log_in!=NULL){
		*(log_in+0)='M';
		*(log_in+1)='a';
		*(log_in+2)='s';
		*(log_in+3)='t';
		*(log_in+4)='e';
		*(log_in+5)='r';
		do{
			printf("\n\tVeuillez saisir votre mot de passe :\n");
			printf("\t\t");
			for(i=0;i<6;i++){
			c = getch();
			printf("*");
			*(mdp+i)=c;

		  	}
		   }while(strncmp(mdp,log_in,6)!=0);    // cette fonction est une restriction de la fonction strcmp qui permet de faire la comparaison entre deux pointeurs de char sur une taille d??donn? //
    printf("\n\tConnexion to The Data-Base succeded !\n");
    return 1;
    }

}
