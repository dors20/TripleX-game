#include<iostream>
#include<ctime>

void Printintroduction(int Difficulty)
{
     //the plot 
    std::cout<<"\n\nyou are a secret agent breaking into a level "<<Difficulty<<" secure server room\n";
    std::cout<<"enter the correct code to continue\n\n";
}

bool PlayGame(int Difficulty, int MaxDifficulty)
{   
    Printintroduction(Difficulty);
    //setting the code
    int CodeA=rand()%Difficulty +5;
    int CodeB=rand()%Difficulty +5;
    int CodeC=rand()%Difficulty +5;

    int CodeSum = CodeA+CodeB+CodeC;
    int CodeProduct=CodeA * CodeB*CodeC;

    std::cout<<"the code has 3 numbers\n";
    std::cout<<"the sum of the numbers is:  "<<CodeSum<<"\n";
    std::cout<<"the product of the code is:    "<<CodeProduct<<"\n";

    int GuessA,GuessB,GuessC;
    //inputting the users guess    
    std::cin>>GuessA;
    std::cin>>GuessB;
    std::cin>>GuessC;
    std::cout<<"players guess is:  "<<GuessA<<GuessB<<GuessC;

    int GuessSum=GuessA+GuessB+GuessC;
    int GuessProduct=GuessA*GuessB*GuessC;

    //checking the users guess
    if(GuessSum==CodeSum && GuessProduct==CodeProduct)
    {   
    if(Difficulty==MaxDifficulty)
    {
    std::cout<<"\n\nyou have successfully breached into the vault.....\nMISSION COMPLETE\n\n";
    return true;
    }
    else
    {
    std::cout<<"\nyou win!!\nContinue to the next level "<<Difficulty+1<<"\n";
    return true;
        }
    }
    else
    {
        std::cout<<"\nyou lose!!\nRetry the level"<<Difficulty<<"\n";
        return false;
    }
    
}

int main()
{   
    srand(time(NULL)); //makes the rand function more random
    int LevelDifficulty =1;
    const int MaxLevel =5;
    
    while(LevelDifficulty <= MaxLevel)
    {
    bool bLevelComplete=PlayGame(LevelDifficulty,MaxLevel);
    if(bLevelComplete)
    {
        ++LevelDifficulty;
    }
    std::cin.clear();//clears any errors
    std::cin.ignore();//removes buffer
    }
return 0;
}