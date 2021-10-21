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
            --Lives;
            PrintLine(TEXT("Lost a life!"));
            if (Lives > 0)
            {
                if (Input.Len() != HiddenWord.Len())
                {
                    PrintLine(TEXT("Sorry, try to guessing again! \nYou have %i lives remaining"), Lives);
                }
            }
            else
            {
                PrintLine(TEXT("You have no lives left!"));
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
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i Lives!"), Lives);
    PrintLine(TEXT("Type in your guess and \npress enter to continue...")); // Prompt player for guess.
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again."));
}