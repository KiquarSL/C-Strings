#ifndef STR_H
#define STR_H

/**
 * @file str.h
 * @brief Dynamic strings library for C
 * 
 * Provides automatic memory management for strings with length and capacity tracking.
 * Supports binary data (does not rely on null-terminator).
 * 
 * @author KiquarSL
 * @version 2.0
 */

#include <stddef.h>    // size_t
#include <sys/types.h> // ssize_t
#include <stdbool.h>   // bool

/**
 * @def MIN_CAPACITY
 * @brief Minimum initial capacity for a new string (in bytes)
 */
#define MIN_CAPACITY 10

/**
 * @brief Dynamic string structure
 * 
 * Not a C-string (no trailing '\\0' guaranteed).
 * Use @ref to_cstr to get a null-terminated copy.
 */
typedef struct str {
    char* text;   ///< Pointer to character data
    size_t len;   ///< Current length of the string
    size_t cap;   ///< Allocated capacity (in bytes)
} str;

/**
 * @brief Result of string splitting
 * 
 * Contains an array of C-strings and their count.
 * Each string is null-terminated and must be freed separately.
 */
typedef struct splited {
    char** text;  ///< Array of C-strings
    size_t size;  ///< Number of strings in the array
} splited;

/**
 * @brief Creates a new empty string with minimum capacity
 * @return Pointer to new string, or NULL on allocation failure
 * @code
 * str* s = str_new();
 * // ... use s ...
 * str_free(s);
 * @endcode
 */
str* str_new();

/**
 * @brief Creates a new empty string with a specified initial capacity
 * @param cap Initial capacity (will be rounded up to MIN_CAPACITY if smaller)
 * @return Pointer to new string, or NULL on allocation failure
 * @code
 * str* s = str_new_cap(100); // preallocate for 100 chars
 * @endcode
 */
str* str_new_cap(size_t cap);

/**
 * @brief Creates a string from a C-string (copies the data)
 * @param text Input null-terminated string
 * @return Pointer to new string, or NULL on allocation failure
 * @code
 * str* s = to_str("Hello, World!");
 * printf("%zu\n", str_len(s)); // 13
 * @endcode
 */
str* to_str(char* text);

/**
 * @brief Frees the string and its internal buffer
 * @param s Pointer to the string
 * @code
 * str_free(s);
 * @endcode
 */
void str_free(str* s);

/**
 * @brief Appends a formatted string (like printf) to the end
 * @param s Target string
 * @param fmt Format string (printf-style)
 * @param ... Arguments for the format
 * @return Pointer to the string (for chaining)
 * @code
 * str* s = to_str("Result: ");
 * str_pushf(s, "x = %d, y = %f", 42, 3.14);
 * @endcode
 */
str* str_pushf(str* s, char* fmt, ...);

/**
 * @brief Appends a single character to the end
 * @param s Target string
 * @param c Character to append
 * @return Pointer to the string (for chaining)
 * @code
 * str* s = to_str("Hell");
 * str_push(s, 'o'); // s is now "Hello"
 * @endcode
 */
str* str_push(str* s, char c);

/**
 * @brief Appends a C-string to the end
 * @param s Target string
 * @param text Null-terminated string to append
 * @return Pointer to the string (for chaining)
 * @code
 * str* s = to_str("Hello");
 * str_push_cstr(s, ", World!"); // "Hello, World!"
 * @endcode
 */
str* str_push_cstr(str* s, char* text);

/**
 * @brief Appends another string to the end
 * @param s Target string
 * @param s2 Source string to append
 * @return Pointer to the string (for chaining)
 * @code
 * str* a = to_str("Hello");
 * str* b = to_str(", World!");
 * str_push_str(a, b); // a is now "Hello, World!"
 * @endcode
 */
str* str_push_str(str* s, str* s2);

/**
 * @brief Inserts a character at the specified position
 * @param s Target string
 * @param pos Position (0-based). Must be <= str_len(s)
 * @param c Character to insert
 * @return Pointer to the string (for chaining)
 * @code
 * str* s = to_str("Helo");
 * str_ins(s, 3, 'l'); // "Hello"
 * @endcode
 */
str* str_ins(str* s, size_t pos, char c);

/**
 * @brief Inserts a C-string at the specified position
 * @param s Target string
 * @param pos Position (0-based). Must be <= str_len(s)
 * @param text Null-terminated string to insert
 * @return Pointer to the string (for chaining)
 * @code
 * str* s = to_str("Hello!");
 * str_ins_cstr(s, 5, " World"); // "Hello World!"
 * @endcode
 */
str* str_ins_cstr(str* s, size_t pos, char* text);

/**
 * @brief Inserts another string at the specified position
 * @param s Target string
 * @param pos Position (0-based). Must be <= str_len(s)
 * @param s2 Source string to insert
 * @return Pointer to the string (for chaining)
 * @code
 * str* s = to_str("Hello!");
 * str* s2 = to_str(" World");
 * str_ins_str(s, 5, s2); // "Hello World!"
 * @endcode
 */
str* str_ins_str(str* s, size_t pos, str* s2);

/**
 * @brief Returns a null-terminated copy of the string
 * @param s Source string
 * @return Newly allocated C-string (must be freed with free()), or NULL on error
 * @code
 * str* s = to_str("Hello");
 * char* cstr = to_cstr(s);
 * printf("%s\n", cstr);
 * free(cstr);
 * @endcode
 */
char* to_cstr(str* s);

/**
 * @brief Returns the length of the string
 * @param s Source string
 * @return Number of characters (bytes) in the string
 * @code
 * str* s = to_str("Hello");
 * size_t len = str_len(s); // 5
 * @endcode
 */
size_t str_len(str* s);

/**
 * @brief Returns a pointer to the character at the specified index
 * @param s Source string
 * @param index Position (0-based). Must be < str_len(s)
 * @return Pointer to the character, or NULL if index is out of bounds
 * @code
 * str* s = to_str("Magic");
 * char c = *str_get(s, 1); // 'a'
 * @endcode
 */
char* str_get(str* s, size_t index);

/**
 * @brief Extracts a substring as a new C-string (copy)
 * @param s Source string
 * @param index Start position (0-based)
 * @param len Number of characters to extract
 * @return Newly allocated C-string (must be freed), or NULL if out of bounds
 * @code
 * str* s = to_str("Hello!");
 * char* subs = str_subs(s, 0, 4); // "Hell"
 * free(subs);
 * @endcode
 */
char* str_subs(str* s, size_t index, size_t len);

/**
 * @brief Splits the string by a delimiter
 * @param s Source string
 * @param divider Delimiter character
 * @return Splitted structure with C-strings, or NULL on allocation failure
 * @code
 * str* s = to_str("apple,banana,cherry");
 * splited* parts = str_split(s, ',');
 * for (size_t i = 0; i < parts->size; i++) {
 *     printf("%s\n", parts->text[i]);
 * }
 * // Remember to free each string and the structure
 * @endcode
 */
splited* str_split(str* s, char divider);

/**
 * @brief Finds the first occurrence of a substring (left-to-right)
 * @param s Source string
 * @param to_find Substring to search for
 * @return Position of the first occurrence, or -1 if not found
 * @code
 * str* s = to_str("Hello, World!");
 * ssize_t pos = str_lfind(s, "World"); // 7
 * @endcode
 */
ssize_t str_lfind(str* s, char* to_find);

/**
 * @brief Finds the last occurrence of a substring (right-to-left)
 * @param s Source string
 * @param to_find Substring to search for
 * @return Position of the last occurrence, or -1 if not found
 * @code
 * str* s = to_str("Hello, World!");
 * ssize_t pos = str_rfind(s, "o"); // 8 (last 'o' in "World")
 * @endcode
 */
ssize_t str_rfind(str* s, char* to_find);

/**
 * @brief Replaces all occurrences of `from` with `to`
 * @param s Target string
 * @param from Substring to replace
 * @param to Replacement substring
 * @return true if at least one replacement was made, false otherwise
 * @code
 * str* s = to_str("Hello, World!");
 * str_rep(s, "World", "C-Strings"); // "Hello, C-Strings!"
 * @endcode
 */
bool str_rep(str* s, char* from, char* to);

/**
 * @brief Compares two strings lexicographically (byte-by-byte)
 * @param s1 First string
 * @param s2 Second string
 * @return 0 if equal, <0 if s1 < s2, >0 if s1 > s2
 * @code
 * str* a = to_str("apple");
 * str* b = to_str("banana");
 * int cmp = str_cmp(a, b); // cmp < 0
 * @endcode
 */
int str_cmp(str* s1, str* s2);

#endif // STR_H