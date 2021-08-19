//
// Created by galahadv on 11/2/20.
//

#include "landbasedtracked.h"

namespace rwa3{
    void LandBasedTracked::GoUp(int x, int y) {
        std::cout << "LandBasedTracked::GoUp is called\n";
    }

    void LandBasedTracked::GoDown(int x, int y) {
        std::cout << "LandBasedTracked::GoDown is called\n";
    }

    void LandBasedTracked::TurnLeft(int x, int y) {
        std::cout << "LandBasedTracked::TurnLeft is called\n";
    }

    void LandBasedTracked::TurnRight(int x, int y) {
        std::cout << "LandBasedTracked::TurnRight is called\n";
    }

    void LandBasedTracked::PickUp(std::string object) {
        std::cout << "LandBasedTracked::PickUp is called\n";
    }

    void LandBasedTracked::Release(std::string object) {
        std::cout << "LandBasedTracked::Release is called\n";
    }
}