#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fichier.h"

data *creerdata(listelogin *tete){
	data *infos;
	char login[20],code[20],mail[30];
	infos=malloc(sizeof(data));
	printf("donner votre nom: ");
	scanf("%s",infos->nom);
	printf("donner votre prénom: ");
	scanf("%s",infos->prenom);
	printf("donner votre etablissement: ");
	scanf("%s",infos->etablissement);
	printf("donner votre pays: ");
	scanf("%s",infos->pays);
	do{
		printf("donner votre mail: ");
		scanf("%s",infos->mail);
		printf("veuillez confirmer votre mail: ");
		scanf("%s",mail);
		if (strcmp(infos->mail,mail)!=0){printf("Veuillez ressaisir votre mail correctement\n");}
	}while(strcmp(infos->mail,mail)!=0);
	int v=1;
	do{
		v=1;
		do{		
		printf("donner un Login (Il ne pourat plus être changer) : ");
		scanf("%s",infos->login);
		printf("veuillez confirmer votre Login : ");
		scanf("%s",login);
		if (strcmp(infos->login,login)!=0){printf("Veuillez ressaisir votre CIN correctement\n");}
		}while(strcmp(infos->login,login)!=0);
		v=rechercheloginexiste(tete,login);
		if(v==0) printf("Veuillez choisir un autre login, celui-ci existe déjà\n");
	}while(v==0);
	do{
		printf("donner un Code: ");
		scanf("%s",infos->code);
		printf("veuillez confirmer votre Code: ");
		scanf("%s",code);
		if (strcmp(infos->code,code)!=0){printf("Veuillez ressaisir votre Code correctement\n");}
	}while(strcmp(infos->code,code)!=0);
	tete=inserelogin(tete,login);
	do{
		printf("donner votre niveau: ");
		scanf("%d",&(infos->niveau));
		if(infos->niveau<1 || infos->niveau>3) printf("Votre niveau est obligatoirement compris entre 1 et 3\n");
	}while(infos->niveau<1 || infos->niveau>3);
	infos->nbrclasse_ens=0;
	infos->nbrclasse_etd=0;
	infos->nbrformation_ens=0;
	infos->nbrformation_etd=0;
	infos->nbrclasse_ens_total=0;
	infos->nbrclasse_etd_total=0;
	infos->nbrformation_ens_total=0;
	infos->nbrformation_etd_total=0;
	infos->classe_enseigner=NULL;
	infos->classe_accreditation_etudier=NULL;
	infos->formation_enseigner=NULL;
	infos->formation_accreditation_etudier=NULL;
return infos;
}
////////////////////////////////////////////////////////////////////
formateurs *insererformateur(formateurs *tete,listelogin **tetelogins){
	formateurs *frm=NULL;
	frm=malloc(sizeof(formateurs));
	frm->datas=creerdata(*tetelogins);
	frm->suivant=NULL;
	if (tete==NULL){tete=frm;}
	else{
		frm->suivant=tete;
		tete=frm;
	}
return tete;
}
/////////////////////////////////////////////////////////////////////
void afficher_1_formateur(formateurs *tete){
	if (tete!=NULL){
	printf("Le login est : %s\n",tete->datas->login);
	printf("Le nom est : %s\n",tete->datas->nom);
	printf("Le prénom est : %s \n",tete->datas->prenom);
	printf("Le mail est : %s\n",tete->datas->mail);
	printf("L'etablissement est : %s\n",tete->datas->etablissement);
	printf("Le pays est : %s\n",tete->datas->pays);
	printf("Le niveau est : %d\n",tete->datas->niveau);
	printf("Le nombre totale de classes que t'a crée est : %d\n",tete->datas->nbrclasse_ens_total);
	printf("Le nombre totale de classes que tu suit est : %d\n",tete->datas->nbrclasse_etd_total);
	printf("Le nombre de formations totale que tu suit est : %d\n",tete->datas->nbrformation_etd_total);
	if(tete->datas->niveau>1)
	printf("Le nombre de formations totale que t'a crée est : %d\n",tete->datas->nbrformation_ens_total);
	}
	else printf("La tete est vide\n");
	}

///////////////////////////////////////////////////////////////////////////
formateurs *recherchefrmcode(formateurs *tete,char *login,char *c){
	formateurs *baladeur=tete;
	while(baladeur!=NULL && strcmp(baladeur->datas->login,login)!=0 && strcmp(baladeur->datas->code,c)!=0){
		baladeur=baladeur->suivant;
		}
	if (baladeur==NULL)
	{printf("votre login/code n'est pas valide. \n");}
	
return baladeur;}
///////////////////////////////////////////////////////////////////////////
formateurs *recherchefrmmail(formateurs *tete,char *login,char *m){
	formateurs *baladeur=tete;
	while(baladeur!=NULL && strcmp(baladeur->datas->login,login)!=0 && strcmp(baladeur->datas->mail,m)!=0){
		baladeur=baladeur->suivant;
		}
	if (baladeur==NULL)
	{printf("votre login/mail n'existe pas dans la base de donné. \n");}
	
return baladeur;}
///////////////////////////////////////////////////////////////////////////
int changer_donnee_formateur(formateurs **tete){
	int choix=menu_changer_donner();
	switch (choix){
	case 2:{
		printf("donner votre nouveau nom :");
		scanf("%s",(*tete)->datas->nom);
		break;
		}
	case 3:{
		printf("donner votre nouveau prénom :");
		scanf("%s",(*tete)->datas->prenom);
		break;}
	case 4:{
		char mail[20];
		do{
			printf("donner votre mail: ");
			scanf("%s",(*tete)->datas->mail);
			printf("veuillez confirmer votre mail: ");
			scanf("%s",mail);
			if (strcmp((*tete)->datas->mail,mail)!=0){printf("Veuillez ressaisir votre mail\n");}
		}while(strcmp((*tete)->datas->mail,mail)!=0);
		break;}
	case 5:{
		printf("donner votre etablissement: ");
		scanf("%s",(*tete)->datas->etablissement);
		break;}
	case 6:{
		char code[20];
		do{
			printf("donner un Code: ");
			scanf("%s",(*tete)->datas->code);
			printf("veuillez confirmer votre Code: ");
			scanf("%s",code);
			if (strcmp((*tete)->datas->code,code)!=0){printf("Veuillez ressaisir votre Code\n");}
		}while(strcmp((*tete)->datas->code,code)!=0);
		break;}
	case 7:{
		printf("donner votre pays: ");
		scanf("%s",(*tete)->datas->pays);
		break;}
	}
return choix;}

