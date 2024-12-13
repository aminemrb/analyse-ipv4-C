SUJET 2 : ANALYSE D'ADRESSE IP

URL DEPOT GIT : https://gitlab.info.iut-tlse3.fr/mrm4917a/sujet2_mourabit_mirepoix/-/blob/main/README.md?ref_type=heads

RÉALISÉ PAR :  Amine MOURABIT & Walid MIREPOIX (Groupe D)


OBJECTIF : Ce projet a pour objectif de développer une application permettant d'analyser une adresse IP et son masque réseau. L'application détermine la classe de l'adresse IP, son type (privée ou publique), ainsi que les adresses réseau et hôte correspondantes.




DOCUMENTATION DES FONCTIONS ET CAS D'ERREUR

1. verifier_format :
    Cette première fonction permet de vérifier si le format de l'adresse IP avec le masque (CIDR) est valide. Elle prend en entréé la chaîne de caractère saisie par l'utilisateur et renvoi "1" si le format et valide et "0" si non.
    Elle renvoi "0" si la notation CIDR n'est pas respectée et si chaque octet de l'adresse IP est bien compris entre 0 et 255

2. extraire_champs :
    Cette fonction permet d'extraire l'adresse IP et le masque à partir de la chaîne de caractère entrée par l'utilisateur. Elle prend en paramètre d'entrée la chaîne de caractère saisie, la chaîne de caractère de la partie IP et celle du masque et renvoie "1" si l'extraction est réussite.
    La fonction renvoie "0" si le format du masque est invalide et si le masque est compris entre 0 et 32.

3. decoder_ip :
    Cette fonction détermine la classe et le type de l'adresse IP entrée. Elle prend en paramètre la chaîne de caractère IP, classe et type. Elle ne renvoie rien (void).
    Il n'y a pas de cas erreur.

4. convertir_en_numerique :
    Cette fonction convertit l'adresse IP en valeurs numériques. Elle prend en entrée la chaîne de caractère IP et l'entier ip_numerique[4]

5. calculer_reseau_hote :
    Cette fonction calcule les adresses réseau et hôte à partir de l'adresse IP et du masque. Elle prend en entrée la chaîne IP, l'entier masque/réseau/hôte. Elle ne renvoie rien (void).
    Il n'y a pas de cas erreur.

6. afficher_ip :
    Cette fonction permet d'afficher l'adresse ip en format pointé. Elle prend en entrée l'entier non signée ip. Elle ne renvoie rien (void).
    Il n'y a pas de cas erreur.

7. enregistrer_donnees :
    Enfin, cette fonction permet d'enregistrer les données de l'adresse IP (valide) que l'utilisateur rentre, c'est à dire ce que renvoi la fonction main est directement enregistrer dans ce fichier. De plus, le Makefile permet de supprimer ce fichier lorsqu'on utilise "make clean". Elle ne renvoie rien (void).
    Une erreur ce déclanche si le fichier ne s'ouvre pas.

8. main :
    L'utilisateur compile le fichier "analyse_ip.c" avec le Makefile (commande "make") puis l'exécute avec "./analyse_ip". Ensuite, il est demandé à l'utilsateur de saisie sa chaîne de caractère conforme à la notation CIDR (cas d'erreur si cela n'est pas respeté).
    En sortie de programme, s'affiche les différentes caractéristiques de l'adresse IP (adresse IP saisie, masque saisie, classe, type, adresse reseau/hôte) saisie par l'utilisateur. S'affiche également "ip invalide" si la fonction verifier_format échoue et affiche "masque invalide" si la fonction extraire_champs échoue.
