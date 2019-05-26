/*
 * plates.c
 *
 *  Created on: 07 mag 2018
 *      Author: gabriele
 */

#include "plates.h"

#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static const int ZERO = 0;
static const int ONE = 1;
static const int TWO = 2;
static const int THREE = 3;
static const int FOUR = 4;
static const int SEVEN = 7;
static const int EIGHT = 8;
static const char U = 'U';
static const char Q = 'Q';
static const char O = 'O';
static const char I = 'I';
static const char G = 'G';

static bool is_valid_plate(char* plate){
	bool flag = true;
	for (int i = ZERO; i < strlen(plate) && flag;)
		flag = isalnum(plate[i++]);
	return flag;
}

static bool are_old_plate_chars(char* plate){
	bool flag = true;
	for (int i = ZERO; i < strlen(plate) && flag;)
		flag = (i == ZERO || i == ONE) ? isalpha(plate[i++]) :
				(i == TWO) ? isalnum(plate[i++]) : isdigit(plate[i++]);
	return flag;
}

static bool is_old_plate(char* plate){
	return strlen(plate) == EIGHT && are_old_plate_chars(plate);
}

static bool is_new_plate_alpha(char plate){
	return isalpha(plate) && plate != G && plate != I && plate != O
			&& plate != Q && plate != U;
}

static bool are_new_plate_chars(char* plate){
	bool flag = true;
	for (int i = ZERO; i < strlen(plate) && flag;)
		flag = (i == TWO || i == THREE || i == FOUR) ?
				isdigit(plate[i++]) : is_new_plate_alpha(plate[i++]);
	return flag;
}

static bool is_new_plate(char* plate){
	return strlen(plate) == SEVEN && are_new_plate_chars(plate);
}

plate_t check_plate(char* plate){
	assert(plate != NULL);
	assert(is_valid_plate(plate));
	plate_t result = (is_old_plate(plate)) ? OLD_PLATE :
			(is_new_plate(plate)) ? NEW_PLATE : UNRECOGNIZED;
	assert(result == NEW_PLATE || result == OLD_PLATE || result == UNRECOGNIZED);
	return result;
}
