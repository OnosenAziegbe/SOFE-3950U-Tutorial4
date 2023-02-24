/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#ifndef JEOPARDY_H_
#define JEOPARDY_H_

#define MAX_LEN 256

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
extern void tokenize(char *input, char **tokens);

// Checks if a question has already been answered.
extern int is_question_done(int category, int value);

// Retrieves the question for the specified category and value.
extern char* get_question(int category, int value);

// Validates the answer to a question and updates the player's score.
extern int validate_answer(int category, int value, char *answer);

// Retrieves the answer to a question.
extern char* get_answer(int category, int value);

// Checks if the game is over.
extern int is_game_over();

// Displays the game results for each player, their name and final score, ranked from first to last place
extern void show_results(player *players, int num_players);

#endif /* JEOPARDY_H_ */