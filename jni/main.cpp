#include <string>
#include<cxxabi.h>
#include <jni.h>
std::string toString(JNIEnv* env, jstring j_str)
{
	//DO NOT RELEASE.
	const char * c_str = env->GetStringUTFChars(j_str, 0);
	std::string cpp_str = c_str;
	return cpp_str;
}

extern "C"
{
	JNIEXPORT jstring JNICALL Java_com_skytnt_elfbox_Utils_demangle(JNIEnv*env,jobject thiz,jstring str)
	{
		char const* symbol_name = toString(env,str).c_str();
		char const* ret = abi::__cxa_demangle(symbol_name,0,0,0);
		if(symbol_name&&ret!=""&&ret){
			return env->NewStringUTF(ret);
			
		}
		return str;
	}
}
