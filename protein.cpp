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

lab::Protein lab::Protein::operator+(const lab::Protein &other) {
    const char *a = protein.c_str();
    const char *b = other.protein.c_str();
    const char *temp = strchr(a, b[0]), *common = NULL;
    int overlap = 0;
    while (temp && *temp && common != b) {
        common = strstr(b, temp);
        overlap = strlen(temp);
        temp = strchr(++temp, b[0]);
    }
    if (common != b) overlap = 0;

    lab::Protein result(*this);
    for (int i = 0; i < (other.protein.length()-overlap); i++) {
        result.protein.push_back(other.protein[overlap+i]);
    }
    return result;
}

lab::Protein& lab::Protein::operator+=(const lab::Protein &other) {
    const char *a = protein.c_str();
    const char *b = other.protein.c_str();
    const char *temp = strchr(a, b[0]), *common = NULL;
    int overlap = 0;
    while (temp && *temp && common != b) {
        common = strstr(b, temp);
        overlap = strlen(temp);
        temp = strchr(++temp, b[0]);
    }
    if (common != b) overlap = 0;

    for (int i = 0; i < (other.protein.length()-overlap); i++) {
        protein.push_back(other.protein[overlap+i]);
    }
    return *this;
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
