#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

enum Location { CLASSROOM, HALLWAY, HOME };

struct player {
    std::string name;
    int hp = 100;
    Location currentLoc = CLASSROOM;
    bool hasKey = false;
};

void showStatus(const player& p) {
    std::cout << "\n--- СТАТУС: Игрок " << p.name << " | HP: " << p.hp << " | Локация: " 
              << (p.currentLoc == CLASSROOM ? "Класс" : (p.currentLoc == HALLWAY ? "Коридор" : "Дом")) << " ---" << std::endl;
}

int main() {
    std::srand(std::time(0));
    player p;
    int choice;

    std::cout << "Как тебя зовут, герой? ";
    std::cin >> p.name;

    while (true) {
        showStatus(p);

        if (p.currentLoc == CLASSROOM) {
            if (!p.hasKey) {
                std::cout << "Дверь заперта. Что будешь делать?\n1. Искать на парте учителя\n2. Искать в шкафчиках: ";
                std::cin >> choice;
                if (choice == 1) {
                    if (rand() % 2 == 0) {
                        std::cout << "Ты нашел ключ!" << std::endl;
                        p.hasKey = true;
                    } else {
                        p.hp -= 20;
                     std::cout << "Ты нашел панталоны учителя... хуепутало задроченное напяль его себе на голову. Твое HP: " << p.hp << std::endl;
                    p.hasKey = false;
                    }
                } else {
                    std::cout << "В шкафчиках пусто, только пыль бикини твоей одноклассницы.. ебло утинное" << std::endl;
                }
            } else {
                std::cout << "У тебя есть ключ! Выйти из класса?\n1. Да\n2. Нет, посижу еще: ";
                std::cin >> choice;
                if (choice == 1) {
                    if (rand() % 2 == 0) {
                        std::cout << "Ты открыл дверь и вышел в коридор!" << std::endl;
                        p.currentLoc = HALLWAY;
                    } else {
                        std::cout << "Ключ сломался в замке! Ты застрял..." << std::endl;
                        p.hp = 0;
                    }
                }
            }
        } 
        else if (p.currentLoc == HALLWAY) {
            std::cout << "Ты в коридоре. Здесь тихо.\n1. Пойти в столовую\n2. Пойти домой: ";
            std::cin >> choice;
            if (choice == 1) {
                std::cout << "Столовая закрыта, но ты нашел там яблоко (+10 HP)." << std::endl;
                if (p.hp < 100) p.hp += 10;
            } else {
                std::cout << "Ты пошел домой.. тебя ждал миша с песюном" << std::endl;
                p.currentLoc = HOME;
            }
        } 
        else if (p.currentLoc == HOME) {
            std::cout << "Иди сюди сынок.. нужно поговорить.\n1. Подойти к мише\n2. Не подходить: ";
            std::cin >> choice;
            if (choice == 1) {
                std::cout << "шо ты стоишь на месте.. щенок ебаный, *кинул чебурке на стол*\nшо я тобi сказав зробить блять!\nЧто будешь делать?\n1.Пойдешь и сбежишь через окно\n2.Побежишь в комнату найти предмет чтобы отбится." << std::endl;
                std::cin >> choice;
                if (choice == 1) {
                    std::cout << p.name << ", скоро выйдет продолжение.. это еще не конец" << std::endl;
                    break;
                } else {
                    std::cout << "Ты побежал в комнату и решил что-то делать.. что же?\n1.Проверишь тумбочку.\n2.Попытаешься удержать дверь" << std::endl;
                    std::cin >> choice;
                    if (choice == 1) {
                        std::cout << "Ты нашел резиновый хуй..\nМиша вошел в комнату и сказал:\nО.. сам нашел.. спасибо сынок\nКонцовка: Тебя изнасиловал отчим.." << std::endl;
                        p.hp = 0;
                    } else {
                        std::cout << "Ты попытался придержать дверь но.. он вошел.. и в комнату, и в тебя." << std::endl;
                        p.hp = 0;
                    }
                }
            }
        }

        if (p.hp <= 0) {
            std::cout << "Ты погиб. Игра окончена." << std::endl;
            break;
        }
    }
    return 0;
}
