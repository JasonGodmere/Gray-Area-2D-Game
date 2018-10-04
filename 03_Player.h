#pragma once

#include "00_Entity.h"
#include "30_World.h"

class Player : public Entity
{
private:
	//Running Animation Variables
	double totalLegLength;
	double contactWidth; //the width of ground contact relative to player on each step
	double footPos; //farthest left of ground contact
	double footSpeed;
	double footVelocity;
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

	//this is a 2d vector holding all the corner point values of player collision box
	float playerCollisionPoints[2][4];//4 points, 2 values (x and y) for each point
	//the order of points doesn't matter as long as it is in sequence around the parimeter

	//the same is done for the chunk box
	float chunkCollisionPoints[2][4];

	float lastPosX;
	float lastPosY;

public:
	int collisionZoneX[2];//index[0] refers to bottom end of range and index[1] is to top end of range
	int collisionZoneY[2];

	/*
	COLLISION CONCEPT
	
	Problem
	since the player falling can travel as much as 1040 pixels per second falling, at 5 fps (lowest framerate program allows)
	the player will travel 208 pixels every frame. If I were to only detect collisions when the player is
	inside a block (currently 32 pixels), a falling player could "move" through as many as 6 blocks before the next frame.

	Solution
	My idea is to have the player track its previous location (the location of its last frame) and "draw" a 
	line through them. if the line of the last frame and current frame cross a barrier, the player can back
	track along that line until the barrier is not within the collision box (bottom collision has priority.

	Note
	We only need to check the collisions of things that are in the (influence box) drawn from the players last position
	to its current position.
	*/


	double legLength; //total length of leg

	int playerX;
	int playerY;

	double posX;
	double posY;

	int facing;

	Player(Textures* textures);
	
	void LoadFrame(Textures* textures); //the character body skeleton
	
	//actions
	void Building(Controls& controls, World& world);
	void Running(Controls& controls, sf::RenderWindow &window);
	void Jump(Controls *controls);
	void Aiming(sf::RenderWindow &window);

	void PlayerCollision(Physics& physics, World& world);

	void Update(Physics& physics, Controls *controls, World& world, sf::RenderWindow &window);

	void Draw(Physics& physics, sf::RenderWindow &window);

	//building
	sf::RectangleShape block;

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