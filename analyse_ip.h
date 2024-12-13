#ifndef ANALYSE_IP_H
#define ANALYSE_IP_H

// Fonction pour vérifier le format de l'adresse IP et du masque
int verifier_format(const char *ip_avec_masque);

// Fonction pour extraire l'adresse IP et le masque à partir de la chaîne d'entrée
int extraire_champs(const char *ip_avec_masque, char *ip, int *masque);

// Fonction pour décoder l'adresse IP et déterminer sa classe et son type
void decoder_ip(const char *ip, char *classe_ip, char *type_ip);

// Fonction pour convertir l'adresse IP en valeurs numériques
void convertir_en_numerique(const char *ip, int ip_numerique[4]);

// Fonction pour calculer les adresses réseau et hôte
void calculer_reseau_hote(const char *ip, int masque, int *reseau, int *hote);

// Fonction pour afficher l'adresse IP en format pointé
void afficher_ip(unsigned long ip);

//Fonction pour obtenir le masque de sous réseau
void convertir_masque(int masque_cidr, unsigned char masque_dec[4]);

#endif /* ANALYSE_IP_H */
