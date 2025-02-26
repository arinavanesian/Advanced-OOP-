#include <iostream>
#include <vector>
using namespace std;
// Template class for Molecule, storing atoms of type T
template <typename T>
class Molecule {
private:
    std::vector<T> atoms;  // Container for atoms of type T

public:
    // Add an atom to the molecule
    void addAtom(const T& atom) {
        atoms.push_back(atom);
    }

    // Display molecule composition
    void display() const {
        std::cout << "Molecule contains: ";
        for (const auto& atom : atoms) {
            std::cout << atom << " ";
        }
        std::cout << std::endl;
    }
};

// Example Atom class
class Atom {
private:
    std::string symbol;
public:
    Atom(std::string sym) : symbol(sym) {}
    friend std::ostream& operator<<(std::ostream& os, const Atom& atom) {
        os << atom.symbol;
        return os;
    }
};

int main() {
    Molecule<std::string> water;  // Using strings for atoms
    water.addAtom("H");
    water.addAtom("O");
    water.addAtom("H");
    water.display();

    Molecule<Atom> methane;  // Using Atom objects
    methane.addAtom(Atom("C"));
    methane.addAtom(Atom("H"));
    methane.addAtom(Atom("H"));
    methane.addAtom(Atom("H"));
    methane.addAtom(Atom("H"));
    methane.display();

    return 0;
}

