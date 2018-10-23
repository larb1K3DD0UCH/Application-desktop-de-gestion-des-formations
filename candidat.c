#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fichier.h"

datacandidat *creerdata_candidat(){
	datacandidat *infos;
	char login[20],code[20],mail[30];
	infos=malloc(sizeof(datacandidat));
	printf("donner votre nom: ");
	scanf("%s",infos->nom);
	printf("donner votre prénom: ");
	scanf("%s",infos->prenom);
	do{
		printf("donner votre mail: ");
		scanf("%s",infos->mail);
		printf("veuillez confirmer votre mail: ");
		scanf("%s",mail);
		if (strcmp(infos->mail,mail)!=0){printf("Veuillez ressaisir votre mail correctement\n");}
	}while(strcmp(infos->mail,mail)!=0);
	do{
		printf("donner un Login (Il ne pourat plus être changer) : ");
		scanf("%s",infos->login);
		printf("veuillez confirmer votre Login : ");
		scanf("%s",login);
		if (strcmp(infos->login,login)!=0){printf("Veuillez ressaisir votre CIN correctement\n");}
	}while(strcmp(infos->login,login)!=0);
	do{
		printf("donner un Code: ");
		scanf("%s",infos->code);
		printf("veuillez confirmer votre Code: ");
		scanf("%s",code);
		if (strcmp(infos->code,code)!=0){printf("Veuillez ressaisir votre Code correctement\n");}
	}while(strcmp(infos->code,code)!=0);
	infos->nbrclasse_suivi=0;
	infos->nbrformation_suivi=0;
	infos->classe_Normal_etudier=NULL;
	infos->formation_Normal_etudier=NULL;
return infos;
}
////////////////////////////////////////////////////////////////////
candidat *inserercandidat(candidat *tete){
	candidat *cdd=NULL;
	cdd=malloc(sizeof(candidat));
	cdd->datas=creerdata_candidat();
	cdd->suivant=NULL;
	if (tete==NULL){tete=cdd;}
	else{
		cdd->suivant=tete;
		tete=cdd;
	}
return tete;
}
///////////////////////////////////////////////////////////////////////////
candidat *recherchecandidatcode(candidat *tete,char *login,char *c){
	candidat *baladeur=tete;
	while(baladeur!=NULL && strcmp(baladeur->datas->login,login)!=0 && strcmp(baladeur->datas->code,c)!=0){
		baladeur=baladeur->suivant;
		}
	if (baladeur==NULL)
	{printf("votre login/code n'est pas valide. \n");}
	
return baladeur;}
///////////////////////////////////////////////////////////////////////////
candidat *recherchecandidatmail(candidat *tete,char *login,char *m){
	candidat *baladeur=tete;
	while(baladeur!=NULL && strcmp(baladeur->datas->login,login)!=0 && strcmp(baladeur->datas->mail,m)!=0){
		baladeur=baladeur->suivant;
		}
	if (baladeur==NULL)
	{printf("votre login/mail n'existe pas dans la base de donné. \n");}
	
return baladeur;}
////////////////////////////////////////////////////////////////////////////
int changer_donnee_candidat(candidat **tete){
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
			if (strcmp((*tete)->datas->mail,mail)!=0){
				printf("Veuillez ressaisir votre mail\n");}
		}while(strcmp((*tete)->datas->mail,mail)!=0);
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
	}
return choix;}
////////////////////////////////////////////////////////////////////////////////////////
void afficher_1_candidat(candidat *tete){
	if (tete!=NULL){
	printf("Le login est : %s\n",tete->datas->login);
	printf("Le nom est : %s\n",tete->datas->nom);
	printf("Le prénom est : %s \n",tete->datas->prenom);
	printf("Le mail est : %s\n",tete->datas->mail);
	if(tete->datas->classe_Normal_etudier!=NULL){
		printf("Tu suit %d classes,dont les id sont:\n",tete->datas->nbrclasse_suivi);
		classeNormal *baladeur=tete->datas->classe_Normal_etudier;
		while(baladeur!=NULL){
			printf("%s",baladeur->idclasse);
			baladeur=baladeur->suivant;}
	}
	if(tete->datas->formation_Normal_etudier!=NULL){
		printf("Tu suit %d formations,dont les id sont:\n",tete->datas->nbrformation_suivi);
		formationNormal *baladeur2=tete->datas->formation_Normal_etudier;
		while(baladeur2!=NULL){
			printf("%s",baladeur2->idformation);
			baladeur2=baladeur2->suivant;}
	}
	}}

//////////////////////////////////////////////////////////////////////////////////////
int afficher_classe_disponible_candidat(listeclasse *tete,candidat *cdd){
	int n=0;
	if (tete==NULL){printf("Il n'y a aucune classe disponible pour le moment\n");}
	else{n=1;
	int v=1;
	classeNormal *classe_Normal_etudier=NULL;
	printf("Veuillez choisir entre ces classes qui vous sont disponible\n\n");
	listeclasse *baladeur=tete;
	while(baladeur!=NULL){
		if (baladeur->datas->nbreleve<30 && strcmp(baladeur->datas->typeclasse,"Normal")==0 && strcmp(baladeur->datas->login,cdd->datas->login)!=0){
		classe_Normal_etudier=cdd->datas->classe_Normal_etudier;
		v=1;
		while(classe_Normal_etudier!=NULL && v==1){
 			if(strcmp(cdd->datas->classe_Normal_etudier->idclasse,baladeur->datas->idclasse)==0){
				v=0;
			}
			classe_Normal_etudier=classe_Normal_etudier->suivant;}
		if(v==1){
		printf("nom de classe: %s || Login de Formateur: %s || L'id de la classe est: %s\n",baladeur->datas->nomclasse,baladeur->datas->login,baladeur->datas->idclasse);
		printf("\n");}}
		baladeur=baladeur->suivant;
		}
	}
return n;
}
////////////////////////////////////////////////////////////////////////////////////////
listeclasse *desinscrire_classe_candidat(listeclasse *tete,candidat **cdd){
	listeclasse *baladeur=tete;
	char idclasse[30];
	printf("Donner l'id de classe dont vous voulez désinscrire: ");
	scanf("%s",idclasse);
	while(baladeur!=NULL && ( strcmp(baladeur->datas->typeclasse,"Normal")!=0 || strcmp(baladeur->datas->idclasse,idclasse)!=0 )){
			baladeur=baladeur->suivant;}
	if (baladeur==NULL){printf("Erreur de saisis: Aucune formation n'a ces données\n");}
	else{
		baladeur->datas->nbreleve--;
		(*cdd)->datas->nbrclasse_suivi--;
		classeNormal *baladeur2=(*cdd)->datas->classe_Normal_etudier;
		classeNormal *prec2=(*cdd)->datas->classe_Normal_etudier;
		while(baladeur2==NULL && strcmp(baladeur2->idclasse,idclasse)!=0){
			prec2=baladeur2;
			baladeur2=baladeur2->suivant;}
		prec2->suivant=baladeur2->suivant;
		printf("Votre désinscription a été faite avec succée.\n");}
return tete;
}
/////////////////////////////////////////////////////////////////////////////////////////
formations *desinscrire_formation_candidat(formations *tete,candidat **cdd){
	formations *baladeur=tete;
	char idformation[30];
	printf("Donner l'id de formation dont vous voulez désinscrire: ");
	scanf("%s",idformation);
	while(baladeur!=NULL && ( strcmp(baladeur->datas->typeformation,"Normal")!=0 || strcmp(baladeur->datas->idformation,idformation)!=0 )){
			baladeur=baladeur->suivant;}
	if (baladeur==NULL){printf("Erreur de saisis: Aucune formation n'a ces données\n");}
	else{
		baladeur->datas->nbrformateur--;
		(*cdd)->datas->nbrformation_suivi--;
		formationNormal *baladeur2=(*cdd)->datas->formation_Normal_etudier;
		formationNormal *prec2=(*cdd)->datas->formation_Normal_etudier;
		while(baladeur2==NULL && strcmp(baladeur2->idformation,idformation)!=0){
			prec2=baladeur2;
			baladeur2=baladeur2->suivant;}
		prec2->suivant=baladeur2->suivant;
		printf("Votre désinscription a été faite avec succée.\n");}
return tete;
}
////////////////////////////////////////////////////////////////////////////////////
int afficher_formation_disponible_candidat(formations *tete,candidat *cdd){
	int n=0;									//n=0 si tete est null, 1 sinon
	if (tete==NULL){printf("Il n'y a aucun Formation disponible pour le moment\n");}
	else{n=1;
	int v=1;
	formationNormal *formation_Normal_etudier=NULL;
	printf("Veuillez choisir entre ces formations qui vous sont disponible: \n\n");
	formations *baladeur=tete;
	while(baladeur!=NULL){
		if (baladeur->datas->nbrformateur<20 && strcmp(baladeur->datas->typeformation,"Normal")==0){
		formation_Normal_etudier=cdd->datas->formation_Normal_etudier;
		v=1;
		while(formation_Normal_etudier!=NULL && v==1){
 			if(strcmp(cdd->datas->formation_Normal_etudier->idformation,baladeur->datas->idformation)==0){
				v=0;
			}
			formation_Normal_etudier=formation_Normal_etudier->suivant;}
		if(v==1){
		printf("nom de formation: %s || Login de Formateur: %s || L'id de la formation est: %s\n",baladeur->datas->nomformation,baladeur->datas->login,baladeur->datas->idformation);
		printf("\n");}}
		baladeur=baladeur->suivant;
		}
	}
return n;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
formations *suivre_formation_candidat(formations *tete,candidat **cdd,char *idformation){
	formations *baladeur=tete;
	while(baladeur!=NULL && ( strcmp(baladeur->datas->typeformation,"Normal")!=0 || strcmp(baladeur->datas->idformation,idformation)!=0)){
			baladeur=baladeur->suivant;}
	if (baladeur==NULL){printf("Erreur de saisis: cette formation n'est disponible");}
	else{
	if (baladeur->datas->nbrformateur<20){
			baladeur->datas->nbrformateur++;
			formationNormal *donneeformation;
			donneeformation=malloc(sizeof(formationNormal));
			strcpy(donneeformation->idformation,idformation);
			strcpy(donneeformation->nomformation,baladeur->datas->nomformation);
			donneeformation->suivant=NULL;
			if ((*cdd)->datas->formation_Normal_etudier==NULL)
				(*cdd)->datas->formation_Normal_etudier=donneeformation;
			else{
			donneeformation->suivant=(*cdd)->datas->formation_Normal_etudier;
			(*cdd)->datas->formation_Normal_etudier=donneeformation;}
			(*cdd)->datas->nbrformation_suivi++;
		printf("Votre enregistrement a été avec succée. Vous pouver y accéder dès maintenant rentrer.\n");}
	else {printf("Erreur: cette formation n'est disponible\n");}
	}
return tete;
}
