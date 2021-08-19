//
// Created by galahadv on 11/2/20.
//

#include <iostream>
#include <utility>

#ifndef RWA3_GROUP7_LANDBASEDROBOT_H
#define RWA3_GROUP7_LANDBASEDROBOT_H

namespace rwa3 {
    class LandBasedRobot {
    public:
        explicit LandBasedRobot(std::string name = "LandRobot", double speed = 0, double width = 0, double length = 0,
                                double height = 0, double capacity = 0, int x = 0, int y = 0) :
                name_{name},
                speed_{speed},
                width_{width},
                length_{length},
                height_{height},
                capacity_{capacity},
                x_{x},
                y_{y}{
            std::cout << "Constructor called for " << name_  << std::endl;
        }

        explicit LandBasedRobot(std::string name, int x, int y):
            name_{name},
            x_{x},
            y_{y}{
            std::cout << "Constructor 2 called for " << name_  << std::endl;
        }

        virtual ~LandBasedRobot(){
            std::cout << "Destructor called for " << name_ << std::endl;
        }

        virtual void GoUp(int x, int y)=0;
        virtual void GoDown(int x, int y);
        virtual void TurnLeft(int x, int y);
        virtual void TurnRight(int x, int y);
        virtual void PickUp(std::string object);
        virtual void Release(std::string object);
        virtual int get_x() const{return x_;}
        virtual int get_y() const{return y_;}

    protected:
        std::string name_;
        double speed_;
        double width_;
        double length_;
        double height_;
        double capacity_;
        int x_;
        int y_;
    };//--class LandBasedRobot
}//--namespace rwa


#endif //RWA3_GROUP7_LANDBASEDROBOT_H
