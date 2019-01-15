#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

#define CMAX 15
#define nbrMAX 10

typedef struct Personne
{
    char pr_nom[CMAX];
    char pr_prenom[CMAX];
    int sexe;
    int date_de_naissance[3];
    char CIN[CMAX];
    int identifiant;
    int nbr_d_enfant;
    
    int enfant_ide[nbrMAX];

}Personne;

typedef struct Element Element;
struct Element
{
    Personne personne;
    Element *suivant;
};

typedef struct Liste
{
    Element *premier;
}Liste;


//GENERER ACTE //
int index_acte();
void acte_generator(Element *element,Liste *liste);

// opérations sur fichier //
void enregistrer(Liste *liste);
void modifier_enfants(Personne *personne);
void modifier(Liste *liste);
Liste* lire();
void Ecrire(Liste *liste);

// Afficher et ajouter une certaine personne //
void consulter(Liste *liste);
void afficher_enfants(int ide,Liste *liste);
void ajouter(Liste *liste);
int  gender_confirmed(Liste *liste,int ide,int sexe);

// Chercher une personne /enfants //
Element* chercher_par_ide(Liste *liste);
Element* chercher_par_CIN(Liste *liste);
Element* chercher_par_nom(Liste *liste);
Element* chercher_par_prenom(Liste *liste);
Element* where_is_mum(Liste *liste,int ide);
Element* where_is_dad(Liste *liste,int ide);
Element* where_are_my_kids(Liste *liste,int ide,int test);

// Fonction age //
void age(Personne p);

//Supprimer  //
void supprimer(Liste *liste);

// TRIE //
void trie_ide(Liste *liste);
void trie_nom(Liste *liste);

//MENU //
void menu(Liste *liste);
void menu_personne(Liste *liste);
void menu_enfants(Liste *liste);

// UTILITY
void char_permute(char a[],char b[]);
void int_permute(int *a, int *b);


#endif // STRUCTURES_H_INCLUDED
