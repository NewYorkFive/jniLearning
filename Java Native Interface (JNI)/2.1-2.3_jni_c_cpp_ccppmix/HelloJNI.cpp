//c
//#include <jni.h>
//#include <stdio.h>
//#include "HelloJNI.h"
//
//// Implementation of native method sayHello() of HelloJNI class
//JNIEXPORT void JNICALL Java_HelloJNI_sayHello(JNIEnv *env, jobject thisObj) {
//    printf("Hello Girls!\n");
//    return;
//}
//
//

#include <jni.h>
#include <iostream>
#include "HelloJNI.h"
using namespace std;

// Implementation of native method sayHello() of HelloJNI class
JNIEXPORT void JNICALL Java_HelloJNI_sayHello(JNIEnv *env, jobject thisObj) {
    cout << "Hello World from C++!" << endl;
    cout << "THIS IS TODAY" << endl;
    return;
}
