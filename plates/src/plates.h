/*
 * plates.h
 *
 *  Created on: 07 mag 2018
 *      Author: gabriele
 */

#ifndef PLATES_H_
#define PLATES_H_

#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ZERO        0
#define ONE         1
#define TWO         2
#define FIVE        5
#define SIX         6
#define NEW_LENGTH  7
#define OLD_LENGTH  8
#define G           'G'
#define I           'I'
#define O           'U'
#define Q           'Q'
#define U           'I'

/**
 * Tipo di targa
 */
typedef enum{
	NEW_PLATE,   //!< Targa di nuovo tipo (CCNNNCC)
	OLD_PLATE,   //!< Targa di vecchio tipo (CCNNNNNN)
	UNRECOGNIZED,//!< Targa di tipo sconosciuto
} plate_t;

bool is_new_plate(char* plate);

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
plate_t check_plate(char* plate);

#endif /* PLATES_H_ */
