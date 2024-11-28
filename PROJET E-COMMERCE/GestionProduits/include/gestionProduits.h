#ifndef GESTION_PRODUITS_H
#define GESTION_PRODUITS_H

#include <string>

// Structure pour un produit
struct Produit {
    std::string nom;
    std::string description;
    double prix;
    int quantite;
};

// Structure pour une vente
struct Vente {
    int id;
    std::string nomProduit;
    int quantiteVendue;
    std::string date;
};

// Fonctions pour gérer les produits
void ajouterProduit();
void modifierProduit();
void supprimerProduit();
void rechercherProduit();
void afficherProduits();

// Fonctions pour gérer les ventes
void enregistrerVente();
void listerVentes();

// Fonctions pour sauvegarder et charger les données
void sauvegarderProduits();
void chargerProduits();

#endif
