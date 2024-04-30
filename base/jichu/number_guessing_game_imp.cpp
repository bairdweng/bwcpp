#include "number_guessing_game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void playNumberGuessingGame() {
    srand(time(nullptr));

    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    bool correct = false;

    cout << "欢迎来到数字猜测游戏！" << endl;
    cout << "游戏规则：猜测1到100之间的秘密数字。" << endl;

    while (!correct) {
        cout << "请输入你的猜测：";
        cin >> guess;
        attempts++;

        if (guess == secretNumber) {
            cout << "恭喜你猜对了！";
            cout << "你用了 " << attempts << " 次猜测。" << endl;
            correct = true;
        } else if (guess < secretNumber) {
            cout << "猜的数字太小了，请再试一次。" << endl;
        } else {
            cout << "猜的数字太大了，请再试一次。" << endl;
        }
    }
}