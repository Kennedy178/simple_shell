#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

/**
 * my_getline - reads input from a stream and stores it in a buffer.
 * 
 */

 /*Function to read input from stream and store it in a buffer */
/*does not return anything therefore no need for void*/
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream) {
static char buffer[BUFFER_SIZE];
static char *buffer_pos = buffer;
static size_t buffer_size = 0;
ssize_t result;
char *line_end;
/* Check for invalid arguments */
if (!lineptr || !n || !stream) {
return -1;
}
/* Read data into buffer if it is empty */
if (buffer_pos >= buffer + buffer_size) {
buffer_size = read(fileno(stream), buffer, BUFFER_SIZE);
buffer_pos = buffer;
if (buffer_size <= 0) {
return buffer_size;
}
}
/* Find end of line in buffer */
line_end = memchr(buffer_pos, '\n', buffer + buffer_size - buffer_pos);
if (line_end) {
/* Null-terminate the line and calculate its length */
*line_end = '\0';
result = line_end - buffer_pos + 1;
} else {
/* No end of line found - return remaining buffer data */
result = buffer + buffer_size - buffer_pos;
}
/* Allocate/reallocate lineptr buffer if necessary */
if (*lineptr && *n < (size_t)(result + 1)) {
*lineptr = realloc(*lineptr, result + 1);
if (!*lineptr) {
return -1;
}
} else if (!*lineptr) {
*lineptr = malloc(result + 1);
if (!*lineptr) {
return -1;
}
*n = result + 1;
}
memcpy(*lineptr, buffer_pos, result);
(*lineptr)[result] = '\0';
buffer_pos += result;
return result;
}
