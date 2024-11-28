#include <iostream>
#include <fstream>
#include <vector>
#include "../include/gestionProduits.h"

// Global product list (used for example purpose)
std::vector<Produit> produits;

// Ajouter un produit
void ajouterProduit() {
    Produit produit;
    std::cout << "Nom du produit : ";
    std::cin.ignore(); // Pour ignorer les caractères résiduels
    std::getline(std::cin, produit.nom);
    std::cout << "Description : ";
    std::getline(std::cin, produit.description);
    std::cout << "Prix : ";
    std::cin >> produit.prix;
    std::cout << "Quantité : ";
    std::cin >> produit.quantite;

    produits.push_back(produit);
    sauvegarderProduits();  // Sauvegarde après ajout
    std::cout << "Produit ajouté avec succès !\n";
}

// Modifier un produit
void modifierProduit() {
    std::string nom;
    std::cout << "Nom du produit à modifier : ";
    std::cin.ignore();
    std::getline(std::cin, nom);

    for (auto &produit : produits) {
        if (produit.nom == nom) {
            std::cout << "Modifier description : ";
            std::getline(std::cin, produit.description);
            std::cout << "Modifier prix : ";
            std::cin >> produit.prix;
            std::cout << "Modifier quantité : ";
            std::cin >> produit.quantite;
            sauvegarderProduits();  // Sauvegarde après modification
            std::cout << "Produit modifié avec succès !\n";
            return;
        }
    }
    std::cout << "Produit non trouvé.\n";
}

// Supprimer un produit
void supprimerProduit() {
    std::string nom;
    std::cout << "Nom du produit à supprimer : ";
    std::cin.ignore();
    std::getline(std::cin, nom);

    for (auto it = produits.begin(); it != produits.end(); ++it) {
        if (it->nom == nom) {
            produits.erase(it);
            sauvegarderProduits();  // Sauvegarde après suppression
            std::cout << "Produit supprimé avec succès !\n";
            return;
        }
    }
    std::cout << "Produit non trouvé.\n";
}

// Rechercher un produit
void rechercherProduit() {
    std::string nom;
    std::cout << "Nom du produit à rechercher : ";
    std::cin.ignore();
    std::getline(std::cin, nom);

    for (const auto &produit : produits) {
        if (produit.nom == nom) {
            std::cout << "Nom: " << produit.nom << ", Description: " << produit.description
                      << ", Prix: " << produit.prix << ", Quantité: " << produit.quantite << "\n";
            return;
        }
    }
    std::cout << "Produit non trouvé.\n";
}

// Sauvegarder les produits dans un fichier
void sauvegarderProduits() {
    std::ofstream fichier("data/produits.txt", std::ios::trunc);
    if (fichier) {
        for (const auto &produit : produits) {
            fichier << produit.nom << "," << produit.description << ","
                    << produit.prix << "," << produit.quantite << "\n";
        }
        fichier.close();
    } else {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier produits.txt\n";
    }
}

// Charger les produits depuis le fichier
void chargerProduits() {
    std::ifstream fichier("data/produits.txt");
    if (fichier) {
        std::string ligne;
        while (std::getline(fichier, ligne)) {
            Produit produit;
            size_t pos = 0;
            pos = ligne.find(",");
            produit.nom = ligne.substr(0, pos);
            ligne.erase(0, pos + 1);

            pos = ligne.find(",");
            produit.description = ligne.substr(0, pos);
            ligne.erase(0, pos + 1);

            pos = ligne.find(",");
            produit.prix = std::stod(ligne.substr(0, pos));
            produit.quantite = std::stoi(ligne.substr(pos + 1));

            produits.push_back(produit);
        }
        fichier.close();
    } else {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier produits.txt\n";
    }
}

// Enregistrer une vente
void enregistrerVente() {
    int id;
    std::string nomProduit;
    int quantiteVendue;
    std::string date;

    std::cout << "ID de la vente : ";
    std::cin >> id;
    std::cout << "Nom du produit : ";
    std::cin.ignore();
    std::getline(std::cin, nomProduit);
    std::cout << "Quantité vendue : ";
    std::cin >> quantiteVendue;
    std::cout << "Date de la vente (format YYYY-MM-DD) : ";
    std::cin >> date;

    std::ofstream fichier("data/ventes.txt", std::ios::app);
    if (fichier) {
        fichier << id << "," << nomProduit << "," << quantiteVendue << "," << date << "\n";
        fichier.close();
        std::cout << "Vente enregistrée avec succès !\n";
    } else {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier ventes.txt\n";
    }
}

// Lister toutes les ventes
void listerVentes() {
    std::ifstream fichier("data/ventes.txt");
    if (fichier) {
        std::string ligne;
        std::cout << "\n--- Liste des ventes ---\n";
        while (std::getline(fichier, ligne)) {
            std::cout << ligne << "\n";
        }
        fichier.close();
    } else {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier ventes.txt\n";
    }
}
