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

/* Unsigned char produces much better code than signed.  */
#define DEFAULT_SIGNED_CHAR 0

#ifdef __cplusplus__
extern "C" {
#endif
extern void __helenos_clear_instruction_cache(void *begin, void *end);
#ifdef __cplusplus__
}
#endif

#define CLEAR_INSN_CACHE(begin, end) __helenos_clear_instruction_cache(begin, end)

#undef  HELENOS_ARCH_OS_CPP_BUILTINS
#define HELENOS_ARCH_OS_CPP_BUILTINS() TARGET_BPABI_CPP_BUILTINS()

#undef  FPUTYPE_DEFAULT
#define FPUTYPE_DEFAULT "vfp"

#undef  TARGET_DEFAULT_FLOAT_ABI
#define TARGET_DEFAULT_FLOAT_ABI ARM_FLOAT_ABI_SOFT

/* We default to the "aapcs-linux" ABI so that enums are int-sized by
   default.  */
#undef  ARM_DEFAULT_ABI
#define ARM_DEFAULT_ABI ARM_ABI_AAPCS_LINUX

/* TARGET_BIG_ENDIAN_DEFAULT is set in
   config.gcc for big endian configurations.  */
#undef  TARGET_LINKER_EMULATION
#if TARGET_BIG_ENDIAN_DEFAULT
#define TARGET_ENDIAN_OPTION     "mbig-endian"
#define TARGET_LINKER_EMULATION "armelfb_helenos"
#else
#define TARGET_ENDIAN_OPTION     "mlittle-endian"
#define TARGET_LINKER_EMULATION "armelf_helenos"
#endif

#undef  SUBTARGET_EXTRA_LINK_SPEC
#define SUBTARGET_EXTRA_LINK_SPEC " -m " TARGET_LINKER_EMULATION

#undef LINK_SPEC
#define LINK_SPEC EABI_LINK_SPEC "%{h*} \
   %{static:-Bstatic} \
   %{shared:-shared} \
   %{symbolic:-Bsymbolic} \
   %{!static: \
     %{rdynamic:-export-dynamic} \
     %{!shared:-dynamic-linker " HELENOS_DYNAMIC_LINKER "}} \
   -X \
   %{mbig-endian:-EB} %{mlittle-endian:-EL}" \
   SUBTARGET_EXTRA_LINK_SPEC

#undef MULTILIB_DEFAULTS

#undef LIBGCC_SPEC

// TODO: We currently use APCS frame, but eventually we want to switch to
// a metadata-based unwinder.
#undef  TARGET_DEFAULT
#define TARGET_DEFAULT (MASK_APCS_FRAME | MASK_INTERWORK | TARGET_ENDIAN_DEFAULT)

/* Call the function profiler with a given profile label.  */
#undef  ARM_FUNCTION_PROFILER
#define ARM_FUNCTION_PROFILER(STREAM, LABELNO)  			\
{									\
  fprintf (STREAM, "\tbl\tmcount%s\n",					\
	   (TARGET_ARM && NEED_PLT_RELOC) ? "(PLT)" : "");		\
}

/* The GNU/Linux profiler clobbers the link register.  Make sure the
   prologue knows to save it.  */
#define PROFILE_HOOK(X)						\
  emit_clobber (gen_rtx_REG (SImode, LR_REGNUM))

/* Add .note.GNU-stack.  */
#undef NEED_INDICATE_EXEC_STACK
#define NEED_INDICATE_EXEC_STACK	1

/* Uninitialized common symbols in non-PIE executables, even with
   strong definitions in dependent shared libraries, will resolve
   to COPY relocated symbol in the executable.  See PR65780.  */
#undef TARGET_BINDS_LOCAL_P
#define TARGET_BINDS_LOCAL_P default_binds_local_p_2

/* Define this to be nonzero if static stack checking is supported.  */
#define STACK_CHECK_STATIC_BUILTIN 1

#undef  SUBTARGET_CPP_SPEC
#define SUBTARGET_CPP_SPEC ""

#undef ARM_TARGET2_DWARF_FORMAT
#define ARM_TARGET2_DWARF_FORMAT (DW_EH_PE_pcrel | DW_EH_PE_indirect)

/* Additional HelenOS flags. */
#define HELENOS_DRIVER_ARCH_SPECS  MCPU_MTUNE_NATIVE_SPECS TARGET_MODE_SPECS "-ffixed-r9 -mtp=soft"


#if 0

// TODO: adapt this for our flags

#define SUBTARGET_OVERRIDE_INTERNAL_OPTIONS				\
do {									\
    if (opts_set->x_unaligned_access == 1)				\
        warning (0, "target OS does not support unaligned accesses");	\
    if (opts->x_unaligned_access)					\
	opts->x_unaligned_access = 0;					\
} while (0)


#endif
