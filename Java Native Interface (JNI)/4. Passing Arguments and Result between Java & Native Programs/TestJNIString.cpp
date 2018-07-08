#include <jni.h>
//#include <stdio.h>
#include <iostream>
#include <string>
#include "TestJNIString.h"

using namespace std;

JNIEXPORT jstring JNICALL Java_TestJNIString_sayHello(JNIEnv *env, jobject thisObj, jstring inJNIStr) {
   const char *inCStr = env->GetStringUTFChars(inJNIStr, NULL);
   if (NULL == inCStr) return NULL;
 
    cout << "In C++, the received string is: " << inCStr <<endl;
   env->ReleaseStringUTFChars(inJNIStr, inCStr);  // release resources
 
//   char outCStr[128];
//    cout << "Enter a String:" ;
//    cin >> outCStr;
//   return env->NewStringUTF(outCStr);
    
    string outCStr;
    cout << "enter a string:";
    cin >> outCStr;
    return env->NewStringUTF(outCStr.c_str());
    
}

