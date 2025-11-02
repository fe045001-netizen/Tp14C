#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Produit {
private:
    string nom;
    int stock;
public:
    Produit(string nomProduit, int stockInitial) {
        nom = nomProduit;
        stock = stockInitial;
    }

    void vendre(int quantite) {
        if (quantite > stock) {
          
            stringstream ss;
            ss << " stock insuffisant :  " 
               << " stock actuel : " << stock
               << ", demande : " << quantite;
            cout << ss.str() << endl;
        } else {
            stock -= quantite;
            cout << quantite << " unites vendues de " << nom
                 << ". Stock restant : " << stock << endl;
        }
    }
};

int main() {
    Produit p("Chargeur", 75);

    p.vendre(5);   
    p.vendre(80);  

    return 0;
}



