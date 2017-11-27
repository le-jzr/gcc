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

/* We reuse definitions from gnu-user.h, with minor modifications. */

/* Don't assume anything about the header files.  */
#define NO_IMPLICIT_EXTERN_C

/* TODO: switch to a more standard startfile naming. */
#undef  STARTFILE_SPEC
#define STARTFILE_SPEC "entry.o"

/* TODO: we currently have no endfile, and no support for static destructors. */
#undef  ENDFILE_SPEC
#define ENDFILE_SPEC ""

#undef  LIB_SPEC
#define LIB_SPEC "%{pthread:-lpthread -lposix} %{posix:-lposix} -lc -lsoftfloat -lsoftint"

#if defined(HAVE_LD_EH_FRAME_HDR)
#define LINK_EH_SPEC "%{!static:--eh-frame-hdr} "
#endif

#undef LINK_GCC_C_SEQUENCE_SPEC
#define LINK_GCC_C_SEQUENCE_SPEC \
  "%{static:--start-group} %G %L %{static:--end-group}%{!static:%G}"

/* Use --as-needed -lgcc_s for eh support.  */
#ifdef HAVE_LD_AS_NEEDED
#define USE_LD_AS_NEEDED 1
#endif

/* Pretend we have everything glibc has. */
#undef TARGET_LIBC_HAS_FUNCTION
#define TARGET_LIBC_HAS_FUNCTION gnu_libc_has_function

#undef CPLUSPLUS_CPP_SPEC
#define CPLUSPLUS_CPP_SPEC "%(cpp)"

#ifndef HELENOS_ARCH_CPP_SPEC
#define HELENOS_ARCH_CPP_SPEC
#endif

#undef CPP_SPEC
#define CPP_SPEC "%{posix:-D_POSIX_SOURCE} -D_REENTRANT"

/* This disables gcov. */
#undef TARGET_POSIX_IO

#define HELENOS_DYNAMIC_LINKER "/lib/ld.so.0"
#define HELENOS_DYNAMIC_LINKER32 "/lib/ld.so.0"
#define HELENOS_DYNAMIC_LINKER64 "/lib/ld64.so.0"
#define HELENOS_DYNAMIC_LINKERX32 "/lib/ldx32.so.0"

#define HELENOS_CPP_BUILTINS()						\
    do {								\
	builtin_define ("__HelenOS__");					\
	builtin_define ("__helenos__");					\
	builtin_assert ("system=HelenOS");				\
	builtin_assert ("system=helenos");				\
    } while (0)

#ifndef HELENOS_ARCH_OS_CPP_BUILTINS
#define HELENOS_ARCH_OS_CPP_BUILTINS()
#endif

#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()				\
  do								\
    {								\
	HELENOS_CPP_BUILTINS();					\
	HELENOS_ARCH_OS_CPP_BUILTINS();				\
    }								\
  while (0)

/* Some architectures need frame pointer, so I'm being lazy here. */
#undef  SUBTARGET_FRAME_POINTER_REQUIRED
#define SUBTARGET_FRAME_POINTER_REQUIRED 1

/* Not supported yet.  */
# undef TARGET_THREAD_SSP_OFFSET

/* Not supported yet.  */
# undef TARGET_CAN_SPLIT_STACK
# undef TARGET_THREAD_SPLIT_STACK_OFFSET

/* Not supported yet.  */
#undef STACK_CHECK_MOVING_SP
#undef STACK_CHECK_STATIC_BUILTIN

/* Add .note.GNU-stack.  */
#undef TARGET_ASM_FILE_END
#define TARGET_ASM_FILE_END file_end_indicate_exec_stack

/* SUBTARGET_FRAME_POINTER_REQUIRED somehow doesn't work on i386. More laziness. */
#define HELENOS_DRIVER_COMMON_SPECS "-fno-omit-frame-pointer"

#ifndef HELENOS_DRIVER_ARCH_SPECS
#define HELENOS_DRIVER_ARCH_SPECS ""
#endif

#undef  DRIVER_SELF_SPECS
#define DRIVER_SELF_SPECS  HELENOS_DRIVER_COMMON_SPECS, HELENOS_DRIVER_ARCH_SPECS

/* There is absolutely no reason for wchar_t and wint_t to vary with architecture. */

#undef WCHAR_TYPE
#define WCHAR_TYPE "int"
#undef WCHAR_TYPE_SIZE
#define WCHAR_TYPE_SIZE 32
#undef  WINT_TYPE
#define WINT_TYPE "int"

#undef PTRDIFF_TYPE
#define PTRDIFF_TYPE (LONG_TYPE_SIZE == 64 ? "long int" : "int")
#undef SIZE_TYPE
#define SIZE_TYPE (LONG_TYPE_SIZE == 64 ? "long unsigned int" : "unsigned int")

