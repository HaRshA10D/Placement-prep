#include <iostream>
#include <vector>
using namespace std;
int directions[] = {0,90,180,270};
class Drone{
    int x_max,y_max;
    public:
        Drone(int,int,int,int,int);
        void spin(int);
        void move();
        vector <int> position_info();
    private:
      int current_position_x, current_position_y,direction;
};
Drone::Drone(int initial_x,int initial_y,int x_max,int y_max,int direction){
    current_position_x = initial_x;
    current_position_y = initial_y;
    this->x_max = x_max;
    this->y_max = y_max;
    this->direction = direction;
}
void Drone::spin(int is_clockwise){
    if(is_clockwise){
        direction = (direction+1)%4;
    }else{
        direction = (direction-1);
        if(direction == -1) direction = 3;
    }
}
void Drone::move(){
    if(direction == 0){
        if(current_position_y!=1){
            current_position_y--;
        }else{
            cout << "Can't move you are already at extreme" << endl;
        }
    }
    else if(direction == 1){
        if(current_position_x!=x_max){
            current_position_x++;
        }else{
            cout << "Can't move you are already at extreme" << endl;
        }
    }
    else if(direction == 2){
        if(current_position_y!=y_max){
            current_position_y++;
        }else{
            cout << "Can't move you are already at extreme" << endl;
        }
    }
    else{
        if(current_position_x!=1){
            current_position_x--;
        }else{
            cout << "Can't move you are already at extreme" << endl;
        }
    }
}
vector<int> Drone::position_info(){
    vector<int> position;
    position.push_back(current_position_x);
    position.push_back(current_position_y);
    position.push_back(direction);
    return position;
}
void showPosition(vector<int> current_drone_position){
    cout << "X,Y cordinates: " <<  current_drone_position[0] << ", " << current_drone_position[1] << " Direction: " << directions[current_drone_position[2]] << endl;
}
void Visualize(vector<Drone> all_drones){
    for(int drone_i=0;drone_i < all_drones.size();drone_i++){
        cout << "Drone " << drone_i << " position: " << endl;
        showPosition(all_drones[drone_i].position_info());
    }
}
int main() {
    // your code goes here
    int grid_length, grid_width;
    cout << "Give grid dimensions. length and width" << endl;
    cin >> grid_length >> grid_width;
    vector <Drone> all_Drones;
    int no_drones = 5;
    for(int drone_i=0;drone_i<no_drones;drone_i++){
        cout << "Starting Drone: " << drone_i+1 << " Enter initial conditions x position, y_position, its direction 0:0 1:90 2:180 3:270 degrees" << endl;
        int initial_x,initial_y,direction;
        cin >> initial_x >> initial_y >> direction;
        Drone new_drone(initial_x,initial_y,grid_length,grid_width,direction);
        all_Drones.push_back(new_drone);
        Drone* current_drone = &all_Drones[all_Drones.size()-1];
        int stop = 1;
        while(stop){
            cout << "Do what you like:" << endl << "Options: L: Left  R: Right  M: Move  S: Show  D: ok with position   A: all positions of drones" << endl;
            char choice;
            cin >> choice;
            switch(choice){
                case 'L': cout << "Rotating Left .." << endl;
                        (*current_drone).spin(0);
                        break;
                case 'R': cout << "Rotating right .." << endl;
                        (*current_drone).spin(1);
                        break;
                case 'M': cout << "Moving..." << endl;
                        (*current_drone).move();
                        break;
                case 'S': cout << "Showing co-ordinates" << endl;
                        showPosition((*current_drone).position_info());
                        break;
                case 'D': cout << "Done with drone!!" << endl << "Showing drone's final state: " << endl;
                        showPosition((*current_drone).position_info());
                        stop = 0;
                        break;
                case 'A': cout << "Current position of all drones: " << endl;
                        Visualize(all_Drones);
                        break;
                default: cout << "Sorry wrong option, please..." << endl;
            }
        }
    }
    return 0;
}
