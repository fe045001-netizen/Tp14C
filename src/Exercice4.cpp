#include <iostream>
#include <string>
#include <sstream>  
#include <stdexcept>
using namespace std;

class Compte {
private:
    string titulaire;
    int solde;
public:
    Compte(string nom, int soldeInitial) {
    	 titulaire=nom;
		 solde=soldeInitial;
	} 

    void deposer(int montant) {
        if (montant <= 0) {
            stringstream ss;
            ss << "montant invalide (" << montant << ")";
            throw runtime_error(ss.str());
        }
        solde += montant;
        cout << " Nouveau solde : " << solde << " DH." << endl;
    }

    void retirer(int montant) {
        if (montant <= 0) {
            stringstream ss;
            ss << " : montant invalide (" << montant << ")";
            throw runtime_error(ss.str());
        }
        if (montant > solde) {
            stringstream ss;
            ss << " solde insuffisant  " << montant
               << " Dh(votre solde actuel : " << solde << " Dh)";
            throw runtime_error(ss.str());
        }
        solde -= montant;
        cout << "Retire : " << montant << " Dh. Nouveau solde : " << solde << " 	Dh." << endl;
    }
};

int main() {
    Compte c("Sara", 1000);

    try {
        c.deposer(550);    
        c.retirer(65);   
        c.retirer(150);   
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    try {
        c.deposer(-200);   
        c.retirer(-100);   
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}

