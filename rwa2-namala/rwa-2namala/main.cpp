/** \file main.cpp
 * This program is path planner for a robot in a maze
 */

#include <iostream>
#include<array>

// The maze has been hard coded according to the coordinates given in the rwa-2 assignment document
std::array<std::array<char ,8>,6> map_of_maze {{
    {'#','.','.','.','#','#','.','#'},
    {'.','.','#','.','.','#','.','.'},
    {'#','.','#','#','.','#','.','#'},
    {'#','.','#','.','.','#','.','.'},
    {'#','.','.','#','.','.','.','#'},
    {'#','#','#','#','#','#','#','#'}}};

unsigned short int number_of_rows = map_of_maze.size();
unsigned short int number_of_columns = map_of_maze.at(1).size();
/**
 * @return Prints the maze every time this function is called
 */
 //Printing will be done as it is shown in the assignment document
int PrintArray() {
    for (short int i = map_of_maze.size(); i>0; i--){
        for (char element : map_of_maze.at(i-1)){
            std::cout<< element<<" ";
        }
        std::cout<<' '<<std::endl; //For space between elements
    }
    return 0;
}
/**
 * @brief The user is asked to input the start point until a valid input is obtained
 * @return The function returns the start point entered by the user
 */
std::array<unsigned short int ,2> StartPoint() {

    unsigned short int i{0};
    unsigned short int j{0};
    while (true) {
        std::cout << "Enter the position of start point(row number first then column)" << std::endl;
        std::cin >> i;
        std::cin >> j;
        if (map_of_maze.at(i).at(j) == '#') {
            std::cout << "You entered a border position. Enter a valid position" << std::endl;
            continue;
        } else {
//            map_of_maze.at(i).at(j) = start_point;
            break;
        }
    }
    return {i,j};
}
/**
 * @brief The user is asked to input the goal point until a valid input is obtained
 * @return The function returns the goal point entered by the user
 */
int GoalPoint() {
    char goal_point{'G'};
    while (true) {
        unsigned short int i;
        unsigned short int j;
        std::cout << "Enter the position of goal point(row number first then column)" << std::endl;
        std::cin >> i;
        std::cin >> j;
        if (map_of_maze.at(i).at(j) == '#') {
            std::cout << "You entered an invalid position. Enter a valid position" << std::endl;
            continue;
        } else {
            map_of_maze.at(i).at(j) = goal_point;
            break;
        }
    }
    return 0;
}
/**
 * @brief A recursive function which continues to call itself until it finds a path or cannot find a path
 * @param row : x coordinate of starting point
 * @param column : y coordinate of starting point
 * @return The path of followed by the robot is marked and unmarked(for tracing bad path) until the program finds a path ir gives no solution.
 */

bool FindPath(int row, int column){
    //Is the point in maze?
    //Since index starts with zero, the global variables number_of_rows and number_of_columns are subtracted with 1 to ensure they match the index range
    if ((row < 0 or row > number_of_rows-1) or (column < 0 or column > number_of_columns-1)){
        return false;
    }
    //Is the point goal?
    else if (map_of_maze.at(row).at(column) == 'G'){
        return true;
    }
    //Is the point open?
    else if (map_of_maze.at(row).at(column) != '.'){
        return false;
    }
    //Marking point (x,y)
    map_of_maze.at(row).at(column)='+';

    //Check the north of current point?
    if(FindPath(row+1,column) ){
        return true;
    }
    //Check the east of current point?
    if(FindPath(row,column+1) ){
        return true;
    }
    //Check the south of current point?
    if(FindPath(row-1,column) ){
        return true;
    }
    //Check the west of current point?
    if(FindPath(row,column-1) ){
        return true;
    }
    // Unmark the route.
    map_of_maze.at(row).at(column)='X';
    return false;
}

int main(){
    //Printing the maze at the start of the program
    std::cout<< "The map of the maze is as follows"<< std::endl;
    PrintArray();

    //User inputs the start point. It is assigned to start_point_location to use it as an input to FindPath
    auto start_point_location{StartPoint()};

    //User inputs the goal point and it is directly put in the map
    GoalPoint();
    //a is used to check if find path returns the solution to the maze. Depending in that we can inform the user
    bool a;//Used to track the value returned by FindPath function
    //The control is passed to the FindPath function
    a=FindPath(start_point_location.at(0),start_point_location.at(1));
    if (a){
        std::cout<<"Path to goal is found"<<std::endl;
    }
    else{
        std::cout<<"Path to goal could not be found"<<std::endl;
    }

    //Assigning the start point a character for user readability of the map.
    map_of_maze.at(start_point_location.at(0)).at(start_point_location.at(1)) = 'S';

    //Showing the solution to the User.
    PrintArray();
}
