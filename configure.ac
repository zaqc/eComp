AC_PREREQ(2.61)

# package version number (not shared library version)
# odd micro numbers indicate in-progress development
# even micro numbers indicate released versions
m4_define(Comp_version_major, 0)
m4_define(Comp_version_minor, 1)
m4_define(Comp_version_micro, 0)

m4_define([Comp_version],
          [Comp_version_major.Comp_version_minor.Comp_version_micro])
m4_define([Comp_api_version],
          [Comp_version_major.Comp_version_minor])

AC_INIT(Comp, Comp_version)
AM_INIT_AUTOMAKE(Comp, Comp_version)
AC_CONFIG_HEADERS(config.h)

# Checks for programs.
AC_PROG_LIBTOOL
AC_PROG_CXX
AC_PROG_INSTALL

# enable pkg-config
PKG_PROG_PKG_CONFIG

# Checks for library functions.
#AC_CHECK_FUNCS([memset])

AC_SUBST(Comp_CFLAGS)
AC_SUBST(Comp_LIBS)


#icondir=${datadir}/icons/hicolor/32x32/apps
#AC_SUBST(icondir)

AC_OUTPUT([
Makefile
src/Makefile
])

echo ""
echo "   Comp $VERSION"
echo "   ====================="
echo ""
echo "   To build the project, run \"make\""
echo ""
