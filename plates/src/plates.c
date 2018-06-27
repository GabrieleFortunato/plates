/*
 * plates.c
 *
 *  Created on: 07 mag 2018
 *      Author: gabriele
 */

#include "plates.h"

static const char U = 'U';
static const char Q = 'Q';
static const char O = 'O';
static const char I = 'I';
static const char G = 'G';
static const int OLD_PLATE_LENGTH = 8;
static const int NEW_PLATE_LENGTH = 7;
static const int FOUR = 4;
static const int THREE = 3;
static const int TWO = 2;
static const int ONE = 1;
static const int ZERO = 0;

static bool is_valid_plate(char* plate){
	bool flag = true;
	for (int i = ZERO; i < strlen(plate); i++)
		flag = isalnum(plate[i]);
	return flag;
}

static bool is_valid_alpha_new_plate(char a){
	return isalpha(a) && a != G && a != I && a != O && a != Q && a != U;
}

static bool are_valid_chars_new_plate(char* plate){
	bool flag = true;
	for (int i = ZERO; i < strlen(plate) && flag; i++)
		flag = (i == TWO || i == THREE || i == FOUR) ?
				isdigit(plate[i]) : is_valid_alpha_new_plate(plate[i]);
	return flag;
}

static bool is_new_plate(char* plate){
	return strlen(plate) == NEW_PLATE_LENGTH && are_valid_chars_new_plate(plate);
}

static bool are_valid_chars_old_plate(char* plate){
	bool flag = true;
	for (int i = ZERO; i < strlen(plate) && flag; i++)
		flag = (i == ZERO || i == ONE) ? isalpha(plate[i]) :
				(i == TWO) ? isalnum(plate[i]) : isdigit(plate[i]);
	return flag;
}

static bool is_old_plate(char* plate){
	return strlen(plate) == OLD_PLATE_LENGTH && are_valid_chars_old_plate(plate);
}

plate_t check_plate(char* plate){
	assert(plate!=NULL);
	assert(is_valid_plate(plate));
	plate_t result = is_new_plate(plate)?NEW_PLATE:is_old_plate(plate)?OLD_PLATE:UNRECOGNIZED;
	assert(result == NEW_PLATE || result == OLD_PLATE || result == UNRECOGNIZED);
	return result;
}
