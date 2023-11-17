#include <assert.h>
#include "lab.h"

int main(void) {
    try { lab::AminoAcid amino3("UACU"); }
    catch (const std::length_error& e) {};
    try { lab::AminoAcid amino4("UAF"); }
    catch (const std::invalid_argument& e) {};

    lab::AminoAcid amino1, amino2("UAU");
    assert(amino2.getData() == "UAU");

    lab::AminoAcid amino5(amino2);
    assert(amino5.getData() == amino2.getData());

    amino5.synthesize("ACG");
    assert(amino5.getData() == "ACG");

    try { amino5.synthesize("AUGU"); }
    catch (const std::length_error& e) {};
    try { amino5.synthesize("RCG"); }
    catch (const std::invalid_argument& e) {};
    return 0;
}
