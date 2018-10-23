#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fichier.h"

admins *initialiseradmins(){
	admins *adm;
	adm=(admins*)malloc(sizeof(admins));
	data_admin *datas;
	datas=malloc(sizeof(data_admin));
	strcpy(datas->login,"Amine");
	strcpy(datas->code,"Larbi");
	adm->datas=datas;
	adm->suivant=NULL;
return adm;}
int rechercheradm(admins *adm,char *login,char *code){
	admins *baladeur=adm;
	int p=1;
	while(baladeur!=NULL && (strcmp(baladeur->datas->login,login)!=0 || strcmp(baladeur->datas->code,code)!=0)){
		baladeur=baladeur->suivant;
		}
	if (baladeur==NULL)
	{printf("votre login/code n'est pas valide. \n");p=0;}
	
return p;}

void afficher_1_formateur_pour_admin(formateurs *tete){
	printf("Le login est : %s\n",tete->datas->login);
	printf("Le nom est : %s\n",tete->datas->nom);
	printf("Le prénom est : %s \n",tete->datas->prenom);
	printf("Le mail est : %s\n",tete->datas->mail);
	printf("L'etablissement est : %s\n",tete->datas->etablissement);
	printf("Le pays est : %s\n",tete->datas->pays);
	printf("Le niveau est : %d\n",tete->datas->niveau);
	printf("Le nombre de classes qu'il a crée est : %d\n",tete->datas->nbrclasse_ens);
	printf("Le nombre de classes qu'il suit est : %d\n",tete->datas->nbrclasse_etd);
	printf("Le nombre de formations qu'il a crée est : %d\n",tete->datas->nbrformation_ens);
	printf("Le nombre de formations qu'il suit est : %d\n",tete->datas->nbrformation_etd);
}

void afficher_Tous_formateur(formateurs *tete){
	if (tete==NULL){printf("Il n'y a aucun Formateur dans votre base de donnée\n");}
	else{
	formateurs *baladeur=tete;
	while(baladeur!=NULL){
		afficher_1_formateur_pour_admin(baladeur);
		printf("\n");
		baladeur=baladeur->suivant;
		}
	}
}

void afficher_Tous_formateur_nv1(formateurs *tete){
	if (tete==NULL){printf("Il n'y a aucun Formateur dans votre base de donnée\n");}
	else{
	int c=0;
	formateurs *baladeur=tete;
	while(baladeur!=NULL){
		if(baladeur->datas->niveau==1){
		c=1;
		afficher_1_formateur_pour_admin(baladeur);
		printf("\n");}
		baladeur=baladeur->suivant;
		}
	if (c==0) printf("Il n'y a aucun Formateur de niveau 1 dans votre base de donnée\n");
	}
}

void afficher_Tous_formateur_nv2(formateurs *tete){
	if (tete==NULL){printf("Il n'y a aucun Formateur dans votre base de donnée\n");}
	else{int c=0;
	formateurs *baladeur=tete;
	while(baladeur!=NULL){
		if(baladeur->datas->niveau==2){
		c=1;
		afficher_1_formateur_pour_admin(baladeur);
		printf("\n");}
		baladeur=baladeur->suivant;
		}
	if (c==0) printf("Il n'y a aucun Formateur de niveau 2 dans votre base de donnée\n");
	}
}

void afficher_Tous_formateur_nv3(formateurs *tete){
	if (tete==NULL){printf("Il n'y a aucun Formateur dans votre base de donnée\n");}
	else{
	int c=0;
	formateurs *baladeur=tete;
	while(baladeur!=NULL){
		if(baladeur->datas->niveau==3){
		c=1;
		afficher_1_formateur_pour_admin(baladeur);
		printf("\n");}
		baladeur=baladeur->suivant;
		}
	if (c==0) printf("Il n'y a aucun Formateur de niveau 3 dans votre base de donnée\n");
	}
}

void rechercher_formateur_par_login(formateurs *tete,char *login){
	formateurs *baladeur=tete;
	while(baladeur!=NULL && strcmp(baladeur->datas->login,login)!=0){
		baladeur=baladeur->suivant;
		}
	if (baladeur==NULL)
	{printf("votre login n'existe pas dans la base de donnée. \n");}
	else{
	afficher_1_formateur_pour_admin(baladeur);}
}

void afficher_1_formation_pour_admin(formations *tete){

	char nomformation[40],typeformation[20];	
	int nbrformateur,nbrformation_avec_meme_nom;
	char *login;
	
	printf("Le nom de la formation est : %s\n",tete->datas->nomformation);
	printf("Le type de la formation est : %s \n",tete->datas->typeformation);
	printf("L'id de la formation est : %s \n",tete->datas->idformation);
	printf("Le nombre de formateur qui suit cette formation est : %d\n",tete->datas->nbrformateur);
	printf("Le login de l'enseigneur est : %s\n\n\n",tete->datas->login);
	}

void afficher_Formation_Accreditation(formations *tete){
	if (tete==NULL){printf("Il n'y a aucun Formation dans votre base de donnée\n");}
	else{
	int c=0;
	formations *baladeur=tete;
	while(baladeur!=NULL){
		if(strcmp("Accréditation",tete->datas->typeformation)==0){
		c=1;
		afficher_1_formation_pour_admin(baladeur);
		printf("\n");}
		baladeur=baladeur->suivant;
		}
	if (c==0) printf("Il n'y a aucun Formation de type accréditation dans votre base de donnée\n");
}}

void afficher_Formation_Normal(formations *tete){
	if (tete==NULL){printf("Il n'y a aucun Formation dans votre base de donnée\n");}
	else{
	int c=0;
	formations *baladeur=tete;
	while(baladeur!=NULL){
		if(strcmp("Normal",tete->datas->typeformation)==0){
		c=1;
		afficher_1_formation_pour_admin(baladeur);
		printf("\n");}
		baladeur=baladeur->suivant;
		}
	if (c==0) printf("Il n'y a aucun Formation de type normal dans votre base de donnée\n");
	}
}

formateurs *supprimerformateur(formateurs *tete,char *login){
	formateurs *baladeur=tete,*prec=tete;
	while(baladeur!=NULL && strcmp(baladeur->datas->login,login)!=0){
		prec=baladeur;
		baladeur=baladeur->suivant;
		}
	if (baladeur==NULL)
	{printf("Ce login n'existe pas dans la base de donné.\n");}
	else{
	char sure;
	do{
	printf("Etes-vous sure de vouloir supprimer ce formateur (O/N): ");
	scanf(" %c",&sure);
	if(sure=='O' || sure=='o'){
	prec->suivant=baladeur->suivant;
	free(baladeur);}
	}while(sure!='O' ||sure=='o' ||sure=='N' ||sure=='n');}
return tete;}
/*
formations *supprimerformation(formations *tete,char *login,char *type){
	formations *baladeur=tete,*prec=tete;
	while(baladeur!=NULL &&( strcmp(baladeur->datas->login,login)!=0 || strcmp(baladeur->datas->typeformation,type)!=0)){
		prec=baladeur;
		baladeur=baladeur->suivant;
		}
	if (baladeur==NULL)
	{printf("Aucune formation avec ces données n'existe pas dans la base de donné.\n");}
	else{
	char sure;
	do{
	printf("Etes-vous sure de vouloir supprimer ce formateur (O/N): ");
	scanf("%c",&sure);
	if(sure=='O' || sure=='o'){
		if(baladeur->datas->nbrformation_avec_meme_nom==1){
			prec->suivant=baladeur->suivant;
			free(baladeur);
			printf("Formation supprimer\n");}
		else if(baladeur->datas->nbrformation_avec_meme_nom<1){
			baladeur->datas->nbrformation_avec_meme_nom--;
			printf("nombre de formation avec meme nom est diminuer\n");
		}
	}
	}while(sure!='O' ||sure=='o' ||sure=='N' ||sure=='n');}
return tete;}
*/

data_admin *creerdataadmin(){
	data_admin *infos;
	char login[20],code[20];
	infos=malloc(sizeof(data_admin));
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
return infos;
}

admins *ajouteradmin(admins *tete,data_admin *infos){
	admins *baladeur;
	baladeur=malloc(sizeof(admins));
	baladeur->datas=infos;
	baladeur->suivant=NULL;
	if(tete==NULL)
		tete=baladeur;
	else{
		baladeur->suivant=tete;
		tete=baladeur;}
return tete;
}

data_admin *creerdataadmin_fichier(char *login,char *code){
	data_admin *infos;
	infos=malloc(sizeof(data_admin));
	strcpy(infos->login,login);
	strcpy(infos->code,code);
return infos;
}
