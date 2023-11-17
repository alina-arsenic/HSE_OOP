#ifndef __LAB_H__
#define __LAB_H__

#include <stdexcept>
#include <cstring>

namespace lab {
    class AminoAcid {
        public:
        AminoAcid() : aminoAcid("") {};
        AminoAcid(const char *nucleotides);
        AminoAcid(const AminoAcid &other);
        ~AminoAcid() { delete &aminoAcid; };

        void synthesize(const char *nucleotides);
        std::string getData() const;

        private:
        std::string aminoAcid;
    };

    class Protein {
        //
    };

}  // namespace lab

#endif  // __LAB_H__
