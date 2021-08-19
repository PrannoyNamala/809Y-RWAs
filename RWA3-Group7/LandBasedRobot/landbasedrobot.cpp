//
// Created by galahadv on 11/2/20.
//

#include "landbasedrobot.h"
namespace rwa3 {
    void LandBasedRobot::GoUp(int x, int y) {
        std::cout << "LandBasedRobot::GoUp is called\n";
    }

    void LandBasedRobot::GoDown(int x, int y) {
        std::cout << "LandBasedRobot::GoDown is called\n";
    }

    void LandBasedRobot::TurnLeft(int x, int y) {
        std::cout << "LandBasedRobot::TurnLeft is called\n";
    }

    void LandBasedRobot::TurnRight(int x, int y) {
        std::cout << "LandBasedRobot::TurnRight is called\n";
    }

    void LandBasedRobot::PickUp(std::string object) {
        std::cout << "LandBasedRobot::PickUp is called\n";
    }

    void LandBasedRobot::Release(std::string object) {
        std::cout << "LandBasedRobot::Release is called\n";
    }
}