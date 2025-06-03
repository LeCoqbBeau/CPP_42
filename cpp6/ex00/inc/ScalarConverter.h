//
// Created by lecoqbeau on 10/16/24.
//

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <utils.h>

#include <cerrno>
#include <cstdlib>
#include <climits>
#include <cfloat>

#define VOIDDEL delete static_cast<int*>
#define LOWER_ALPHABET "abcdefghijklmnopqrstuvwxyz"
#define UPPER_ALPHABET "ABCDEFGHIJKLMNOPQTSTUVWXYZ"

typedef enum e_type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    E_TYPE_END
} t_type;

class ScalarConverter {
    public:
        static void convert(str cref input);
    private:
        // Canonical Orthodox Form
        ScalarConverter();
        ScalarConverter(ScalarConverter cref rhs);
        ScalarConverter ref operator = (ScalarConverter cref rhs);
        ~ScalarConverter();

        // Methods
        static t_type   _identify(str cref input);
        static void     *_convert(str cref input, t_type type);
        static void     _print(void *value, t_type type);
};

#endif //SCALARCONVERTER_H
