#include<stdio.h>
#include<stdlib.h>
#include"fichier.h"

int menu_princ(){
	int choix=0;
	do{
	printf("\t\t\t\t ______________________MENU Principal_______________________\n");
	printf("\t\t\t\t|                                                           |\n");
	printf("\t\t\t\t|1- Si vous êtes formateur                                  |\n");
	printf("\t\t\t\t|2- Si vous êtes candidat                                   |\n");
	printf("\t\t\t\t|3- Si vous êtes administrateur                             |\n");
	printf("\t\t\t\t|0- Pour quitter                                            |\n");
	printf("\t\t\t\t|___________________________________________________________|\n");
	printf("\n\tchoisissez une valeur: "); 
	scanf("%d",&choix);
	}while(choix<1 && choix>4);
return choix;
}
////////////////////////////////////////////////////////////////////////////
int menu_formateur1(){
	int choix=0;
	do{
	printf("\t\t\t\t ______________________MENU Formateur_______________________\n");
	printf("\t\t\t\t|                                                           |\n");
	printf("\t\t\t\t|1- Si vous êtes déjà inscrit                               |\n");
	printf("\t\t\t\t|2- Si vous êtes nouveau                                    |\n");
	printf("\t\t\t\t|3- Pour retourner au menu précédent                        |\n");
	printf("\t\t\t\t|0- Pour quitter                                            |\n");
	printf("\t\t\t\t|___________________________________________________________|\n");
	printf("\n\tchoisissez une valeur: ");
	scanf("%d",&choix);
	}while(choix<0 && choix>3);
return choix;
}
////////////////////////////////////////////////////////////////////////////
int menu_formateur_niveau1(){
	int choix=0;
	do{
	printf("\t\t\t\t _________________MENU Formateur de niveau 1_________________\n");
	printf("\t\t\t\t|                                                            |\n");
	printf("\t\t\t\t|2-  Pour creer une classe                                   |\n");
	printf("\t\t\t\t|3-  Pour supprimer une classe                               |\n");
	printf("\t\t\t\t|4-  Pour s'inscrire dans une classe                         |\n");
	printf("\t\t\t\t|5-  Pour se désinscrire d'une classe                        |\n");
	printf("\t\t\t\t|6-  Pour suivre une formation                               |\n");
	printf("\t\t\t\t|7-  Pour se désinscrire d'une formation                     |\n");
	printf("\t\t\t\t|8-  Pour passer au niveau 2                                 |\n");
	printf("\t\t\t\t|9-  Pour Afficher vos données                               |\n");
	printf("\t\t\t\t|10- Pour vous voulez changer vos données                    |\n");
	printf("\t\t\t\t|1-  Pour se déconnecter                                     |\n");
	printf("\t\t\t\t|0-  Pour quitter                                            |\n");
	printf("\t\t\t\t|____________________________________________________________|\n");
	printf("\n\tchoisissez une valeur: ");
	scanf("%d",&choix);
	}while(choix<0 && choix>10);
return choix;
}
////////////////////////////////////////////////////////////////////////////
int menu_formateur_niveau2(){
	int choix=0;
	do{
	printf("\t\t\t\t _________________MENU Formateur de niveau 2_________________\n");
	printf("\t\t\t\t|                                                            |\n");
	printf("\t\t\t\t|2-  Pour creer une classe                                   |\n");
	printf("\t\t\t\t|3-  Pour supprimer une classe                               |\n");
	printf("\t\t\t\t|4-  Pour s'inscrire dans une classe                         |\n");
	printf("\t\t\t\t|5-  Pour se désinscrire d'une classe                        |\n");
	printf("\t\t\t\t|6-  Pour suivre une formation                               |\n");
	printf("\t\t\t\t|7-  Pour se désinscrire d'une formation                     |\n");
	printf("\t\t\t\t|8-  Pour creer une formation                                |\n");
	printf("\t\t\t\t|9-  Pour supprimer une formation                            |\n");
	printf("\t\t\t\t|10- Pour passer au niveau 3                                 |\n");
	printf("\t\t\t\t|11- Pour Afficher vos données                               |\n");
	printf("\t\t\t\t|12- Pour changer vos données                                |\n");
	printf("\t\t\t\t|1-  Pour se déconnecter                                     |\n");
	printf("\t\t\t\t|0-  Pour quitter                                            |\n");
	printf("\t\t\t\t|____________________________________________________________|\n");
	printf("\n\tchoisissez une valeur: ");
	scanf("%d",&choix);
	}while(choix<0 && choix>12);
return choix;
}
////////////////////////////////////////////////////////////////////////////
int menu_formateur_niveau3(){
	int choix=0;
	do{
	printf("\t\t\t\t _________________MENU Formateur de niveau 3_________________\n");
	printf("\t\t\t\t|                                                            |\n");
	printf("\t\t\t\t|2-  Pour creer une classe                                   |\n");
	printf("\t\t\t\t|3-  Pour supprimer une classe                               |\n");
	printf("\t\t\t\t|4-  Pour s'inscrire dans une classe                         |\n");
	printf("\t\t\t\t|5-  Pour se désinscrire d'une classe                        |\n");
	printf("\t\t\t\t|6-  Pour suivre une formation                               |\n");
	printf("\t\t\t\t|7-  Pour se désinscrire d'une formation                     |\n");
	printf("\t\t\t\t|8-  Pour donner une formation                               |\n");
	printf("\t\t\t\t|9-  Pour supprimer une formation                            |\n");
	//printf("\t\t\t\t|10- Pour organiser une conférence                           |\n");
	printf("\t\t\t\t|10- Pour Afficher vos données                               |\n");
	printf("\t\t\t\t|11- Pour vous voulez changer vos données                    |\n");
	printf("\t\t\t\t|1-  Pour se déconnecter                                     |\n");
	printf("\t\t\t\t|0-  Pour quitter                                            |\n");
	printf("\t\t\t\t|____________________________________________________________|\n");
	printf("\n\tchoisissez une valeur: ");
	scanf("%d",&choix);
	}while(choix<0 && choix>11);
return choix;
}
////////////////////////////////////////////////////////////////////////////
int menu_changer_donner(){
	int choix=0;
	do{
	printf("\t\t\t\t _Sous MENU Formateur : Modification des données personnels_\n");
	printf("\t\t\t\t|                                                           |\n");
	printf("\t\t\t\t|2- Pour changer le nom                                     |\n");
	printf("\t\t\t\t|3- Pour changer le prénom                                  |\n");
	printf("\t\t\t\t|4- Pour changer le mail                                    |\n");
	printf("\t\t\t\t|5- Pour changer l'etablissement                            |\n");
	printf("\t\t\t\t|6- Pour changer le code                                    |\n");
	printf("\t\t\t\t|7- Pour changer le pays                                    |\n");
	printf("\t\t\t\t|1- Pour retourner au menu précedent                        |\n");
	printf("\t\t\t\t|0- Pour quitter                                            |\n");
	printf("\t\t\t\t|___________________________________________________________|\n");
	printf("\n\tchoisissez une valeur: ");
	scanf("%d",&choix);
	}while(choix<0 && choix>7);
return choix;
}
////////////////////////////////////////////////////////////////////////////
int menu_administrateur(){
	int choix=0;
	do{
	printf("\t\t\t\t _____________________MENU Administrateur____________________\n");
	printf("\t\t\t\t|                                                            |\n");
	printf("\t\t\t\t|2-  Pour afficher tous les formateurs                       |\n");
	printf("\t\t\t\t|3-  Pour afficher tous les formateurs de niveau 1           |\n");
	printf("\t\t\t\t|4-  Pour afficher tous les formateurs de niveau 2           |\n");
	printf("\t\t\t\t|5-  Pour afficher tous les formateurs de niveau 3           |\n");
	printf("\t\t\t\t|6-  Pour rechercher un formateur par son login              |\n");
	printf("\t\t\t\t|7-  Pour afficher tous les formations d'accréditation       |\n");
	printf("\t\t\t\t|8-  Pour afficher tous les formations Normal                |\n");
	printf("\t\t\t\t|9-  Pour supprimer un formateur                             |\n");
	printf("\t\t\t\t|10- Pour supprimer une formation                            |\n");
	printf("\t\t\t\t|11- Pour ajouter un autre administrateur                    |\n");
	printf("\t\t\t\t|1-  Pour se déconnecter                                     |\n");
	printf("\t\t\t\t|0-  Pour quitter le programme                               |\n");
	printf("\t\t\t\t|____________________________________________________________|\n");
	printf("\n\tchoisissez une valeur: ");
	scanf("%d",&choix);
	if (choix<0 && choix>11) printf("Erreur");
	}while(choix<0 && choix>11);
return choix;
}
/////////////////////////////////////////////////////////////////////////////
int menu_candidat1(){
	int choix=0;
	do{
	printf("\t\t\t\t ______________________MENU Candidat_______________________\n");
	printf("\t\t\t\t|                                                           |\n");
	printf("\t\t\t\t|1- Si vous êtes déjà inscrit                               |\n");
	printf("\t\t\t\t|2- Si vous êtes nouveau                                    |\n");
	printf("\t\t\t\t|3- Pour retourner au menu précédent                        |\n");
	printf("\t\t\t\t|0- Pour quitter                                            |\n");
	printf("\t\t\t\t|___________________________________________________________|\n");
	printf("\n\tchoisissez une valeur: ");
	scanf("%d",&choix);
	}while(choix<0 && choix>3);
return choix;
}

/////////////////////////////////////////////////////////////////////////////
int menu_candidat(){
	int choix=0;
	do{
	printf("\t\t\t\t _______________________MENU candidat_______________________\n");
	printf("\t\t\t\t|                                                           |\n");
	printf("\t\t\t\t|2- Pour s'inscrire dans une classe                         |\n");
	printf("\t\t\t\t|3- Pour se désinscrire d'une classe                        |\n");
	printf("\t\t\t\t|4- Pour suivre une formation                               |\n");
	printf("\t\t\t\t|5- Pour se désinscrire d'une formation                     |\n");
	printf("\t\t\t\t|6- Pour Afficher vos données                               |\n");
	printf("\t\t\t\t|7- Pour vous voulez changer vos données                    |\n");
	printf("\t\t\t\t|1- Pour retourner au menu précédent                        |\n");
	printf("\t\t\t\t|0- Pour quitter                                            |\n");
	printf("\t\t\t\t|___________________________________________________________|\n");
	printf("\n\tchoisissez une valeur: ");
	scanf("%d",&choix);
	}while(choix<0 && choix>7);
return choix;
}
////////////////////////////////////////////////////////////////////////////////////////
int menu_changer_donner_cdd(){
	int choix=0;
	do{
	printf("\t\t\t\t __Sous MENU Candidat: Modification des données personnels__\n");
	printf("\t\t\t\t|                                                           |\n");
	printf("\t\t\t\t|2- Pour changer le nom                                     |\n");
	printf("\t\t\t\t|3- Pour changer le prénom                                  |\n");
	printf("\t\t\t\t|4- Pour changer le mail                                    |\n");
	printf("\t\t\t\t|5- Pour changer le code                                    |\n");
	printf("\t\t\t\t|1- Pour retourner au menu précedent                        |\n");
	printf("\t\t\t\t|0- Pour quitter                                            |\n");
	printf("\t\t\t\t|___________________________________________________________|\n");
	printf("\n\tchoisissez une valeur: ");
	scanf("%d",&choix);
	}while(choix<0 && choix>5);
return choix;
}
