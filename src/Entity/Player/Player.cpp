
#include "Player.h"


Player::Player(Textures* textures, sf::RenderWindow& window)
{
	LoadFrame(textures);
	legToggle = 0;
	footPos = 25;
	torsoHeight = 72;
	baseTorsoHeight = 72;
	legLength = 90;
	position[0] = 0;

	footSpeed = 0;
	footVelocity = 0;

	Physics::InitPhysics();

	//viewchunk initialization
	//viewChunks = new ViewChunks(window.getSize().x, window.getSize().y, world);

	//everything align with hitbox, hitbox origin is very bottom
	rect.setSize(sf::Vector2f(40, 160));
	rect.setFillColor(sf::Color(255, 255, 255, 255));
	rect.setOrigin(20, 160);
	rect.setPosition(position[0], position[1]);
}

Player::~Player()
{
	//delete viewChunks;
}

void Player::LoadFrame(Textures* textures)
{
	//head, red green blue for teams and player distinctions (head color)
	head.setRadius(16);
	head.setFillColor(sf::Color(150,150,150));
	head.setOrigin(16,16);

	//torso
	torso.setSize(sf::Vector2f(10,80));
	torso.setFillColor(sf::Color(150,150,150));
	torso.setOrigin(5, 80);

	//armT1
	armT1.setSize(sf::Vector2f(10, 30));
	armT1.setFillColor(sf::Color(150,150,150));
	armT1.setOrigin(5, 0);
	//armT2
	armT2.setSize(sf::Vector2f(10, 30));
	armT2.setFillColor(sf::Color(150, 150, 150));
	armT2.setOrigin(5, 0);

	//armB1
	armB1.setSize(sf::Vector2f(10, 30));
	armB1.setFillColor(sf::Color(100,100,100));
	armB1.setOrigin(5, 0);
	//armB2
	armB2.setSize(sf::Vector2f(10, 30));
	armB2.setFillColor(sf::Color(100, 100, 100));
	armB2.setOrigin(5, 0);

	//legT1
	legT1.setSize(sf::Vector2f(10, 45));
	legT1.setFillColor(sf::Color(150,150,150));
	legT1.setOrigin(5, 0);
	//legT2
	legT2.setSize(sf::Vector2f(10, 45));
	legT2.setFillColor(sf::Color(150, 150, 150));
	legT2.setOrigin(5, 0);

	//legB1
	legB1.setSize(sf::Vector2f(10, 45));
	legB1.setFillColor(sf::Color(80,80,80));
	legB1.setOrigin(5, 0);
	//legB1
	legB2.setSize(sf::Vector2f(10, 45));
	legB2.setFillColor(sf::Color(80,80,80));
	legB2.setOrigin(5, 0);
}

void Player::Draw(Physics& physics, sf::RenderWindow &window)
{
	rect.setPosition(playerX, playerY);

	torso.setPosition(playerX, playerY - torsoHeight);

	armT1.setPosition(playerX + 15, playerY - (40 + torsoHeight));
	armB1.setPosition(playerX, playerY - (40 + torsoHeight));

	legT1.setPosition(playerX, playerY - torsoHeight);
	legB1.setPosition(playerX, playerY - torsoHeight);

	//pin head to torso
	limbHyp = torso.getSize().y;
	limbAngle = torso.getRotation();
	limbLegX = sin(limbAngle*3.1415 / 180) * limbHyp;
	limbLegY = -1 * cos(limbAngle*3.1415 / 180) * limbHyp;
	head.setPosition(torso.getPosition().x + limbLegX,
		torso.getPosition().y + limbLegY);

	//pin upper armT to torso
	limbHyp = torso.getSize().y - 30;
	limbAngle = torso.getRotation();
	limbLegX = sin(limbAngle*3.1415 / 180) * limbHyp;
	limbLegY = -1 * cos(limbAngle*3.1415 / 180) * limbHyp;
	armT1.setPosition(torso.getPosition().x + limbLegX,
		torso.getPosition().y + limbLegY);

	//pin upper armB to torso
	limbHyp = torso.getSize().y - 30;
	limbAngle = torso.getRotation();
	limbLegX = sin(limbAngle*3.1415 / 180) * limbHyp;
	limbLegY = -1 * cos(limbAngle*3.1415 / 180) * limbHyp;
	armB1.setPosition(torso.getPosition().x + limbLegX,
		torso.getPosition().y + limbLegY);

	//pin armT upper arm to lower arm
	limbHyp = armT1.getSize().y;
	limbAngle = armT1.getRotation();
	limbLegX = -1 * sin(limbAngle*3.1415 / 180) * limbHyp;
	limbLegY = cos(limbAngle*3.1415 / 180) * limbHyp;
	armT2.setPosition(armT1.getPosition().x + limbLegX,
		armT1.getPosition().y + limbLegY);

	//pin armB upper arm to lower arm
	limbHyp = armB1.getSize().y;
	limbAngle = armB1.getRotation();
	limbLegX = -1 * sin(limbAngle*3.1415 / 180) * limbHyp;
	limbLegY = cos(limbAngle*3.1415 / 180) * limbHyp;
	armB2.setPosition(armB1.getPosition().x + limbLegX,
		armB1.getPosition().y + limbLegY);

	//pin legT upper leg to lower leg
	limbHyp = legT1.getSize().y;
	limbAngle = legT1.getRotation();
	limbLegX = -1 * sin(limbAngle*3.1415 / 180) * limbHyp;
	limbLegY = cos(limbAngle*3.1415 / 180) * limbHyp;
	legT2.setPosition(legT1.getPosition().x + limbLegX,
		legT1.getPosition().y + limbLegY);

	//pin legB upper leg to lower leg
	limbHyp = legB1.getSize().y;
	limbAngle = legB1.getRotation();
	limbLegX = -1 * sin(limbAngle*3.1415 / 180) * limbHyp;
	limbLegY = cos(limbAngle*3.1415 / 180) * limbHyp;
	legB2.setPosition(legB1.getPosition().x + limbLegX,
		legB1.getPosition().y + limbLegY);

	//viewchunks have to display first so player is over it
	viewChunks->Draw(position[0], position[1], window);

	//window.draw(rect);
	window.draw(armB1);
	window.draw(armB2);
	window.draw(legB1);
	window.draw(legB2);
	window.draw(torso);
	window.draw(head);
	window.draw(legT1);
	window.draw(legT2);
	window.draw(armT1);
	window.draw(armT2);

	window.draw(block);
}