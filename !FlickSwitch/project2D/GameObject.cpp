#include "GameObject.h"

GameObject::GameObject()
{
	m_texture = nullptr;
	m_transform.SetPosition(Vector2(0, 0));
	m_radius = 0.0f;
	objType = "Unknown";
	collision = false;
}

GameObject::GameObject(aie::Texture * a_texture, Vector2 a_position)
{
	m_transform.SetPosition(a_position);
	SetTexture(a_texture);
	m_radius = (a_texture->getWidth() / 2);
	objType = "Unknown";
	collision = false;
}


GameObject::~GameObject()
{

}

void GameObject::SetTexture(aie::Texture * a_texture)
{
	m_texture = a_texture;
}


bool GameObject::startup()
{
	return true;
}

void GameObject::update(float deltaTime)
{

}

void GameObject::draw(aie::Renderer2D* a_2drenderer)
{
	//draw the object's texture
	//a_renderer.drawSpriteTransformed3x3(m_texture, (float*)m_transform.GetGlobalMatrix);
}

Vector2 GameObject::getPosition()
{
	return m_transform.GetPosition();
}

Vector2 GameObject::getLinePos1()
{
	return linePos1;
}

Vector2 GameObject::getLinePos2()
{
	return linePos2;
}

void GameObject::setLinePos1(Vector2 a_linePos1)
{
	linePos1 = a_linePos1;
}

void GameObject::setLinePos2(Vector2 a_linePos2)
{
	linePos2 = a_linePos2;
}

std::string GameObject::getType()
{
	return objType;
}

void GameObject::OnCollision(GameObject * a_obj2)
{

}

void GameObject::setCollision(bool a_collision)
{
	collision = a_collision;
}

float GameObject::getRadius() const
{
	return m_radius;
}

void GameObject::setRadius(float a_radius)
{
	m_radius = a_radius;
}

void GameObject::setType(std::string a_objType)
{
	objType = a_objType;
}