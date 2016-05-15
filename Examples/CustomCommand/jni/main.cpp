#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include "Substrate.h" // We will use this header for hooking other functions

#define LOG_TAG "net.caborambo.addon.customcommand"
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)) // Left here for debugging

#include "mcpe/ChatScreen.h" // We will use this header for hooking ChatScreen::init
#include "mcpe/MinecraftClient.h" // We will use this header for defining MinecraftClient

MinecraftClient* mcclient; // Our variable for reusing it in later functions. For now it will be null.

// This function will be called once our command is sent by a player
// I will explain this function later on
std::string TestFunction(std::vector<Token> const& args) {
	for (int a = 0; a < 150; a++) {
		mcclient->minecraft.getLevel()->addParticle((ParticleType) 31, mcclient->getLocalPlayer()->getPos(), {0, 0, 0}, 8); // Spawns a particle 150 times
	}
	return "Yay, your command worked!"; // Returns a string with our message to the Player after using the command
}

static void (*ChatScreen$init_real)(ChatScreen*); // The actual function of our hook
static void ChatScreen$init_hook(ChatScreen* screen) { // This hook is called whenever the Player opens the Chat screen
	ChatScreen$init_real(screen); // Chat screen will act as if nothing happened
	
	screen->client.minecraft.cmdParser->addCommand("testcmd", "s", TestFunction); // This function adds our command to the command list of MCPE
	// First parameter is command name: we will use 'testcmd' that will hear for '/testcmd <string>' on the command screen
	// Second parameter are parameters: 'n' and 'i' stand for numbers/integers, 's' stands for strings and '|' stands for not obligatory parameters
	// Examples:
	// 		- 'ns' will stand for a number and an integer: /testcmd <number> <string>
	//		- 's|s' will stand for two strings, the difference is that after the '|', any parameter symbol that is there won't be
	// 		   obligatory at the time of sending the command: /testcmd <string> [secondString]
	// Third parameter is the function that will be called if the command is sent by any Player. See line 17 for the function we will be using
	// for this.
	
	LOGI("ServerCommandParser: %i", screen->client.minecraft.cmdParser); // This is left here to check whether ServerCommandParser is null or not
}

static void (*MinecraftClient$init_real)(MinecraftClient*);
static void MinecraftClient$init_hook(MinecraftClient* client) {
	mcclient = client;
	MinecraftClient$init_real(client);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*) &ChatScreen::init, (void*) &ChatScreen$init_hook, (void**) &ChatScreen$init_real); // Our hook for ChatScreen::init
	MSHookFunction(dlsym(RTLD_DEFAULT, "_ZN15MinecraftClient4initEv"), (void*) &MinecraftClient$init_hook, (void**) &MinecraftClient$init_real); // Our hook for MinecraftClient::init
	// Used a symbol cuz I'm lazy to include it in the header
	return JNI_VERSION_1_2;
}
