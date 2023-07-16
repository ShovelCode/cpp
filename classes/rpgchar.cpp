#include <string>

class Character {
private:
    std::string name;
    int level;
    int health;
    int strength;
    int mana;

public:
    Character(std::string characterName, int characterLevel, int characterHealth, int characterStrength, int characterMana)
    : name(characterName), level(characterLevel), health(characterHealth), strength(characterStrength), mana(characterMana) {}

    std::string getName() { return name; }
    int getLevel() { return level; }
    int getHealth() { return health; }
    int getStrength() { return strength; }
    int getMana() { return mana; }

    void setName(std::string newName) { name = newName; }
    void setLevel(int newLevel) { level = newLevel; }
    void setHealth(int newHealth) { health = newHealth; }
    void setStrength(int newStrength) { strength = newStrength; }
    void setMana(int newMana) { mana = newMana; }
};
