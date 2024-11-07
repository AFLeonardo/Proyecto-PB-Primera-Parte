#include <iostream>

using namespace std;

ostream& tab(ostream& output) {
    return output << '\t';
}

int main() {
    cout << tab << "hola";
    return 0;
}
