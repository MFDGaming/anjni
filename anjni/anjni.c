#include "anjni.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

anjni_class_t **classes = NULL;
size_t classes_count = 0;

anjni_class_t *anjni_find_class(const char *name) {
    int i;
    for (i = 0; i < classes_count; ++i) {
        if (!strcmp(name, classes[i]->name)) {
            return classes[i];
        }
    }
    return NULL;
}

int anjni_create_class(const char *name, anjni_class_t *super, anjni_class_t **clazz) {
    anjni_class_t *obj = anjni_find_class(name);
    if (obj) {
        if (clazz) {
            *clazz = NULL;
        }
        return -1;
    }
    obj = (anjni_class_t *)malloc(sizeof(anjni_class_t));
    if (!obj) {
        if (clazz) {
            *clazz = NULL;
        }
        return -1;
    }
    if (!classes || !classes_count) {
        classes_count = 1;
        classes = (anjni_class_t **)malloc(sizeof(anjni_class_t *));
    } else {
        classes = (anjni_class_t **)realloc(classes, ++classes_count * sizeof(anjni_class_t *));
    }
    if (!classes) {
        puts("anjni: cannot allocate memory");
        abort();
    }
    obj->name = strdup(name);
    obj->super = super;
    obj->object.type = ANJNI_OBJECT_TYPE_JCLASS;
    obj->methods = NULL;
    obj->methods_count = 0;
    classes[classes_count - 1] = obj;
    if (clazz) {
        *clazz = obj;
    }
    return 0;
}

int anjni_add_method(anjni_class_t *clazz, anjni_method_type_t t, char *name, char *sig, char is_static, char is_nonvirtual, jvalue (*method)(jobject obj, va_list ap)) {
    anjni_method_t *m;
    if (!clazz->methods || !clazz->methods_count) {
        clazz->methods = (anjni_method_t *)malloc(sizeof(anjni_method_t));
        clazz->methods_count = 1;
    } else {
        clazz->methods = (anjni_method_t *)realloc(clazz->methods, ++clazz->methods_count * sizeof(anjni_method_t));
    }
    if (!clazz->methods) {
        puts("anjni: cannot allocate memory");
        abort();
    }
    m = &clazz->methods[clazz->methods_count - 1];
    m->type = t;
    m->name = strdup(name);
    m->sig = strdup(sig);
    m->is_static = is_static;
    m->is_nonvirtual = is_nonvirtual;
    m->method = method;
    return 0;
}

jint android_GetVersion(JNIEnv *env) {
    return JNI_VERSION_1_6;
}

jclass android_DefineClass(JNIEnv *env, const char *name, jobject loader, const jbyte *buf, jsize len) {
    puts("android_DefineClass");
    return NULL;
}

jclass android_FindClass(JNIEnv *env, const char *name) {
    puts("android_FindClass");
    puts(name);
    return (jclass)anjni_find_class(name);
}

jmethodID android_FromReflectedMethod(JNIEnv *env, jobject method) {
    puts("android_FromReflectedMethod");
    return NULL;
}

jfieldID android_FromReflectedField(JNIEnv *env, jobject field) {
    puts("android_FromReflectedField");
    return NULL;
}

jobject android_ToReflectedMethod(JNIEnv *env, jclass cls, jmethodID methodID, jboolean isStatic) {
    puts("android_ToReflectedMethod");
    return NULL;
}

jclass android_GetSuperclass(JNIEnv *env, jclass sub) {
    puts("android_GetSuperclass");
    return NULL;
}

jboolean android_IsAssignableFrom(JNIEnv *env, jclass sub, jclass sup) {
    puts("android_IsAssignableFrom");
    return JNI_FALSE;
}

jobject android_ToReflectedField(JNIEnv *env, jclass cls, jfieldID fieldID, jboolean isStatic) {
    puts("android_ToReflectedField");
    return NULL;
}

jint android_Throw(JNIEnv *env, jthrowable obj) {
    puts("android_Throw");
    return JNI_ERR;
}

jint android_ThrowNew(JNIEnv *env, jclass clazz, const char *msg) {
    puts("android_ThrowNew");
    return JNI_ERR;
}

jthrowable android_ExceptionOccurred(JNIEnv *env) {
    puts("android_ExceptionOccurred");
    return NULL;
}

void android_ExceptionDescribe(JNIEnv *env) {
    puts("android_ExceptionDescribe");
}

void android_ExceptionClear(JNIEnv *env) {
    puts("android_ExceptionClear");
}

void android_FatalError(JNIEnv *env, const char *msg) {
    puts("android_FatalError");
}

jint android_PushLocalFrame(JNIEnv *env, jint capacity) {
    puts("android_PushLocalFrame");
    return JNI_ERR;
}

jobject android_PopLocalFrame(JNIEnv *env, jobject result) {
    puts("android_PopLocalFrame");
    return NULL;
}

jobject android_NewGlobalRef(JNIEnv *env, jobject lobj) {
    puts("android_NewGlobalRef");
    printf("obj: %p\n", lobj);
    return lobj;
}

void android_DeleteGlobalRef(JNIEnv *env, jobject gref) {
    puts("android_DeleteGlobalRef");
}

void android_DeleteLocalRef(JNIEnv *env, jobject obj) {
    puts("android_DeleteLocalRef");
}

jboolean android_IsSameObject(JNIEnv *env, jobject obj1, jobject obj2) {
    puts("android_IsSameObject");
    return JNI_FALSE;
}

jobject android_NewLocalRef(JNIEnv *env, jobject ref) {
    puts("android_NewLocalRef");
    return ref;
}

jint android_EnsureLocalCapacity(JNIEnv *env, jint capacity) {
    puts("android_EnsureLocalCapacity");
    return JNI_ERR;
}

jobject android_AllocObject(JNIEnv *env, jclass clazz) {
    puts("android_AllocObject");
    return NULL;
}

jobject android_NewObject(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
    puts("android_NewObject");
    return NULL;
}

jobject android_NewObjectV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
    puts("android_NewObjectV");
    printf("obj: %p\n", clazz);
    if (methodID) {
        ((anjni_method_t *)methodID)->method(clazz, args);
    }
    return (jobject)clazz;
}

jobject android_NewObjectA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
    puts("android_NewObjectA");
    return NULL;
}

jclass android_GetObjectClass(JNIEnv *env, jobject obj) {
    puts("android_GetObjectClass");
    return NULL;
}

jboolean android_IsInstanceOf(JNIEnv *env, jobject obj, jclass clazz) {
    puts("android_IsInstanceOf");
    return JNI_FALSE;
}

jmethodID android_GetMethodID(JNIEnv *env, jclass clazz, const char *name, const char *sig) {
    puts("android_GetMethodID");
    printf("name: %s, sig: %s, class: %p\n", name, sig, clazz);
    int i;
    anjni_method_t *methods = ((anjni_class_t *)clazz)->methods;
    size_t methods_count = ((anjni_class_t *)clazz)->methods_count;
    for (i = 0; i < methods_count; ++i) {
        if (!strcmp(methods[i].name, name) && !strcmp(methods[i].sig, sig) && !methods[i].is_static) {
            return (jmethodID)&methods[i];
        }
    }
    return (jmethodID)0;
}

jobject android_CallObjectMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
    puts("android_CallObjectMethod");
    return NULL;
}

jobject android_CallObjectMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
    puts("android_CallObjectMethodV");
    return NULL;
}

jobject android_CallObjectMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
    puts("android_CallObjectMethodA");
    return NULL;
}

jboolean android_CallBooleanMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
    puts("android_CallBooleanMethod");
    return JNI_FALSE;
}

jboolean android_CallBooleanMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
    anjni_method_t *method = (anjni_method_t *)methodID;
    if (method) {
        return method->method(obj, args).z;
    }
    puts("android_CallBooleanMethodV");
    return JNI_FALSE;
}

jboolean android_CallBooleanMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
    puts("android_CallBooleanMethodA");
    return JNI_FALSE;
}

jbyte android_CallByteMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
    puts("android_CallByteMethod");
    return 0;
}

jbyte android_CallByteMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
    puts("android_CallByteMethodV");
    return 0;
}

jbyte android_CallByteMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
    puts("android_CallByteMethodA");
    return 0;
}

jchar android_CallCharMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
    puts("android_CallCharMethod");
    return 0;
}

jchar android_CallCharMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
    puts("android_CallCharMethodV");
    return 0;
}

jchar android_CallCharMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
    puts("android_CallCharMethodA");
    return 0;
}

jshort android_CallShortMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
    puts("android_CallShortMethod");
    return 0;
}

jshort android_CallShortMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
    puts("android_CallShortMethodV");
    return 0;
}

jshort android_CallShortMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
    puts("android_CallShortMethodA");
    return 0;
}

jint android_CallIntMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
    puts("android_CallIntMethod");
    return 0;
}

jint android_CallIntMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
    puts("android_CallIntMethodV");
    return 0;
}

jint android_CallIntMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
    puts("android_CallIntMethodA");
    return 0;
}

jlong android_CallLongMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
    puts("android_CallLongMethod");
    return 0;
}

jlong android_CallLongMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
    puts("android_CallLongMethodV");
    return 0;
}

jlong android_CallLongMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
    puts("android_CallLongMethodA");
    return 0;
}

jfloat android_CallFloatMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
    puts("android_CallFloatMethod");
    return 0.0f;
}

jfloat android_CallFloatMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
    puts("android_CallFloatMethodV");
    return 0.0f;
}

jfloat android_CallFloatMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
    puts("android_CallFloatMethodA");
    return 0.0f;
}

jdouble android_CallDoubleMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
    puts("android_CallDoubleMethod");
    return 0.0;
}

jdouble android_CallDoubleMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
    puts("android_CallDoubleMethodV");
    return 0.0;
}

jdouble android_CallDoubleMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
    puts("android_CallDoubleMethodA");
    return 0.0;
}

void android_CallVoidMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
    puts("android_CallVoidMethod");
}

void android_CallVoidMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
    anjni_method_t *method = (anjni_method_t *)methodID;
    if (method) {
        method->method(obj, args);
    } else {
        puts("android_CallVoidMethodV");
    }
}

void android_CallVoidMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
    puts("android_CallVoidMethodA");
}

jobject android_CallNonvirtualObjectMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
    puts("android_CallNonvirtualObjectMethod");
    return NULL;
}

jobject android_CallNonvirtualObjectMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
    puts("android_CallNonvirtualObjectMethodV");
    return NULL;
}

jobject android_CallNonvirtualObjectMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
    puts("android_CallNonvirtualObjectMethodA");
    return NULL;
}

jboolean android_CallNonvirtualBooleanMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
    puts("android_CallNonvirtualBooleanMethod");
    return JNI_FALSE;
}

jboolean android_CallNonvirtualBooleanMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
    puts("android_CallNonvirtualBooleanMethodV");
    return JNI_FALSE;
}

jboolean android_CallNonvirtualBooleanMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
    puts("android_CallNonvirtualBooleanMethodA");
    return JNI_FALSE;
}

jbyte android_CallNonvirtualByteMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
    puts("android_CallNonvirtualByteMethod");
    return 0;
}

jbyte android_CallNonvirtualByteMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
    puts("android_CallNonvirtualByteMethodV");
    return 0;
}

jbyte android_CallNonvirtualByteMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
    puts("android_CallNonvirtualByteMethodA");
    return 0;
}

jchar android_CallNonvirtualCharMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
    puts("android_CallNonvirtualCharMethod");
    return 0;
}

jchar android_CallNonvirtualCharMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
    puts("android_CallNonvirtualCharMethodV");
    return 0;
}

jchar android_CallNonvirtualCharMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
    puts("android_CallNonvirtualCharMethodA");
    return 0;
}

jshort android_CallNonvirtualShortMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
    puts("android_CallNonvirtualShortMethod");
    return 0;
}

jshort android_CallNonvirtualShortMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
    puts("android_CallNonvirtualShortMethodV");
    return 0;
}

jshort android_CallNonvirtualShortMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
    puts("android_CallNonvirtualShortMethodA");
    return 0;
}

jint android_CallNonvirtualIntMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
    puts("android_CallNonvirtualIntMethod");
    return 0;
}

jint android_CallNonvirtualIntMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
    puts("android_CallNonvirtualIntMethodV");
    return 0;
}

jint android_CallNonvirtualIntMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
    puts("android_CallNonvirtualIntMethodA");
    return 0;
}

jlong android_CallNonvirtualLongMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
    puts("android_CallNonvirtualLongMethod");
    return 0;
}

jlong android_CallNonvirtualLongMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
    puts("android_CallNonvirtualLongMethodV");
    return 0;
}

jlong android_CallNonvirtualLongMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
    puts("android_CallNonvirtualLongMethodA");
    return 0;
}

jfloat android_CallNonvirtualFloatMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
    puts("android_CallNonvirtualFloatMethod");
    return 0.0f;
}

jfloat android_CallNonvirtualFloatMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
    puts("android_CallNonvirtualFloatMethodV");
    return 0.0f;
}

jfloat android_CallNonvirtualFloatMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
    puts("android_CallNonvirtualFloatMethodA");
    return 0.0f;
}

jdouble android_CallNonvirtualDoubleMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
    puts("android_CallNonvirtualDoubleMethod");
    return 0.0;
}

jdouble android_CallNonvirtualDoubleMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
    puts("android_CallNonvirtualDoubleMethodV");
    return 0.0;
}

jdouble android_CallNonvirtualDoubleMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
    puts("android_CallNonvirtualDoubleMethodA");
    return 0.0;
}

void android_CallNonvirtualVoidMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
    puts("android_CallNonvirtualVoidMethod");
}

void android_CallNonvirtualVoidMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
    puts("android_CallNonvirtualVoidMethodV");
}

void android_CallNonvirtualVoidMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
    puts("android_CallNonvirtualVoidMethodA");
}

jfieldID android_GetFieldID(JNIEnv *env, jclass clazz, const char *name, const char *sig) {
    puts("android_GetFieldID");
    return NULL;
}

jobject android_GetObjectField(JNIEnv *env, jobject obj, jfieldID fieldID) {
    puts("android_GetObjectField");
    return NULL;
}

jboolean android_GetBooleanField(JNIEnv *env, jobject obj, jfieldID fieldID) {
    puts("android_GetBooleanField");
    return JNI_FALSE;
}

jbyte android_GetByteField(JNIEnv *env, jobject obj, jfieldID fieldID) {
    puts("android_GetByteField");
    return 0;
}

jchar android_GetCharField(JNIEnv *env, jobject obj, jfieldID fieldID) {
    puts("android_GetCharField");
    return 0;
}

jshort android_GetShortField(JNIEnv *env, jobject obj, jfieldID fieldID) {
    puts("android_GetShortField");
    return 0;
}

jint android_GetIntField(JNIEnv *env, jobject obj, jfieldID fieldID) {
    puts("android_GetIntField");
    return 0;
}

jlong android_GetLongField(JNIEnv *env, jobject obj, jfieldID fieldID) {
    puts("android_GetLongField");
    return 0;
}

jfloat android_GetFloatField(JNIEnv *env, jobject obj, jfieldID fieldID) {
    puts("android_GetFloatField");
    return 0.0f;
}

jdouble android_GetDoubleField(JNIEnv *env, jobject obj, jfieldID fieldID) {
    puts("android_GetDoubleField");
    return 0.0;
}

void android_SetObjectField(JNIEnv *env, jobject obj, jfieldID fieldID, jobject val) {
    puts("android_SetObjectField");
}

void android_SetBooleanField(JNIEnv *env, jobject obj, jfieldID fieldID, jboolean val) {
    puts("android_SetBooleanField");
}

void android_SetByteField(JNIEnv *env, jobject obj, jfieldID fieldID, jbyte val) {
    puts("android_SetByteField");
}

void android_SetCharField(JNIEnv *env, jobject obj, jfieldID fieldID, jchar val) {
    puts("android_SetCharField");
}

void android_SetShortField(JNIEnv *env, jobject obj, jfieldID fieldID, jshort val) {
    puts("android_SetShortField");
}

void android_SetIntField(JNIEnv *env, jobject obj, jfieldID fieldID, jint val) {
    puts("android_SetIntField");
}

void android_SetLongField(JNIEnv *env, jobject obj, jfieldID fieldID, jlong val) {
    puts("android_SetLongField");
}

void android_SetFloatField(JNIEnv *env, jobject obj, jfieldID fieldID, jfloat val) {
    puts("android_SetFloatField");
}

void android_SetDoubleField(JNIEnv *env, jobject obj, jfieldID fieldID, jdouble val) {
    puts("android_SetDoubleField");
}

jmethodID android_GetStaticMethodID(JNIEnv *env, jclass clazz, const char *name, const char *sig) {
    puts("android_GetStaticMethodID");
    printf("name: %s, sig: %s, class: %p\n", name, sig, clazz);
    int i;
    anjni_method_t *methods = ((anjni_class_t *)clazz)->methods;
    size_t methods_count = ((anjni_class_t *)clazz)->methods_count;
    for (i = 0; i < methods_count; ++i) {
        if (!strcmp(methods[i].name, name) && !strcmp(methods[i].sig, sig) && methods[i].is_static) {
            return (jmethodID)&methods[i];
        }
    }
    return (jmethodID)0;
}

jobject android_CallStaticObjectMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
    puts("android_CallStaticObjectMethod");
    return NULL;
}

jobject android_CallStaticObjectMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
    puts("android_CallStaticObjectMethodV");
    return NULL;
}

jobject android_CallStaticObjectMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
    puts("android_CallStaticObjectMethodA");
    return NULL;
}

jboolean android_CallStaticBooleanMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
    puts("android_CallStaticBooleanMethod");
    return JNI_FALSE;
}

jboolean android_CallStaticBooleanMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
    puts("android_CallStaticBooleanMethodV");
    anjni_method_t *method = (anjni_method_t *)methodID;
    if (method) {
        return method->method(NULL, args).z;
    }
    return JNI_FALSE;
}

jboolean android_CallStaticBooleanMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
    puts("android_CallStaticBooleanMethodA");
    return JNI_FALSE;
}

jbyte android_CallStaticByteMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
    puts("android_CallStaticByteMethod");
    return 0;
}

jbyte android_CallStaticByteMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
    puts("android_CallStaticByteMethodV");
    return 0;
}

jbyte android_CallStaticByteMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
    puts("android_CallStaticByteMethodA");
    return 0;
}

jchar android_CallStaticCharMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
    puts("android_CallStaticCharMethod");
    return 0;
}

jchar android_CallStaticCharMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
    puts("android_CallStaticCharMethodV");
    return 0;
}

jchar android_CallStaticCharMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
    puts("android_CallStaticCharMethodA");
    return 0;
}

jshort android_CallStaticShortMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
    puts("android_CallStaticShortMethod");
    return 0;
}

jshort android_CallStaticShortMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
    puts("android_CallStaticShortMethodV");
    return 0;
}

jshort android_CallStaticShortMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
    puts("android_CallStaticShortMethodA");
    return 0;
}

jint android_CallStaticIntMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
    puts("android_CallStaticIntMethod");
    return 0;
}

jint android_CallStaticIntMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
    puts("android_CallStaticIntMethodV");
    return 0;
}

jint android_CallStaticIntMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
    puts("android_CallStaticIntMethodA");
    return 0;
}

jlong android_CallStaticLongMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
    puts("android_CallStaticLongMethod");
    return 0;
}

jlong android_CallStaticLongMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
    puts("android_CallStaticLongMethodV");
    return 0;
}

jlong android_CallStaticLongMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
    puts("android_CallStaticLongMethodA");
    return 0;
}

jfloat android_CallStaticFloatMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
    puts("android_CallStaticFloatMethod");
    return 0.0f;
}

jfloat android_CallStaticFloatMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
    puts("android_CallStaticFloatMethodV");
    return 0.0f;
}

jfloat android_CallStaticFloatMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
    puts("android_CallStaticFloatMethodA");
    return 0.0f;
}

jdouble android_CallStaticDoubleMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
    puts("android_CallStaticDoubleMethod");
    return 0.0;
}

jdouble android_CallStaticDoubleMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
    puts("android_CallStaticDoubleMethodV");
    return 0.0;
}

jdouble android_CallStaticDoubleMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
    puts("android_CallStaticDoubleMethodA");
    return 0.0;
}

void android_CallStaticVoidMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
    puts("android_CallStaticVoidMethod");
}

void android_CallStaticVoidMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
    puts("android_CallStaticVoidMethodV");
}

void android_CallStaticVoidMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
    puts("android_CallStaticVoidMethodA");
}

jfieldID android_GetStaticFieldID(JNIEnv *env, jclass clazz, const char *name, const char *sig) {
    puts("android_GetStaticFieldID");
    return NULL;
}

jobject android_GetStaticObjectField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
    puts("android_GetStaticObjectField");
    return NULL;
}

jboolean android_GetStaticBooleanField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
    puts("android_GetStaticBooleanField");
    return JNI_FALSE;
}

jbyte android_GetStaticByteField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
    puts("android_GetStaticByteField");
    return 0;
}

jchar android_GetStaticCharField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
    puts("android_GetStaticCharField");
    return 0;
}

jshort android_GetStaticShortField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
    puts("android_GetStaticShortField");
    return 0;
}

jint android_GetStaticIntField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
    puts("android_GetStaticIntField");
    return 0;
}

jlong android_GetStaticLongField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
    puts("android_GetStaticLongField");
    return 0;
}

jfloat android_GetStaticFloatField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
    puts("android_GetStaticFloatField");
    return 0.0f;
}

jdouble android_GetStaticDoubleField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
    puts("android_GetStaticDoubleField");
    return 0.0;
}

void android_SetStaticObjectField(JNIEnv *env, jclass clazz, jfieldID fieldID, jobject value) {
    puts("android_SetStaticObjectField");
}

void android_SetStaticBooleanField(JNIEnv *env, jclass clazz, jfieldID fieldID, jboolean value) {
    puts("android_SetStaticBooleanField");
}

void android_SetStaticByteField(JNIEnv *env, jclass clazz, jfieldID fieldID, jbyte value) {
    puts("android_SetStaticByteField");
}

void android_SetStaticCharField(JNIEnv *env, jclass clazz, jfieldID fieldID, jchar value) {
    puts("android_SetStaticCharField");
}

void android_SetStaticShortField(JNIEnv *env, jclass clazz, jfieldID fieldID, jshort value) {
    puts("android_SetStaticShortField");
}

void android_SetStaticIntField(JNIEnv *env, jclass clazz, jfieldID fieldID, jint value) {
    puts("android_SetStaticIntField");
}

void android_SetStaticLongField(JNIEnv *env, jclass clazz, jfieldID fieldID, jlong value) {
    puts("android_SetStaticLongField");
}

void android_SetStaticFloatField(JNIEnv *env, jclass clazz, jfieldID fieldID, jfloat value) {
    puts("android_SetStaticFloatField");
}

void android_SetStaticDoubleField(JNIEnv *env, jclass clazz, jfieldID fieldID, jdouble value) {
    puts("android_SetStaticDoubleField");
}

jstring android_NewString(JNIEnv *env, const jchar *unicode, jsize len) {
    puts("android_NewString");
    return NULL;
}

jsize android_GetStringLength(JNIEnv *env, jstring str) {
    puts("android_GetStringLength");
    return 0;
}

const jchar *android_GetStringChars(JNIEnv *env, jstring str, jboolean *isCopy) {
    puts("android_GetStringChars");
    return NULL;
}

void android_ReleaseStringChars(JNIEnv *env, jstring str, const jchar *chars) {
    puts("android_ReleaseStringChars");
}

jstring android_NewStringUTF(JNIEnv *env, const char *bytes) {
    puts("android_NewStringUTF");
    return NULL;
}

jsize android_GetStringUTFLength(JNIEnv *env, jstring str) {
    puts("android_GetStringUTFLength");
    return 0;
}

const char *android_GetStringUTFChars(JNIEnv *env, jstring str, jboolean *isCopy) {
    puts("android_GetStringUTFChars");
    return NULL;
}

void android_ReleaseStringUTFChars(JNIEnv *env, jstring str, const char *chars) {
    puts("android_ReleaseStringUTFChars");
}

jsize android_GetArrayLength(JNIEnv *env, jarray array) {
    puts("android_GetArrayLength");
    return 0;
}

jobjectArray android_NewObjectArray(JNIEnv *env, jsize length, jclass elementClass, jobject initialElement) {
    puts("android_NewObjectArray");
    return NULL;
}

jobject android_GetObjectArrayElement(JNIEnv *env, jobjectArray array, jsize index) {
    puts("android_GetObjectArrayElement");
    return NULL;
}

void android_SetObjectArrayElement(JNIEnv *env, jobjectArray array, jsize index, jobject val) {
    puts("android_SetObjectArrayElement");
}

jbooleanArray android_NewBooleanArray(JNIEnv *env, jsize length) {
    puts("android_NewBooleanArray");
    return NULL;
}

jbyteArray android_NewByteArray(JNIEnv *env, jsize length) {
    puts("android_NewByteArray");
    return calloc(length, 1);
}

jcharArray android_NewCharArray(JNIEnv *env, jsize length) {
    puts("android_NewCharArray");
    return NULL;
}

jshortArray android_NewShortArray(JNIEnv *env, jsize length) {
    puts("android_NewShortArray");
    return NULL;
}

jintArray android_NewIntArray(JNIEnv *env, jsize length) {
    puts("android_NewIntArray");
    return NULL;
}

jlongArray android_NewLongArray(JNIEnv *env, jsize length) {
    puts("android_NewLongArray");
    return NULL;
}

jfloatArray android_NewFloatArray(JNIEnv *env, jsize length) {
    puts("android_NewFloatArray");
    return NULL;
}

jdoubleArray android_NewDoubleArray(JNIEnv *env, jsize length) {
    puts("android_NewDoubleArray");
    return NULL;
}

jboolean *android_GetBooleanArrayElements(JNIEnv *env, jbooleanArray array, jboolean *isCopy) {
    puts("android_GetBooleanArrayElements");
    return NULL;
}

jbyte *android_GetByteArrayElements(JNIEnv *env, jbyteArray array, jboolean *isCopy) {
    puts("android_GetByteArrayElements");
    return NULL;
}

jchar *android_GetCharArrayElements(JNIEnv *env, jcharArray array, jboolean *isCopy) {
    puts("android_GetCharArrayElements");
    return NULL;
}

jshort *android_GetShortArrayElements(JNIEnv *env, jshortArray array, jboolean *isCopy) {
    puts("android_GetShortArrayElements");
    return NULL;
}

jint *android_GetIntArrayElements(JNIEnv *env, jintArray array, jboolean *isCopy) {
    puts("android_GetIntArrayElements");
    return NULL;
}

jlong *android_GetLongArrayElements(JNIEnv *env, jlongArray array, jboolean *isCopy) {
    puts("android_GetLongArrayElements");
    return NULL;
}

jfloat *android_GetFloatArrayElements(JNIEnv *env, jfloatArray array, jboolean *isCopy) {
    puts("android_GetFloatArrayElements");
    return NULL;
}

jdouble *android_GetDoubleArrayElements(JNIEnv *env, jdoubleArray array, jboolean *isCopy) {
    puts("android_GetDoubleArrayElements");
    return NULL;
}

void android_ReleaseBooleanArrayElements(JNIEnv *env, jbooleanArray array, jboolean *elems, jint mode) {
    puts("android_ReleaseBooleanArrayElements");
}

void android_ReleaseByteArrayElements(JNIEnv *env, jbyteArray array, jbyte *elems, jint mode) {
    puts("android_ReleaseByteArrayElements");
}

void android_ReleaseCharArrayElements(JNIEnv *env, jcharArray array, jchar *elems, jint mode) {
    puts("android_ReleaseCharArrayElements");
}

void android_ReleaseShortArrayElements(JNIEnv *env, jshortArray array, jshort *elems, jint mode) {
    puts("android_ReleaseShortArrayElements");
}

void android_ReleaseIntArrayElements(JNIEnv *env, jintArray array, jint *elems, jint mode) {
    puts("android_ReleaseIntArrayElements");
}

void android_ReleaseLongArrayElements(JNIEnv *env, jlongArray array, jlong *elems, jint mode) {
    puts("android_ReleaseLongArrayElements");
}

void android_ReleaseFloatArrayElements(JNIEnv *env, jfloatArray array, jfloat *elems, jint mode) {
    puts("android_ReleaseFloatArrayElements");
}

void android_ReleaseDoubleArrayElements(JNIEnv *env, jdoubleArray array, jdouble *elems, jint mode) {
    puts("android_ReleaseDoubleArrayElements");
}

void android_GetBooleanArrayRegion(JNIEnv *env, jbooleanArray array, jsize start, jsize len, jboolean *buf) {
    puts("android_GetBooleanArrayRegion");
}

void android_GetByteArrayRegion(JNIEnv *env, jbyteArray array, jsize start, jsize len, jbyte *buf) {
    puts("android_GetByteArrayRegion");
}

void android_GetCharArrayRegion(JNIEnv *env, jcharArray array, jsize start, jsize len, jchar *buf) {
    puts("android_GetCharArrayRegion");
}

void android_GetShortArrayRegion(JNIEnv *env, jshortArray array, jsize start, jsize len, jshort *buf) {
    puts("android_GetShortArrayRegion");
}

void android_GetIntArrayRegion(JNIEnv *env, jintArray array, jsize start, jsize len, jint *buf) {
    puts("android_GetIntArrayRegion");
}

void android_GetLongArrayRegion(JNIEnv *env, jlongArray array, jsize start, jsize len, jlong *buf) {
    puts("android_GetLongArrayRegion");
}

void android_GetFloatArrayRegion(JNIEnv *env, jfloatArray array, jsize start, jsize len, jfloat *buf) {
    puts("android_GetFloatArrayRegion");
}

void android_GetDoubleArrayRegion(JNIEnv *env, jdoubleArray array, jsize start, jsize len, jdouble *buf) {
    puts("android_GetDoubleArrayRegion");
}

void android_SetBooleanArrayRegion(JNIEnv *env, jbooleanArray array, jsize start, jsize len, const jboolean *buf) {
    puts("android_SetBooleanArrayRegion");
}

void android_SetByteArrayRegion(JNIEnv *env, jbyteArray array, jsize start, jsize len, const jbyte *buf) {
    //puts("android_SetByteArrayRegion");
    if (array) {
        memcpy((char *)array + start, buf, len);
    }
}

void android_SetCharArrayRegion(JNIEnv *env, jcharArray array, jsize start, jsize len, const jchar *buf) {
    puts("android_SetCharArrayRegion");
}

void android_SetShortArrayRegion(JNIEnv *env, jshortArray array, jsize start, jsize len, const jshort *buf) {
    puts("android_SetShortArrayRegion");
}

void android_SetIntArrayRegion(JNIEnv *env, jintArray array, jsize start, jsize len, const jint *buf) {
    puts("android_SetIntArrayRegion");
}

void android_SetLongArrayRegion(JNIEnv *env, jlongArray array, jsize start, jsize len, const jlong *buf) {
    puts("android_SetLongArrayRegion");
}

void android_SetFloatArrayRegion(JNIEnv *env, jfloatArray array, jsize start, jsize len, const jfloat *buf) {
    puts("android_SetFloatArrayRegion");
}

void android_SetDoubleArrayRegion(JNIEnv *env, jdoubleArray array, jsize start, jsize len, const jdouble *buf) {
    puts("android_SetDoubleArrayRegion");
}

jint android_RegisterNatives(JNIEnv *env, jclass clazz, const JNINativeMethod* methods, jint nMethods) {
    puts("android_RegisterNatives");
    return JNI_ERR;
}

jint android_UnregisterNatives(JNIEnv *env, jclass clazz) {
    puts("android_UnregisterNatives");
    return JNI_ERR;
}

jint android_MonitorEnter(JNIEnv *env, jobject obj) {
    puts("android_MonitorEnter");
    return JNI_ERR;
}

jint android_MonitorExit(JNIEnv *env, jobject obj) {
    puts("android_MonitorExit");
    return JNI_ERR;
}

jint android_GetJavaVM(JNIEnv *env, JavaVM** vm) {
    puts("android_GetJavaVM");
    *vm = android_JavaVM;
    return JNI_OK;
}

void android_GetStringRegion(JNIEnv *env, jstring str, jsize start, jsize len, jchar *buf) {
    puts("android_GetStringRegion");
}

void android_GetStringUTFRegion(JNIEnv *env, jstring str, jsize start, jsize len, char* buf) {
    puts("android_GetStringUTFRegion");
}

void *android_GetPrimitiveArrayCritical(JNIEnv *env, jarray array, jboolean *isCopy) {
    puts("android_GetPrimitiveArrayCritical");
    return NULL;
}

void android_ReleasePrimitiveArrayCritical(JNIEnv *env, jarray array, void *carray, jint mode) {
    puts("android_ReleasePrimitiveArrayCritical");
}

const jchar *android_GetStringCritical(JNIEnv *env, jstring str, jboolean *isCopy) {
    puts("android_GetStringCritical");
    return NULL;
}

void android_ReleaseStringCritical(JNIEnv *env, jstring str, const jchar *cstring) {
    puts("android_ReleaseStringCritical");
}

jweak android_NewWeakGlobalRef(JNIEnv *env, jobject obj) {
    puts("android_NewWeakGlobalRef");
    return NULL;
}

void android_DeleteWeakGlobalRef(JNIEnv *env, jweak obj) {
    puts("android_DeleteWeakGlobalRef");
}

jboolean android_ExceptionCheck(JNIEnv *env) {
    puts("android_ExceptionCheck");
    return JNI_FALSE;
}

jobject android_NewDirectByteBuffer(JNIEnv *env, void *address, jlong capacity) {
    puts("android_NewDirectByteBuffer");
    return NULL;
}

void *android_GetDirectBufferAddress(JNIEnv *env, jobject buf) {
    puts("android_GetDirectBufferAddress");
    return NULL;
}

jlong android_GetDirectBufferCapacity(JNIEnv *env, jobject buf) {
    puts("android_GetDirectBufferCapacity");
    return 0;
}

jobjectRefType android_GetObjectRefType(JNIEnv *env, jobject obj) {
    puts("android_GetObjectRefType");
    return JNIInvalidRefType;
}

const struct JNINativeInterface android_JNINativeInterface = {
    NULL, NULL, NULL, NULL,
    android_GetVersion,
    android_DefineClass,
    android_FindClass,
    android_FromReflectedMethod,
    android_FromReflectedField,
    android_ToReflectedMethod,
    android_GetSuperclass,
    android_IsAssignableFrom,
    android_ToReflectedField,
    android_Throw,
    android_ThrowNew,
    android_ExceptionOccurred,
    android_ExceptionDescribe,
    android_ExceptionClear,
    android_FatalError,
    android_PushLocalFrame,
    android_PopLocalFrame,
    android_NewGlobalRef,
    android_DeleteGlobalRef,
    android_DeleteLocalRef,
    android_IsSameObject,
    android_NewLocalRef,
    android_EnsureLocalCapacity,
    android_AllocObject,
    android_NewObject,
    android_NewObjectV,
    android_NewObjectA,
    android_GetObjectClass,
    android_IsInstanceOf,
    android_GetMethodID,
    android_CallObjectMethod,
    android_CallObjectMethodV,
    android_CallObjectMethodA,
    android_CallBooleanMethod,
    android_CallBooleanMethodV,
    android_CallBooleanMethodA,
    android_CallByteMethod,
    android_CallByteMethodV,
    android_CallByteMethodA,
    android_CallCharMethod,
    android_CallCharMethodV,
    android_CallCharMethodA,
    android_CallShortMethod,
    android_CallShortMethodV,
    android_CallShortMethodA,
    android_CallIntMethod,
    android_CallIntMethodV,
    android_CallIntMethodA,
    android_CallLongMethod,
    android_CallLongMethodV,
    android_CallLongMethodA,
    android_CallFloatMethod,
    android_CallFloatMethodV,
    android_CallFloatMethodA,
    android_CallDoubleMethod,
    android_CallDoubleMethodV,
    android_CallDoubleMethodA,
    android_CallVoidMethod,
    android_CallVoidMethodV,
    android_CallVoidMethodA,
    android_CallNonvirtualObjectMethod,
    android_CallNonvirtualObjectMethodV,
    android_CallNonvirtualObjectMethodA,
    android_CallNonvirtualBooleanMethod,
    android_CallNonvirtualBooleanMethodV,
    android_CallNonvirtualBooleanMethodA,
    android_CallNonvirtualByteMethod,
    android_CallNonvirtualByteMethodV,
    android_CallNonvirtualByteMethodA,
    android_CallNonvirtualCharMethod,
    android_CallNonvirtualCharMethodV,
    android_CallNonvirtualCharMethodA,
    android_CallNonvirtualShortMethod,
    android_CallNonvirtualShortMethodV,
    android_CallNonvirtualShortMethodA,
    android_CallNonvirtualIntMethod,
    android_CallNonvirtualIntMethodV,
    android_CallNonvirtualIntMethodA,
    android_CallNonvirtualLongMethod,
    android_CallNonvirtualLongMethodV,
    android_CallNonvirtualLongMethodA,
    android_CallNonvirtualFloatMethod,
    android_CallNonvirtualFloatMethodV,
    android_CallNonvirtualFloatMethodA,
    android_CallNonvirtualDoubleMethod,
    android_CallNonvirtualDoubleMethodV,
    android_CallNonvirtualDoubleMethodA,
    android_CallNonvirtualVoidMethod,
    android_CallNonvirtualVoidMethodV,
    android_CallNonvirtualVoidMethodA,
    android_GetFieldID,
    android_GetObjectField,
    android_GetBooleanField,
    android_GetByteField,
    android_GetCharField,
    android_GetShortField,
    android_GetIntField,
    android_GetLongField,
    android_GetFloatField,
    android_GetDoubleField,
    android_SetObjectField,
    android_SetBooleanField,
    android_SetByteField,
    android_SetCharField,
    android_SetShortField,
    android_SetIntField,
    android_SetLongField,
    android_SetFloatField,
    android_SetDoubleField,
    android_GetStaticMethodID,
    android_CallStaticObjectMethod,
    android_CallStaticObjectMethodV,
    android_CallStaticObjectMethodA,
    android_CallStaticBooleanMethod,
    android_CallStaticBooleanMethodV,
    android_CallStaticBooleanMethodA,
    android_CallStaticByteMethod,
    android_CallStaticByteMethodV,
    android_CallStaticByteMethodA,
    android_CallStaticCharMethod,
    android_CallStaticCharMethodV,
    android_CallStaticCharMethodA,
    android_CallStaticShortMethod,
    android_CallStaticShortMethodV,
    android_CallStaticShortMethodA,
    android_CallStaticIntMethod,
    android_CallStaticIntMethodV,
    android_CallStaticIntMethodA,
    android_CallStaticLongMethod,
    android_CallStaticLongMethodV,
    android_CallStaticLongMethodA,
    android_CallStaticFloatMethod,
    android_CallStaticFloatMethodV,
    android_CallStaticFloatMethodA,
    android_CallStaticDoubleMethod,
    android_CallStaticDoubleMethodV,
    android_CallStaticDoubleMethodA,
    android_CallStaticVoidMethod,
    android_CallStaticVoidMethodV,
    android_CallStaticVoidMethodA,
    android_GetStaticFieldID,
    android_GetStaticObjectField,
    android_GetStaticBooleanField,
    android_GetStaticByteField,
    android_GetStaticCharField,
    android_GetStaticShortField,
    android_GetStaticIntField,
    android_GetStaticLongField,
    android_GetStaticFloatField,
    android_GetStaticDoubleField,
    android_SetStaticObjectField,
    android_SetStaticBooleanField,
    android_SetStaticByteField,
    android_SetStaticCharField,
    android_SetStaticShortField,
    android_SetStaticIntField,
    android_SetStaticLongField,
    android_SetStaticFloatField,
    android_SetStaticDoubleField,
    android_NewString,
    android_GetStringLength,
    android_GetStringChars,
    android_ReleaseStringChars,
    android_NewStringUTF,
    android_GetStringUTFLength,
    android_GetStringUTFChars,
    android_ReleaseStringUTFChars,
    android_GetArrayLength,
    android_NewObjectArray,
    android_GetObjectArrayElement,
    android_SetObjectArrayElement,
    android_NewBooleanArray,
    android_NewByteArray,
    android_NewCharArray,
    android_NewShortArray,
    android_NewIntArray,
    android_NewLongArray,
    android_NewFloatArray,
    android_NewDoubleArray,
    android_GetBooleanArrayElements,
    android_GetByteArrayElements,
    android_GetCharArrayElements,
    android_GetShortArrayElements,
    android_GetIntArrayElements,
    android_GetLongArrayElements,
    android_GetFloatArrayElements,
    android_GetDoubleArrayElements,
    android_ReleaseBooleanArrayElements,
    android_ReleaseByteArrayElements,
    android_ReleaseCharArrayElements,
    android_ReleaseShortArrayElements,
    android_ReleaseIntArrayElements,
    android_ReleaseLongArrayElements,
    android_ReleaseFloatArrayElements,
    android_ReleaseDoubleArrayElements,
    android_GetBooleanArrayRegion,
    android_GetByteArrayRegion,
    android_GetCharArrayRegion,
    android_GetShortArrayRegion,
    android_GetIntArrayRegion,
    android_GetLongArrayRegion,
    android_GetFloatArrayRegion,
    android_GetDoubleArrayRegion,
    android_SetBooleanArrayRegion,
    android_SetByteArrayRegion,
    android_SetCharArrayRegion,
    android_SetShortArrayRegion,
    android_SetIntArrayRegion,
    android_SetLongArrayRegion,
    android_SetFloatArrayRegion,
    android_SetDoubleArrayRegion,
    android_RegisterNatives,
    android_UnregisterNatives,
    android_MonitorEnter,
    android_MonitorExit,
    android_GetJavaVM,
    android_GetStringRegion,
    android_GetStringUTFRegion,
    android_GetPrimitiveArrayCritical,
    android_ReleasePrimitiveArrayCritical,
    android_GetStringCritical,
    android_ReleaseStringCritical,
    android_NewWeakGlobalRef,
    android_DeleteWeakGlobalRef,
    android_ExceptionCheck,
    android_NewDirectByteBuffer,
    android_GetDirectBufferAddress,
    android_GetDirectBufferCapacity,
    android_GetObjectRefType
};

static struct _JNIEnv _android_JNIEnv = {&android_JNINativeInterface};
JNIEnv *android_JNIEnv = (JNIEnv *)&_android_JNIEnv;

jint android_DestroyJavaVM(JavaVM *vm) {
    return JNI_OK;
}

jint android_AttachCurrentThread(JavaVM *vm, JNIEnv **penv, void *args) {
    return JNI_OK;
}

jint android_DetachCurrentThread(JavaVM *vm) {
    return JNI_OK;
}

jint android_GetEnv(JavaVM *vm, void **env, jint version) {
    *env = (void *)android_JNIEnv;
    return JNI_OK;
}

jint android_AttachCurrentThreadAsDaemon(JavaVM *vm, JNIEnv **penv, void *args) {
    return JNI_OK;
}

const struct JNIInvokeInterface android_JNIInvokeInterface = {
    NULL, NULL, NULL,
    android_DestroyJavaVM,
    android_AttachCurrentThread,
    android_DetachCurrentThread,
    android_GetEnv,
    android_AttachCurrentThreadAsDaemon
};

static struct _JavaVM _android_JavaVM = {&android_JNIInvokeInterface};
JavaVM *android_JavaVM = (JavaVM *)&_android_JavaVM;
