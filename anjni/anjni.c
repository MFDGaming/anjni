#include "anjni.h"
#include <stdlib.h>

jint android_GetVersion(JNIEnv *env) {
    return JNI_VERSION_1_6;
}

jclass android_DefineClass(JNIEnv *env, const char *name, jobject loader, const jbyte *buf, jsize len) {

}

jclass android_FindClass(JNIEnv *env, const char *name) {
 
}

jmethodID android_FromReflectedMethod(JNIEnv *env, jobject method) {
 
}

jfieldID android_FromReflectedField(JNIEnv *env, jobject field) {
 
}

jobject android_ToReflectedMethod(JNIEnv *env, jclass cls, jmethodID methodID, jboolean isStatic) {
 
}

jclass android_GetSuperclass(JNIEnv *env, jclass sub) {
 
}

jboolean android_IsAssignableFrom(JNIEnv *env, jclass sub, jclass sup) {
 
}

jobject android_ToReflectedField(JNIEnv *env, jclass cls, jfieldID fieldID, jboolean isStatic) {
 
}

jint android_Throw(JNIEnv *env, jthrowable obj) {
 
}

jint android_ThrowNew(JNIEnv *env, jclass clazz, const char *msg) {
 
}

jthrowable android_ExceptionOccurred(JNIEnv *env) {
 
}

void android_ExceptionDescribe(JNIEnv *env) {
 
}

void android_ExceptionClear(JNIEnv *env) {
 
}

void android_FatalError(JNIEnv *env, const char *msg) {
 
}

jint android_PushLocalFrame(JNIEnv *env, jint capacity) {
 
}

jobject android_PopLocalFrame(JNIEnv *env, jobject result) {
 
}

jobject android_NewGlobalRef(JNIEnv *env, jobject lobj) {
 
}

void android_DeleteGlobalRef(JNIEnv *env, jobject gref) {
 
}

void android_DeleteLocalRef(JNIEnv *env, jobject obj) {
 
}

jboolean android_IsSameObject(JNIEnv *env, jobject obj1, jobject obj2) {
 
}

jobject android_NewLocalRef(JNIEnv *env, jobject ref) {
 
}

jint android_EnsureLocalCapacity(JNIEnv *env, jint capacity) {
 
}

jobject android_AllocObject(JNIEnv *env, jclass clazz) {
 
}

jobject android_NewObject(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
 
}

jobject android_NewObjectV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
 
}

jobject android_NewObjectA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
 
}

jclass android_GetObjectClass(JNIEnv *env, jobject obj) {
 
}

jboolean android_IsInstanceOf(JNIEnv *env, jobject obj, jclass clazz) {
 
}

jmethodID android_GetMethodID(JNIEnv *env, jclass clazz, const char *name, const char *sig) {
 
}

jobject android_CallObjectMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
 
}

jobject android_CallObjectMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
 
}

jobject android_CallObjectMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
 
}

jboolean android_CallBooleanMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
 
}

jboolean android_CallBooleanMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
 
}

jboolean android_CallBooleanMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
 
}

jbyte android_CallByteMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
 
}

jbyte android_CallByteMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
 
}

jbyte android_CallByteMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
 
}

jchar android_CallCharMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
 
}

jchar android_CallCharMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
 
}

jchar android_CallCharMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
 
}

jshort android_CallShortMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
 
}

jshort android_CallShortMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
 
}

jshort android_CallShortMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
 
}

jint android_CallIntMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
 
}

jint android_CallIntMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
 
}

jint android_CallIntMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
 
}

jlong android_CallLongMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
 
}

jlong android_CallLongMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
 
}

jlong android_CallLongMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
 
}

jfloat android_CallFloatMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
 
}

jfloat android_CallFloatMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
 
}

jfloat android_CallFloatMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
 
}

jdouble android_CallDoubleMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
 
}

jdouble android_CallDoubleMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
 
}

jdouble android_CallDoubleMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
 
}

void android_CallVoidMethod(JNIEnv *env, jobject obj, jmethodID methodID, ...) {
 
}

void android_CallVoidMethodV(JNIEnv *env, jobject obj, jmethodID methodID, va_list args) {
 
}

void android_CallVoidMethodA(JNIEnv *env, jobject obj, jmethodID methodID, jvalue *args) {
 
}

jobject android_CallNonvirtualObjectMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
 
}

jobject android_CallNonvirtualObjectMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
 
}

jobject android_CallNonvirtualObjectMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
 
}

jboolean android_CallNonvirtualBooleanMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
 
}

jboolean android_CallNonvirtualBooleanMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
 
}

jboolean android_CallNonvirtualBooleanMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
 
}

jbyte android_CallNonvirtualByteMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
 
}

jbyte android_CallNonvirtualByteMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
 
}

jbyte android_CallNonvirtualByteMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
 
}

jchar android_CallNonvirtualCharMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
 
}

jchar android_CallNonvirtualCharMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
 
}

jchar android_CallNonvirtualCharMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
 
}

jshort android_CallNonvirtualShortMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
 
}

jshort android_CallNonvirtualShortMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
 
}

jshort android_CallNonvirtualShortMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
 
}

jint android_CallNonvirtualIntMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
 
}

jint android_CallNonvirtualIntMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
 
}

jint android_CallNonvirtualIntMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
 
}

jlong android_CallNonvirtualLongMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
 
}

jlong android_CallNonvirtualLongMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
 
}

jlong android_CallNonvirtualLongMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
 
}

jfloat android_CallNonvirtualFloatMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
 
}

jfloat android_CallNonvirtualFloatMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
 
}

jfloat android_CallNonvirtualFloatMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
 
}

jdouble android_CallNonvirtualDoubleMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
 
}

jdouble android_CallNonvirtualDoubleMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
 
}

jdouble android_CallNonvirtualDoubleMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
 
}

void android_CallNonvirtualVoidMethod(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, ...) {
 
}

void android_CallNonvirtualVoidMethodV(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, va_list args) {
 
}

void android_CallNonvirtualVoidMethodA(JNIEnv *env, jobject obj, jclass clazz, jmethodID methodID, jvalue *args) {
 
}

jfieldID android_GetFieldID(JNIEnv *env, jclass clazz, const char *name, const char *sig) {
 
}

jobject android_GetObjectField(JNIEnv *env, jobject obj, jfieldID fieldID) {
 
}

jboolean android_GetBooleanField(JNIEnv *env, jobject obj, jfieldID fieldID) {
 
}

jbyte android_GetByteField(JNIEnv *env, jobject obj, jfieldID fieldID) {
 
}

jchar android_GetCharField(JNIEnv *env, jobject obj, jfieldID fieldID) {
 
}

jshort android_GetShortField(JNIEnv *env, jobject obj, jfieldID fieldID) {
 
}

jint android_GetIntField(JNIEnv *env, jobject obj, jfieldID fieldID) {
 
}

jlong android_GetLongField(JNIEnv *env, jobject obj, jfieldID fieldID) {
 
}

jfloat android_GetFloatField(JNIEnv *env, jobject obj, jfieldID fieldID) {
 
}

jdouble android_GetDoubleField(JNIEnv *env, jobject obj, jfieldID fieldID) {
 
}

void android_SetObjectField(JNIEnv *env, jobject obj, jfieldID fieldID, jobject val) {
 
}

void android_SetBooleanField(JNIEnv *env, jobject obj, jfieldID fieldID, jboolean val) {
 
}

void android_SetByteField(JNIEnv *env, jobject obj, jfieldID fieldID, jbyte val) {
 
}

void android_SetCharField(JNIEnv *env, jobject obj, jfieldID fieldID, jchar val) {
 
}

void android_SetShortField(JNIEnv *env, jobject obj, jfieldID fieldID, jshort val) {
 
}

void android_SetIntField(JNIEnv *env, jobject obj, jfieldID fieldID, jint val) {
 
}

void android_SetLongField(JNIEnv *env, jobject obj, jfieldID fieldID, jlong val) {
 
}

void android_SetFloatField(JNIEnv *env, jobject obj, jfieldID fieldID, jfloat val) {
 
}

void android_SetDoubleField(JNIEnv *env, jobject obj, jfieldID fieldID, jdouble val) {
 
}

jmethodID android_GetStaticMethodID(JNIEnv *env, jclass clazz, const char *name, const char *sig) {
 
}

jobject android_CallStaticObjectMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
 
}

jobject android_CallStaticObjectMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
 
}

jobject android_CallStaticObjectMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
 
}

jboolean android_CallStaticBooleanMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
 
}

jboolean android_CallStaticBooleanMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
 
}

jboolean android_CallStaticBooleanMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
 
}

jbyte android_CallStaticByteMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
 
}

jbyte android_CallStaticByteMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
 
}

jbyte android_CallStaticByteMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
 
}

jchar android_CallStaticCharMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
 
}

jchar android_CallStaticCharMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
 
}

jchar android_CallStaticCharMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
 
}

jshort android_CallStaticShortMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
 
}

jshort android_CallStaticShortMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
 
}

jshort android_CallStaticShortMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
 
}

jint android_CallStaticIntMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
 
}

jint android_CallStaticIntMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
 
}

jint android_CallStaticIntMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
 
}

jlong android_CallStaticLongMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
 
}

jlong android_CallStaticLongMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
 
}

jlong android_CallStaticLongMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
 
}

jfloat android_CallStaticFloatMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
 
}

jfloat android_CallStaticFloatMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
 
}

jfloat android_CallStaticFloatMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
 
}

jdouble android_CallStaticDoubleMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
 
}

jdouble android_CallStaticDoubleMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
 
}

jdouble android_CallStaticDoubleMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
 
}

void android_CallStaticVoidMethod(JNIEnv *env, jclass clazz, jmethodID methodID, ...) {
 
}

void android_CallStaticVoidMethodV(JNIEnv *env, jclass clazz, jmethodID methodID, va_list args) {
 
}

void android_CallStaticVoidMethodA(JNIEnv *env, jclass clazz, jmethodID methodID, jvalue *args) {
 
}

jfieldID android_GetStaticFieldID(JNIEnv *env, jclass clazz, const char *name, const char *sig) {
 
}

jobject android_GetStaticObjectField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
 
}

jboolean android_GetStaticBooleanField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
 
}

jbyte android_GetStaticByteField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
 
}

jchar android_GetStaticCharField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
 
}

jshort android_GetStaticShortField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
 
}

jint android_GetStaticIntField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
 
}

jlong android_GetStaticLongField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
 
}

jfloat android_GetStaticFloatField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
 
}

jdouble android_GetStaticDoubleField(JNIEnv *env, jclass clazz, jfieldID fieldID) {
 
}

void android_SetStaticObjectField(JNIEnv *env, jclass clazz, jfieldID fieldID, jobject value) {
 
}

void android_SetStaticBooleanField(JNIEnv *env, jclass clazz, jfieldID fieldID, jboolean value) {
 
}

void android_SetStaticByteField(JNIEnv *env, jclass clazz, jfieldID fieldID, jbyte value) {
 
}

void android_SetStaticCharField(JNIEnv *env, jclass clazz, jfieldID fieldID, jchar value) {
 
}

void android_SetStaticShortField(JNIEnv *env, jclass clazz, jfieldID fieldID, jshort value) {
 
}

void android_SetStaticIntField(JNIEnv *env, jclass clazz, jfieldID fieldID, jint value) {
 
}

void android_SetStaticLongField(JNIEnv *env, jclass clazz, jfieldID fieldID, jlong value) {
 
}

void android_SetStaticFloatField(JNIEnv *env, jclass clazz, jfieldID fieldID, jfloat value) {
 
}

void android_SetStaticDoubleField(JNIEnv *env, jclass clazz, jfieldID fieldID, jdouble value) {
 
}

jstring android_NewString(JNIEnv *env, const jchar *unicode, jsize len) {
 
}

jsize android_GetStringLength(JNIEnv *env, jstring str) {
 
}

const jchar *android_GetStringChars(JNIEnv *env, jstring str, jboolean *isCopy) {
 
}

void android_ReleaseStringChars(JNIEnv *env, jstring str, const jchar *chars) {
 
}

jstring android_NewStringUTF(JNIEnv *env, const char *bytes) {
 
}

jsize android_GetStringUTFLength(JNIEnv *env, jstring str) {
 
}

const char *android_GetStringUTFChars(JNIEnv *env, jstring str, jboolean *isCopy) {
 
}

void android_ReleaseStringUTFChars(JNIEnv *env, jstring str, const char *chars) {
 
}

jsize android_GetArrayLength(JNIEnv *env, jarray array) {
 
}

jobjectArray android_NewObjectArray(JNIEnv *env, jsize length, jclass elementClass, jobject initialElement) {
 
}

jobject android_GetObjectArrayElement(JNIEnv *env, jobjectArray array, jsize index) {
 
}

void android_SetObjectArrayElement(JNIEnv *env, jobjectArray array, jsize index, jobject val) {
 
}

jbooleanArray android_NewBooleanArray(JNIEnv *env, jsize length) {
 
}

jbyteArray android_NewByteArray(JNIEnv *env, jsize length) {
 
}

jcharArray android_NewCharArray(JNIEnv *env, jsize length) {
 
}

jshortArray android_NewShortArray(JNIEnv *env, jsize length) {
 
}

jintArray android_NewIntArray(JNIEnv *env, jsize length) {
 
}

jlongArray android_NewLongArray(JNIEnv *env, jsize length) {
 
}

jfloatArray android_NewFloatArray(JNIEnv *env, jsize length) {
 
}

jdoubleArray android_NewDoubleArray(JNIEnv *env, jsize length) {
 
}

jboolean *android_GetBooleanArrayElements(JNIEnv *env, jbooleanArray array, jboolean *isCopy) {
 
}

jbyte *android_GetByteArrayElements(JNIEnv *env, jbyteArray array, jboolean *isCopy) {
 
}

jchar *android_GetCharArrayElements(JNIEnv *env, jcharArray array, jboolean *isCopy) {
 
}

jshort *android_GetShortArrayElements(JNIEnv *env, jshortArray array, jboolean *isCopy) {
 
}

jint *android_GetIntArrayElements(JNIEnv *env, jintArray array, jboolean *isCopy) {
 
}

jlong *android_GetLongArrayElements(JNIEnv *env, jlongArray array, jboolean *isCopy) {
 
}

jfloat *android_GetFloatArrayElements(JNIEnv *env, jfloatArray array, jboolean *isCopy) {
 
}

jdouble *android_GetDoubleArrayElements(JNIEnv *env, jdoubleArray array, jboolean *isCopy) {
 
}

void android_ReleaseBooleanArrayElements(JNIEnv *env, jbooleanArray array, jboolean *elems, jint mode) {
 
}

void android_ReleaseByteArrayElements(JNIEnv *env, jbyteArray array, jbyte *elems, jint mode) {
 
}

void android_ReleaseCharArrayElements(JNIEnv *env, jcharArray array, jchar *elems, jint mode) {
 
}

void android_ReleaseShortArrayElements(JNIEnv *env, jshortArray array, jshort *elems, jint mode) {
 
}

void android_ReleaseIntArrayElements(JNIEnv *env, jintArray array, jint *elems, jint mode) {
 
}

void android_ReleaseLongArrayElements(JNIEnv *env, jlongArray array, jlong *elems, jint mode) {
 
}

void android_ReleaseFloatArrayElements(JNIEnv *env, jfloatArray array, jfloat *elems, jint mode) {
 
}

void android_ReleaseDoubleArrayElements(JNIEnv *env, jdoubleArray array, jdouble *elems, jint mode) {
 
}

void android_GetBooleanArrayRegion(JNIEnv *env, jbooleanArray array, jsize start, jsize len, jboolean *buf) {
 
}

void android_GetByteArrayRegion(JNIEnv *env, jbyteArray array, jsize start, jsize len, jbyte *buf) {
 
}

void android_GetCharArrayRegion(JNIEnv *env, jcharArray array, jsize start, jsize len, jchar *buf) {
 
}

void android_GetShortArrayRegion(JNIEnv *env, jshortArray array, jsize start, jsize len, jshort *buf) {
 
}

void android_GetIntArrayRegion(JNIEnv *env, jintArray array, jsize start, jsize len, jint *buf) {
 
}

void android_GetLongArrayRegion(JNIEnv *env, jlongArray array, jsize start, jsize len, jlong *buf) {
 
}

void android_GetFloatArrayRegion(JNIEnv *env, jfloatArray array, jsize start, jsize len, jfloat *buf) {
 
}

void android_GetDoubleArrayRegion(JNIEnv *env, jdoubleArray array, jsize start, jsize len, jdouble *buf) {
 
}

void android_SetBooleanArrayRegion(JNIEnv *env, jbooleanArray array, jsize start, jsize len, const jboolean *buf) {
 
}

void android_SetByteArrayRegion(JNIEnv *env, jbyteArray array, jsize start, jsize len, const jbyte *buf) {
 
}

void android_SetCharArrayRegion(JNIEnv *env, jcharArray array, jsize start, jsize len, const jchar *buf) {
 
}

void android_SetShortArrayRegion(JNIEnv *env, jshortArray array, jsize start, jsize len, const jshort *buf) {
 
}

void android_SetIntArrayRegion(JNIEnv *env, jintArray array, jsize start, jsize len, const jint *buf) {
 
}

void android_SetLongArrayRegion(JNIEnv *env, jlongArray array, jsize start, jsize len, const jlong *buf) {
 
}

void android_SetFloatArrayRegion(JNIEnv *env, jfloatArray array, jsize start, jsize len, const jfloat *buf) {
 
}

void android_SetDoubleArrayRegion(JNIEnv *env, jdoubleArray array, jsize start, jsize len, const jdouble *buf) {
 
}

jint android_RegisterNatives(JNIEnv *env, jclass clazz, const JNINativeMethod* methods, jint nMethods) {
 
}

jint android_UnregisterNatives(JNIEnv *env, jclass clazz) {
 
}

jint android_MonitorEnter(JNIEnv *env, jobject obj) {
 
}

jint android_MonitorExit(JNIEnv *env, jobject obj) {
 
}

jint android_GetJavaVM(JNIEnv *env, JavaVM** vm) {
    *vm = android_JavaVM;
    return JNI_OK;
}

void android_GetStringRegion(JNIEnv *env, jstring str, jsize start, jsize len, jchar *buf) {
 
}

void android_GetStringUTFRegion(JNIEnv *env, jstring str, jsize start, jsize len, char* buf) {
 
}

void *android_GetPrimitiveArrayCritical(JNIEnv *env, jarray array, jboolean *isCopy) {
 
}

void android_ReleasePrimitiveArrayCritical(JNIEnv *env, jarray array, void *carray, jint mode) {
 
}

const jchar *android_GetStringCritical(JNIEnv *env, jstring str, jboolean *isCopy) {
 
}

void android_ReleaseStringCritical(JNIEnv *env, jstring str, const jchar *cstring) {
 
}

jweak android_NewWeakGlobalRef(JNIEnv *env, jobject obj) {
 
}

void android_DeleteWeakGlobalRef(JNIEnv *env, jweak obj) {
 
}

jboolean android_ExceptionCheck(JNIEnv *env) {
 
}

jobject android_NewDirectByteBuffer(JNIEnv *env, void *address, jlong capacity) {
 
}

void *android_GetDirectBufferAddress(JNIEnv *env, jobject buf) {
 
}

jlong android_GetDirectBufferCapacity(JNIEnv *env, jobject buf) {
 
}

jobjectRefType android_GetObjectRefType(JNIEnv *env, jobject obj) {
 
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
