/*
 * plates.c
 *
 *  Created on: 07 mag 2018
 *      Author: gabriele
 */

#include "plates.h"

static bool is_valid_plate(char* plate){
	bool flag = true;
	for (int i=ZERO;i<strlen(plate)&&flag;)
		flag = isalnum(plate[i++]);
	return true;
}

static bool are_valid_chars_old_plate(char* plate){
	bool flag = true;
	for (int i=ZERO;i<strlen(plate)&&flag;i++)
		flag = (i==ZERO||i==ONE)?isupper(plate[i]):
				(i==TWO)?isalnum(plate[i]):isdigit(plate[i]);
	return flag;
}

static bool is_old_plate(char* plate){
	return strlen(plate)==OLD_LENGTH&&are_valid_chars_old_plate(plate);
}

static bool is_valid_char(char plate){
	return plate!=G&&plate!=I&&plate!=O&&plate!=Q&&plate!=U;
}

static bool index_to_upper(int i){
	return (i==ZERO||i==ONE||i==FIVE||i==SIX);
}

static bool are_valid_chars_new_plate(char* plate){
	bool flag = true;
	for (int i=ZERO;i<strlen(plate)&&flag;i++)
		flag=(index_to_upper(i))?
				(isupper(plate[i])&&is_valid_char(plate[i])):isdigit(plate[i]);
	return flag;
}

static bool is_new_plate(char* plate){
	return strlen(plate)==NEW_LENGTH&&are_valid_chars_new_plate(plate);
}

static bool is_valid_result(plate_t result){
	return result==NEW_PLATE||result==OLD_PLATE||result==UNRECOGNIZED;
}

plate_t check_plate(char* plate){
	assert(plate!=NULL&&is_valid_plate(plate));
	plate_t result = (is_new_plate(plate))?NEW_PLATE:
			(is_old_plate(plate))?OLD_PLATE:UNRECOGNIZED;
	assert(is_valid_result(result));
	return result;
}
