AC_INIT([bar], [1.0])
AM_INIT_AUTOMAKE([1.14 subdir-objects -Wall foreign])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_FILES([Makefile])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADER([config.h])
AC_PROG_CC

AC_SEARCH_LIBS([libfoo_add], [foo],,
	       [AC_MSG_ERROR([cannot find libfoo])])

AC_ARG_WITH([libconfig],
            AS_HELP_STRING([--with-libconfig], [Build with libconfig]))

AS_IF([test "x$with_libconfig" = "xyes"], [
	PKG_CHECK_MODULES([LIBCONFIG], [libconfig], [use_libconfig=yes])
])

AS_IF([test "$use_libconfig" = "yes"],
      [AC_DEFINE([USE_LIBCONFIG], [1], [Define if using libconfig.])])

AC_OUTPUT
