Analyse d'adresse IPv4

Description du projet

Ce projet a pour objectif de développer une application en langage C capable d'analyser une adresse IPv4 et son masque réseau selon la notation CIDR. L'application calcule et fournit les informations suivantes :

La classe de l'adresse IP.

Le type de l'adresse (privée ou publique).

Les adresses réseau et hôte correspondantes.

Ce projet inclut également des validations sur la syntaxe de l'adresse IP et du masque, ainsi qu'une fonctionnalité pour enregistrer les résultats dans un fichier.

Fonctionnalités principales

Vérification de la validité de l'adresse IP et du masque.

Extraction et traitement des champs de l'adresse IP et du masque.

Calcul de la classe et du type de l'adresse IP.

Conversion de l'adresse IP en format numérique.

Détermination des adresses réseau et hôte.

Affichage des résultats de manière claire.

Enregistrement des données dans un fichier.

Structure des fonctions

1. verifier_format

Description : Vérifie si l'adresse IP et le masque suivent une notation CIDR valide.

Paramètres :

Entrée : Chaîne de caractères (adresse IP avec masque).

Sortie : 1 si le format est valide, 0 sinon.

Cas d'erreur :

Format CIDR incorrect.

Valeurs des octets de l'adresse IP hors de l'intervalle [0, 255].

2. extraire_champs

Description : Extrait l'adresse IP et le masque de la chaîne d'entrée.

Paramètres :

Entrée : Chaîne de caractères (adresse IP et masque).

Sortie : Chaîne pour l'adresse IP, chaîne pour le masque, et 1 si réussi.

Cas d'erreur :

Masque invalide ou hors de l'intervalle [0, 32].

3. decoder_ip

Description : Détermine la classe (A, B, C, D, E) et le type (privé ou public) de l'adresse IP.

Paramètres :

Entrée : Chaîne de caractères pour l'adresse IP.

Sortie : Chaîne pour la classe et le type.

Cas d'erreur : Aucun.

4. convertir_en_numerique

Description : Convertit une adresse IP en format numérique.

Paramètres :

Entrée : Chaîne de caractères pour l'adresse IP.

Sortie : Tableau d'entiers contenant les valeurs numériques des octets.

Cas d'erreur : Aucun.

5. calculer_reseau_hote

Description : Calcule les adresses réseau et hôte en fonction de l'adresse IP et du masque.

Paramètres :

Entrée : Adresse IP et masque.

Sortie : Adresses réseau et hôte.

Cas d'erreur : Aucun.

6. afficher_ip

Description : Affiche une adresse IP au format décimal pointé.

Paramètres :

Entrée : Valeurs numériques de l'adresse IP.

Cas d'erreur : Aucun.

7. enregistrer_donnees

Description : Enregistre les résultats de l'analyse dans un fichier texte.

Paramètres : Aucun.

Cas d'erreur : Une erreur se produit si le fichier ne peut pas être ouvert.

8. main

Description :

Permet à l'utilisateur de saisir une adresse IP avec masque au format CIDR.

Affiche les résultats de l'analyse (classe, type, adresse réseau, adresse hôte).

Cas d'erreur :

Affiche « IP invalide » si verifier_format échoue.

Affiche « Masque invalide » si extraire_champs échoue.

Instructions d'utilisation

Compilation et exécution

Compilez le projet avec le Makefile fourni :

make

Exécutez le programme :

./analyse_ip

Saisie utilisateur

Saisissez une adresse IP avec son masque au format CIDR (par ex. 192.168.1.1/24).

Exemple de sortie

Adresse IP saisie : 192.168.1.1
Masque saisie : 24
Classe : C
Type : Privée
Adresse réseau : 192.168.1.0
Adresse hôte : 192.168.1.1

Fichiers du projet

analyse_ip.c : Code source principal.

Makefile : Fichier pour compiler et nettoyer le projet.

resultats.txt : Fichier généré contenant les résultats de l'analyse.

Améliorations possibles

Ajouter une interface graphique pour rendre l'application plus conviviale.

Supporter d'autres notations IP (par ex. notation décimale ou hexadécimale).

Ajouter une fonction pour analyser des plages d'adresses IP.

Auteur

Ce projet a été réalisé par [Votre Nom] dans le cadre d'un projet personnel de développement en C
