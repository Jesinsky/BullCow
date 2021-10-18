// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    // Welcoming the player.
    PrintLine(TEXT("Elcome to Bull Cows!"));
    PrintLine(TEXT("Guess the 3 letter word!")); // Need to remove the number later on.
    PrintLine(TEXT("Press enter to continue..."));

    SetupGame(); // Setting up game.


    // Prompt player for guess.
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    // Checking players guess.

    if (Input == HiddenWord)
    {
        PrintLine(TEXT("Yo have won!"));
    }
    else
    {
        PrintLine(TEXT("You have lost!"));
    }
    // Check if isogram.
    // Prompt to guess again.
    // Check right number of characters.
    // Prompt to guess again.

    // Remove life

    // Check if lives > 0.
    // If yes GuessAgain.
    // Show lives left.
    // If no show GameOver and HiddenWord.
    // Prompt to play again, Press enter to PlayAgain.
    // Check user input.
    // PlayAgain or Quit.


}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("cow");
    Lives = 3;
}