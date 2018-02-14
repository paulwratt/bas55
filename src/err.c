/* ===========================================================================
 * bas55, an implementation of the Minimal BASIC programming language.
 *
 * Error reporting functions and error texts.
 * ===========================================================================
 */

#include <config.h>
#include "ecma55.h"
#include <ctype.h>
#include <string.h>

static const char *s_errors[] = {
	"ok",
	"not enough memory",
	"invalid line number",
	"line too long",
	"invalid command",
	"index out of range",
	"stack overflow",
	"stack underflow",
	"syntax error",
	"line not in program",
	"OPTION redeclared",
	"invalid OPTION after arrays",
	"redimensioned variable",
	"type mismatch",
	"invalid DIM subscript",
	"numeric variable as array",
	"array too big",
	"program ram too big",
	"NEXT without FOR",
	"string not terminated",
	"invalid TAB argument",
	"function redeclared",
	"function argument as array",
	"undefined function",
	"wrong number of parameters",
	"insuficient input data",
	"too much input data",
	"error on input stream",
	"numeric constant overflow",
	"jump into FOR block",
	"file name too long",
	"end of file",
	"couldn't open file",
	"no space after line number",
	"line without instructions",
	"wrong number of arguments",
	"bad file name",
	"program must have an END statement",
	"line after an END statement",
	"division by zero",
	"operation overflow",
	"zero raised to negative value",
	"negative value raised to non-integral value",
	"FOR without NEXT",
	"outer FOR uses the same variable",
	"function domain error",
	"invalid characters",
	"duplicated line number",
	"invalid line order",
	"number too big",
	"variable used before value assigned",
	"insufficient data for READ",
	"reading string into numeric variable",
	"no space after keyword"
};

/* Prints the error code on stderr. */
void eprint(enum error_code ecode)
{
	fputs("error: ", stderr);
	fputs(s_errors[ecode], stderr);
	fputc(' ', stderr);
}

/*
 * Prints the error code and the line lineno on stderr.
 * If lineno <= 0, doesn't print the line number.
 */
void eprintln(enum error_code ecode, int lineno)
{
	if (lineno > 0)
		fprintf(stderr, "%d: ", lineno);
	eprint(ecode);
}

/* Prints the error code on stderr as a warning. */
void wprint(enum error_code ecode)
{
	fputs("warning: ", stderr);
	fputs(s_errors[ecode], stderr);
	fputc(' ', stderr);
}

/*
 * Prints the error code as a warning and the line lineno on stderr.
 * If lineno <= 0, doesn't print the line number.
 */
void wprintln(enum error_code ecode, int lineno)
{
	if (lineno > 0)
		fprintf(stderr, "%d: ", lineno);
	wprint(ecode);
}

/* Prints \n on stderr. */
void enl(void)
{
	fputc('\n', stderr);
}

/* Prints the program name on stderr. */
void eprogname(void)
{
	fprintf(stderr, PACKAGE": ");
}
