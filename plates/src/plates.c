/*
 * plates.c
 *
 *  Created on: 07 mag 2018
 *      Author: gabriele
 */

#include "plates.h"

static bool is_valid_plate(char* plate){
	bool flag = true;
	for (int i=ZERO;i<strlen(plate)&&flag;i++)
		flag = isalnum(plate[i]);
	return flag;
}

static bool are_valid_char_old_plate(char* plate){
	bool flag = true;
	for (int i=ZERO;i<strlen(plate)&&flag;i++)
		flag = (i==ZERO||i==ONE)?isalpha(plate[i]):(i==TWO)?isalnum(plate[i]):isdigit(plate[i]);
	return flag;
}

static bool is_old_plate(char* plate){
	return strlen(plate)==OLD_PLATE_LENGTH&&are_valid_char_old_plate(plate);
}

static bool is_ok_alpha(char a){
	return isalpha(a)&&a!=G&&a!=I&&a!=O&&a!=Q&&a!=U;
}

static bool are_valid_char_new_plate(char* plate){
	bool flag = true;
	for (int i=ZERO;i<strlen(plate)&&flag;i++)
		flag = (i==ZERO||i==ONE||i==FIVE||i==SIX)?is_ok_alpha(plate[i]):isdigit(plate[i]);
	return flag;
}

static bool is_new_plate(char* plate){
	return strlen(plate)==NEW_PLATE_LENGTH&&are_valid_char_new_plate(plate);
}

plate_t check_plate(char* plate){
	assert(plate!=NULL);
	assert(is_valid_plate(plate));
	plate_t result = is_old_plate(plate)?OLD_PLATE:is_new_plate(plate)?NEW_PLATE:UNRECOGNIZED;
	assert(result==OLD_PLATE||result==NEW_PLATE||result==UNRECOGNIZED);
	return result;
}
