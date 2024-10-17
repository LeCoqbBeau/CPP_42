//
// Created by mscheman on 10/16/24.
//

#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <iostream>
#include <string>
#include <stdint.h>
#include "colors.h"

#define PRINT std::cout <<
#define AND <<
#define ENDL << std::endl

typedef struct s_veryComplicatedData {
	int	complicatedNumber;
	std::string complicatedString;
} t_veryComplicatedData;

class Serializer {
public:
	static uintptr_t serialize(t_veryComplicatedData *complicatedPtr);
	static t_veryComplicatedData *deserialize(uintptr_t complicatedRawNumber);
private:
	Serializer();
};


#endif //SERIALIZER_H
