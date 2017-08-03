// ---------------------------------------------------------------------
//
// Copyright (C) 2017 by the deal.II authors
//
// This file is part of the deal.II library.
//
// The deal.II library is free software; you can use it, redistribute
// it, and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full text of the license can be found in the file LICENSE at
// the top level of the deal.II distribution.
//
// ---------------------------------------------------------------------


// test the implementation of theh constexpr min/max functions
// in case deal.II is compiled with C++14 support, we only test
// the STL.


#include "../tests.h"
#include <deal.II/base/std_cxx14/algorithm.h>
#include <deal.II/base/logstream.h>
#include <fstream>
#include <iomanip>

constexpr bool comp (const int &a, const int &b)
{
  return b<a;
}


int main ()
{
  initlog();
  deallog.threshold_double(1.e-10);

  constexpr int max_1 = std_cxx14::max(0,1);
  deallog << max_1 << std::endl;
  constexpr int max_2 = std_cxx14::max(3,2,comp);
  deallog << max_2 << std::endl;

  constexpr int min_1 = std_cxx14::min(1,2);
  deallog << min_1 << std::endl;
  constexpr int min_2 = std_cxx14::min(1,2,comp);
  deallog << min_2 << std::endl;

  deallog << "OK" << std::endl;
}
