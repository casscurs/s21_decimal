# s21_decimal

This is a collaborative project developed by students of School 21 in Moscow: Aftonbur, Aquamanp, Arvillaj, and Jesicahi.

## Chapter I

### Binary Representation

A Decimal number is represented in binary as a combination of a sign bit, a 96-bit integer, and a scaling factor that divides the integer to specify the decimal fraction. The scaling factor, implicitly 10, is raised to an exponent ranging from 0 to 28.

A Decimal number can be implemented using a four-element array of 32-bit signed integers (`int bits[4]`).

- `bits[0]`, `bits[1]`, and `bits[2]` represent the low, middle, and high 32 bits of the 96-bit integer, respectively.
- `bits[3]` contains the scale factor and sign:
  - Bits 0 to 15 are unused and must be zero.
  - Bits 16 to 23 contain an exponent between 0 and 28.
  - Bits 24 to 30 are unused and must be zero.
  - Bit 31 contains the sign, with 0 for positive and 1 for negative.

### Example:

```c
typedef struct {
    int bits[4];
} s21_decimal;
```
Arithmetic Operators
| Operator                | Operators | Function                                                |
|-------------------------|-----------|---------------------------------------------------------|
| Addition                | +         | `int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)` |
| Subtraction             | -         | `int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)` |
| Multiplication          | *         | `int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)` |
| Division                | /         | `int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)` |

The functions return error codes:

- 0: OK
- 1: Number too large or equal to infinity
- 2: Number too small or equal to negative infinity
- 3: Division by 0

Comparison Operators
| Operator                | Operators | Function                                                |
|-------------------------|-----------|---------------------------------------------------------|
| Less than               | <         | `int s21_is_less(s21_decimal, s21_decimal)`             |
| Less than or equal to   | <=        | `int s21_is_less_or_equal(s21_decimal, s21_decimal)`    |
| Greater than            | >         | `int s21_is_greater(s21_decimal, s21_decimal)`          |
| Greater than or equal to| >=        | `int s21_is_greater_or_equal(s21_decimal, s21_decimal)` |
| Equal to                | ==        | `int s21_is_equal(s21_decimal, s21_decimal)`            |
| Not equal to            | !=        | `int s21_is_not_equal(s21_decimal, s21_decimal)`        |

Return value:

- 0: FALSE
- 1: TRUE

Converters and Parsers
| Convertor/Parser       | Function                                                |
|------------------------|---------------------------------------------------------|
| From int               | `int s21_from_int_to_decimal(int src, s21_decimal *dst)` |
| From float             | `int s21_from_float_to_decimal(float src, s21_decimal *dst)` |
| To int                 | `int s21_from_decimal_to_int(s21_decimal src, int *dst)` |
| To float               | `int s21_from_decimal_to_float(s21_decimal src, float *dst)` |

Return value - error code:

- 0: OK
- 1: Conversion error

Other Functions
| Description            | Function                                                |
|------------------------|---------------------------------------------------------|
| Round to floor         | `int s21_floor(s21_decimal value, s21_decimal *result)` |
| Round to nearest integer | `int s21_round(s21_decimal value, s21_decimal *result)` |
| Truncate fractional digits | `int s21_truncate(s21_decimal value, s21_decimal *result)` |
| Negate value           | `int s21_negate(s21_decimal value, s21_decimal *result)` |

Return value - error code:

- 0: OK
- 1: Calculation error

Chapter II

Part 1. Implementation of the s21_decimal.h Library Functions
The functions of the s21_decimal.h library described above must be implemented with the following guidelines:

- Developed in C language of C11 standard using gcc compiler
- Code located in the src folder on the develop branch
- Follow the Google style guide
- Static library with the s21_decimal.h header file
- Developed according to structured programming principles
- Use prefix s21_ before each function
- Full coverage of library functions with unit-tests using the Check library
- Unit tests covering at least 80% of each function (checked using gcov)
- Provide a Makefile for building the library and tests (with targets all, clean, test, s21_decimal.a, gcov_report)
- The gcov_report target generates an HTML page
- Avoid using the __int128 type
- Trailing zeros can be preserved or deleted (except for the s21_truncate function)
- Support numbers from -79,228,162,514,264,337,593,543,950,335 to +79,228,162,514,264,337,593,543,950,335
