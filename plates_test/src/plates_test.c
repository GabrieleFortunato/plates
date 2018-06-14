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
#include "CUnit/Basic.h"
#include "plates.h"
#include <stdio.h>

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
	int n_elements = sizeof(oldPlates) / sizeof(oldPlates[0]);
	for(int i=0; i<n_elements; i++)
		CU_ASSERT_EQUAL(check_plate(oldPlates[i]), OLD_PLATE);
}

void test_new_plates(void){
	int n_elements = sizeof(newPlates) / sizeof(newPlates[0]);
	for(int i=0; i<n_elements; i++)
		CU_ASSERT_EQUAL(check_plate(newPlates[i]), NEW_PLATE);
}

void test_unr_plates(void){
	int n_elements = sizeof(unrPlates) / sizeof(unrPlates[0]);
	for(int i=0; i<n_elements; i++)
		CU_ASSERT_EQUAL(check_plate(unrPlates[i]), UNRECOGNIZED);
}


/*
 * Funzioni di inizializzazione e pulizia delle suite.
 * Di default sono funzioni vuote.
 */
int init_suite_default(void)
{
	return 0;
}

int clean_suite_default(void)
{
	return 0;
}

/* **************************************************
 *	TEST di UNITA'
 */

int main()
{

	/* inizializza registro - e' la prima istruzione */
	CU_initialize_registry();

	/* Aggiungi le suite al test registry */
	CU_pSuite pSuite_wd = CU_add_suite("Old plates", init_suite_default,
			clean_suite_default);

	/* Aggiungi i test alle suite
	 * NOTA - L'ORDINE DI INSERIMENTO E' IMPORTANTE
	 */
	CU_add_test(pSuite_wd, "old plates", test_old_plates);
	CU_add_test(pSuite_wd, "new plates", test_new_plates);
	CU_add_test(pSuite_wd, "unrecognized plates", test_unr_plates);

	/* Esegue tutti i casi di test con output sulla console */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	/* Pulisce il registro e termina lo unit test */
	CU_cleanup_registry();

	return CU_get_error();
}

