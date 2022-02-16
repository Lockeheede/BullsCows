// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    //Instead of using the \n make the two separate functions to do two separate things
    PrintLine(TEXT("Hello! Welcome to Bull Cows!"));
    PrintLine(TEXT("Press Enter to Continue..."));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    //Declare and assign an isogram named HiddenWord
    FString HiddenWord = TEXT("raft");
}