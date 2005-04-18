/*
 * cpwline.h - coplanar waveguide line class definitions
 *
 * Copyright (C) 2004, 2005 Vincent Habchi, F5RCS <10.50@free.fr>
 * Copyright (C) 2004, 2005 Stefan Jahn <stefan@lkcc.org>
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this package; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * $Id: cpwline.h,v 1.6 2005/04/07 11:57:50 raimi Exp $
 *
 */

#ifndef __CPWLINE_H__
#define __CPWLINE_H__

class cpwline : public circuit
{
 public:
  cpwline ();
  void initSP (void);
  void calcSP (nr_double_t);
  void calcNoiseSP (nr_double_t);
  void initDC (void);
  void initTR (void);
  void initAC (void);
  void calcAC (nr_double_t);
  void calcNoiseAC (nr_double_t);

  static void ellipke (nr_double_t, nr_double_t &, nr_double_t &);
  static nr_double_t ellipk (nr_double_t);
  static nr_double_t ellipa (nr_double_t);

 private:
  void calcAB (nr_double_t, nr_double_t&, nr_double_t&, nr_double_t&);
  void initPropagation (void);

  nr_double_t sr_er;
  nr_double_t sr_er0;
  nr_double_t zl_factor;
  nr_double_t ac_factor;
  nr_double_t ad_factor;
  nr_double_t bt_factor;
  nr_double_t fte, G;
  nr_double_t len, tand, rho;
};

#endif /* __CPWLINE_H__ */