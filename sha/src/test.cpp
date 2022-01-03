#include <iostream>
#include <jni.h>
#include "ysh_Sha.h"
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{
	string input;
	cin >> input;

	JavaVM* vm;
	JNIEnv* env;
	JavaVMInitArgs vm_args;
	JavaVMOption options;

	//options.optionString = "-Djava.class.path=/home/enc/1JNItest/cal";
	options.optionString = "-Djava.class.path=/home/enc/sha/sha";
	//자바 클래스파일 경로
	
	memset(&vm_args, 0, sizeof(vm_args));
	//메모리 초기화
	
	vm_args.version = JNI_VERSION_1_8;
	vm_args.nOptions = 1;
	vm_args.options = &options;

	jint res = JNI_CreateJavaVM(&vm, (void**)&env, &vm_args);
	//JVM구동
	
	if (res < 0)
	{
		printf("Can't create Java VM\n");
		return -1;
	}

	jclass cls;
	jobject obj;

	cls = env->FindClass("ysh/Sha");
	//cls = env->FindClass("java/lang/String");
	if (cls != 0)
	{
		jmethodID cls_constructor = env->GetMethodID(cls, "<init>", "()V");
		if (cls_constructor != 0)
		{
			obj = env->NewObject(cls, cls_constructor, "()V");
		}
	}
	else
	{
		printf("Can't find Class\n");
		return -1;
	}
	
	char* cinput = new char[input.length()];
	strcpy(cinput, input.c_str());

	jstring output1 = Java_ysh_Sha_sha256(env, obj, env->NewStringUTF(cinput));
	const char* coutput = new char[64];
	coutput = env->GetStringUTFChars(output1, 0);
	cout << "sha256('" << input << "'):" << coutput << endl;
	vm->DestroyJavaVM();
	return 0;
}
