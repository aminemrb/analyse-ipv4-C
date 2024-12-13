/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet : SUJET 2                                                             *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : ANALYSE ADRESSE IP                                                           *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom : MOURABIT Amine                                                          *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier :  analyse_ip.c                                                         *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "analyse_ip.h"

// Fonction pour vérifier le format de l'adresse IP et du masque
int verifier_format(const char *ip_avec_masque) {
    int nb_slash = 0;
    int octet1, octet2, octet3, octet4;
    
    if (sscanf(ip_avec_masque, "%d.%d.%d.%d/%d", &octet1, &octet2, &octet3, &octet4, &nb_slash) != 5) {
        return 0; // Format incorrect
    }
    
    if (octet1 < 0 || octet1 > 255 ||
        octet2 < 0 || octet2 > 255 ||
        octet3 < 0 || octet3 > 255 ||
        octet4 < 0 || octet4 > 255) {
        return 0; // Octet invalide
    }
    
    return 1; // Format valide
}

// Fonction pour extraire l'adresse IP et le masque à partir de la chaîne d'entrée
int extraire_champs(const char *ip_avec_masque, char *ip, int *masque) {
    if (sscanf(ip_avec_masque, "%[^/]/%d", ip, masque) != 2) {
        return 0; // Erreur lors de l'extraction des champs
    }
    // Vérification du masque
    if (*masque < 0 || *masque > 32) {
        return 0; // Masque invalide
    }
    return 1;
}

// Fonction pour décoder l'adresse IP et déterminer sa classe et son type
// Fonction pour décoder l'adresse IP et déterminer sa classe et son type
void decoder_ip(const char *ip, char *classe_ip, char *type_ip) {
    int premier_octet, deuxieme_octet, troisieme_octet, quatrieme_octet;
    sscanf(ip, "%d.%d.%d.%d", &premier_octet, &deuxieme_octet, &troisieme_octet, &quatrieme_octet);

    if (premier_octet >= 0 && premier_octet <= 127) {
        *classe_ip = 'A';
    } else if (premier_octet >= 128 && premier_octet <= 191) {
        *classe_ip = 'B';
    } else if (premier_octet >= 192 && premier_octet <= 223) {
        *classe_ip = 'C';
    } else if (premier_octet >= 224 && premier_octet <= 239) {
        *classe_ip = 'D';
    } else {
        *classe_ip = 'E';
    }

    if (premier_octet == 10 ||
        (premier_octet == 172 && deuxieme_octet >= 16 && deuxieme_octet <= 31) ||
        (premier_octet == 192 && deuxieme_octet == 168)) {
        strcpy(type_ip, "Privee");
    } else if (premier_octet == 127 && deuxieme_octet == 0 && troisieme_octet == 0 && quatrieme_octet == 1) {
        strcpy(type_ip, "Localhost");
    } else if (premier_octet >= 224 && premier_octet <= 239) {
        strcpy(type_ip, "Multicast");
    } else {
        strcpy(type_ip, "Publique");
    }
}


// Fonction pour convertir l'adresse IP en valeurs numériques
void convertir_en_numerique(const char *ip, int ip_numerique[4]) {
    sscanf(ip, "%d.%d.%d.%d", &ip_numerique[0], &ip_numerique[1], &ip_numerique[2], &ip_numerique[3]);
}

// Fonction pour calculer les adresses réseau et hôte
void calculer_reseau_hote(const char *ip, int masque, int *reseau, int *hote) {
    int ip_numerique[4];
    convertir_en_numerique(ip, ip_numerique );

    // Convertir l'IP en une valeur binaire unique
    unsigned long ip_binaire = (ip_numerique[0] << 24) | (ip_numerique[1] << 16) | (ip_numerique[2] << 8) | ip_numerique[3];
    
    // Créer le masque binaire correspondant à la longueur du masque CIDR
    unsigned long masque_binaire = (0xFFFFFFFF << (32 - masque)) & 0xFFFFFFFF;

    // Calculer l'adresse réseau : appliquer un ET binaire entre l'IP et le masque
    *reseau = ip_binaire & masque_binaire;

    // Calculer l'adresse hôte : appliquer un NON binaire entre l'IP et le masque
    *hote = ip_binaire & ~masque_binaire;
}


// Fonction pour afficher l'adresse IP en format pointé
void afficher_ip(unsigned long ip) {
    printf("%lu.%lu.%lu.%lu\n",
           (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF);
}

// Fonction pour convertir le masque CIDR en notation décimale
void convertir_masque(int masque_cidr, unsigned char masque_dec[4]) {
    unsigned long masque_binaire = (0xFFFFFFFF << (32 - masque_cidr)) & 0xFFFFFFFF;
    masque_dec[0] = (masque_binaire >> 24) & 0xFF;
    masque_dec[1] = (masque_binaire >> 16) & 0xFF;
    masque_dec[2] = (masque_binaire >> 8) & 0xFF;
    masque_dec[3] = masque_binaire & 0xFF;
}

// Fonction pour enregistrer les données dans un fichier
void enregistrer_donnees(const char *filename, const char *ip, int masque, char classe_ip, const char *type_ip, int reseau, int hote) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return;
    }

    unsigned char masque_dec[4];
    convertir_masque(masque, masque_dec);

    fprintf(file, "Adresse IP : %s, Masque : %d (%u.%u.%u.%u)\n",
            ip, masque, masque_dec[0], masque_dec[1], masque_dec[2], masque_dec[3]);
    fprintf(file, "Classe IP : %c, Type IP : %s\n", classe_ip, type_ip);
    fprintf(file, "Adresse reseau : %u.%u.%u.%u\n",
            (reseau >> 24) & 0xFF, (reseau >> 16) & 0xFF, (reseau >> 8) & 0xFF, reseau & 0xFF);
    fprintf(file, "Adresse hote : %u.%u.%u.%u\n",
            (hote >> 24) & 0xFF, (hote >> 16) & 0xFF, (hote >> 8) & 0xFF, hote & 0xFF);
    fclose(file);
}

int main() {
    char ip_avec_masque[20];
    char ip[16];
    int masque;
    char classe_ip;
    char type_ip[10];
    int reseau, hote;

    printf("Entrez l'adresse IP avec CIDR (par exemple, 192.168.1.1/24) : ");
    scanf("%19s", ip_avec_masque);

    if (!verifier_format(ip_avec_masque)) {
        printf("Le format de l'adresse IP est invalide\n");
        return 1;
    }

    if (!extraire_champs(ip_avec_masque, ip, &masque)) {
        printf("Le format du masque est invalide\n");
        return 1;
    }

    decoder_ip(ip, &classe_ip, type_ip);
    calculer_reseau_hote(ip, masque, &reseau, &hote);

    // Affichage des résultats
    unsigned char masque_dec[4];
    convertir_masque(masque, masque_dec); // Conversion en notation décimale
    printf("Adresse IP : %s, Masque : %d (%u.%u.%u.%u)\n",
            ip, masque, masque_dec[0], masque_dec[1], masque_dec[2], masque_dec[3]);
    printf("Classe IP : %c, Type IP : %s\n", classe_ip, type_ip);
    printf("Adresse reseau : ");
    afficher_ip(reseau);
    printf("Adresse hote : ");
    afficher_ip(hote);

    // Enregistrement dans un fichier
    enregistrer_donnees("resultats.txt", ip, masque, classe_ip, type_ip, reseau, hote);

    return 0;
}
