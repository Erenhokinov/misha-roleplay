#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"

void showStatus(const player& p) {
    std::cout << "\n--- СТАТУС: Игрок " << p.name << " | HP: " << p.hp << " | Локация: " << p.currentLoc << " ---" << std::endl;
}

int main() {
    std::srand(std::time(0));
    player p;
    int choice;

    std::cout << "Как тебя зовут, герой? ";
    std::cin >> p.name;

    while (true) {
        if (p.hp <= 0) { std::cout << "Ты погиб. Игра окончена." << std::endl; break; }

        if (p.currentLoc == CLASSROOM) {
            if (!p.hasKey) {
                std::cout << "Дверь заперта. Что будешь делать?\n1. Искать на парте учителя\n2. Искать в шкафчиках: ";
                std::cin >> choice;
                if (choice == 1 && rand() % 2 == 0) { std::cout << "Ты нашел ключ!" << std::endl; p.hasKey = true; }
                else if (choice == 1) { p.hp -= 20; std::cout << "Ты нашел панталоны учителя... хуепутало задроченное напяль его себе на голову. Твое HP: " << p.hp << std::endl; }
                else std::cout << "В шкафчиках пусто, только пыль бикини твоей одноклассницы.. ебло утинное" << std::endl;
            } else {
                std::cout << "У тебя есть ключ! Выйти из класса?\n1. Да\n2. Нет: ";
                std::cin >> choice;
                if (choice == 1) p.currentLoc = HALLWAY;
            }
        }
        else if (p.currentLoc == HALLWAY) {
            std::cout << "Ты в коридоре. 1. Столовая 2. Пойти домой: ";
            std::cin >> choice;
            if (choice == 1) { std::cout << "Столовая закрыта, но ты нашел яблоко (+10 HP)." << std::endl; if (p.hp < 100) p.hp += 10; }
            else { std::cout << "Ты пошел домой.. тебя ждал миша с песюном" << std::endl; p.currentLoc = HOME; }
        }
        else if (p.currentLoc == HOME) {
            std::cout << "Миша: Иди сюди сынок.. 1. Подойти 2. Не подходить: ";
            std::cin >> choice;
            if (choice == 1) {
                std::cout << "Миша: *кинул чебурке на стол* шо я тобi сказав зробить блять, А!? 1. Сбежать в окно 2. В комнату: ";
                std::cin >> choice;
                if (choice == 1) p.currentLoc = STREET;
                else { std::cout << "1. проверить тумбочку 2. попытаться сдержать дверь: "; std::cin >> choice; p.hp = 0; }
            }
        }
        else if (p.currentLoc == STREET) {
            std::cout << "Ты сбежал в окно.. Что будешь делать? " << p.name << ". 1. позвонишь ментам 2. Пошлёшь его нахуй: ";
            std::cin >> choice;
            if (choice == 1) { std::cout << "Миша успел вылезти из окна и нахуярил тебя чебуреком."; break; }
            else { std::cout << "Он вылез из окна, догнал тебя и отвёз в лес.. затем он попросил сьесть тебя чебурека..\n1. Убежать\n2. Послать его: "; std::cin >> choice; p.currentLoc = FOREST; }
        }
        else if (p.currentLoc == FOREST) {
            if (choice == 1) { std::cout << "Ты попытался сбежать. Но Миша настиг тебя.. и отпиздил твое ебло утинное этим же чебуреком."; break; }
            else { std::cout << "Ты послал его нахуй, забрал ножи и разрезал верёвки пока он отвлекся.. затем ты убежал домой к роме..\n миша обзвонил всех твоих друзей и в итоге удже стоит под дверью.\n1. Не открывать\n2. Открыть: "; std::cin >> choice; if(choice == 2) break; else std::cout << "миша взял тебя за шкибарки и отвел домой, сказавшы: ты будешь сидеть дома пока мамка не придёт щенок ебаный"; p.hp -= 10; }
        } 
    }
    return 0;
}
