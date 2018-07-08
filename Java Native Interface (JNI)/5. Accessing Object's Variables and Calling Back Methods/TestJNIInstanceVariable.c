#include <jni.h>
#include <stdio.h>
#include "TestJNIInstanceVariable.h"

JNIEXPORT void JNICALL Java_TestJNIInstanceVariable_modifyInstanceVariable(JNIEnv *env, jobject thisObj){
	jclass thisClass = (*env)->GetObjectClass(env,thisObj);

	jfieldID fidNumber = (*env)->GetFieldID(env,thisClass,"number","I");
	if (NULL == fidNumber) return;
	jint number = (*env)->GetIntField(env, thisObj, fidNumber);
	printf("In C, the int is %d\n", number);
	number = 99;
	(*env)->SetIntField(env, thisObj,fidNumber,number);

	jfieldID fidMessage = (*env)->GetFieldID(env,thisClass,"message","Ljava/lang/String;");
	if (NULL == fidMessage) return;
	jstring message = (*env)->GetObjectField(env, thisObj, fidMessage);

	const char *cStr =(*env)->GetStringUTFChars(env,message,NULL);
	if (NULL == cStr) return;
	printf("In C, the string is %s\n", cStr);
	(*env)->ReleaseStringUTFChars(env,message,cStr);
	message = (*env)->NewStringUTF(env,"Hello from C");
	if (NULL == message) return;

	(*env)->SetObjectField(env,thisObj,fidMessage,message);
}