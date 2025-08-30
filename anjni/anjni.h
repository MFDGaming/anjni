#ifndef NINECRAFT_JNI_IMPL_H
#define NINECRAFT_JNI_IMPL_H

#include "jni.h"
#include <stdlib.h>

typedef enum anjni_object_type_t {
    ANJNI_OBJECT_TYPE_JCLASS,
    ANJNI_OBJECT_TYPE_JSTRING,
    ANJNI_OBJECT_TYPE_JOBJECTARRAY,
    ANJNI_OBJECT_TYPE_JBOOLEANARRAY,
    ANJNI_OBJECT_TYPE_JBYTEARRAY,
    ANJNI_OBJECT_TYPE_JCHARARRAY,
    ANJNI_OBJECT_TYPE_JSHORTARRAY,
    ANJNI_OBJECT_TYPE_JINTARRAY,
    ANJNI_OBJECT_TYPE_JLONGARRAY,
    ANJNI_OBJECT_TYPE_JFLOATARRAY,
    ANJNI_OBJECT_TYPE_JDOUBLEARRAY,
    ANJNI_OBJECT_TYPE_JTHROWABLE,
    ANJNI_OBJECT_TYPE_JWEAK
} anjni_object_type_t;

typedef enum anjni_method_type_t {
    ANJNI_METHOD_TYPE_OBJECT,
    ANJNI_METHOD_TYPE_BOOLEAN,
    ANJNI_METHOD_TYPE_BYTE,
    ANJNI_METHOD_TYPE_CHAR,
    ANJNI_METHOD_TYPE_SHORT,
    ANJNI_METHOD_TYPE_INT,
    ANJNI_METHOD_TYPE_LONG,
    ANJNI_METHOD_TYPE_FLOAT,
    ANJNI_METHOD_TYPE_DOUBLE,
    ANJNI_METHOD_TYPE_VOID
} anjni_method_type_t;

typedef struct anjni_object_t {
    anjni_object_type_t type;
} anjni_object_t;

typedef struct anjni_method_t {
    anjni_method_type_t type;
    char *name;
    char *sig;
    char is_static;
    char is_nonvirtual;
    jvalue (*method)(jobject obj, va_list ap);
} anjni_method_t;

typedef struct anjni_class_t {
    anjni_object_t object;
    char *name;
    struct anjni_class_t *super;
    anjni_method_t *methods;
    size_t methods_count;
} anjni_class_t;

anjni_class_t *anjni_find_class(const char *name);
int anjni_create_class(const char *name, anjni_class_t *super, anjni_class_t **clazz);
int anjni_add_method(anjni_class_t *clazz, anjni_method_type_t t, char *name, char *sig, char is_static, char is_nonvirtual, jvalue (*method)(jobject obj, va_list ap));

extern JNIEnv *android_JNIEnv;
extern JavaVM *android_JavaVM;

#endif