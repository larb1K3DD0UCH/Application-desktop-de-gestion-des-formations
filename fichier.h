typedef struct _listelogin{
	char login[20];
	struct _listelogin *suivant;
}listelogin;
///////////////////////////////////////Structeur formateur/////////////////////////////////
typedef struct _formationense{
	char nomformation[20],idformation[20],typeformation[20];
	struct _formationense *suivant;
}formationEnse;

typedef struct _classeAcc{
	char idclasse[20],nomclasse[20],typeclasse[20];
	struct _classeAcc *suivant;
}classeAcc;

typedef struct _data{
	char nom[20],prenom[30],etablissement[100],login[20],code[20],mail[30],pays[20];		
	int niveau,nbrclasse_ens,nbrclasse_etd,nbrclasse_ens_total,nbrclasse_etd_total;
	int nbrformation_ens,nbrformation_etd,nbrformation_ens_total,nbrformation_etd_total;
	classeAcc *classe_enseigner,*classe_accreditation_etudier;
	formationEnse *formation_enseigner,*formation_accreditation_etudier;	
}data;

typedef struct _formateurs{
	data *datas;
	struct _formateurs *suivant;
}formateurs;
////////////////////////////////////////Administrateur////////////////////////////////////
typedef struct _data_admin{
	char login[20],code[20];
}data_admin;

typedef struct _admins{
	data_admin *datas;
	struct _admins *suivant;
}admins;
////////////////////////////////////////Structure classe//////////////////////////////////
typedef struct _classe{
	char typeclasse[20],nomclasse[20],idclasse[20];		//nomclasse: ce qu'on va etudier a cette classe(langage C,JAVA,...)
							//typeclasse=accréditation (si elle est didié au formateur)
							//typeclasse=Normal (si elle est didié au candidat)
	int nbreleve;
	char login[20];
}classe;

typedef struct _listeclasse{
	classe *datas;
	struct _listeclasse *suivant;
}listeclasse;


////////////////////////////////////////Structure formation//////////////////////////////////
typedef struct _dataformation{
	char nomformation[40],typeformation[20],idformation[20];	
	int nbrformateur;
	char login[20];
}dataformation;

typedef struct _formations{
	dataformation *datas;
	struct _formations *suivant;
}formations;
//////////////////////////////////////////////////////////////////////////////////////////
typedef struct _formationNormal{
	char nomformation[20],idformation[20];
	struct _formationNormal *suivant;
}formationNormal;

typedef struct _classeNormal{
	char idclasse[20],nomclasse[20];
	struct _classeNormal *suivant;
}classeNormal;

typedef struct _datacandidat{
	char nom[20],prenom[20],code[20],mail[30];	
	int nbrclasse_suivi,nbrformation_suivi;
	char login[20];
	classeNormal *classe_Normal_etudier;
	formationNormal *formation_Normal_etudier;
}datacandidat;

typedef struct _candidat{
	datacandidat *datas;
	struct _candidat *suivant;
}candidat;
//////////////////////////////////////////////////////////////////////////////////////////

int rechercheloginexiste(listelogin *tete,char *login);

listelogin *inserelogin(listelogin *tete,char *login);

listelogin *charge_login(int *nbrlogins);

void sauvegarde_login(char *nom,listelogin *logins,int nbrlogins);
////////////////////////////////////////////////////////////////////////////////////

formations  *insererformation(formations *tete,dataformation *infos,formateurs **frm);

formations  *insererformation_fichier(formations *tete,dataformation *infos);

dataformation *creer_donnee_formation_enseigner(int niveau,formateurs *frm,char *idformation);

int afficher_formation_disponible(formations *tete,formateurs *frm,char *typeformation);

int afficher_formation_disponible_candidat(formations *tete,candidat *cdd);

formations *suivre_formation(formations *tete,formateurs **frm,char *idformation,char *typeformation);

formations *suivre_formation_candidat(formations *tete,candidat **cdd,char *idformation);

formations *desinscrire_formation(formations *tete,formateurs **frm,char *typeformation);

formations *desinscrire_formation_candidat(formations *tete,candidat **cdd);

formations *supprimer_formation(formations *tete,formateurs **frm);

formations *charge_formation(int *nbrformation);

void sauvegarde_formation(char *nom,formations *tete,int nbrformation);
/////////////////////////////////////////////////////////////////////////////////////////////
candidat *recherchecandidatcode(candidat *tete,char *login,char *c);

candidat *recherchecandidatmail(candidat *tete,char *login,char *mail);

candidat *inserercandidat(candidat *tete);

void afficher_1_candidat(candidat *tete);

int changer_donnee_candidat(candidat **tete);

char *idclssegenerateur(char *c);
////////////////////////////////////////Fonctions Classe/////////////////////////////////////
classe *creerclasse(int niveau,formateurs *frm,char *idclasse);

listeclasse *insererclasse(listeclasse *tete,classe *infos);

int afficher_classe_disponible(listeclasse *tete,formateurs *frm,char *typeclasse);

listeclasse *suivre_classe(listeclasse *tete,formateurs **frm,char *idclasse);

int afficher_classe_disponible_candidat(listeclasse *tete,candidat *cdd);

listeclasse *suivre_classe_candidat(listeclasse *tete,candidat **cdd,char *idclasse);

listeclasse *desinscrire_classe(listeclasse *tete,formateurs **frm,char *typeclasse);
	
listeclasse *desinscrire_classe_candidat(listeclasse *tete,candidat **cdd);

listeclasse *supprimer_classe(listeclasse *tete,formateurs **frm);

listeclasse *charge_classe(int *nbrclasse);

void sauvegarde_classe(char *nom,listeclasse *tete,int nbrclasse);
////////////////////////////////////////Fonctions Formations/////////////////////////////////////
dataformation *creer_donnee_formation_etudier(int niveau,formateurs *frm);

dataformation *creer_donnee_formation_enseigner(int niveau,formateurs *frm,char *idformation);

formations *inserer_formation(listeclasse *tete,dataformation *infos);

////////////////////////////Fonctions charge/sauvegarde Formateur////////////////////////////
formateurs *charge_formateur();
	
void sauvegarde_formateur(char *nom,formateurs *tete,int nbrformateur);	
	
data *creerdata_fichier(char *nom,char *prenom,char *etablissement,char *login,char *code,char *mail,char *pays,int niveau,int nbrclasse_ens,int nbrclasse_etd,int nbrformation_ens,int nbrformation_etd,int nbrclasse_ens_total,int nbrclasse_etd_total,int nbrformation_ens_total,int nbrformation_etd_total,classeAcc *classe_enseigner,classeAcc *classe_accreditation_etudier,formationEnse *formation_enseigner,formationEnse *formation_accreditation_etudier);

formateurs *insererformateur_fichier(formateurs *tete,data *infos);	

classeAcc *creerdata_classe(char *nomclasse,char *idclasse,char *typeclasse);

classeAcc *insererclasse_frm(classeAcc *tete,classeAcc *infos);

formationEnse *creerdata_formation(char *nomformation,char *idformation,char *typeformation);

formationEnse *insererformation_frm(formationEnse *tete,formationEnse *infos);

/////////////////////////////////////Fonction Formateur//////////////////////////////////////

data *creerdata(listelogin *tete);

formateurs *insererformateur(formateurs *tete,listelogin **tetelogins);

formateurs *recherchefrmcode(formateurs *tete,char *login,char *c);

formateurs *recherchefrmmail(formateurs *tete,char *login,char *m);

int changer_donnee_formateur(formateurs **tete);

void afficher_1_formateur(formateurs *tete);

////////////////////////////////////Fonction Administrateur////////////////////////////////
admins *initialiseradmins();

int rechercheradm(admins *adm,char *login,char *code);

void afficher_1_formateur_pour_admin(formateurs *tete);

void afficher_Tous_formateur(formateurs *tete);

void afficher_Tous_formateur_nv1(formateurs *tete);

void afficher_Tous_formateur_nv2(formateurs *tete);

void afficher_Tous_formateur_nv3(formateurs *tete);

void rechercher_formateur_par_login(formateurs *tete,char *login);

void afficher_1_formation_pour_admin(formations *tete);

void afficher_Formation_Accreditation(formations *tete);

void afficher_Formation_Normal(formations *tete);

formateurs *supprimerformateur(formateurs *tete,char *login);

/////////////////////////////////////////Les Menus////////////////////////////////////////
int menu_princ();

int menu_formateur1();

int menu_formateur_niveau1();

int menu_formateur_niveau2();

int menu_formateur_niveau3();

int menu_changer_donner();

int menu_administrateur();

int menu_changer_donner_cdd();
///////////////////////////////////////////////////////////////////////////////////////////////
data_admin *creerdataadmin();

data_admin *creerdataadmin_fichier(char *login,char *code);

admins *ajouteradmin(admins *tete,data_admin *infos);

admins *chargeadmin(int *nbradmin);

void sauvegarde_admins(char *nom,admins *tete,int nbradmin);
