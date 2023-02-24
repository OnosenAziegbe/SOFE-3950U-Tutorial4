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
#include "questions.h"

#define NUM_QUESTIONS 3
#define NUM_CATEGORIES 3

// The array of categories
//char *categories[NUM_CATEGORIES] = {"Programming","Algorithms", "Databases"};

// The array of questions
question questions[NUM_QUESTIONS];

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
    questions[0] = (question){"Programming", "What keyword is used to define a function?", "void", 100, false};
    questions[1] = (question){"Algorithms", "What is another name for the half-interval search, logarithmic search?", "BinarySearch", 200, false};
    questions[2] = (question){"Databases", "What is the name of the organized collection of data stored and accessed electronically?", "Database", 200, false};
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    printf("Categories:\n");
    for (int i = 0; i < NUM_CATEGORIES; i++) {
        printf("%s:\n", categories[i]);
        for (int j = 0; j < NUM_QUESTIONS; j++) {
            if (strcmp(questions[j].category, categories[i]) == 0 && questions[j].answered == false) {
                printf("$%d\n", questions[j].value);
            }
        }
    }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            printf("%s\n", questions[i].question);
            break;
        }
    }
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            if (strcmp(questions[i].answer, answer) == 0) {
                questions[i].answered = true;
                return true;
            }
            break;
        }
    }
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            if (questions[i].answered == true) {
                return true;
            }
            break;
        }
    }
    return false;
}
