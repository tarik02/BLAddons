#pragma once

struct Vec3;

struct AABB {
	float x1, y1, z1, x2, y2, z2; // 0-28
	
	AABB();
	AABB(const Vec3&, float);
	AABB(const Vec3&, const Vec3&);
	AABB(float, float, float, float, float, float);
	
	static AABB EMPTY;
};