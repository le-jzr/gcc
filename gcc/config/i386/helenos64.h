/* Definitions for HelenOS.
   Copyright (C) 1996-2017 Free Software Foundation, Inc.
   Copyright (C) 2017 CZ.NIC, z.s.p.o.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

/* Most of this is copied from gnu*.h with minor modifications. */

/* Provide a LINK_SPEC.  Here we provide support for the special GCC
   options -static and -shared, which allow us to link things in one
   of these three modes by applying the appropriate combinations of
   options at link-time.

   When the -shared link option is used a final link is not being
   done.  */

#if TARGET_64BIT_DEFAULT
#define SPEC_32 "m16|m32"
#if TARGET_BI_ARCH == 2
#define SPEC_64 "m64"
#define SPEC_X32 "m16|m32|m64:;"
#else
#define SPEC_64 "m16|m32|mx32:;"
#define SPEC_X32 "mx32"
#endif
#else
#define SPEC_32 "m64|mx32:;"
#define SPEC_64 "m64"
#define SPEC_X32 "mx32"
#endif

#undef ASM_SPEC
#define ASM_SPEC "%{" SPEC_32 ":--32} \
 %{" SPEC_64 ":--64} \
 %{" SPEC_X32 ":--x32} \
 %{!mno-sse2avx:%{mavx:-msse2avx}} %{msse2avx:%{!mavx:-msse2avx}}"

#undef	LINK_SPEC
#define LINK_SPEC				   \
                  "%{" SPEC_64 ":-m elf_x86_64} \
                   %{" SPEC_32 ":-m elf_i386} \
                   %{" SPEC_X32 ":-m elf_i386} \
  %{shared:-shared} \
  %{!shared: \
    %{!static: \
      %{rdynamic:-export-dynamic} \
      %{" SPEC_32 ":-dynamic-linker " HELENOS_DYNAMIC_LINKER32 "} \
      %{" SPEC_64 ":-dynamic-linker " HELENOS_DYNAMIC_LINKER64 "} \
      %{" SPEC_X32 ":-dynamic-linker " HELENOS_DYNAMIC_LINKERX32 "}} \
    %{static:-static}}"

#if TARGET_64BIT_DEFAULT
#if TARGET_BI_ARCH == 2
#define MULTILIB_DEFAULTS { "mx32" }
#else
#define MULTILIB_DEFAULTS { "m64" }
#endif
#else
#define MULTILIB_DEFAULTS { "m32" }
#endif

