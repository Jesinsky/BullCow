// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    PrintLine(TEXT("The HiddenWord is: %s"), *HiddenWord); // Debug line.

    // Welcoming the player.
    PrintLine(TEXT("Elcome to Bull Cows!"));
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("Type in your guess and press enter to continue..."));

    // Prompt player for guess.
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    // Checking players guess.

    if (Input == HiddenWord)
    {
        PrintLine(TEXT("Yo have won!"));
        // bGameOver = true;
    }
    else
    {
        if (Input.Len() != HiddenWord.Len())
        {
            PrintLine(TEXT("The hidden word is %i characters long, try agin!"), HiddenWord.Len());
        }

        PrintLine(TEXT("You have lost!"));
        // bGameOver = true;
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
    HiddenWord = TEXT("cows");
    Lives = 3;
}