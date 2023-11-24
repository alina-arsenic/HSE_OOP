#include "lab.h"

lab::Protein::Protein(const char *nucleotides) {
    protein = "";
    for (int i = 0; i < strlen(nucleotides); i++) {
        char n = nucleotides[i];
        if (!(n == 'U' || n == 'C' || n == 'A' || n == 'G'))
        throw std::invalid_argument("Incorrect nucleotide types");
        protein += n;
    }
}

lab::Protein::Protein(const AminoAcid &amino) {
    protein = amino.getData();
}

lab::Protein::Protein(const Protein &other) {
    protein = other.protein;
}

void lab::Protein::print() const {
    std::cout << "Protein: " << protein << "\n";
}

std::string lab::Protein::getData() const {
    return protein;
}

void lab::Protein::synthesize(const char *nucleotides) {
    protein = "";
    for (int i = 0; i < strlen(nucleotides); i++) {
        char n = nucleotides[i];
        if (!(n == 'U' || n == 'C' || n == 'A' || n == 'G'))
        throw std::invalid_argument("Incorrect nucleotide types");
        protein += n;
    }
}

void lab::Protein::synthesize(const AminoAcid &amino) {
    protein = amino.getData();
}

void lab::Protein::reset() {
    protein = "";
}

void lab::Protein::add(const char *nucleotides) {
    for (int i = 0; i < strlen(nucleotides); i++) {
        char n = nucleotides[i];
        if (!(n == 'U' || n == 'C' || n == 'A' || n == 'G'))
        throw std::invalid_argument("Incorrect nucleotide types");
        protein += n;
    }
}

void lab::Protein::add(const AminoAcid &amino) {
    protein += amino.getData();
}
