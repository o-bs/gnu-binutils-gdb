/* ld.h -

   Copyright (C) 1991, 1993 Free Software Foundation, Inc.

   This file is part of GLD, the Gnu Linker.

   GLD is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   GLD is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GLD; see the file COPYING.  If not, write to
   the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */

#ifndef LD_H
#define LD_H

/* Extra information we hold on sections */
typedef struct  user_section_struct
{
  /* Pointer to the section where this data will go */
  struct lang_input_statement_struct *file;
} section_userdata_type;


#define get_userdata(x) ((x)->userdata)

#define BYTE_SIZE	(1)
#define SHORT_SIZE	(2)
#define LONG_SIZE	(4)
#define QUAD_SIZE	(8)

/* ALIGN macro changed to ALIGN_N to avoid	*/
/* conflict in /usr/include/machine/machparam.h */
/* WARNING: If THIS is a 64 bit address and BOUNDARY is a 32 bit int,
   you must coerce boundary to the same type as THIS.
   ??? Is there a portable way to avoid this.  */
#define ALIGN_N(this, boundary) \
  ((( (this) + ((boundary) -1)) & (~((boundary)-1))))

typedef struct
{
  /* 1 => assign space to common symbols even if `relocatable_output'.  */
  boolean force_common_definition;
  boolean relax;
} args_type;

extern args_type command_line;

typedef int token_code_type;

typedef struct 
{
  bfd_size_type specified_data_size;
  boolean magic_demand_paged;
  boolean make_executable;

  /* If true, doing a dynamic link.  */
  boolean dynamic_link;

  boolean build_constructors;

  /* If true, warn about merging common symbols with others.  */
  boolean warn_common;

  boolean sort_common;

  boolean text_read_only;

  char *map_filename;
  FILE *map_file;

  boolean stats;
} ld_config_type;

extern ld_config_type config;

typedef enum
{
  lang_first_phase_enum,
  lang_allocating_phase_enum,
  lang_final_phase_enum
} lang_phase_type;

extern boolean had_script;
extern boolean force_make_executable;

extern int yyparse PARAMS ((void));

#endif
