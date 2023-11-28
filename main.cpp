#include "lab.h"
#include <assert.h>

int main(void) {
  try {
    lab::AminoAcid amino3("UACU");
  } catch (const std::length_error &e) {
  };

  try {
    lab::AminoAcid amino4("UAF");
  } catch (const std::invalid_argument &e) {
  };

  lab::AminoAcid amino1, amino2("UAU");
  amino2.print();
  assert(amino2.getData() == "UAU");

  lab::AminoAcid amino5(amino2);
  amino5.print();
  assert(amino5.getData() == amino2.getData());

  amino5.synthesize("ACG");
  amino5.print();
  assert(amino5.getData() == "ACG");

  try {
    amino5.synthesize("AUGU");
  } catch (const std::length_error &e) {
  };

  try {
    amino5.synthesize("RCG");
  } catch (const std::invalid_argument &e) {
  };


  try {
    lab::Protein pr1("AAAaa");
  } catch (const std::invalid_argument &e) {
  };

  lab::Protein p1("AAAAA"), p2(p1), p3(amino2);
  p1.print();
  p2.print();
  p3.print();
  assert(p1.getData() == "AAAAA");
  assert(p2.getData() == "AAAAA");
  assert(p3.getData() == amino2.getData());

  p1.add(amino2);
  p1.add("UUUGGGAAAAAAA");
  assert(p1.getData() == "AAAAAUAUUUUGGGAAAAAAA");
  p1.print();

  try {
    p1.add("AuA");
  } catch (const std::invalid_argument &e) {
  };

  std::cout << "\n";
  lab::Protein p4 = p1 + p2;
  p1.print();
  std::cout << "+\n";
  p2.print();
  std::cout << "=\n";
  p4.print();
  assert(p4.getData() == "AAAAAUAUUUUGGGAAAAAAAA");

  std::cout << "\n";
  p1.synthesize("AUAUAUA");
  p2.synthesize("GAGAGGUU");
  p4 = p1 + p2;
  p1.print();
  std::cout << "+\n";
  p2.print();
  std::cout << "=\n";
  p4.print();
  assert(p4.getData() == "AUAUAUAGAGAGGUU");

  std::cout << "\n";
  p1.synthesize("GUAC");
  p1.print();
  p2.synthesize("GUAC");
  p1 += p2;
  std::cout << "+\n";
  p2.print();
  std::cout << "=\n";
  p1.print();
  assert(p1.getData() == "GUAC");

  std::cout << "\n";
  p1.print();
  p2.synthesize("AGUAC");
  p1 += p2;
  std::cout << "+\n";
  p2.print();
  std::cout << "=\n";
  p1.print();
  assert(p1.getData() == "GUACAGUAC");

  std::cout << "\n";
  p1.synthesize("CUCUACCCAGUACAGUACAAAAA");
  p1.print();
  p2.synthesize("GUACAGUACAAAAAGUCAC");
  p1 += p2;
  std::cout << "+\n";
  p2.print();
  std::cout << "=\n";
  p1.print();
  assert(p1.getData() == "CUCUACCCAGUACAGUACAAAAAGUCAC");

  std::cout << "\nEverything's fine\n";
  return 0;
}
