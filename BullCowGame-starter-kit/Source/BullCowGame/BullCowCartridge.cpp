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
    // else Checking players guess.
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else // Checking the PLayerGuess
    {
        ProcessGuess(Input);
    }
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
    PrintLine(TEXT("\nPress enter to play again."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("Yo have won!"));
        EndGame();
        return;
    }

    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("You have to write a %i letters long"), HiddenWord.Len());
        PrintLine(TEXT("Sorry, try to guessing again! \nYou have %i lives remaining"), Lives);
        return;
    }

    // Check if isogram.
    if (!IsIsogram(Guess))
    {
        PrintLine(TEXT("No repeating letter, guess again"));
        return;
    }
    
    // Remove life
    PrintLine(TEXT("Lost a life!"));
    --Lives;

    if (Lives <= 0)
    {
        ClearScreen();
        PrintLine(TEXT("You have no lives left!"));
        PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
        EndGame();
        return;
    }

    // Show the player Bulls and Cows.
    PrintLine(TEXT("Guess again, you have %i lives left"), Lives);
    // Check if lives > 0.
    // If yes GuessAgain.
    // Show lives left.
    // If no show GameOver and HiddenWord.
    // Prompt to play again, Press enter to PlayAgain.
    // Check user input.
    // PlayAgain or Quit. 
}

bool UBullCowCartridge::IsIsogram(FString Word)
{
    // loop trough the HiddenWord.Len()
    // Check no repiting letters in the word
    // if the Input == HiddenWord return true

    return true;
}