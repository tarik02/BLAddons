#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include "Substrate.h"

#define LOG_TAG "MyCustomItem"
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

#include "mcpe/Item.h"

class MyCustomItem : public Item {
public:
    MyCustomItem(int id, const std::string& name);
    
    virtual int getEnchantSlot() const; // for overriding the Item's enchant slot
    virtual int getEnchantValue() const; // for overriding the Item's enchant value
};

MyCustomItem::MyCustomItem(int id, const std::string& name) : Item(name, id - 0x100) {
    this->setIcon("apple", 0);
    this->setCategory((CreativeItemCategory) 3);
}

int MyCustomItem::getEnchantSlot() const {
    return 16; // sword
}

int MyCustomItem::getEnchantValue() const {
    return 7; // :v
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems_hook, (void**) &Item$initItems_real);
    return JNI_VERSION_1_2;
}