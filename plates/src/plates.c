/*
 * plates.c
 *
 *  Created on: 07 mag 2018
 *      Author: gabriele
 */

#include "plates.h"

static bool is_valid_alpha(char plate){
	return isalpha(plate)&&plate!=G&&plate!=I&&plate!=O&&plate!=Q&&plate!=U;
}

static bool is_valid_new_plate_char(char plate, int i){
	return (i==ZERO||i==ONE||i==FIVE||i==SIX)?is_valid_alpha(plate):isdigit(plate);
}

static bool is_valid_new_plate_chars(char* plate){
	bool flag = true;
	for (int i=ZERO;i<strlen(plate)&&flag;i++)
		flag = is_valid_new_plate_char(plate[i],i);
	return flag;
}

static bool is_new_plate(char* plate){
	return strlen(plate)==NEW_PLATE_LENGTH&&is_valid_new_plate_chars(plate);
}

static bool is_valid_old_plate_char(char plate, int i){
	return (i==ZERO||i==ONE)?isalpha(plate):(i==TWO)?isalnum(plate):isdigit(plate);
}

static bool is_valid_old_plate_chars(char* plate){
	bool flag = true;
	for (int i=ZERO;i<strlen(plate)&&flag;i++)
		flag = is_valid_old_plate_char(plate[i],i);
	return flag;
}

static bool is_old_plate(char* plate){
	return strlen(plate)==OLD_PLATE_LENGTH&&is_valid_old_plate_chars(plate);
}

/**
 * Restituisce il tipo di targa.
 * La funzione riconosce due soli tipi di targa: vecchio tipo o nuovo tipo.
 * Per targhe di vecchio tipo, il metodo restituisce OLD_PLATE; per targhe di nuovo tipo
 * il metodo restituisce NEW_PLATE.
 * Se la funzione non riconosce il tipo di targa, restituisce
 * UNRECOGNIZED.
 * <p>
 * TARGHE DI VECCHIO TIPO <br>
 * Una targa di vecchio tipo e' costituita da 8 caratteri. I primi due caratteri sono
 * lettere, gli ultimi
 * cinque caratteri sono cifre. Il terzo carattere puo' essere lettera o cifra.
 * <p>
 * TARGHE DI NUOVO TIPO <br>
 * Una targa di nuovo tipo e' costituita da 7 caratteri.
 * I primi due caratteri e gli ultimi due caratteri
 * sono lettere AMMESSE. I tre caratteri centrali sono cifre.
 * Le lettere ammesse sono tutte le lettere
 * dell'alfabeto TRANNE: GIOQU
 * <p>
 * @pre plate non puo' essere null e deve essere costituita esclusivamente da caratteri
 * alfanumerici.
 * @post il valore restituito puo' essere solo OLD_PLATE, NEW_PLATE oppure
 * UNRECOGNIZED.
 * <p>
 * @param[in] plate la targa automobilistica
 * @return il tipo di targa
 */
plate_t check_plate(char* plate){
	assert(plate!=NULL);
	plate_t result=is_new_plate(plate)?NEW_PLATE:is_old_plate(plate)?OLD_PLATE:UNRECOGNIZED;
	assert(result==OLD_PLATE||result==NEW_PLATE||result==UNRECOGNIZED);
	return result;
}
