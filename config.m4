PHP_ARG_ENABLE(fdopen, whether to enable fdopen support,
[ --enable-fdopen   Enable fdopen support])

if test "$PHP_FDOPEN" = "yes"; then
  AC_DEFINE(HAVE_FDOPEN, 1, [Whether you have fdopen])
  PHP_NEW_EXTENSION(fdopen, fdopen.c, $ext_shared)
fi
