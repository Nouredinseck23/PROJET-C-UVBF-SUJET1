#include <iostream>
#include <fstream>
#include <string>
#include "../include/gestionProduits.h"

/*
================================================================================
Système de Gestion d'Inventaire pour un Magasin
--------------------------------------------------------------------------------
Description :
Ce programme permet de gérer efficacement l'inventaire d'un magasin. Il offre
les fonctionnalités suivantes :
1. Ajouter un nouvel article avec nom, catégorie, prix et quantité.
2. Modifier les informations d'un article existant.
3. Supprimer un article du stock.
4. Rechercher des articles par nom.
5. Afficher tous les articles disponibles en stock avec leur quantité actuelle.
6. Enregistrer les transactions (ajout et retrait d'inventaire) dans un fichier
   de log pour assurer une traçabilité.
7. Sauvegarder et charger l'état de l'inventaire dans un fichier afin de
   maintenir la persistance des données entre les exécutions du programme.

Structure :
- **Menu Principal** : Permet à l'utilisateur de choisir une action.
- **Fonctions associées** :
  - `ajouterProduit()` : Ajouter un nouvel article.
  - `modifierProduit()` : Modifier un article existant.
  - `supprimerProduit()` : Supprimer un article.
  - `rechercherProduit()` : Rechercher un article spécifique.
  - `enregistrerVente()` : Enregistrer une vente (transaction).
  - `listerVentes()` : Afficher l'historique des transactions.
- **Persistance des données** :
  - Les données de l'inventaire et des ventes sont sauvegardées dans des fichiers
    pour être récupérées ultérieurement.
- **Bibliothèque incluse** : Le fichier `gestionProduits.h` contient les
  déclarations et les implémentations des fonctions utilisées.

================================================================================
*/

int main() {
    int choix;
    do {
        std::cout << "\n--- Menu Gestion des Produits ---\n";
        std::cout << "1. Ajouter un produit\n";
        std::cout << "2. Modifier un produit\n";
        std::cout << "3. Supprimer un produit\n";
        std::cout << "4. Rechercher un produit\n";
        std::cout << "5. Enregistrer une vente\n";
        std::cout << "6. Lister les ventes\n";
        std::cout << "7. Quitter\n";
        std::cout << "Choisissez une option : ";
        std::cin >> choix;

        switch (choix) {
            case 1: ajouterProduit(); break;
            case 2: modifierProduit(); break;
            case 3: supprimerProduit(); break;
            case 4: rechercherProduit(); break;
            case 5: enregistrerVente(); break;
            case 6: listerVentes(); break;
            case 7: std::cout << "Au revoir !\n"; break;
            default: std::cout << "Option invalide. Réessayez.\n";
        }
    } while (choix != 7);

    return 0;
}
