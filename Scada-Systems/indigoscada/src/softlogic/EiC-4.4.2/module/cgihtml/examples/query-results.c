/* query-results.c - generic query program using either GET or POST
   Eugene Kim, eekim@fas.harvard.edu
   $Id: query-results.c,v 1.2 1998/05/05 19:42:59 edb Exp $

   Copyright (C) 1996 Eugene Eric Kim
   All Rights Reserved
*/

#include <stdio.h>
#include "cgi-lib.h"
#include "html-lib.h"

int main()
{
  llist entries;
  int status;

  html_header();
  html_begin("Query Results");
  status = read_cgi_input(&entries);
  printf("<h1>Status = %d</h1>\n",status);
  h1("Query results");
  print_entries(entries);
  html_end();
  list_clear(&entries);
  return 0;
}
