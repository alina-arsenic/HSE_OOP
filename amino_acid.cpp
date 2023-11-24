#include "lab.h"

lab::AminoAcid::AminoAcid(const char *nucleotides) {
  if (strlen(nucleotides) != 3)
    throw std::length_error("The nucleotides count must be 3");
  aminoAcid = "";
  for (int i = 0; i < 3; i++) {
    char n = nucleotides[i];
    if (!(n == 'U' || n == 'C' || n == 'A' || n == 'G'))
      throw std::invalid_argument("Incorrect nucleotide types");
    aminoAcid += n;
  }
}

lab::AminoAcid::AminoAcid(const AminoAcid &other) {
  aminoAcid = other.aminoAcid;
}

void lab::AminoAcid::print() const {
  std::cout << "Amino Acid: " << aminoAcid << "\n";
}

void lab::AminoAcid::synthesize(const char *nucleotides) {
  if (strlen(nucleotides) != 3)
    throw std::length_error("The nucleotides count must be 3");
  aminoAcid = "";
  for (int i = 0; i < 3; i++) {
    char n = nucleotides[i];
    if (!(n == 'U' || n == 'C' || n == 'A' || n == 'G'))
      throw std::invalid_argument("Incorrect nucleotide types");
    aminoAcid += n;
  }
}

std::string lab::AminoAcid::getData() const {
  return aminoAcid;
}
