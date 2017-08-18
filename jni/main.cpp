#include <string>
#include<cxxabi.h>
#include <jni.h>
extern "C"
{
	JNIEXPORT jstring JNICALL Java_com_skytnt_elfbox_Utils_demangle(JNIEnv*env,jobject thiz,jstring str)
	{
		const char* symbol_name =env->GetStringUTFChars(str, 0);
		const char* ret = abi::__cxa_demangle(symbol_name,0,0,0);
		return ret?env->NewStringUTF(ret):str;
	}
}
