/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#ifndef JEOPARDY_H_
#define JEOPARDY_H_

#include "players.h"

#define MAX_LEN 256

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Checks if a question has already been answered.
int is_question_done(int category, int value);

// Retrieves the question for the specified category and value.
char* get_question(int category, int value);

// Validates the answer to a question and updates the player's score.
int validate_answer(int category, int value, char *answer);

// Retrieves the answer to a question.
char* get_answer(int category, int value);

// Checks if the game is over.
int is_game_over();

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);

#endif /* JEOPARDY_H_ */




