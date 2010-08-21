#ifndef PHP_FDOPEN_H
#define PHP_FDOPEN_H 1

#define PHP_FDOPEN_VERSION "1.0"
#define PHP_FDOPEN_EXTNAME "fdopen"

PHP_FUNCTION(fdopen);

extern zend_module_entry fdopen_module_entry;
#define phpext_fdopen_ptr &fdopen_module_entry

#endif
