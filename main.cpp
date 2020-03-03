#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>
#include <cstdlib>

class Warrior {
private:
    std::string name;
    int health;
    int attack;
    int block;
    
public:
    std::string GetName() {return name;}
    void SetName(std::string name) {this -> name = name;}
    int GetHealth() {return health;}
    void SetHealth(int health) {this -> health = health;}
    int GetAttack() {return attack;}
    void SetAttack(int attack) {this -> attack = attack;}
    int GetBlock() {return block;}
    void SetBlock(int block) {this -> block = block;}
    
    int Attack() {
        int damage = rand()%(attack + 1);
        return damage;
    }
    
    void Block(int damage) {
        damage = damage - this->block;
        int health = this->GetHealth();
        if (health < damage) {
            this->SetHealth(0);
        }
        else {
            int new_health {};
            new_health= health - damage;
            SetHealth(new_health);
        }
    }
    
    int Block() {
        int warrior_block = rand()%(block + 1);
        return warrior_block;
    }
    
    void SetAll(std::string, int, int, int);
    Warrior(std::string, int, int, int);
    Warrior();
    ~Warrior();
};

void Warrior::SetAll(std::string name, int health, int attack, int block) {
    this->name = name;
    this->health = health;
    this->attack = attack;
    this->block = block;
}

Warrior::Warrior(std::string name, int health, int attack, int block) {
    this->name = name;
    this->health = health;
    this->attack = attack;
    this->block = block;
}

Warrior::Warrior() {
    this->name = "";
    this->health = 0;
    this->attack = 0;
    this->block = 0;
}

Warrior::~Warrior() {
    std::cout << "Warrior " << this->name <<" is destroyed.\n";
}


class Battle {
public:
    void AttackRival (Warrior &player1, Warrior &player2) {
        int player1_attack = player1.Attack();
        player2.Block(player1_attack);
        std::cout << player1.GetName() << " attacks " << player2.GetName() << " and deals " << player1_attack << " damage.\n";
        std::cout << player2.GetName() << " is down to " << player2.GetHealth() << " health.\n";
    }
    
    void StartFight(Warrior &player1, Warrior &player2) {
        std::cout<< "Let it begin...\n";
        std::string winner = "";
        std::string looser = "";
        while (true) {
            AttackRival(player1, player2);
            if (player2.GetHealth()==0) {
                winner = player1.GetName();
                looser = player2.GetName();
                break;
            }
            AttackRival(player2, player1);
            if (player1.GetHealth()==0) {
                winner = player2.GetName();
                looser = player1.GetName();
                break;
            }
        }
        std::cout << looser << " has died and " << winner << " is Victorious.\n";
    }
    
    void SetAll(Warrior, Warrior);
    Battle(Warrior, Warrior);
    Battle();
    ~Battle();
};


Battle::Battle() {
    std::cout << "The Great Battle\n";
}

Battle::~Battle() {
    std::cout<<"Game over\n\n";
}



int main() {
    srand( (unsigned int) time(NULL) );
    
    Warrior thor("Thor", 100, 30, 15);
    Warrior hulk("Hulk", 135, 35, 10);
    
    Battle new_battle;
    new_battle.StartFight(thor, hulk);
    return 0;
}
