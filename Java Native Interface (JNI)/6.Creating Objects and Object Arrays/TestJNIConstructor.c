#include <jni.h>
#include <stdio.h>
#include "TestJNIConstructor.h"
 
JNIEXPORT jobject JNICALL Java_TestJNIConstructor_getIntegerObject(JNIEnv *env, jobject thisObj, jint number) {
	jclass cls = (*env)->FindClass(env, "java/lang/Integer");
	jmethodID midInit = (*env)->GetMethodID(env,cls,"<init>","(I)V");
	if(NULL == midInit) return NULL;
	jobject newObj = (*env)->NewObject(env, cls, midInit, number);

	jmethodID midToString = (*env)->GetMethodID(env,cls,"toString","()Ljava/lang/String;");
	if(NULL == midToString) return NULL;
	jstring resultStr = (*env)->CallObjectMethod(env,newObj,midToString);
	const char *resultCStr = (*env)->GetStringUTFChars(env,resultStr,NULL);
	printf("IN C: the number is %s\n", resultCStr);
	return newObj;
}