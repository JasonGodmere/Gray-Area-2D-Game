#pragma once

#include "00_Entity.h"
#include "31_Chunk.h"

class Player : public Entity
{
private:
	//Running Animation Variables
	double totalLegLength;
	double contactWidth; //the width of ground contact relative to player on each step
	double footPos; //farthest left of ground contact
	double footSpeed;
	double footVelocity;
	double footHeight;
	double footContactPos; // where on ground contact is
	double footHyp; //foot hypothenuse length with torso origin
	double angleA;
	double angleB;
	double angleC; 
	double angle1;
	double angle2;
	double legToggle;

	//Limb Anchoring Variables
	double torsoHeight;
	double baseTorsoHeight;
	double limbAngle;
	double limbHyp;
	double limbLegX;
	double limbLegY;

	//rect collision variables
	double rectLeftEdge;
	double rectRightEdge;
	double rectTopEdge;
	double rectBottomEdge;
	int rectInfluenceMargin;
	double rightEdge;
	double leftEdge;
	double topEdge;
	double bottomEdge;

public:
	bool leftCollision;
	bool rightCollision;
	bool topCollision;
	bool bottomCollision;

	double legLength; //total length of leg

	double mapPosX;
	double mapPosY;

	int playerX;
	int playerY;

	double posX;
	double posY;

	int facing;

	Player(Textures* textures);
	
	void LoadTextures(Textures* textures);
	void Running(Controls& controls, sf::RenderWindow &window);
	void Jump(Controls *controls);
	void PlayerCollision(int x, int y, Physics& physics, std::vector<std::vector<Chunk>> &chunks);

	void Aiming(sf::RenderWindow &window);

	void Update(Physics& physics, Controls *controls, sf::RenderWindow &window);

	void Draw(Physics& physics, sf::RenderWindow &window);

	//inventory
	sf::RectangleShape invRect;
	sf::Sprite invSprite;

	//player
	sf::CircleShape head;
	sf::Sprite head_S;

	sf::RectangleShape torso;
	sf::Sprite torso_S;

	sf::RectangleShape armT1;
	sf::Sprite armT1_S;
	sf::RectangleShape armT2;
	sf::Sprite armT2_S;

	sf::RectangleShape armB1;
	sf::Sprite armB1_S;
	sf::RectangleShape armB2;
	sf::Sprite ermB2_S;

	sf::RectangleShape legT1;
	sf::Sprite legT1_S;
	sf::RectangleShape legT2;
	sf::Sprite legT2_S;

	sf::RectangleShape legB1;
	sf::Sprite legB1_S;
	sf::RectangleShape legB2;
	sf::Sprite legB2_S;
};