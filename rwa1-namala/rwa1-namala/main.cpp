/** \file main.cpp
 * This program is a planner for a kitting robot.
 * The program gives the plan followed by the robot for kitting requirement of the user.
 */

#include <iostream>
#include <array>

/**
 * @brief PartType is an user defined enum data type. It stores type of parts that are present on the floor.
 */
enum PartType {
    kRed = 0,
    kBlue = 1,
    kGreen = 2,
    kUnspecified=3,
};
/**
 * @brief GripperStateVariable is an user defined enum data type. It stores the status of the gripper.
 */
enum GripperStateVariable{
    kEmpty = 0,
    kHolding = 1,
};


/**
 * @brief The function pick orders the robot to pick the object. The order of picking parts is Red, Blue and Green. All the variables have been passed by reference.
 * @param a is the type of part which the gripper is picking.
 * @param g is the parameter which stores the state of the gripper(either holding or empty).
 * @param entered_input is the array consisting of the input by the user
 * @param inventory_array is the array which keeps track of the number of parts in the bin.
 * @return Changes the state of gripper state and assigns the part type to a so that it can be referenced in the place function.
 */

int Pick(PartType& a,GripperStateVariable& g, std::array<unsigned int,3>& entered_input,std::array<unsigned int,3>& inventory_array){
    //function is executed when only when the gripper is empty.
    if (g==kEmpty){
        if ((entered_input.at(kRed) != 0)){
            //assigns part type to parameter a so that it can be used again by the place function.
            a=kRed;
            //Since red part is picked the respective quantity in bin and input is decreased. Other if condition are also coded similarly.
            inventory_array.at(a) -=1;
            entered_input.at(a) -=1;
            std::cout<< "Pick a Red Part" <<std::endl;
            g=kHolding;
        }
        else if (entered_input.at(kBlue) != 0){
            a=kBlue;
            inventory_array.at(a) -=1;
            entered_input.at(a) -=1;
            std::cout<< "Pick a Blue Part" <<std::endl;
            g=kHolding;
        }
        else if (entered_input.at(kGreen) != 0){
            a=kGreen;
            inventory_array.at(a) -=1;
            entered_input.at(a) -=1;
            std::cout<< "Pick a Green Part" <<std::endl;
            g=kHolding;
        }
        else{
            std::cout<< "All the parts have been put in the kit" <<std::endl;
            a=kUnspecified;
        }
    }
    return 0;
}

/**
 *
 * @param a is the PartType enum variable which is represents the type of part the gripper is picking
 * @param g is the GripperStateVariable enum variable. It represents the state of the gripper(holding a part or empty)
 * @param kit_to_be_assembled is an array which stores the
 * @return kit is filled with the required number of parts.
 */
int Place(PartType& a,GripperStateVariable& g,std::array<unsigned int,3>& kit_to_be_assembled){
    //function is only executed if the gripper is holding a part and the part will be added to the kit if it is specified by parameter a.
    if(g==kHolding){
        //According to the value of a assigned by the pick function, the value is added to the kit.
        if (a == kRed){
            kit_to_be_assembled.at(a) +=1;
            g=kEmpty;
            std::cout<<"Place a red part"<<std::endl;
        }
        else if(a == kBlue){
            kit_to_be_assembled.at(a) +=1;
            g=kEmpty;
            std::cout<<"Place a blue part"<<std::endl;
        }
        else if(a == kGreen) {
            kit_to_be_assembled.at(a) += 1;
            g=kEmpty;
            std::cout << "Place a green part" << std::endl;
        }
        else{
            std::cout<< "part type unspecified" <<std::endl;
        }
    }
    else{
        std::cout<<"All the parts have been assembled"<<std::endl;
    }
    return 0;
}
/**
 * @param bin is an array which keeps track of the available parts. It is the inventory from which the robot has to take the part.
 * @param kit is an array which represents the kit. The aim of the generated plan is to fill the kit user entered
 * @param inputs_to_kit is an array where the user input is stored.
 * @brief User inputs the number of parts of each kind he wants in the kit. The program checks if the inputs from the user exceed from what the bin is having. If an excess input is entered, the user is asked to input again.
 * @return With the help of pick and place functions and some state maintaining variables, appropriate plan is generated.
 */
int main(){
    // Initializing a bool variable which is used to control the outer while loop
    bool enter_again{true};
    // bin is an array which stores the number of parts of each type which are present in the bin
    std::array <unsigned int ,3> bin{10,10,10};
// The while loop is initiated to enable user to run the code again.
    while(enter_again){
        //kit is an array which stores the the number of parts which are entered into it. It is zero initialized.
        std::array <unsigned int ,3> kit{0,0,0};
        //The user inputs are stored in the inputs_to_kit array.
        std::array <unsigned int ,3> inputs_to_kit{0,0,0};
        //The number of parts present in the bin is displayed.
        std::cout << "There are "<<bin[kRed] << "red parts."<<std::endl;
        std::cout << "There are "<<bin[kBlue] << "blue parts."<<std::endl;
        std::cout << "There are "<<bin[kGreen] << "green parts."<<std::endl;
        //The user is asked for input of different part types in to the kit. These values are stored in the inputs_to_kit array.
        std::cout<< "Enter the number of red parts for the kit" <<std::endl;
        std::cin>>inputs_to_kit[kRed];
        std::cout<< "Enter the number of blue parts for the kit" <<std::endl;
        std::cin>>inputs_to_kit[kBlue];
        std::cout<< "Enter the number of green parts for the kit" <<std::endl;
        std::cin>>inputs_to_kit[kGreen];
        //A variable of GripperStateVariable datatype is initialized to keep track of the state of the gripper
        GripperStateVariable gripper{kEmpty};
        //A variable of PartType data type is initialized to keep track of the part type held by the gripper.
        PartType partHeldByGripper{kUnspecified};
        // The plan is generated only if the entered input is valid.
        if (inputs_to_kit.at(kRed) <= bin.at(kRed) && inputs_to_kit.at(kGreen) <= bin.at(kGreen) && inputs_to_kit.at(kBlue) <= bin.at(kBlue)){
            std::cout<< "The plan is as follows:" <<std::endl;
            //The pick and place functions are executed until inputs_to_kit become zero and kit has all the values of the input
            while (!(inputs_to_kit.at(kRed) == 0 && inputs_to_kit.at(kBlue) == 0 && inputs_to_kit.at(kGreen) == 0)){
                Pick(partHeldByGripper,gripper,inputs_to_kit,bin);
                Place(partHeldByGripper,gripper,kit);
            }
            //Summary is printed
            std::cout<< "Summary:" <<std::endl;
            std::cout<< "The number of red parts in the kit: "<< kit.at(kRed) <<std::endl;
            std::cout<< "The number of blue parts in the kit: "<< kit.at(kBlue) <<std::endl;
            std::cout<< "The number of green parts in the kit: "<< kit.at(kGreen) <<std::endl;
        }
        //If the user enters a larger input, else statements check which parts are exceeding the current values in the bin and send a message to the user.
        else{
            if(inputs_to_kit.at(kRed) > bin.at(kRed)){
                std::cout<< "The input of red parts exceeds the number of available parts. The available number of red parts are: " << bin[kRed] <<std::endl;
            }
            if(inputs_to_kit.at(kBlue) > bin.at(kBlue)){
                std::cout<< "The input of blue parts exceeds the number of available parts. The available number of blue parts are: " << bin[kBlue] <<std::endl;
            }
            if(inputs_to_kit.at(kGreen) > bin.at(kGreen)){
                std::cout<< "The input of green parts exceeds the number of available parts. The available number of green parts are: " << bin[kGreen] <<std::endl;
            }
        }
        //enter_again_str is used to ask the user if they want to assemble a new kit.
        std::string enter_again_str{};
        std::cout<< "Do you want to plan for the next kit?(Y/N)"<<std::endl;
        std::cin>>enter_again_str;
        //if user enters Y or y the bool variable, enter_again remains true, else it is assigned false so that during the next iteration, the loop is not executed.
        if (enter_again_str =="Y" || enter_again_str == "y"){
            enter_again= true;
        }
        else if(enter_again_str =="N" || enter_again_str == "n"){
            enter_again= false;
        }
    }
    return 0;
}
