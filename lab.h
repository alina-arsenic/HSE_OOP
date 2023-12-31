#ifndef __LAB_H__
#define __LAB_H__

#include <cstring>
#include <stdexcept>
#include <iostream>

namespace lab {
class AminoAcid {
public:
  AminoAcid() : aminoAcid("") {};
  AminoAcid(const char *nucleotides);
  AminoAcid(const AminoAcid &other);
  ~AminoAcid() {};

  virtual void print() const;
  std::string getData() const;
  void synthesize(const char *nucleotides);

private:
  std::string aminoAcid;
};

class Protein : AminoAcid {
public:
  Protein() : protein("") {};
  Protein(const char *nucleotides);
  Protein(const AminoAcid &amino);
  Protein(const Protein &other);
  ~Protein() {};

  Protein operator+(const Protein& other);
  Protein& operator+=(const Protein& other);

  virtual void print() const;
  std::string getData() const;
  void synthesize(const char *nucleotides);
  void synthesize(const AminoAcid &amino);

  void reset();
  void add(const char *nucleotides);
  void add(const AminoAcid &amino);

private:
  std::string protein;
};

} // namespace lab

#endif // __LAB_H__
