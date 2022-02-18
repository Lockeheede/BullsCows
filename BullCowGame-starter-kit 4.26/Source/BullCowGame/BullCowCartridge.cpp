// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
  
    SetupGame();

    //Debug Line to turn on/off
    PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord);    
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{    
    //If bGameOver; ClearScreen and SetUpGame
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else //Checking PlayerGuess (Input)
    {
        ProcessGuess(Input);
    }
   
}

    

void UBullCowCartridge::SetupGame()
{
    //Welcoming The Player
    PrintLine(TEXT("Hello! Welcome to Bull Cows!"));

    HiddenWord = TEXT("ass");
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives!"), Lives);
    PrintLine(TEXT("Type in your guess. \nAnd press Enter to continue..."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("The Hidden Word was: %s"), *HiddenWord);
    PrintLine(TEXT("\nPress Enter to play again..."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("You Won!"));
        EndGame();
        return;
    }

    
    //if (!IsIsogram)
    //{
    //    PrintLine(TEXT("There are no repeating letters.\nGuess Again!"));
    //}
    
   
    //PlayAgain or Quit

    else if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("The Hidden Word is %i characters long!\n Try again!"), HiddenWord.Len());
        PrintLine(TEXT("You didn't lose a life and have %i lives left!"), Lives);
        return;
    }
    else if (Guess != HiddenWord)
    {
        PrintLine(TEXT("That is not the hidden word"));
        PrintLine(TEXT("You lost a life!"));
        PrintLine(TEXT("You have %i lives left!"), --Lives);
    }

    if (Lives <= 0)
    {
        PrintLine(TEXT("You ran out of lives, you lost!"));
        EndGame();
        return;
    }
}