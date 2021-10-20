// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    PrintLine(TEXT("The HiddenWord is: %s"), *HiddenWord); // Debug line.
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    // else Checking players guess.
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else // Checking the PLayerGuess
    {
        if (Input == HiddenWord)
        {
            PrintLine(TEXT("Yo have won!"));
            EndGame();
        }
        else
        {
            if (Input.Len() != HiddenWord.Len())
            {
                PrintLine(TEXT("The hidden word is %i characters long. You have lost!"), HiddenWord.Len());
                EndGame();
            }
        }    
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
    // Welcoming the player.
    PrintLine(TEXT("Welcome to Bull Cows!"));

    HiddenWord = TEXT("cows");
    Lives = 3;
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("Type in your guess.\nPress enter to continue...")); // Prompt player for guess.
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again."));
}