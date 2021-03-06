/* $Id: $ */

/* Copyright (C) 1997 Sverre Hvammen Johansen and Terje Mjoes,
 * Department of Informatics, University of Oslo.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "cim.h"

/******************************************************************************
                                                        RutineInner          */

void
__rinner (plev)
     int plev;
{
  if (plev <
#if __CHAR_UNSIGNED__
      (signed char)
#endif
      __pb->pp->plev)
    {
      __goto = __pb->pp->pref[plev + 1]->adr;
      __goto.ent++;
    }
  else
    {
      __goto = __pb->pp->adr;
      __goto.ent += 2;
    }
}
