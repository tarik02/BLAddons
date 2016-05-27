#pragma once

struct Entity;
enum EntityRendererId;

struct EntityRenderDispatcher {
	void* getRenderer(Entity&);
	void* getRenderer(EntityRendererId);
	
	static EntityRenderDispatcher* getInstance();
}; 