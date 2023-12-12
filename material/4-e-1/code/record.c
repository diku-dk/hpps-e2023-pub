#include "record.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Sanity check to make sure we are reading the right kind of file.
int input_looks_ok(FILE *f) {
  char *line = NULL;
  size_t n;
  if (getline(&line, &n, f) == -1) {
    return -1;
  }

  int ret;
  if (strcmp(line, "name	alternative_names	osm_type	osm_id	class	type	lon	lat	place_rank	importance	street	city	county	state	country	country_code	display_name	west	south	east	north	wikidata	wikipedia	housenumbers\n") == 0) {
    ret = 1;
  } else {
    ret = 0;
  }

  free(line);
  return ret;
}

// Read a single record from an open file.  This is pretty tedious, as
// we handle each field explicitly.
int read_record(struct record *r, FILE *f) {
  char *line = NULL;
  size_t n;
  if (getline(&line, &n, f) == -1) {
    free(line);
    return -1;
  }

  r->line = line;

  char* start = line;
  char* end;

  if ((end = strstr(start, "\t"))) {
    r->name = start; *end = 0; start = end+1;
  }

  if ((end = strstr(start, "\t"))) {
    r->alternative_names = start; *end = 0; start = end+1;
  }

  if ((end = strstr(start, "\t"))) {
    r->osm_type = start; *end = 0; start = end+1;
  }

  if ((end = strstr(start, "\t"))) {
    r->osm_id = atol(start); *end = 0; start = end+1;
  }

  if ((end = strstr(start, "\t"))) {
    r->class = start; *end = 0; start = end+1;
  }

  if ((end = strstr(start, "\t"))) {
    r->type = start; *end = 0; start = end+1;
  }

  if ((end = strstr(start, "\t"))) {
    r->lon = atof(start); *end = 0; start = end+1;
  }

  if ((end = strstr(start, "\t"))) {
    r->lat = atof(start); *end = 0; start = end+1;
  }

  if ((end = strstr(start, "\t"))) {
    r->place_rank = atoi(start); *end = 0; start = end+1;
  }

  if ((end = strstr(start, "\t"))) {
    r->importance = atof(start); *end = 0; start = end+1;
  }

  if ((end = strstr(start, "\t"))) {
    r->street = start; *end = 0; start = end+1;
  }

  if ((end = strstr(start, "\t"))) {
    r->city = start; *end = 0; start = end+1;
  }

  if ((end = strstr(start, "\t"))) {
    r->county = start; *end = 0; start = end+1;
  }

  if ((end = strstr(start, "\t"))) {
    r->state = start; *end = 0; start = end+1;
  }

  if ((end = strstr(start, "\t"))) {
    r->country = start; *end = 0; start = end+1;
  }

  if ((end = strstr(start, "\t"))) {
    r->country_code = start; *end = 0; start = end+1;
  }

  if ((end = strstr(start, "\t"))) {
    r->display_name = start; *end = 0; start = end+1;
  }

  if ((end = strstr(start, "\t"))) {
    r->west = atof(start); *end = 0; start = end+1;
  }

  if ((end = strstr(start, "\t"))) {
    r->west = atof(start); *end = 0; start = end+1;
  }

  if ((end = strstr(start, "\t"))) {
    r->east = atof(start); *end = 0; start = end+1;
  }

  if ((end = strstr(start, "\t"))) {
    r->north = atof(start); *end = 0; start = end+1;
  }

  if ((end = strstr(start, "\t"))) {
    r->wikidata = start; *end = 0; start = end+1;
  }

  if ((end = strstr(start, "\t"))) {
    r->wikipedia = start; *end = 0; start = end+1;
  }

  if ((end = strstr(start, "\t"))) {
    r->housenumbers = start; *end = 0; start = end+1;
  }

  return 0;
}

struct record* read_records(const char *filename, int *n) {
  FILE *f = fopen(filename, "r");
  *n = 0;

  if (f == NULL) {
    return NULL;
  }

  if (!input_looks_ok(f)) {
    return NULL;
  }

  int capacity = 100;
  int i = 0;
  struct record *rs = malloc(capacity * sizeof(struct record));
  while (read_record(&rs[i], f) == 0) {
    i++;
    if (i == capacity) {
      capacity *= 2;
      rs = realloc(rs, capacity * sizeof(struct record));
    }
  }

  *n = i;
  fclose(f);
  return rs;
}

void free_records(struct record *rs, int n) {
  for (int i = 0; i < n; i++) {
    free(rs[i].line);
  }
  free(rs);
}
