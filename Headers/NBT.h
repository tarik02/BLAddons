#pragma once

#include <memory>
#include <string>

class PrintStream;
class IDataOutput;
class IDataInput;

// Size: 8
struct Tag {
	// void** vtable;	// 0-4
	std::string name;	// 4-8
	
	virtual ~Tag();
	virtual void deleteChildren();
	virtual void write(IDataOutput&) const = 0;
	virtual void load(IDataInput&) const = 0;
	virtual std::string toString() const = 0;
	virtual char getId() const = 0;
	virtual bool equals(const Tag&) const;
	virtual void print(PrintStream&) const;
	virtual void print(const std::string&, PrintStream&) const;
	virtual Tag* setName(const std::string&);
	virtual std::string getName() const;
	virtual Tag* copy() const = 0;
	
	enum class Type {
		None = 0,
		Byte,
		Short,
		Int,
		Long,
		Float,
		Double,
		ByteArray,
		String,
		List,
		Compound,
		IntArray
	};
	
	Tag(const std::string&);
};

struct CompoundTag : public Tag {
	std::map<std::string, std::unique_ptr<Tag>> data; // 8-?
	
	virtual ~CompoundTag();
	virtual void deleteChildren();
	virtual void write(IDataOutput&) const;
	virtual void load(IDataInput&) const;
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag&) const;
	virtual void print(PrintStream&) const;
	virtual void print(const std::string&, PrintStream&) const;
	virtual Tag* setName(const std::string&);
	virtual std::string getName() const;
	virtual Tag* copy() const;
	
	bool contains(const std::string&) const;
	bool contains(const std::string&, Tag::Type) const;
	std::unique_ptr<Tag> get(const std::string&) const; // not sure about return type
	void getAllTags(std::vector<Tag*>&) const;
	bool getBoolean(const std::string&) const;
	char getByte(const std::string&) const;
	void* getByteArray(const std::string&) const; // return type is void* until appropiate ByteArray class definition
	CompoundTag getCompound(const std::string&) const; // probably a std::unique_ptr<CompoundTag>; #FuckMojang
	double getDouble(const std::string&) const;
	float getFloat(const std::string&) const;
	int getInt(const std::string&) const;
	long long getInt64(const std::string&) const;
	void* getIntArray(const std::string&) const; // return type is void* until appropiate ByteArray class definition
	ListTag getList(const std::string&) const; // probably a std::unique_ptr<ListTag>; #FuckMojang
	short getShort(const std::string&) const;
	std::string getString(const std::string&) const;
	bool isEmpty() const;
	CompoundTag&& operator=(CompoundTag&&);
	void put(const std::string&, std::unique_ptr<Tag>);
	void putBoolean(const std::string&, bool);
	void putByte(const std::string&, char);
	void putByteArray(const std::string&, TagMemoryChunk);
	void putCompound(const std::string&, std::unique_ptr<CompoundTag>);
	void putDouble(const std::string&, float);
	void putFloat(const std::string&, float);
	void putInt(const std::string&, int);
	void putInt64(const std::string&, long long);
	void putShort(const std::string&, short);
	void putString(const std::string&, const std::string&);
	int rawView() const;
	void remove(const std::string&);
	
	CompoundTag();
	CompoundTag(CompoundTag&&);
	CompoundTag(const std::string&);
};

// Size: 20
struct ListTag : public Tag {
	std::vector<std::unique_ptr<Tag>> list;	// 8-20
	
	virtual ~ListTag();
	virtual void deleteChildren();
	virtual void write(IDataOutput&) const;
	virtual void load(IDataInput&) const;
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag&) const;
	virtual void print(PrintStream&) const;
	virtual void print(const std::string&, PrintStream&) const;
	virtual Tag* setName(const std::string&);
	virtual std::string getName() const;
	virtual Tag* copy() const;
	
	void add(std::unique_ptr<Tag>);
	std::unique_ptr<Tag> get(int) const; // not sure about return type
	std::unique_ptr<CompoundTag> getCompound(unsigned int) const;
	float getFloat(int) const;
	int getInt(int) const;
	int size() const;
	
	ListTag();
	ListTag(const std::string&);
};

class ListTagFloatAdder {
public:
	ListTagFloatAdder& operator()(const std::string&, float);
	ListTagFloatAdder& operator()(float);
};

// Size: 12
struct FloatTag : public Tag {
	float data;	// 8-12
	
	virtual ~FloatTag();
	virtual void deleteChildren();
	virtual void write(IDataOutput&) const;
	virtual void load(IDataInput&) const;
	virtual std::string toString() const;
	virtual char getId() const;
	virtual bool equals(const Tag&) const;
	virtual void print(PrintStream&) const;
	virtual void print(const std::string&, PrintStream&) const;
	virtual Tag* setName(const std::string&);
	virtual std::string getName() const;
	virtual Tag* copy() const;
	
	FloatTag(const std::string&);
	FloatTag(const std::string&, float);
};