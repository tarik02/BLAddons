#pragma once

#include <string>
#include <vector>
#include <memory>

#define PACKET_DISCONNECT_ID 5
#define PACKET_TEXT_ID 7

namespace RakNet {
	class BitStream;
}
class NetEventCallback;

struct Packet {
	//void** vtable;	// 0
	int a;	// 4
	int b;	// 8
	bool c; // 12
	
	virtual ~Packet();
	virtual int getId() const = 0;
	virtual void write(RakNet::BitStream*) const = 0;
	virtual void read(RakNet::BitStream*) = 0;
	virtual void handle(const RakNet::RakNetGUID&, NetEventCallback*) const = 0;
};

class MinecraftPackets {
public:
	static std::unique_ptr<Packet> createPacket(int);
};

struct DisconnectPacket : public Packet {
public:
	std::string message;	// 16
	
	virtual ~DisconnectPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream*) const;
	virtual void read(RakNet::BitStream*);
	virtual void handle(const RakNet::RakNetGUID&, NetEventCallback*) const;
};

enum TextPacketType : int {
	RAW,
	CHAT,
	LOCALIZABLE,
	POPUP,
	TIP,
	SYSTEM
};

struct TextPacket : public Packet {
	TextPacketType type;				// 13
	std::string source; 				// 16
	std::string message;				// 20
	std::vector<std::string> params;	// 24
	
	virtual ~TextPacket();
	virtual int getId() const;
	virtual void write(RakNet::BitStream*) const;
	virtual void read(RakNet::BitStream*);
	virtual void handle(const RakNet::RakNetGUID&, NetEventCallback*) const;
	
	TextPacket(TextPacketType, const std::string&, const std::string&, std::vector<std::string> const&);
	
	static TextPacket* createRaw(const std::string&);
	static TextPacket* createSystemMessage(const std::string&);
	static TextPacket* createTranslated(const std::string&, std::vector<std::string> const&);
};
