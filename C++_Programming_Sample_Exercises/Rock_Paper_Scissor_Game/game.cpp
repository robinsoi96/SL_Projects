// Rock, Paper, Scissor Game in C++

#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()
#include <limits> // Required for std::numeric_limits

int getTotalRoundNum()
{
    int num;
    while(1){
        std::cout << "Enter number of round: ";
        std::cin >> num;
        std::cout << std::endl;
        if (num > 0){break;}
        std::cout << "Number entered is lesser than 1 or not in integer. Please try again." << std::endl;
        if (std::cin.fail()){ // In case not integer data type given
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return num;
}

int getUserInput(int roundNum)
{
    int userKey;
    std::cout << "==================================================" << std::endl;
    std::cout << "Round " << roundNum << ":" << std::endl;
    while(1){
        std::cout << "Enter '1' for rock, '2' for paper, '3' for scissor" << std::endl;
        std::cout << "Enter your key: ";
        std::cin >> userKey;
        if (userKey == 1 || userKey == 2 || userKey == 3){break;}
        std::cout << "Wrong key input. Please try again." << std::endl;
        if (std::cin.fail()){ // In case not integer data type given
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return userKey; 
}

int getComInput()
{
    srand(time(NULL)); //generate random number
    int comKey = (rand() % 3) + 1; // Allow computer to random generate from 1 to 3
    return comKey;
}

int getResults(int roundNum, int userKey, int comKey)
{
    std::string element[3] = {"ROCK", "PAPER", "SCISSOR"};
    std::cout << std::endl;
    std::cout << "COM : " << element[comKey - 1] << std::endl;
    std::cout << "PLAYER: " << element[userKey - 1] << std::endl;
    std::cout << std::endl;
    if (userKey == comKey){
        std::cout << "Round " << roundNum << ": DRAW" << std::endl; 
        return 0;
    }
    if ((userKey == 1 && comKey == 2) || (userKey == 2) && (comKey == 3) || (userKey == 3) && (comKey == 1)){
        std::cout << "Round " << roundNum << ": COM WINS" << std::endl;
        return -1;
    } else {
        std::cout << "Round " << roundNum << ": PLAYER WINS" << std::endl;
        return 1;
    }
}

int main()
{
    std::cout << "Welcome to Rock, Paper, Scissor Game !!!\n" << std::endl;
    int totalRoundNum = getTotalRoundNum();
    int totalWin = 0;
    int totalLoss = 0;
    int totalDraw = 0;
    for(int i = 0; i < totalRoundNum; ++i){
        int roundNum = i + 1;
        int userKey = getUserInput(roundNum);
        int comKey = getComInput();
        int result = getResults(roundNum, userKey, comKey);
        if (result == 1){
            totalWin += 1;  
        } else if (result == -1) {
            totalLoss += 1;   
        } else {
            totalDraw += 1;
        }
    }
    std::cout << std::endl;
    std::cout << "==================================================" << std::endl;
    std::cout << "ROCK PAPER SCISSOR GAME RESULTS\n" << std::endl;
    std::cout << "COM WINS: " << totalLoss << std::endl;
    std::cout << "PLAYER WINS: " << totalWin << std::endl;
    std::cout << "DRAW: " << totalDraw << std::endl;
    std::cout << std::endl;
    if (totalLoss == totalWin){
        std::cout << "DRAW !!!" << std::endl;
    } else if (totalLoss > totalWin) {
        std::cout << "PLAYER LOSE !!!" << std::endl;
    } else {
        std::cout << "PLAYER WINS !!!" << std::endl;
    }
    std::cout << std::endl;
    return 0;
}