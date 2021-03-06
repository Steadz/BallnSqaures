#pragma once
#include "Transform.h"
#include "GameObject.h"
#include "CollisionInfo.h"
class Player : public GameObject
{
public:
	Player();
	Player(aie::Texture* a_texture, Vector2 a_position);
	~Player();

	bool startup();

	void update(float deltaTime);

	void draw(aie::Renderer2D * a_2dRenderer);

	void OnCollision(GameObject* a_obj2, CollisionSide a_collisionSide);

private:
	aie::Input* input;

	Vector2 velocity, direction, gravity;
	float speed;
	float maxSpeed = 10.0f;
	bool bGravity;
	Vector2 prevPosition;
	bool collidingWithGround = false;
};

