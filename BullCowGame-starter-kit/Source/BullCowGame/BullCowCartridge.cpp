// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"
// #include "Math/UnrealMathUtility.h" This library was contained in another header file, so its just a reminder

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    Isograms = GetValidWords(Words);

    SetupGame();

    // PrintLine(TEXT("The number of possible words is %i"), Words.Num());
    // PrintLine(TEXT("The number of valid words is: %i"), GetValidWords(Words).Num());
    // PrintLine(TEXT("ValidWords - 1 is: %i"), GetValidWords(Words).Num() -1);
}

void UBullCowCartridge::OnInput(const FString& PlayerInput) // When the player hits enter
{
    // else Checking players guess.
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else // Checking the PLayerGuess
    {
        ProcessGuess(PlayerInput);
    }
}

void UBullCowCartridge::SetupGame()
{
    // Welcoming the player.
    PrintLine(TEXT("Welcome to Bull Cows!"));

    HiddenWord = Isograms[FMath::RandRange(0, Isograms.Num() - 1)];
    Lives = HiddenWord.Len() * 2;
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    // PrintLine(TEXT("The HiddenWord is: %s"), *HiddenWord); // Debug line.
    PrintLine(TEXT("Press tab to enter to the terminal. :D"));
    PrintLine(TEXT("You have %i Lives!"), Lives);
    PrintLine(TEXT("Type in your guess and \npress enter to continue...")); // Prompt player for guess.
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("\nPress enter to play again."));
}

void UBullCowCartridge::ProcessGuess(const FString& Guess)
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
    FBullCowCount Score = GetBullCows(Guess);

    PrintLine(TEXT("You have %i Bulls and %i Cows"), Score.Bulls, Score.Cows);

    PrintLine(TEXT("Guess again, you have %i lives left"), Lives);
}

bool UBullCowCartridge::IsIsogram(const FString& Word) const
{
    // int32 Index = 0; // This is the same as below but with diferent scope, this variables exist in whole function.
    // int32 Comparison = Index + 1;

    for (int32 Index = 0; Index < Word.Len(); Index++)
    {
        for (int32 Comparison = Index + 1; Comparison < Word.Len(); Comparison++)
        {
            if (Word[Comparison] == Word[Index])
            {
                return false;
            }
        }
        
    }
    return true;
}

TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& WordList) const
{
    TArray<FString> ValidWords;

    for (FString Word : WordList)
    {
        if (Word.Len() >= 4 && Word.Len() <= 8 && IsIsogram(Word))
        {
            ValidWords.Emplace(Word);
        }
    }
    return ValidWords;
}

FBullCowCount UBullCowCartridge::GetBullCows(const FString& Guess) const
{
    FBullCowCount Count;

    for (int32 GuessIndex = 0; GuessIndex < Guess.Len(); GuessIndex++)
    {
        if (Guess[GuessIndex] == HiddenWord[GuessIndex])
        {
            Count.Bulls++;
            continue;
        }

        for (int32 HiddenIndex = 0; HiddenIndex < HiddenWord.Len(); HiddenIndex++)
        {
            if (Guess[GuessIndex] == HiddenWord[HiddenIndex])
            {
                Count.Cows++;
                break;
            }
        }
    }
    return Count;
}