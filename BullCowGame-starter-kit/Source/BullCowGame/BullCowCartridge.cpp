// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Elcome to Bull Cows!"));
    PrintLine(TEXT("Guess the 3 letter word!")); // Need to remove the number later on.
    PrintLine(TEXT("Press enter to continue..."));
    HiddenWord = TEXT("cow");
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    FString HiddenWord = TEXT("cow");

    if (Input == HiddenWord)
    {
        PrintLine(TEXT("Yo have won!"));
    }
    else
    {
        PrintLine(TEXT("You have lost!"));
    }

}