//
// Created by lecoqbeau on 10/16/24.
//

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <string>
#include <climits>
#include <cfloat>

#include <colors.h>

#define ERROR std::cerr <<
#define PRINT std::cout <<
#define AND <<
#define ENDL << std::endl
#define TAB "\t"
#define VOIDDEL delete static_cast<int*>

#define LOWER_ALPHABET "abcdefghijklmnopqrstuvwxyz"
#define UPPER_ALPHABET "ABCDEFGHIJKLMNOPQTSTUVWXYZ"

#define DIGITS "0123456789"

typedef enum e_type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    E_TYPE_END
} t_type;

class Serialize {
public:
    static void convert(const std::string &input);
private:
    // Canonical Orthodox Form
    Serialize();
    Serialize(const Serialize &rhs);
    Serialize operator=(const Serialize &rhs);
    ~Serialize();

    // Methods
    static t_type   identify(const std::string &input);
    static void     *convert(const std::string &input, t_type type);
    static void     print(void *value, t_type type);
};



#endif //SCALARCONVERTER_H
