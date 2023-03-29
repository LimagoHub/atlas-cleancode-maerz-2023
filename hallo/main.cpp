#include <iostream>
#include "dummy/ausgabe.h"
#include "atlas/tiere/Schwein.h"
using namespace atlas::tiere;
int main() {
    Schwein schwein;
    ausgabe ausgabe_;
    ausgabe_.print("Hallo");
    return 0;
}
