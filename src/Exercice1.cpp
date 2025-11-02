#include <iostream>
#include <stdexcept> 
using namespace std;
double diviser(int a, int b) {
    if (b == 0) {
        throw runtime_error("Impossible la division par zero !");
    }
    return double(a) / b;

}

int main() {
    int x = 15, y1 = 3, y2 = 0;
  cout << "la division de x sur y1 \n";
    try {
        double resultat = diviser(x, y1);
       cout << x << " / " << y1 << " = " << resultat << endl;
    } catch (const runtime_error& e) {
       cout << e.what() << endl;
    }
    cout << "la division de x sur y2  \n";
    try {
        double resultat = diviser(x, y2);
        cout << x << " / " << y2 << " = " << resultat << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}

