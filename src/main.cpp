#include "../include/DungeonEditor.h"
#include <iostream>

void printMenu() {
    std::cout << "\nBalagur Fate 3 Dungeon Editor\n";
    std::cout << "1. Add NPC\n";
    std::cout << "2. Print all NPCs\n";
    std::cout << "3. Start battle\n";
    std::cout << "4. Save to file\n";
    std::cout << "5. Load from file\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose option: ";
}

int main() {
    DungeonEditor editor;
    int choice;
    
    while (true) {
        printMenu();
        std::cin >> choice;
        
        try {
            switch (choice) {
                case 1: {
                    std::string type, name;
                    int x, y;
                    std::cout << "Enter NPC type (Orc/Squirrel/Druid): ";
                    std::cin >> type;
                    std::cout << "Enter NPC name: ";
                    std::cin >> name;
                    std::cout << "Enter coordinates (x y): ";
                    std::cin >> x >> y;
                    editor.addNPC(type, name, x, y);
                    break;
                }
                case 2: {
                    editor.printNPCs();
                    break;
                }
                case 3: {
                    int range;
                    std::cout << "Enter battle range: ";
                    std::cin >> range;
                    editor.startBattle(range);
                    break;
                }
                case 4: {
                    std::string filename;
                    std::cout << "Enter filename to save: ";
                    std::cin >> filename;
                    editor.saveToFile(filename);
                    break;
                }
                case 5: {
                    std::string filename;
                    std::cout << "Enter filename to load: ";
                    std::cin >> filename;
                    editor.loadFromFile(filename);
                    break;
                }
                case 0:
                    return 0;
                default:
                    std::cout << "Invalid option\n";
            }
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    
    return 0;
} 