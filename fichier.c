#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fichier.h"

int rechercheloginexiste(listelogin *tete,char *login){
	listelogin *baladeur=tete;
	while (baladeur!=NULL){
		if (strcmp(baladeur->login,login)==0) return 0;
		baladeur=baladeur->suivant;
		}
	return 1;
}

listelogin *inserelogin(listelogin *tete,char *login){
	listelogin *caselogin=(listelogin *)malloc(sizeof(listelogin));
	strcpy(caselogin->login,login);
	caselogin->suivant=NULL;
	if (tete==NULL) tete=caselogin;
	else{
		caselogin->suivant=tete->suivant;
		tete=caselogin;
	}
return tete;
}
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

formateurs *charge_formateur(int *nbrformateur){
	FILE *f=NULL;
	int i;
	formateurs *frm=NULL;
	f=fopen("formateur.dta","rb");
	if (f==NULL){printf("Erreur de chargement de donnée \n");}
	else{
		char nom[20],prenom[30],etablissement[100],login[20],code[20],mail[30],pays[20];		
		int niveau,nbrclasse_ens,nbrclasse_etd,nbrformation_ens,nbrformation_etd,nbrformation_etd_total,nbrformation_ens_total, nbrclasse_etd_total,nbrclasse_ens_total;
		char idclasse[20],nomclasse[20],typeclasse[20];
		char nomformation[20],idformation[20],typeformation[20];
		data *infos;
		classeAcc *classe_enseigner=NULL,*classe_accreditation_etudier=NULL;
		formationEnse *formation_enseigner=NULL,*formation_accreditation_etudier=NULL;
		infos=malloc(sizeof(data));
		fread(nbrformateur, sizeof(nbrformateur), 1, f);
		for(i=0;i<*nbrformateur;i++){
		fread(nom, sizeof(nom), 1, f);
		fread(prenom, sizeof(prenom), 1, f);
		fread(etablissement, sizeof(etablissement), 1, f);
		fread(login, sizeof(login), 1, f);
		fread(code, sizeof(code), 1, f);
		fread(mail, sizeof(mail), 1, f);
		fread(pays, sizeof(pays), 1, f);
		fread(&niveau, sizeof(niveau), 1, f);
		fread(&nbrclasse_ens, sizeof(nbrclasse_ens), 1, f);
		fread(&nbrclasse_etd, sizeof(nbrclasse_etd), 1, f);
		fread(&nbrformation_ens, sizeof(nbrformation_ens), 1, f);
		fread(&nbrformation_etd, sizeof(nbrformation_etd), 1, f);
		fread(&nbrclasse_ens_total, sizeof(nbrclasse_ens_total), 1, f);
		fread(&nbrclasse_etd_total, sizeof(nbrclasse_etd_total), 1, f);
		fread(&nbrformation_ens_total, sizeof(nbrformation_ens_total), 1, f);
		fread(&nbrformation_etd_total, sizeof(nbrformation_etd_total), 1, f);
		for(i=0;i<infos->nbrclasse_ens;i++){
			fread(idclasse,sizeof(idclasse),1,f);
			fread(nomclasse,sizeof(nomclasse),1,f);
			fread(typeclasse,sizeof(typeclasse),1,f);
			classe_enseigner=insererclasse_frm(classe_enseigner,creerdata_classe(nomclasse,idclasse,typeclasse));
				}
		for(i=0;i<infos->nbrclasse_etd;i++){
			fread(idclasse,sizeof(idclasse),1,f);
			fread(nomclasse,sizeof(nomclasse),1,f);
			fread(typeclasse,sizeof(typeclasse),1,f);
			classe_accreditation_etudier=insererclasse_frm(classe_accreditation_etudier,creerdata_classe(nomclasse,idclasse,typeclasse));
				}
		for(i=0;i<infos->nbrformation_ens;i++){
			fread(idformation,sizeof(idformation),1,f);
			fread(nomformation,sizeof(nomformation),1,f);
			fread(typeformation,sizeof(typeformation),1,f);
			formation_enseigner=insererformation_frm(formation_enseigner,creerdata_formation(nomformation,idformation,typeformation));
			}
		for(i=0;i<infos->nbrformation_etd;i++){
			fread(idformation,sizeof(idformation),1,f);
			fread(nomformation,sizeof(nomformation),1,f);
			fread(typeformation,sizeof(typeformation),1,f);
			formation_accreditation_etudier=insererformation_frm(formation_accreditation_etudier,creerdata_formation(nomformation,idformation,typeformation));

			}
		infos=creerdata_fichier(nom,prenom,etablissement,login,code,mail,pays,niveau,nbrclasse_ens,nbrclasse_etd, nbrformation_ens,nbrformation_etd,nbrclasse_ens_total,nbrclasse_etd_total,nbrformation_ens_total,nbrformation_etd_total, classe_enseigner,classe_accreditation_etudier,formation_enseigner,formation_accreditation_etudier);
		frm=insererformateur_fichier(frm,infos);
		}

	}
	fclose(f);
return frm;
}

void sauvegarde_formateur(char *nom,formateurs *tete,int nbrformateur){
	FILE *f;
	f=fopen(nom,"wb");
	if (f==NULL)printf("Erreur de sauvegarde \n");
	else{
	formateurs *tete2=tete;
	data *infos;
	int i=0;
	classeAcc *classe_enseigner=NULL,*classe_accreditation_etudier=NULL;
	formationEnse *formation_enseigner=NULL,*formation_accreditation_etudier=NULL;
	printf("----------------------Sauvegarde donnee-------------------------------\n\n");
	fwrite(&nbrformateur, sizeof(&nbrformateur), 1, f);
	while(tete2!=NULL){
			infos=tete2->datas;
			//fwrite(&infos, sizeof(infos), 1, f);
			fwrite(infos->nom, sizeof(infos->nom), 1, f);
			fwrite(infos->prenom, sizeof(infos->prenom), 1, f);
			fwrite(infos->etablissement, sizeof(infos->etablissement), 1, f);
			fwrite(infos->login, sizeof(infos->login), 1, f);
			fwrite(infos->code, sizeof(infos->code), 1, f);
			fwrite(infos->mail, sizeof(infos->mail), 1, f);
			fwrite(infos->pays, sizeof(infos->pays), 1, f);
			fwrite(&infos->niveau, sizeof(infos->niveau), 1, f);
			fwrite(&infos->nbrclasse_ens, sizeof(infos->nbrclasse_ens), 1, f);
			fwrite(&infos->nbrclasse_etd, sizeof(infos->nbrclasse_etd), 1, f);
			fwrite(&infos->nbrformation_ens, sizeof(infos->nbrformation_ens), 1, f);
			fwrite(&infos->nbrformation_ens, sizeof(infos->nbrformation_etd), 1, f);
			fwrite(&infos->nbrclasse_ens_total, sizeof(infos->nbrclasse_ens_total), 1, f);
			fwrite(&infos->nbrclasse_etd_total, sizeof(infos->nbrclasse_etd_total), 1, f);
			fwrite(&infos->nbrformation_ens_total, sizeof(infos->nbrformation_ens_total), 1, f);
			fwrite(&infos->nbrformation_etd_total, sizeof(infos->nbrformation_etd_total), 1, f);
			classe_enseigner=infos->classe_enseigner;
			classe_accreditation_etudier=infos->classe_accreditation_etudier;
			formation_enseigner=infos->formation_enseigner;
			formation_accreditation_etudier=infos->formation_accreditation_etudier;
			for(i=0;i<infos->nbrclasse_ens;i++){
				fwrite(classe_enseigner->idclasse,sizeof(classe_enseigner->idclasse),1,f);
				fwrite(classe_enseigner->nomclasse,sizeof(classe_enseigner->nomclasse),1,f);
				fwrite(classe_enseigner->typeclasse,sizeof(classe_enseigner->typeclasse),1,f);
				classe_enseigner=classe_enseigner->suivant;
				}
			for(i=0;i<infos->nbrclasse_etd;i++){
				fwrite(classe_accreditation_etudier->idclasse,sizeof(classe_accreditation_etudier->idclasse),1,f);
				fwrite(classe_accreditation_etudier->nomclasse,sizeof(classe_accreditation_etudier->nomclasse),1,f);
				fwrite(classe_accreditation_etudier->typeclasse,sizeof(classe_accreditation_etudier->typeclasse),1,f);
				classe_accreditation_etudier=classe_accreditation_etudier->suivant;
				}
			for(i=0;i<infos->nbrformation_ens;i++){
				fwrite(formation_enseigner->idformation,sizeof(formation_enseigner->idformation),1,f);
				fwrite(formation_enseigner->nomformation,sizeof(formation_enseigner->nomformation),1,f);
				fwrite(formation_enseigner->typeformation,sizeof(formation_enseigner->typeformation),1,f);
				formation_enseigner=formation_enseigner->suivant;
				}
			for(i=0;i<infos->nbrformation_etd;i++){
				fwrite(formation_accreditation_etudier->idformation,sizeof(formation_accreditation_etudier->idformation),1,f);
				fwrite(formation_accreditation_etudier->nomformation,sizeof(formation_accreditation_etudier->nomformation),1,f);
				fwrite(formation_accreditation_etudier->typeformation,sizeof(formation_accreditation_etudier->typeformation),1,f);
				formation_accreditation_etudier=formation_accreditation_etudier->suivant;
				}
			//ecriture des formation et des classes
			tete2=tete2->suivant;}
	fclose(f);}
}
///////////////////////////////////////////////////////////////////////////
classeAcc *creerdata_classe(char *nomclasse,char *idclasse,char *typeclasse){
	classeAcc *classe_enseigner;
	classe_enseigner=malloc(sizeof(classeAcc));
	strcpy(classe_enseigner->nomclasse,nomclasse);
	strcpy(classe_enseigner->idclasse,idclasse);
	strcpy(classe_enseigner->typeclasse,typeclasse);
	classe_enseigner->suivant=NULL;
return classe_enseigner;
}
classeAcc *insererclasse_frm(classeAcc *tete,classeAcc *infos){
	
		infos->suivant=tete;
		tete=infos;
return tete;
}
///////////////////////////////////////////////////////////////////////////
formationEnse *creerdata_formation(char *nomformation,char *idformation,char *typeformation){
	formationEnse *formation_enseigner;
	formation_enseigner=malloc(sizeof(formationEnse));
	strcpy(formation_enseigner->nomformation,nomformation);
	strcpy(formation_enseigner->idformation,idformation);
	strcpy(formation_enseigner->typeformation,typeformation);
	formation_enseigner->suivant=NULL;
return formation_enseigner;
}
formationEnse *insererformation_frm(formationEnse *tete,formationEnse *infos){
	
		infos->suivant=tete;
		tete=infos;
return tete;
}
/////////////////////////////////////////////////////////////////////
data *creerdata_fichier(char *nom,char *prenom,char *etablissement,char *login,char *code,char *mail,char *pays,int niveau,int nbrclasse_ens,int nbrclasse_etd,int nbrformation_ens,int nbrformation_etd,int nbrclasse_ens_total,int nbrclasse_etd_total,int nbrformation_ens_total,int nbrformation_etd_total,classeAcc *classe_enseigner,classeAcc *classe_accreditation_etudier,formationEnse *formation_enseigner,formationEnse *formation_accreditation_etudier){
	data *infos;
	infos=malloc(sizeof(data));
	strcpy(infos->nom,nom);
	strcpy(infos->prenom,prenom);
	strcpy(infos->etablissement,etablissement);
	strcpy(infos->login,login);
	strcpy(infos->code,code);
	strcpy(infos->mail,mail);
	strcpy(infos->pays,pays);
	infos->niveau=niveau;
	infos->nbrclasse_ens=nbrclasse_ens;
	infos->nbrformation_ens=nbrformation_ens;
	infos->nbrclasse_etd=nbrclasse_etd;
	infos->nbrformation_etd=nbrformation_etd;
	infos->nbrclasse_ens_total=nbrclasse_ens_total;
	infos->nbrformation_ens_total=nbrformation_ens_total;
	infos->nbrclasse_etd_total=nbrclasse_etd_total;
	infos->nbrformation_etd_total=nbrformation_etd_total;
	infos->classe_enseigner=classe_enseigner;
	infos->classe_accreditation_etudier=classe_accreditation_etudier;
	infos->formation_enseigner=formation_enseigner;
	infos->formation_accreditation_etudier=formation_accreditation_etudier;
return infos;
}
formateurs *insererformateur_fichier(formateurs *tete,data *infos){
	formateurs *frm;
	frm=malloc(sizeof(formateurs));
	frm->datas=infos;
	frm->suivant=NULL;
	if (tete==NULL){tete=frm;}
	else{
		frm->suivant=tete;
		tete=frm;
	}
return tete;
}

////////////////////////////////////////////////////////////////////////////////

classe *creerclasse(int niveau,formateurs *frm,char *idclasse){
	char nomclasse[20];
	classe *cls=malloc(sizeof(classe));
	printf("Donner le nom de la formation que vous allez enseigner dans votre classe : ");
	scanf("%s",cls->nomclasse);
	cls->nbreleve=0;
	strcpy(cls->login,frm->datas->login);
	strcpy(cls->idclasse,idclasse);
	if (niveau==1){
		strcpy(cls->typeclasse,"Normal");
		}
	else {
		int choix=0;
		do{
			printf("Entrer 1 pour créer une classe d'accréditation, 2 pour une classe normal : ");
			scanf("%d",&choix);
			if (choix!=1 && choix!=2) printf("Votre choix doit être soit '1' soit '2'\n");
		}while(choix!=1 && choix!=2);
		if(choix==1) strcpy(cls->typeclasse,"Accréditation");
		else strcpy(cls->typeclasse,"Normal");
	}
return cls;	
}

listeclasse *insererclasse(listeclasse *tete,classe *infos){
	listeclasse *baladeur=tete;
	while(baladeur!=NULL && strcmp(baladeur->datas->login,infos->login)!=0 && strcmp(baladeur->datas->nomclasse,infos->nomclasse)!=0 && strcmp(baladeur->datas->typeclasse,infos->typeclasse)!=0){
		baladeur=baladeur->suivant;
		}
	if(baladeur==NULL){
	listeclasse *cls;
	cls=malloc(sizeof(listeclasse));
	cls->datas=infos;
	cls->suivant=NULL;
	if (tete==NULL){tete=cls;}
	else{
		cls->suivant=tete->suivant;
		tete->suivant=cls;
	}
	}
return tete;
}

int afficher_classe_disponible(listeclasse *tete,formateurs *frm,char *typeclasse){
	int n=0;
	if (tete==NULL){printf("Il n'y a aucune classe disponible pour le moment\n");}
	else{n=1;
	int v=1;
	classeAcc *classe_accreditation_etudier=NULL;
	printf("Veuillez choisir entre ces classes qui vous sont disponible\n\n");
	listeclasse *baladeur=tete;
	while(baladeur!=NULL){
		if (baladeur->datas->nbreleve<30 && strcmp(baladeur->datas->typeclasse,typeclasse)==0 && strcmp(baladeur->datas->login,frm->datas->login)!=0){
		classe_accreditation_etudier=frm->datas->classe_accreditation_etudier;
		v=1;
		while(classe_accreditation_etudier!=NULL && v==1){
 			if(strcmp(frm->datas->classe_accreditation_etudier->idclasse,baladeur->datas->idclasse)==0){
				v=0;
			}
			classe_accreditation_etudier=classe_accreditation_etudier->suivant;}
		if(v==1){
		printf("nom de classe: %s || Login de Formateur: %s || L'id de la classe est: %s\n",baladeur->datas->nomclasse,baladeur->datas->login,baladeur->datas->idclasse);
		printf("\n");}}
		baladeur=baladeur->suivant;
		}
	}
return n;
}

listeclasse *suivre_classe(listeclasse *tete,formateurs **frm,char *idclasse){
	listeclasse *baladeur=tete;
	while(baladeur!=NULL && strcmp(baladeur->datas->typeclasse,"Accréditation")!=0 && strcmp(baladeur->datas->idclasse,idclasse)!=0){
			baladeur=baladeur->suivant;}
	if (baladeur==NULL){printf("Erreur de saisis: cette classe n'est disponible\n");}
	else{
	if (baladeur->datas->nbreleve<30){
			baladeur->datas->nbreleve++;
			classeAcc *donneeclasse;
			donneeclasse=malloc(sizeof(classeAcc));
			strcpy(donneeclasse->idclasse,idclasse);
			donneeclasse->suivant=NULL;
			if ((*frm)->datas->classe_accreditation_etudier==NULL)
				(*frm)->datas->classe_accreditation_etudier=donneeclasse;
			else{
			donneeclasse->suivant=(*frm)->datas->classe_accreditation_etudier->suivant;
			(*frm)->datas->classe_accreditation_etudier=donneeclasse;}
		(*frm)->datas->nbrclasse_etd++;
		printf("Votre enregistrement a été avec succée. Vous pouver y acceder dès maintenant.\n");}
	else {printf("Erreur: cette classe n'est disponible");}
	}
return tete;
}

listeclasse *suivre_classe_candidat(listeclasse *tete,candidat **cdd,char *idclasse){
	listeclasse *baladeur=tete;
	while(baladeur!=NULL && (strcmp(baladeur->datas->typeclasse,"Normal")!=0 || strcmp(baladeur->datas->idclasse,idclasse)!=0)){
			baladeur=baladeur->suivant;}
	if (baladeur==NULL){printf("Erreur de saisis: cette classe n'est disponible\n");return;}
	else{
	if (baladeur->datas->nbreleve<30){
			baladeur->datas->nbreleve++;
			classeNormal *donneeclasse;
			donneeclasse=malloc(sizeof(classeNormal));
			strcpy(donneeclasse->idclasse,idclasse);
			strcpy(donneeclasse->nomclasse,baladeur->datas->nomclasse);
			donneeclasse->suivant=NULL;
			if ((*cdd)->datas->classe_Normal_etudier==NULL)
				(*cdd)->datas->classe_Normal_etudier=donneeclasse;
			else{
			donneeclasse->suivant=(*cdd)->datas->classe_Normal_etudier->suivant;
			(*cdd)->datas->classe_Normal_etudier->suivant=donneeclasse;}
		printf("Votre enregistrement a été avec succée. Vous pouver y acceder dès maintenant.\n");}
	else {printf("Erreur: cette classe n'est disponible");}
	}
return tete;
}
listeclasse *desinscrire_classe(listeclasse *tete,formateurs **frm,char *typeclasse){
	listeclasse *baladeur=tete;
	char idclasse[30];
	printf("Donner l'id de formation dont vous voulez désinscrire: ");
	scanf("%s",idclasse);
	while(baladeur!=NULL && ( strcmp(baladeur->datas->typeclasse,typeclasse)!=0 || strcmp(baladeur->datas->idclasse,idclasse)!=0 )){
			baladeur=baladeur->suivant;}
	if (baladeur==NULL){printf("Erreur de saisis: Aucune formation n'a ces données\n");}
	else{
		baladeur->datas->nbreleve--;
		(*frm)->datas->nbrclasse_etd--;
		classeAcc *baladeur2=(*frm)->datas->classe_accreditation_etudier;
		classeAcc *prec2=(*frm)->datas->classe_accreditation_etudier;
		while(baladeur2==NULL && strcmp(baladeur2->idclasse,idclasse)!=0){
			prec2=baladeur2;
			baladeur2=baladeur2->suivant;}
		prec2->suivant=baladeur2->suivant;
		printf("Votre désinscription a été faite avec succée.\n");}
return tete;
}

listeclasse *supprimer_classe(listeclasse *tete,formateurs **frm){
	listeclasse *baladeur=tete,*prec=tete;
	char idclasse[20],typeclasse[20];
	printf("Donner l'id de classe dont vous voulez supprimer: ");
	scanf("%s",idclasse);
	int choix=0;
		do{
			printf("Entrer 1 pour choisir une classe d'accréditation, 2 pour une classe normal : ");
			scanf("%d",&choix);
			if (choix!=1 && choix!=2) printf("Votre choix doit être soit '1' soit '2'\n");
		}while(choix!=1 && choix!=2);
		if(choix==1) strcpy(typeclasse,"Accréditation");
		else strcpy(typeclasse,"Normal");
	while(baladeur!=NULL && ( strcmp(baladeur->datas->typeclasse,typeclasse)!=0 || strcmp(baladeur->datas->idclasse,idclasse)!=0 || strcmp(baladeur->datas->login,(*frm)->datas->login)!=0 )){
			prec=baladeur;
			baladeur=baladeur->suivant;}
	if (baladeur==NULL){printf("Erreur de saisis: Aucune classe n'a ces données\n");}
	else{
		prec->suivant=baladeur->suivant;
		(*frm)->datas->nbrclasse_ens--;
		classeAcc *baladeur2=(*frm)->datas->classe_enseigner;
		classeAcc *prec2=(*frm)->datas->classe_enseigner;
		while(baladeur2==NULL && strcmp(baladeur2->idclasse,idclasse)!=0){
			prec2=baladeur2;
			baladeur2=baladeur2->suivant;}
		prec2->suivant=baladeur2->suivant;
		printf("Votre suppression a été faite avec succée.\n");}
return tete;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void sauvegarde_classe(char *nom,listeclasse *tete,int nbrclasse){
	FILE *f;
	f=fopen(nom,"wb");
	if (f==NULL)printf("Erreur de sauvegarde \n");
	else{
	listeclasse *tete2=tete;
	classe *infos;
	fwrite(&nbrclasse, sizeof(&nbrclasse), 1, f);
	while(tete2!=NULL){
			infos=tete2->datas;
			//fwrite(&infos, sizeof(infos), 1, f);
			fwrite(infos->typeclasse, sizeof(infos->typeclasse), 1, f);
			fwrite(infos->nomclasse, sizeof(infos->nomclasse), 1, f);
			fwrite(infos->idclasse, sizeof(infos->idclasse), 1, f);
			fwrite(infos->login, sizeof(infos->login), 1, f);
			fwrite(&infos->nbreleve, sizeof(infos->nbreleve), 1, f);
			tete2=tete2->suivant;}
	fclose(f);}
}

listeclasse *charge_classe(int *nbrclasse){
	FILE *f=NULL;
	int i;
	listeclasse *cls=NULL;
	f=fopen("classes.dta","rb");
	if (f==NULL){printf("Erreur de chargement de donnée \n");}
	else{
		char nomclasse[20],typeclasse[20],login[20];		
		int nbreleve,nbrclasse_avec_meme_nom;
		classe *infos;
		infos=malloc(sizeof(classe));
		fread(nbrclasse, sizeof(nbrclasse), 1, f);
		for(i=0;i<*nbrclasse;i++){
			fread(infos->typeclasse, sizeof(infos->typeclasse), 1, f);
			fread(infos->nomclasse, sizeof(infos->nomclasse), 1, f);
			fread(infos->idclasse, sizeof(infos->idclasse), 1, f);
			fread(infos->login, sizeof(infos->login), 1, f);
			fread(&infos->nbreleve, sizeof(infos->nbreleve), 1, f);
		
		cls=insererclasse(cls,infos);
		}

	}
	fclose(f);
return cls;
}
////////////////////////////////////////////////////////////////////////////////////////////

char *idclssegenerateur(char *c){
	if (*(c+6)<'Z'&&*(c+6)>='A'){*(c+6)=*(c+6)+1;}
    	else if(*(c+6)=='Z'){*(c+6)='A';
		if (*(c+5)<'Z'&&*(c+5)>='A'){*(c+5)=*(c+5)+1;}
    		else if(*(c+5)=='Z'){*(c+5)='A';
			if (*(c+4)<'Z'&&*(c+4)>='A'){*(c+4)=*(c+4)+1;}
    			else if(*(c+4)=='Z'){*(c+4)='A';
				if (*(c+3)<'Z'&&*(c+3)>='A'){*(c+3)=*(c+3)+1;}
				else if(*(c+3)=='Z'){*(c+3)='A';
        				if (*(c+2)<'Z'&&*(c+2)>='A'){*(c+2)=*(c+2)+1;}
        				else if(*(c+2)=='Z'){*(c+2)='A';
          		  			if (*(c+1)<'Z'&&*(c+1)>='A'){*(c+1)=*(c+1)+1;}
           		  			else if(*(c+1)=='Z'){*(c+1)='A';
                	  			if (*(c+0)<'Z'&&*(c+0)>='A'){*(c+0)=*(c+0)+1;}
}}}}}}
return c;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
admins *chargeadmin(int *nbradmin){
	FILE *f=NULL;
	int i;
	admins *adm=NULL;
	f=fopen("admins.dta","rb");
	if (f==NULL){printf("Erreur de chargement de donnée \n");}
	else{		
		char login[20],code[20];
		data_admin *infos=NULL;
		infos=malloc(sizeof(data_admin));
		fread(nbradmin, sizeof(*nbradmin), 1, f);
		for(i=0;i<*nbradmin;i++){
			fread(login, sizeof(login),1,f);
			fread(code, sizeof(code),1,f);
			infos=creerdataadmin_fichier(login,code);
			adm=ajouteradmin(adm,infos);
		}
	}
	fclose(f);
return adm;
}

void sauvegarde_admins(char *nom,admins *tete,int nbradmin){
	FILE *f;
	f=fopen(nom,"wb");
	if (f==NULL)printf("Erreur de sauvegarde \n");
	else{
	admins *tete2=tete;
	data_admin *infos;
	fwrite(&nbradmin, sizeof(nbradmin), 1, f);
	while(tete2!=NULL){
			infos=tete2->datas;
			fwrite(infos->login,sizeof(infos->login),1,f);
			printf("\n\n%s\n\n",infos->login);
			fwrite(infos->code,sizeof(infos->code),1,f);
			tete2=tete2->suivant;}
	}
	fclose(f);
	printf("-----------------------Fin sauvegarde------------------------------\n");
}

///////////////////////////////////////////////////////////////////
void sauvegarde_login(char *nom,listelogin *logins,int nbrlogins){
	FILE *f;
	f=fopen(nom,"wb");
	if (f==NULL)printf("Erreur de sauvegarde \n");
	else{
	listelogin *tete=logins;
	fwrite(&nbrlogins, sizeof(nbrlogins), 1, f);
	while(tete!=NULL){
			fwrite(tete->login,sizeof(tete->login),1,f);
			tete=tete->suivant;}
	}
	fclose(f);
}

listelogin *charge_login(int *nbrlogins){
	FILE *f=NULL;
	int i;
	listelogin *logins=(listelogin*)malloc(sizeof(listelogin));
	listelogin *baladeur=(listelogin*)malloc(sizeof(listelogin));
	f=fopen("logins.dta","rb");
	if (f==NULL){printf("Erreur de chargement de donnée \n");}
	else{		
		fread(nbrlogins, sizeof(nbrlogins), 1, f);
		for(i=0;i<*nbrlogins;i++){
			fread(baladeur->login, sizeof(baladeur->login),1,f);
			baladeur->suivant=logins;
			logins=baladeur;
		}
	}
	fclose(f);
return logins;
}
////////////////////////////////////////////////////////////////////////////////////////
void sauvegarde_formation(char *nom,formations *tete,int nbrformation){
	FILE *f;
	f=fopen(nom,"wb");
	if (f==NULL)printf("Erreur de sauvegarde \n");
	else{
	formations *tete2=tete;
	dataformation *infos;
	int i=0;
	fwrite(&nbrformation, sizeof(nbrformation), 1, f);
	while(tete2!=NULL){
			infos=tete2->datas;
			fwrite(infos->nomformation, sizeof(infos->nomformation), 1, f);
			fwrite(infos->typeformation, sizeof(infos->typeformation), 1, f);
			fwrite(infos->idformation, sizeof(infos->idformation), 1, f);
			fwrite(infos->login, sizeof(infos->login), 1, f);
			fwrite(&infos->nbrformateur, sizeof(infos->nbrformateur), 1, f);
			tete2=tete2->suivant;}
	fclose(f);}
}

formations *charge_formation(int *nbrformation){
	FILE *f=NULL;
	int i;
	formations *frmt=NULL;
	f=fopen("formateur.dta","rb");
	if (f==NULL){printf("Erreur de chargement de donnée \n");}
	else{
		char nomformation[40],typeformation[20],idformation[20],login[20];
		int nbrformateur;
		dataformation *infos;
		infos=malloc(sizeof(dataformation));
		fread(nbrformation, sizeof(*nbrformation), 1, f);
		for(i=0;i<*nbrformation;i++){
		fread(infos->nomformation, sizeof(nomformation), 1, f);
		fread(infos->typeformation, sizeof(typeformation), 1, f);
		fread(infos->idformation, sizeof(idformation), 1, f);
		fread(infos->login, sizeof(login), 1, f);
		fread(&infos->nbrformateur, sizeof(infos->nbrformateur), 1, f);
		frmt=insererformation_fichier(frmt,infos);
		}
	}
	fclose(f);
return frmt;
}
