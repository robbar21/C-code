// Chapter_6_Barone_Homework.cpp
// Name: Roberto Barone
// Date: 2/15/23
// Class: CIT-245
// Assignment: Chapter 6 Homework
//

#include <iostream>
#include <cstdlib>

using namespace std;

class Player {

public:

     void setName(string name);
     string getName();
    
     void setPassword(string pass);
     string getPassword();
     
     void setExp(int exp);
     int getExp();

     void setLocationX(int x);
     int getLocationX();

     void setLocationY(int y);
     int getLocationY();

private:
    string name;
    string password;
    int exp;
    int x, y;
};

string* getInv() {
    string* invent = new string[4];
    invent[0] = "Bow and Arrows", "Stamina Potion" , "Teleportaion Cube", "Cloak of Dexterity";
    invent[1] = "Axe", "Stick of Truth", "Sand", "Helmet of Knowledge";
    invent[2] = "Glowing Sword", "Pocket Lint", "Wings of Freedom", "Shoes of Speed";
    invent[3] = "Ball and Chain", "Health Potion", "Wood", "Mining Pickaxe";
    return invent;
}

int main()
{
    Player nameOfPlayer, pass, experience, position;

    string*  inventory;
    inventory = getInv();

    cout << "This program generates three player objects and "
        << " displays them." << endl;
    cout << endl;

    cout << "Player Info:" << endl;
    nameOfPlayer.setName("Steven");
    cout <<"Name: " << nameOfPlayer.getName();
    cout << endl;

    pass.setPassword("JoeShmo");
    cout <<"Password: " << pass.getPassword();
    cout << endl;

    position.setLocationX(rand());
    position.setLocationY(rand());
    cout << "Location: " << position.getLocationX() 
        << ", " << position.getLocationY();
    cout << endl;

    experience.setExp(rand());
    cout <<"Experience: " << experience.getExp();
    cout << endl;

    cout << "Inventory: "
    << endl << inventory[0];
    cout << endl;
    cout << endl;

    cout << "Player Info:" << endl;
    nameOfPlayer.setName("Alex");
    cout << "Name: " << nameOfPlayer.getName();
    cout << endl;

    pass.setPassword("AlexiaTodaysWeather");
    cout << "Password: " << pass.getPassword();
    cout << endl;

    position.setLocationX(rand());
    position.setLocationY(rand());
    cout << "Location: " << position.getLocationX() 
        << ", " << position.getLocationY();
    cout << endl;

    experience.setExp(rand());
    cout << "Experience: " << experience.getExp();
    cout << endl;

    cout << "Inventory: " 
        << endl << inventory[1];
    cout << endl;
    cout << endl;

    cout << "Player Info:" << endl;
    nameOfPlayer.setName("Ben");
    cout << "Name: " << nameOfPlayer.getName();
    cout << endl;

    pass.setPassword("BenAndJerrys");
    cout << "Password: " << pass.getPassword();
    cout << endl;

    position.setLocationX(rand());
    position.setLocationY(rand());
    cout << "Location: " << position.getLocationX()
        << ", " << position.getLocationY();
    cout << endl;

    experience.setExp(rand());
    cout << "Experience: " << experience.getExp();
    cout << endl;

    cout << "Inventory: " 
        << endl << inventory[2];
    cout << endl;
    cout << endl;

    return 0;
}

void Player::setName(string name) {
    this->name = name;
}
string Player::getName( ) {
    return name;
}

void Player::setPassword(string password){
    this->password = password;
}
string Player::getPassword() {
    return password;
}

void Player::setExp(int exp){
    this->exp = exp;
}
int Player::getExp() {
    return exp;
}

void Player::setLocationX(int x){
    this->x = x;
}

int Player::getLocationX(){
    return x;
}
void Player::setLocationY(int y) {
    this->y = y;
}

int Player::getLocationY() {
    return y;
}
