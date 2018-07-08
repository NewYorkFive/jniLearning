#include <jni.h>
#include <stdio.h>
#include "TestJNIStaticVariable.h"

JNIEXPORT void JNICALL Java_TestJNIStaticVariable_modifyStaticVariable(JNIEnv *env, jobject thisObj){
	jclass cls = (*env)->GetObjectClass(env,thisObj);

	jfieldID fidNumber = (*env)->GetStaticFieldID(env,cls,"number","D");
	if (NULL == fidNumber) return;
	jdouble number = (*env)->GetStaticDoubleField(env,cls,fidNumber);
	printf("In C, the double is %lf\n", number);
	number = 77.88;
	(*env)->SetStaticDoubleField(env,cls,fidNumber,number);
}