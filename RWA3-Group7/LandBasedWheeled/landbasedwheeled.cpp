//
// Created by galahadv on 11/2/20.
//

#include "landbasedwheeled.h"

namespace rwa3{
    void LandBasedWheeled::GoUp(int x, int y) {
        std::cout << "LandBasedWheeled::GoUp is called\n";
    }

    void LandBasedWheeled::GoDown(int x, int y) {
        std::cout << "LandBasedWheeled::GoDown is called\n";
    }

    void LandBasedWheeled::TurnLeft(int x, int y) {
        std::cout << "LandBasedWheeled::TurnLeft is called\n";
    }

    void LandBasedWheeled::TurnRight(int x, int y) {
        std::cout << "LandBasedWheeled::TurnRight is called\n";
    }

    void LandBasedWheeled::PickUp(std::string object) {
        std::cout << "LandBasedWheeled::PickUp is called\n";
    }

    void LandBasedWheeled::Release(std::string object) {
        std::cout << "LandBasedWheeled::Release is called\n";
    }
}