#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"fichier.h"

int main(){
	int choix=0,choixform1=0,choix_repeter=1,sortir=0,premiereutilisation=0;
	int nbrformateur=0,nbrclasse=0,nbradmin=1,nbrcandidat=0,nbrformation=0,nbrlogins=0;
	char type_accreditation[20]="Accreditation",type_normal[20]="Normal",idclasse[20]="AAAAAAA",idformation[20]="AAAAAAA";
	formateurs *frm=NULL,*frm1=NULL;
	candidat *cdd=NULL,*cdd1=NULL;
	listeclasse *Lisclasse=NULL;
	formations *Lisformation=NULL;
	listelogin *logins=NULL;
	admins *adm=NULL;
	system("clear");
	printf("\n\t\t\tBonjours, et bienvenue au programme de gestion de formation de formateur \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\tréaliser par: \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\tAmine Farah \n\t\t\t\t\t\t\t\t\t\t\t\t\tLarbi Keddouch\n\n");
	printf("Si c'est votre premiere utilistation entrer 0, 1 sinon (Faite attention, ça peut supprimer vos données):");
	scanf("%d",&premiereutilisation);
	if(premiereutilisation!=0){
		printf("-------------------------Chargement de donnée----------------------------\n");
		printf("----------------------------Donnée Chargé--------------------------------\n");
		frm=charge_formateur(&nbrformateur);
		Lisclasse=charge_classe(&nbrclasse);
		Lisformation=charge_formation(&nbrformation);
		adm=chargeadmin(&nbradmin);
		logins=charge_login(&nbrlogins);
	}
	if (adm==NULL){
		adm=initialiseradmins();}
	do{
	choix=menu_princ();	//Le menu principal
	switch (choix){
	case 1:			//Cas de formateur
		{int retourner_menu_formateur=0;
		do{
		system("clear");
		choixform1=menu_formateur1();
		frm1=NULL;
		if(choixform1==0){sortir=1;
				retourner_menu_formateur=0;}		//Quitter le programme
		else if(choixform1==3){retourner_menu_formateur=0;sortir=0;}	//Retourner au menu précédent
		else if(choixform1==1){			//déja incrit
			char code[20],login[20];
			do{
			printf("Entrer votre login: ");
			scanf("%s",login);
			printf("Entrer votre code et '0' si vous l'avez perdu :");
			scanf("%s",code);
			if (code=="0")			//Si il a oublié le code
				{char mail[50];
				printf("Entrer votre email :");
				scanf("%s",mail);
				frm1=recherchefrmmail(frm,login,mail); 		//rechercher la case memoire qui contient les données par mail
				if (frm1!=NULL) printf("votre login (CIN) est: %s\nvotre code est: %s",frm1->datas->login,frm1->datas->code);}
			else frm1=recherchefrmcode(frm,login,code);		//rechercher la case memoire qui contient les données par code
			
			if(frm1==NULL) {printf("Pour réssayer entrer '0', et autre nombre pour revenir au menu précédent: ");
					scanf("%d",&choix_repeter);
			if(choix_repeter!=0)retourner_menu_formateur=1; }
			}while(choix_repeter==0);}
		else if(choixform1==2){			//s'incrire
			frm=insererformateur(frm,&logins);
			afficher_1_formateur(frm);
			printf("veuillez retenir votre login et code afin d'acceder à vos donner quand vous voulez\n");
			nbrformateur++;
			frm1=frm; //on insére chaque nouveau formateur en tete de liste chainée
			}
		
		if (frm1!=NULL){	//si on a récuperer la case où se trouve les données
			int passer_niveau_sup=0;
			do{
			system("clear");
			passer_niveau_sup=0;
			int niveau=frm1->datas->niveau;		//on test le niveau de formateur
			int choix_retourner_menu_prec=1;

//////////	NIVEAU 1

			if(niveau==1){				//si le niveau est 1(tuteur)
				int choix_nv1;
				do{
					choix_retourner_menu_prec=1;
					choix_nv1=menu_formateur_niveau1();	//on propose le menu
					if (choix_nv1==2){			//créer classe
						Lisclasse=insererclasse(Lisclasse,creerclasse(niveau,frm1,idclasse));
						strcpy(idclasse,idclssegenerateur(idclasse));
						frm1->datas->nbrclasse_ens++;
						frm1->datas->nbrclasse_ens_total++;
						nbrclasse++;
						printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent : ");
						scanf("%d",&choix_retourner_menu_prec);
						if (choix_retourner_menu_prec==0) {sortir=1;
							retourner_menu_formateur=0;}
						else retourner_menu_formateur=1;}
					
					else if (choix_nv1==3){
							Lisclasse=supprimer_classe(Lisclasse,&frm1);
							printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent: ");
							scanf("%d",&choix_retourner_menu_prec);
							if (choix_retourner_menu_prec==0) {sortir=1;
									retourner_menu_formateur=0;}
							else retourner_menu_formateur=1;}

					else if (choix_nv1==4){char idclasse1[20];
						if(afficher_classe_disponible(Lisclasse,frm1,type_accreditation)==1){
						printf("Donner le id de la classe: ");
						scanf("%s",idclasse1);
						Lisclasse=suivre_classe(Lisclasse,&frm1,idclasse);}	
						printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent : ");
						scanf("%d",&choix_retourner_menu_prec);
						if (choix_retourner_menu_prec==0) {sortir=1;
							retourner_menu_formateur=0;}
						else retourner_menu_formateur=1;}

					else if (choix_nv1==5){
							Lisclasse=desinscrire_classe(Lisclasse,&frm1,type_accreditation);
							printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent: ");
							scanf("%d",&choix_retourner_menu_prec);
							if (choix_retourner_menu_prec==0) {sortir=1;
									retourner_menu_formateur=0;}
							else retourner_menu_formateur=1;}
					
					else if (choix_nv1==6){char idformation1[20];
						if(afficher_formation_disponible(Lisformation,frm1,type_accreditation)==1){
						printf("Donner l'id de la formation: ");
						scanf("%s",idformation1);
						
						Lisformation=suivre_formation(Lisformation,&frm1,idformation1,type_accreditation);}
						printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent : ");
						scanf("%d",&choix_retourner_menu_prec);
						if (choix_retourner_menu_prec==0) {sortir=1;
							retourner_menu_formateur=0;}
						else retourner_menu_formateur=1;}	
					
					else if (choix_nv1==7){
							Lisformation=desinscrire_formation(Lisformation,&frm1,type_accreditation);
							printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent: ");
							scanf("%d",&choix_retourner_menu_prec);
							if (choix_retourner_menu_prec==0) {sortir=1;
									retourner_menu_formateur=0;}
							else retourner_menu_formateur=1;}

					else if (choix_nv1==8){			//passer niveau 2
						if (frm1->datas->nbrclasse_ens_total>=3) {frm1->datas->niveau++;
										passer_niveau_sup=1;
										choix_retourner_menu_prec=3;}
						else {printf("veuillez créer au moins 3 classes\n");
						printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent : ");
						scanf("%d",&choix_retourner_menu_prec);}
							if (choix_retourner_menu_prec==0) {sortir=1;
									retourner_menu_formateur=0;}
							else retourner_menu_formateur=1;}

					else if(choix_nv1==9){afficher_1_formateur(frm1);
							printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent: ");
							scanf("%d",&choix_retourner_menu_prec);
							if (choix_retourner_menu_prec==0) {sortir=1;
									retourner_menu_formateur=0;}
							else retourner_menu_formateur=1;}
					
					else if(choix_nv1==10){choix_retourner_menu_prec=changer_donnee_formateur(&frm1);} //changer les données
						
					else if (choix_nv1==1){choix_retourner_menu_prec=0;
								retourner_menu_formateur=1;}
					
					else {choix_retourner_menu_prec=0;
						sortir=1;
						retourner_menu_formateur=0;}
				system("clear");
				}while(choix_retourner_menu_prec==1);}

//////////	NIVEAU 2
 
			else if(niveau==2){
				do{	choix_retourner_menu_prec=1;
					choix=menu_formateur_niveau2();
					switch(choix){
						case (0):{sortir=1;
							retourner_menu_formateur=0;
							choix_retourner_menu_prec=0;break;}			//Quitter le programme

						case (12):{choix_retourner_menu_prec=changer_donnee_formateur(&frm1);
							break;}							//changer les données

						case (11):{afficher_1_formateur(frm1);
							printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent: ");
						scanf("%d",&choix_retourner_menu_prec); 							break;}							//Afficher les données

						case (1):{choix_retourner_menu_prec=0;
							retourner_menu_formateur=1;
							break;}

						case (2):{				//créer classe
							Lisclasse=insererclasse(Lisclasse,creerclasse(niveau,frm1,idclasse));
							strcpy(idclasse,idclssegenerateur(idclasse));
							//if(strcmp(Lisclasse->datas->typeclasse,type_normal)==0)
							frm1->datas->nbrclasse_ens++;
							frm1->datas->nbrclasse_ens_total++;
							nbrclasse++;
							printf("veuillez entrer 0 pour quitter le programme,ou 1 revenir au menu précedent: ");
							scanf("%d",&choix_retourner_menu_prec);
							if (choix_retourner_menu_prec!=0) choix_retourner_menu_prec=1;
							else {sortir=1;
								retourner_menu_formateur=0;}
							break;}	
						case (3):{				//supprimmer classe
							Lisclasse=supprimer_classe(Lisclasse,&frm1);
							printf("veuillez entrer 0 pour quitter le programme,ou 1 revenir au menu précedent: ");
							scanf("%d",&choix_retourner_menu_prec);
							if (choix_retourner_menu_prec!=0) choix_retourner_menu_prec=1;
							else {sortir=1;
								retourner_menu_formateur=0;}
							break;}

						case (4):{				//s'inscrire classe
							char idclasse1[20];
							if(afficher_classe_disponible(Lisclasse,frm1,type_accreditation)==1){
								printf("Donner le id de la classe: ");
								scanf("%s",idclasse1);
								Lisclasse=suivre_classe(Lisclasse,&frm1,idclasse);}	
							printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent: ");
							scanf("%d",&choix_retourner_menu_prec);
							if (choix_retourner_menu_prec==0) {sortir=1;
								retourner_menu_formateur=0;}
							else retourner_menu_formateur=1;
							break;}
						case (5):{				//désinscrire classe
							Lisclasse=desinscrire_classe(Lisclasse,&frm1,type_accreditation);
							printf("veuillez entrer 0 pour quitter le programme,ou 1 revenir au menu précedent: ");
							scanf("%d",&choix_retourner_menu_prec);
							if (choix_retourner_menu_prec!=0) choix_retourner_menu_prec=1;
							else {sortir=1;
								retourner_menu_formateur=0;}
							break;}
		
						case (6):{ 		//suivre une formation d'accreditation
							char idformation1[20];
							if(afficher_formation_disponible(Lisformation,frm1,type_accreditation)==1){
							printf("Donner l'id de la formation: ");
							scanf("%s",idformation1);
							
							Lisformation=suivre_formation(Lisformation,&frm1,idformation1,type_accreditation);}
							printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent: ");
						scanf("%d",&choix_retourner_menu_prec);
						if (choix_retourner_menu_prec==0) {sortir=1;
							retourner_menu_formateur=0;}
						else retourner_menu_formateur=1;
							break;}

						case (7):{				//désinscrire formation
							Lisformation=desinscrire_formation(Lisformation,&frm1,type_accreditation);
							printf("veuillez entrer 0 pour quitter le programme,ou 1 revenir au menu précedent: ");
							scanf("%d",&choix_retourner_menu_prec);
							if (choix_retourner_menu_prec!=0) choix_retourner_menu_prec=1;
							else {sortir=1;
								retourner_menu_formateur=0;}
							break;}
							
						case (8):{		//creer une formation de formateur 
						
							Lisformation=insererformation(Lisformation,creer_donnee_formation_enseigner(niveau,frm1,idformation),&frm1);
							strcpy(idformation,idclssegenerateur(idformation));
							frm1->datas->nbrformation_ens++;
							frm1->datas->nbrformation_ens_total++;
						printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent : ");
						scanf("%d",&choix_retourner_menu_prec);
						if (choix_retourner_menu_prec==0) {sortir=1;
							retourner_menu_formateur=0;}
						else retourner_menu_formateur=1;
							break;}
			
						case (9):{				//supprimer formation
							Lisformation=supprimer_formation(Lisformation,&frm1);
							printf("veuillez entrer 0 pour quitter le programme,ou 1 revenir au menu précedent: ");
							scanf("%d",&choix_retourner_menu_prec);
							if (choix_retourner_menu_prec!=0) choix_retourner_menu_prec=1;
							else {sortir=1;
								retourner_menu_formateur=0;}
							break;}

						case (10):{
						if (frm1->datas->nbrclasse_ens_total<4) printf("veuillez créer au moins 4 classes\n");
						else {			//SI il a cree une 4 formation normal
							if(frm1->datas->nbrformation_etd_total==0){
								printf("veuillez suivre tous d'abord une formartion\n");}
									// si il a suivit une formation d'accréditation
							else{
								if(frm1->datas->nbrformation_ens_total==0){
									printf("veuillez enseigner tous d'abord 3 formartion\n");}
								else{
									if (frm1->datas->nbrformation_ens_total<3){printf("veuillez enseigner encore %d formartions\n",3-frm1->datas->nbrformation_ens_total);}
									else{frm1->datas->niveau++;
										passer_niveau_sup=1;
										choix_retourner_menu_prec=3;}
									
									}
							}
						}
						printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent : ");
						scanf("%d",&choix_retourner_menu_prec);
						if (choix_retourner_menu_prec==0) choix_retourner_menu_prec=7;
						else sortir=1;
						break;
						}}
				system("clear");
				}while(choix_retourner_menu_prec==1);
			}

////////	NIVEAU 3

			else if(niveau==3){
				do{	choix_retourner_menu_prec=1;
					choix=menu_formateur_niveau3();
					switch(choix){
						case (0):{sortir=1;
							choix_retourner_menu_prec=0;
							retourner_menu_formateur=0;break;}			//Quitter le programme

						case (11):{choix_retourner_menu_prec=changer_donnee_formateur(&frm1);
							break;}							//changer les données

						case (10):{afficher_1_formateur(frm1);
							printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent: ");
						scanf("%d",&choix_retourner_menu_prec); 							break;}							//Afficher les données

						case (1):{choix_retourner_menu_prec=0;
							retourner_menu_formateur=1;
							break;}

						case (2):{				//créer classe
							Lisclasse=insererclasse(Lisclasse,creerclasse(niveau,frm1,idclasse));
							strcpy(idclasse,idclssegenerateur(idclasse));
							if(strcmp(Lisclasse->datas->typeclasse,type_normal)==0)
							frm1->datas->nbrclasse_ens++;
							frm1->datas->nbrclasse_ens_total++;
							nbrclasse++;
							printf("veuillez entrer 0 pour quitter le programme,ou 1 revenir au menu précedent: ");
							scanf("%d",&choix_retourner_menu_prec);
							if (choix_retourner_menu_prec==1) choix_retourner_menu_prec=1;
							else {sortir=1;
								retourner_menu_formateur=0;}
							break;}	

						case (3):{				//supprimmer classe
							Lisclasse=supprimer_classe(Lisclasse,&frm1);
							printf("veuillez entrer 0 pour quitter le programme,ou 1 revenir au menu précedent: ");
							scanf("%d",&choix_retourner_menu_prec);
							if (choix_retourner_menu_prec!=0) choix_retourner_menu_prec=1;
							else {sortir=1;
								retourner_menu_formateur=0;}
							break;}
						case (4):{
							char idclasse1[20];
							if(afficher_classe_disponible(Lisclasse,frm1,type_accreditation)==1){
								printf("Donner le id de la classe: ");
								scanf("%s",idclasse1);
								Lisclasse=suivre_classe(Lisclasse,&frm1,idclasse);}	
							printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent: ");
							scanf("%d",&choix_retourner_menu_prec);
							if (choix_retourner_menu_prec==0) {sortir=1;
								retourner_menu_formateur=0;}
							else retourner_menu_formateur=1;
							break;}

						case (5):{				//désinscrire classe
							Lisclasse=desinscrire_classe(Lisclasse,&frm1,type_accreditation);
							printf("veuillez entrer 0 pour quitter le programme,ou 1 revenir au menu précedent: ");
							scanf("%d",&choix_retourner_menu_prec);
							if (choix_retourner_menu_prec!=0) choix_retourner_menu_prec=1;
							else {sortir=1;
								retourner_menu_formateur=0;}
							break;}

						
						case (6):{ 		//suivre une formation d'accreditation
							char idformation1[20];
							if(afficher_formation_disponible(Lisformation,frm1,type_accreditation)==1){
							printf("Donner l'id de la formation: ");
							scanf("%s",idformation1);
							
							Lisformation=suivre_formation(Lisformation,&frm1,idformation1,type_accreditation);}
							printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent: ");
						scanf("%d",&choix_retourner_menu_prec);
						if (choix_retourner_menu_prec==0) {sortir=1;
							retourner_menu_formateur=0;}
						else retourner_menu_formateur=1;
							break;}
			
						case (7):{				//désinscrire formation
							Lisformation=desinscrire_formation(Lisformation,&frm1,type_accreditation);
							printf("veuillez entrer 0 pour quitter le programme,ou 1 revenir au menu précedent: ");
							scanf("%d",&choix_retourner_menu_prec);
							if (choix_retourner_menu_prec!=0) choix_retourner_menu_prec=1;
							else {sortir=1;
								retourner_menu_formateur=0;}
							break;}
						case (8):{		//creer une formation de formateur tuteur(de niveau 1)
						
							Lisformation=insererformation(Lisformation,creer_donnee_formation_enseigner(niveau,frm1,idformation),&frm1);
							strcpy(idformation,idclssegenerateur(idformation));
							frm1->datas->nbrformation_ens++;
							frm1->datas->nbrformation_ens_total++;
						printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent : ");
						scanf("%d",&choix_retourner_menu_prec);
						if (choix_retourner_menu_prec==0) {sortir=1;
							retourner_menu_formateur=0;}
						else retourner_menu_formateur=1;
							break;}
			
						case (9):{

						Lisformation=supprimer_formation(Lisformation,&frm1);
						printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent : ");
						scanf("%d",&choix_retourner_menu_prec);
						if (choix_retourner_menu_prec==0) choix_retourner_menu_prec=7;
						else sortir=1;
						break;
						}}
			system("clear");
			}while(choix_retourner_menu_prec==1);
			}
			system("clear");
			}while(passer_niveau_sup==1);
			}
			system("clear");
			}while(retourner_menu_formateur==1);			
		break;}

	case 2:			//Cas de condidat
		{
		int retourner_menu_candidat=0;
		do{
		system("clear");
		retourner_menu_candidat=0;
		choix=menu_candidat1();
		cdd1=NULL;
		if(choix==0){sortir=1;
				retourner_menu_candidat=1;}
		else if (choix==3){sortir=0;
				retourner_menu_candidat=1;}
		else if (choix==1){
			char code[20],login[20];
			int choix_repeter=1;
			do{
			printf("Entrer votre login: ");
			scanf("%s",login);
			printf("Entrer votre code et '0' si vous l'avez perdu :");
			scanf("%s",code);
			if (code=="0")			//Si il a oublié le code
				{char mail[50];
				printf("Entrer votre email :");
				scanf("%s",mail);
				cdd1=recherchecandidatmail(cdd,login,mail); 		//rechercher la case memoire qui contient les données 												par mail
				if (cdd1!=NULL) printf("votre login (CIN) est: %s\nvotre code est: %s",frm1->datas->login,frm1->datas->code);}
			else cdd1=recherchecandidatcode(cdd,login,code);		//rechercher la case memoire qui contient les données 												par code
			if(cdd1==NULL) {printf("Pour réssayer entrer '0', et autre nombre pour revenir au menu précédent: ");
					scanf("%d",&choix_repeter);
			if(choix_repeter!=0)retourner_menu_candidat=1; }
			system("clear");
			}while(choix_repeter==0);}
		else if(choix==2){			//s'incrire
			cdd=inserercandidat(cdd);
			printf("veuillez retenir votre login et code afin d'acceder à vos donner quand vous voulez\n");
			nbrcandidat++;
			cdd1=cdd; //on insére chaque nouveau formateur en tete de liste chainée
			}
		if (cdd1!=NULL){
			system("clear");
			int choixmenu_candidat=0,retourner_menu_candidat1=1;
			do{
			choixmenu_candidat=menu_candidat();
			switch(choixmenu_candidat){
				case (0):{
					sortir=1;
					retourner_menu_candidat1=0;
					retourner_menu_candidat=1;
					break;}			//Quitter le programme

				case (7):{
					retourner_menu_candidat1=changer_donnee_candidat(&cdd1);
					break;}							//changer les données

				case (6):{
					afficher_1_candidat(cdd1);
					printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent: ");
					scanf("%d",&retourner_menu_candidat1);
					if(retourner_menu_candidat1==0){
						sortir=1;
						retourner_menu_candidat=1;}
					break;}		//Afficher les données

				case (1):{
					sortir=0;
					retourner_menu_candidat=0;
					retourner_menu_candidat1=0;
					break;}
				case (2):{
					char idclasse1[20];
					if(afficher_classe_disponible_candidat(Lisclasse,cdd1)==1){
					printf("Donner le id de la classe: ");
					scanf("%s",idclasse1);
					Lisclasse=suivre_classe_candidat(Lisclasse,&cdd1,idclasse);}
					printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent: ");
					scanf("%d",&retourner_menu_candidat1);
					if(retourner_menu_candidat1==0){
						sortir=1;
						retourner_menu_candidat=1;}
					break;}
				case (3):{
					Lisclasse=desinscrire_classe_candidat(Lisclasse,&cdd1);
					printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent: ");
					scanf("%d",&retourner_menu_candidat1);
					if(retourner_menu_candidat1==0){
						sortir=1;
						retourner_menu_candidat=1;}
					break;}
				case (4):{
					char idformation1[20];
					if(afficher_formation_disponible_candidat(Lisformation,cdd1)==1){
					printf("Donner l'id de la formation: ");
					scanf("%s",idformation1);
						
					Lisformation=suivre_formation_candidat(Lisformation,&cdd1,idformation1);}
					printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent: ");
					scanf("%d",&retourner_menu_candidat1);
					if(retourner_menu_candidat1==0){
						sortir=1;
						retourner_menu_candidat=1;}
					break;}
				case (5):{
					Lisformation=desinscrire_formation_candidat(Lisformation,&cdd1);
					printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent: ");
					scanf("%d",&retourner_menu_candidat1);
					if(retourner_menu_candidat1==0){
						sortir=1;
						retourner_menu_candidat=1;}
					break;}
				}
			system("clear");
			}while(retourner_menu_candidat1!=0);
			}
		system("clear");
		}while(retourner_menu_candidat==0);
			break;}
	case 3:			//Cas d'administrateur
		{int choixadmin,p;
		char *login,*code;
		login=malloc(20*sizeof(char));
		code=malloc(20*sizeof(char));
		printf("donner votre login: ");
		scanf("%s",login);
		printf("donner votre code: ");
		scanf("%s",code);
		p=rechercheradm(adm,login,code);
		if (p==1)
			{do{
			system("clear");
			choixadmin=menu_administrateur();
			switch (choixadmin){choix=0;
				case 2:{	//afficher tous les formateurs
					afficher_Tous_formateur(frm);
					printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent : ");
					scanf("%d",&choix);
					if (choix==0) {sortir=1;}
					else choix=1;
					break;}
				case 3:{	//afficher formateurs de niveau 1
					afficher_Tous_formateur_nv1(frm);
					printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent : ");
					scanf("%d",&choix);
					if (choix==0) {sortir=1;}
					else choix=1;
					break;}
				case 4:{	//afficher formateurs de niveau 2
					afficher_Tous_formateur_nv2(frm);
					printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent : ");
					scanf("%d",&choix);
					if (choix==0) {sortir=1;}
					else choix=1;
					break;}
				case 5:{	//afficher formateurs de niveau 3
					afficher_Tous_formateur_nv3(frm);
					printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent : ");
					scanf("%d",&choix);
					if (choix==0) {sortir=1;}
					else choix=1;
					break;}
				case 6:{	//chercher formateur par login
					char login1[20];
					printf("donner le login de la personne que vous chercher : ");
					scanf("%s",login1);
					rechercher_formateur_par_login(frm,login1);
					printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent : ");
					scanf("%d",&choix);
					if (choix==0) {sortir=1;}
					else choix=1;
					break;}
				case 7:{	//afficher formation d'accréditation
					afficher_Formation_Accreditation(Lisformation);
					printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent : ");
					scanf("%d",&choix);
					if (choix==0) {sortir=1;}
					else choix=1;
					break;}
				case 8:{	//afficher formation normal
					afficher_Formation_Normal(Lisformation);
					printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent : ");
					scanf("%d",&choix);
					if (choix==0) {sortir=1;}
					else choix=1;
					break;}
				case 9:{	//supprimer un formateur
					char login1[20];
					printf("donner le login du formateur que vous voulez supprimer : ");
					scanf("%s",login1);
					frm=supprimerformateur(frm,login1);
					if (nbrformateur>0) nbrformateur--;
					printf("veuillez entrer 0 pour quitter le programme ou 1 revenir au menu précedent : ");
					scanf("%d",&choix);
					if (choix==0) {sortir=1;}
					else choix=1;
					break;}
				case 10:{	//supprimer une formation
					break;}
				case 11:{	//Ajouter un autre administrateur
					adm=ajouteradmin(adm,creerdataadmin());
					nbradmin++;
					break;}
				case 1:{	//se déconnecter
					sortir=0;
					choix=0;
					p=0;
					break;}
				case 0:{	//sortir
					sortir=1;
					choix=0;
					break;}
			}
			system("clear");
			}while(choix==1);
		}
		else if (p==0) sortir=0;
		break;}
	case 0:				//quitter
		{sortir=1;}
	}
	system("clear");
	}while(sortir==0);
	sauvegarde_formateur("formateur.dta",frm,nbrformateur);
	//sauvegarde_candidat("candidat.dta",cdd,nbrcandidat);
	sauvegarde_classe("classes.dta",Lisclasse,nbrclasse);
	sauvegarde_admins("admins.dta",adm,nbradmin);
	sauvegarde_formation("formation.dta",Lisformation,nbrformation);
	sauvegarde_login("logins.dta",logins,nbrlogins);
	
return 0;}
