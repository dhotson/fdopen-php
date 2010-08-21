#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_fdopen.h"

static function_entry fdopen_functions[] = {
    PHP_FE(fdopen, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry fdopen_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_FDOPEN_EXTNAME,
    fdopen_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
#if ZEND_MODULE_API_NO >= 20010901
    PHP_FDOPEN_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_FDOPEN
ZEND_GET_MODULE(fdopen)
#endif

PHP_FUNCTION(fdopen)
{
    long fd;
    char *mode;
    int mode_len;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ls", &fd, &mode, &mode_len) == FAILURE) {
        RETURN_NULL();
    }
    php_stream * stream = php_stream_fopen_from_fd(fd, mode, NULL);
    php_stream_to_zval(stream, return_value);
}
