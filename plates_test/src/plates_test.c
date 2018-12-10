/*
 ============================================================================
 Name        : plates_test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdlib.h>
#include "CUnit/basic.h"
#include "plates.h"

static const char* UNRECOGNIZED_PLATES = "unrecognized plates";
static const char* NEW_PLATES = "new plates";
static const char* OLD_PLATES = "old plates";
static const char* PLATES = "Plates";
static const int ZERO = 0;

char* oldPlates[] = {
	"AZ000000",
	"ZA999999",
	"GQI23456",
};

char* newPlates[] = {
	"AA000AA",
	"ZZ999ZZ",
	"BC234DE",
	"FH567JK",
	"LM890NP",
	"RS123TV",
	"WX456YZ",
};

char* unrPlates[] = {
	"AZ00000",	//una cifra in meno
	"AZ0000000",//una cifra in piu
	"Z000000",//una lettera in meno
	"AZ0X0000",//lettera al posto di una cifra
	"A4000000",//cifra al posto di una lettera

	"AA00AA",// cifra in meno
	"AA0090AA",// cifra in piu'
	"GQ999IU",// lettere inamissibili (semplificato)
	"A0000AA",// cifra al posto di lettera
	"AA00YAA",// lettera al posto di cifra
	"AA00A0A",// scambio di lettera
	"" ,// stringa vuota
};

void test_old_plates(void){
	for (int i = ZERO; i < sizeof(oldPlates) / sizeof(oldPlates[ZERO]);)
		CU_ASSERT_EQUAL(check_plate(oldPlates[i++]), OLD_PLATE);
}

void test_new_plates(void){
	for (int i = ZERO; i < sizeof(newPlates) / sizeof(newPlates[ZERO]);)
		CU_ASSERT_EQUAL(check_plate(newPlates[i++]), NEW_PLATE);
}

void test_unr_plates(void){
	for (int i = ZERO; i < sizeof(unrPlates) / sizeof(unrPlates[ZERO]);)
		CU_ASSERT_EQUAL(check_plate(unrPlates[i++]), UNRECOGNIZED);
}

/*
 * Funzioni di inizializzazione e pulizia delle suite.
 * Di default sono funzioni vuote.
 */
int init_suite_default(void){
	return ZERO;
}

int clean_suite_default(void){
	return ZERO;
}

/* **************************************************
 *	TEST di UNITA'
 */

int main(){

	/* inizializza registro - e' la prima istruzione */
	CU_initialize_registry();

	/* Aggiungi le suite al test registry */
	CU_pSuite pSuite_wd = CU_add_suite(PLATES, init_suite_default,
			clean_suite_default);

	/* Aggiungi i test alle suite
	 * NOTA - L'ORDINE DI INSERIMENTO E' IMPORTANTE
	 */
	CU_add_test(pSuite_wd, OLD_PLATES, test_old_plates);
	CU_add_test(pSuite_wd, NEW_PLATES, test_new_plates);
	CU_add_test(pSuite_wd, UNRECOGNIZED_PLATES, test_unr_plates);

	/* Esegue tutti i casi di test con output sulla console */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	/* Pulisce il registro e termina lo unit test */
	CU_cleanup_registry();

	return CU_get_error();
}


