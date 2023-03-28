//
// Created by JoachimWagner on 27.03.2023.
//

#pragma once


#include <ostream>

class Schwein {
    int gewicht;
public:
    int getGewicht() const {
        return gewicht;
    }

    void setGewicht(int gewicht) {
        Schwein::gewicht = gewicht;
    }

    bool operator==(const Schwein &rhs) const {
        return gewicht == rhs.gewicht;
    }

    bool operator!=(const Schwein &rhs) const {
        return !(rhs == *this);
    }

    friend std::ostream &operator<<(std::ostream &os, const Schwein &schwein) {
        os << "gewicht: " << schwein.gewicht;
        return os;
    }
};
