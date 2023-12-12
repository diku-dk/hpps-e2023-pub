#ifndef RECORD_H
#define RECORD_H

#include <stdio.h>
#include <stdint.h>

// An OpenStreetMap place record.  All the 'const char*' strings are
// pointers into the string stored in the 'line' field.  This string
// is "owned" by the record, meaning that it is freed exactly when the
// record itself is freed.
//
// You don't need to worry about the meaning of these fields.  The
// ones that matter are osm_id, lon, lat, and name.
struct record {
  const char *name;
  const char *alternative_names;
  const char *osm_type;
  int64_t osm_id;
  const char *class;
  const char *type;
  double lon;
  double lat;
  int place_rank;
  double importance;
  const char *street;
  const char *city;
  const char *county;
  const char *state;
  const char *country;
  const char *country_code;
  const char *display_name;
  double west;
  double south;
  double east;
  double north;
  const char *wikidata;
  const char *wikipedia;
  const char *housenumbers;

  // Not a real field - all the other char* elements are pointers into
  // this memory, which we can pass to free().
  char *line;
};

// Read an OpenStreetMap place names dataset from a given file.  On
// success, returns a pointer to the array of records read, and sets
// *n to the number of records.  Returns NULL on failure.
//
// Expects lines of form:
// Index,Date,Open,High,Low,Close,AdjustedClose,Volume
struct record* read_records(const char *filename, int *n);

// Free records returned by read_records().  The 'n' argument must
// correspond to the number of records, as produced by read_records().
void free_records(struct record *r, int n);

#endif
