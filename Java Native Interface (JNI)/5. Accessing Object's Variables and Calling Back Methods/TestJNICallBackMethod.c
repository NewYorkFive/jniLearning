#include <jni.h>
#include <stdio.h>
#include "TestJNICallBackMethod.h"

JNIEXPORT void JNICALL Java_TestJNICallBackMethod_nativeMethod(JNIEnv *env,jobject thisObj){
	jclass thisClass = (*env)->GetObjectClass(env,thisObj);

	jmethodID midCallBack = (*env)->GetMethodID(env, thisClass, "callback", "()V");
	if (NULL == midCallBack) return;
	printf("In C,call back Java's callback() \n");
	(*env)->CallVoidMethod(env,thisObj,midCallBack);

	jmethodID midCallBackStr = (*env)->GetMethodID(env,thisClass,"callback","(Ljava/lang/String;)V");
	if(NULL == midCallBack) return;
	printf("In C,call back Java's callback(String)\n");
	jstring message = (*env)->NewStringUTF(env,"Hello from C");
	(*env)->CallVoidMethod(env,thisObj,midCallBackStr,message);

	jmethodID midCallBackAverage = (*env)->GetMethodID(env,thisClass,"callbackAverage","(II)D");
	if (NULL == midCallBackAverage) return;
	jdouble average = (*env)->CallDoubleMethod(env,thisObj,midCallBackAverage,2,3);
	printf("In C, the average is %lf\n",average);

	jmethodID midCallBackStatic = (*env)->GetStaticMethodID(env,thisClass, "callbackStatic","()Ljava/lang/String;");
	if (NULL == midCallBackStatic) return;
	jstring resultJNIStr = (*env)->CallStaticObjectMethod(env,thisClass,midCallBackStatic);
	const char *resultCStr = (*env)->GetStringUTFChars(env,resultJNIStr,NULL);
	if (resultCStr == NULL) return;
	printf("In C , the returned string is %s\n", resultCStr);
	(*env)->ReleaseStringUTFChars(env,resultJNIStr,resultCStr);
}