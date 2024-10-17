//
// Created by mscheman on 10/16/24.
//

#include "Serializer.h"

uintptr_t Serializer::serialize(t_veryComplicatedData *complicatedPtr) {
	uintptr_t	raw = reinterpret_cast<uintptr_t>(complicatedPtr);
	PRINT BYLW "Serialized very complicated data pointer " CLR AND complicatedPtr;
	PRINT BYLW " into very complicated raw number: " CLR AND raw ENDL;
	return raw;
}

t_veryComplicatedData *Serializer::deserialize(uintptr_t complicatedRawNumber) {
	t_veryComplicatedData	*data = reinterpret_cast<t_veryComplicatedData	*>(complicatedRawNumber);
	PRINT BGRN "Deserialized very complicated raw number " CLR AND complicatedRawNumber;
	PRINT BGRN " into very complicated data pointer: " CLR AND data ENDL;
	return (data);
}
