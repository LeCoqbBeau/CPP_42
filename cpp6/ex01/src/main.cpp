//
// Created by lecoqbeau on 10/16/24.
//

#include <Serializer.h>
#include <cstdlib>
#include <ctime>

int main() {
	t_veryComplicatedData originalVeryComplicatedStorage;

	std::srand(std::time(__nullptr));
	originalVeryComplicatedStorage.complicatedNumber = std::time(__nullptr) % std::rand();
	originalVeryComplicatedStorage.complicatedString = "Hello World!";

	const uintptr_t raw = Serializer::serialize(&originalVeryComplicatedStorage);
	const t_veryComplicatedData* veryComplicatedStoragePointer = Serializer::deserialize(raw);


	NEWL;
	SHOW(originalVeryComplicatedStorage.complicatedString);
	SHOW(veryComplicatedStoragePointer->complicatedString);
	NEWL;
	SHOW(originalVeryComplicatedStorage.complicatedNumber);
	SHOW(veryComplicatedStoragePointer->complicatedNumber);
	NEWL;
}