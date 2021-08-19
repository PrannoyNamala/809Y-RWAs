//
// Created by galahadv on 11/2/20.
//

#ifndef RWA3_GROUP7_LANDBASEDTRACKED_H
#define RWA3_GROUP7_LANDBASEDTRACKED_H

#include <memory>
#include "../LandBasedRobot/landbasedrobot.h"
namespace rwa3 {
    class LandBasedTracked: public LandBasedRobot {
    public:
        explicit LandBasedTracked(std::shared_ptr<std::string> track_type = std::make_shared<std::string>("TrackType"),
                                  std::string name = "LandRobot", double speed = 0, double width = 0, double length = 0,
                                  double height = 0, double capacity = 0, int x = 0, int y = 0):
                LandBasedRobot(name, speed, width, length, height, capacity, x, y), track_type_{track_type}
        {
            std::cout << "Constructor called for " << name_  << std::endl;
        }
        explicit LandBasedTracked(std::string name, int x, int y):LandBasedRobot(name,x,y){}
        virtual ~LandBasedTracked(){
            std::cout << "Destructor called for " << name_ << std::endl;
        }

        virtual void GoUp(int x, int y) override;
        virtual void GoDown(int x, int y) override;
        virtual void TurnLeft(int x, int y) override;
        virtual void TurnRight(int x, int y) override;
        virtual void PickUp(std::string object) override;
        virtual void Release(std::string object) override;
        virtual int get_x() const{return x_;}// not sure how to override this
        virtual int get_y() const{return y_;}// not sure how to override this

    protected:
        std::shared_ptr<std::string> track_type_;
    };
}

#endif //RWA3_GROUP7_LANDBASEDTRACKED_H
