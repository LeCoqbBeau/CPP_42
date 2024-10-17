//
// Created by lecoqbeau on 10/16/24.
//

#include <Serializer.h>

int main() {
	t_veryComplicatedData originalVeryComplicatedStorage;

	originalVeryComplicatedStorage.complicatedNumber = 512;
	originalVeryComplicatedStorage.complicatedString = "Hello World!";

	uintptr_t raw = Serializer::serialize(&originalVeryComplicatedStorage);

	t_veryComplicatedData *veryComplicatedStoragePointer;
	veryComplicatedStoragePointer = Serializer::deserialize(raw);

	PRINT "" ENDL;

	PRINT BPRP "Original very complicated storage's complicated string: " CLR AND originalVeryComplicatedStorage.complicatedString ENDL;
	PRINT BCYN "Very complicated storage pointer's complicated string: " CLR AND veryComplicatedStoragePointer->complicatedString ENDL;

	PRINT "" ENDL;

	PRINT BPRP "Original very complicated storage's complicated number: " CLR AND originalVeryComplicatedStorage.complicatedNumber ENDL;
	PRINT BCYN "Very complicated storage pointer's complicated number: " CLR AND veryComplicatedStoragePointer->complicatedNumber ENDL;

	PRINT "" ENDL;
}