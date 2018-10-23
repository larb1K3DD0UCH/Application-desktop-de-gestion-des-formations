#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fichier.h"


///////////////////////////////////	Création de formation	/////////////////////////////////////
dataformation *creer_donnee_formation_enseigner(int niveau,formateurs *frm,char *idformation){				
	if (niveau==1){	printf("Votre niveau ne vous permet pas d'enseigner une formation ");return ;}		
	else{
	dataformation *infosformation=malloc(sizeof(dataformation));
	printf("Donner le nom de la formation que vous voulez enseigner : ");
	scanf("%s",infosformation->nomformation);
	int choix=0;
		do{
			printf("Entrer 1 pour créer une formation d'accréditation, 2 pour une formation normal : ");
			scanf("%d",&choix);
			if (choix!=1 && choix!=2) printf("Votre choix doit être soit '1' soit '2'\n");
		}while(choix!=1 && choix!=2);
		if(choix==1) strcpy(infosformation->typeformation,"Accréditation");
		else strcpy(infosformation->typeformation,"Normal");
	infosformation->nbrformateur=0;
	strcpy(infosformation->idformation,idformation);
	strcpy(infosformation->login,frm->datas->login);
	return infosformation;}
}

formations  *insererformation(formations *tete,dataformation *infos,formateurs **frm){
	
	formations *formation;
	formation=malloc(sizeof(formation));
	formation->datas=infos;
	formation->suivant=NULL;
	formationEnse *formation_enseigner=NULL;
	formation_enseigner=malloc(sizeof(formationEnse));
	strcpy(formation_enseigner->nomformation,infos->nomformation);
	strcpy(formation_enseigner->typeformation,infos->typeformation);
	strcpy(formation_enseigner->idformation,infos->idformation);
	formation_enseigner->suivant=NULL;
	if ((*frm)->datas->formation_enseigner==NULL) 
		(*frm)->datas->formation_enseigner=formation_enseigner;
	else{
		formation_enseigner->suivant=(*frm)->datas->formation_enseigner;
		(*frm)->datas->formation_enseigner=formation_enseigner;}
	if (tete==NULL){tete=formation;}
	else{
		formation->suivant=tete;
		tete=formation;
		}
return tete;
}

formations  *insererformation_fichier(formations *tete,dataformation *infos){
	
	formations *formation;
	formation=malloc(sizeof(formations));
	formation->datas=infos;
	formation->suivant=NULL;
	formation->suivant=tete;
	tete=formation;
return tete;
}

///////////////////////////////////	Inscription à formation	/////////////////////////////////////
int afficher_formation_disponible(formations *tete,formateurs *frm,char *typeformation){
	int n=0;									//n=0 si tete est null, 1 sinon
	if (tete==NULL){printf("Il n'y a aucun Formation disponible pour le moment\n");}
	else{n=1;
	int v=1;
	formationEnse *formation_accreditation_etudier=NULL;
	printf("Veuillez choisir entre ces formations qui vous sont disponible: \n\n");
	formations *baladeur=tete;
	while(baladeur!=NULL){
		if (baladeur->datas->nbrformateur<20 && strcmp(baladeur->datas->typeformation,typeformation)==0 && strcmp(baladeur->datas->login,frm->datas->login)!=0){
		formation_accreditation_etudier=frm->datas->formation_accreditation_etudier;
		v=1;
		while(formation_accreditation_etudier!=NULL && v==1){
 			if(strcmp(frm->datas->formation_accreditation_etudier->idformation,baladeur->datas->idformation)==0){
				v=0;
			}
			formation_accreditation_etudier=formation_accreditation_etudier->suivant;}
		if(v==1){
		printf("nom de formation: %s || Login de Formateur: %s || L'id de la formation est: %s\n",baladeur->datas->nomformation,baladeur->datas->login,baladeur->datas->idformation);
		printf("\n");}}
		baladeur=baladeur->suivant;
		}
	}
return n;
}

formations *suivre_formation(formations *tete,formateurs **frm,char *idformation,char *typeformation){
	formations *baladeur=tete;
	while(baladeur!=NULL && ( strcmp(baladeur->datas->typeformation,typeformation)!=0 || strcmp(baladeur->datas->idformation,idformation)!=0)){
			baladeur=baladeur->suivant;}
	if (baladeur==NULL){printf("Erreur de saisis: cette formation n'est disponible");}
	else{
	if (baladeur->datas->nbrformateur<20){
			baladeur->datas->nbrformateur++;
			formationEnse *donneeformation;
			donneeformation=malloc(sizeof(formationEnse));
			strcpy(donneeformation->idformation,idformation);
			strcpy(donneeformation->typeformation,typeformation);
			strcpy(donneeformation->nomformation,baladeur->datas->nomformation);
			donneeformation->suivant=NULL;
			if ((*frm)->datas->formation_accreditation_etudier==NULL)
				(*frm)->datas->formation_accreditation_etudier=donneeformation;
			else{
			donneeformation->suivant=(*frm)->datas->formation_accreditation_etudier;
			(*frm)->datas->formation_accreditation_etudier=donneeformation;}
			(*frm)->datas->nbrformation_etd++;
			(*frm)->datas->nbrformation_etd_total++;
		printf("Votre enregistrement a été avec succée. Vous pouver y accéder dès maintenant rentrer.\n");}
	else {printf("Erreur: cette formation n'est disponible\n");}
	}
return tete;
}

formations *desinscrire_formation(formations *tete,formateurs **frm,char *typeformation){
	formations *baladeur=tete;
	char idformation[30];
	printf("Donner l'id de formation dont vous voulez désinscrire: ");
	scanf("%s",idformation);
	while(baladeur!=NULL && ( strcmp(baladeur->datas->typeformation,typeformation)!=0 || strcmp(baladeur->datas->idformation,idformation)!=0 )){
			baladeur=baladeur->suivant;}
	if (baladeur==NULL){printf("Erreur de saisis: Aucune formation n'a ces données\n");}
	else{
		baladeur->datas->nbrformateur--;
		(*frm)->datas->nbrformation_etd--;
		formationEnse *baladeur2=(*frm)->datas->formation_accreditation_etudier;
		formationEnse *prec2=(*frm)->datas->formation_accreditation_etudier;
		while(baladeur2==NULL && strcmp(baladeur2->idformation,idformation)!=0){
			prec2=baladeur2;
			baladeur2=baladeur2->suivant;}
		prec2->suivant=baladeur2->suivant;
		printf("Votre désinscription a été faite avec succée.\n");}
return tete;
}

formations *supprimer_formation(formations *tete,formateurs **frm){
	formations *baladeur=tete,*prec=tete;
	char idformation[20],typeformation[20];
	printf("Donner l'id de formation dont vous voulez supprimer: ");
	scanf("%s",idformation);
	int choix=0;
		do{
			printf("Entrer 1 pour choisir une formation d'accréditation, 2 pour une formation normal : ");
			scanf("%d",&choix);
			if (choix!=1 && choix!=2) printf("Votre choix doit être soit '1' soit '2'\n");
		}while(choix!=1 && choix!=2);
		if(choix==1) strcpy(typeformation,"Accréditation");
		else strcpy(typeformation,"Normal");
	while(baladeur!=NULL && ( strcmp(baladeur->datas->typeformation,typeformation)!=0 || strcmp(baladeur->datas->idformation,idformation)!=0 || strcmp(baladeur->datas->login,(*frm)->datas->login)!=0 )){
			prec=baladeur;
			baladeur=baladeur->suivant;}
	if (baladeur==NULL){printf("Erreur de saisis: Aucune formation n'a ces données\n");}
	else{
		prec->suivant=baladeur->suivant;
		(*frm)->datas->nbrformation_ens--;
		formationEnse *baladeur2=(*frm)->datas->formation_enseigner;
		formationEnse *prec2=(*frm)->datas->formation_enseigner;
		while(baladeur2==NULL && strcmp(baladeur2->idformation,idformation)!=0){
			prec2=baladeur2;
			baladeur2=baladeur2->suivant;}
		prec2->suivant=baladeur2->suivant;
		printf("Votre suppression a été faite avec succée.\n");}
return tete;
}
