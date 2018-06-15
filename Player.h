#pragma once

#include "Entity.h"
#include "ChunkStruct.h"
#include "Item.h"

class Player : public Entity
{
private:
	int mousePosX;
	int mousePosY;

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

	int idleToggle;

	//shooting variables
	double fireTimer;

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

	float moveX;
	float moveY;

	double legLength; //total length of leg
	int userInputK;
	bool userInputJ;
	int userInputM;

	double mapPosX;
	double mapPosY;

	int playerX;
	int playerY;

	double posX;
	double posY;

	int facing;

	struct Inventory
	{
		const int invX = 8;
		const int invY = 5;
		int invRectSize;

		std::vector<Item> ItemsI;
		std::vector<std::vector<Item>> Items;
	};

	Player(PlayerTextureMap *tmap);
	~Player();
	void LoadTextures(PlayerTextureMap *tmap);
	void Running(sf::RenderWindow &window);
	void Jump(Controls *controls);
	void Idle();
	void PlayerCollision(int x, int y, Clock *clock, std::vector<std::vector<ChunkStruct>> &chunkStructs);

	void Aiming(sf::RenderWindow &window);

	void Update(Clock *clock, Controls *controls, sf::RenderWindow &window);

	void Draw(Clock *clock, sf::RenderWindow &window);

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