//
// Created by Gabriel Bernard on 17-10-06.
//

#include "Pixel.h"

bool Pixel::operator==(const Pixel &p) const {
    return (this->retournerR() == p.retournerR() &&
            this->retournerG() == p.retournerG() &&
            this->retournerB() == p.retournerB());
}