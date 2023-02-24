/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here
int num_categories = 0;
int num_questions = 0;

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players) {
    // Sort players by score
    for (int i = 0; i < num_players; i++) {
        for (int j = i + 1; j < num_players; j++) {
            if (players[j].score > players[i].score) {
                player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }

    // Display results
    printf("\nFinal results:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: $%d\n", players[i].name, players[i].score);
    }
}

int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter name for player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
    printf("\n");

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
        // Call functions from the questions and players source files
        char *tokens[BUFFER_LEN] = { 0 };
        tokenize(buffer, tokens);

        // Check for valid question selection
        int category = atoi(tokens[0]);
        int value = atoi(tokens[1]);
        if (category < 0 || category >= num_categories || value < 0 || value >= num_questions) {
            printf("Invalid question selection\n");
            continue;
        }
        if (is_question_done(category, value)) {
            printf("Question already answered\n");
            continue;
        }

        // Display the question and retrieve the user's answer
        char *question = get_question(category, value);
        printf("%s\n", question);
        printf("Enter your answer: ");
        fgets(buffer, BUFFER_LEN, stdin);

        // Check the user's answer and update their score
        int score = validate_answer(category, value, buffer);
        if (score > 0) {
            printf("Correct! You have earned $%d.\n", score);
            update_score(players, NUM_PLAYERS, tokens[2], score);
        } else {
            printf("Incorrect! The answer was \"%s\".\n", get_answer(category, value));
            update_score(players, NUM_PLAYERS, tokens[2], -value);
        }

        // Check if the game is over
        if (is_game_over()) {
            break;
        }
    }

    // Display the final results and exit
    show_results(players, NUM_PLAYERS);
    return EXIT_SUCCESS;
}

// Tokenize the input buffer into whitespace-separated tokens
void tokenize(char *input, char **tokens) {
    char *token = strtok(input, " \t\n");
    int i = 0;
    while (token != NULL) {
        tokens[i] = token;
        token = strtok(NULL," \t\n");
        i++;
  }
}