#include "stdafx.h"
#include "GameManager.h"
#include "Player.h"
#include "MeleeEnemy.h"
#include "RangedEnemy.h"
#include "Key.h"
#include "Door.h"
#include "Wall.h"
#include "HealingSmoke.h"
#include "PoisonGas.h"
#include "HealthPickUp.h"
#include <fstream>

GameManager& GameManager::Instance()
{
	static GameManager instance;

	return instance;
}

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}


void GameManager::BeginPlay()
{
	////////////////////////////////////////////////////////////////////////////////
	// Begin example code

	// Load the image file Untitled.png from the Images folder. Give it the unique name of Image1
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/Player.png"), "Player");
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/Key.png"), "Key");
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/Door.png"), "Door");
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/Wall.png"), "Wall");
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/HealingSmoke.png"), "HealingSmoke");
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/PosionGas.png"), "PosionGas");
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/HealthPickUp.png"), "HealthPickUp");
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/MeleeEnemy.png"), "MeleeEnemy");
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/RangedEnemy.png"), "RangedEnemy");



	
	Player* player1 = new Player();
	player1 -> location = Vector2i(1500, 1500);
	player1 -> name = "Player1";
	player1 -> rotation = 0.0f;
	player1 -> xScale = 0.0f;
	player1 -> yScale = 0.0f;
	player1 -> imageName = "Player";
	player1 -> health = 100;
	player1 -> damage = 25;
	player1 -> atkRange = 1;
	player1 -> moveSpeed = 10;

	MeleeEnemy* meleeEnemy1 = new MeleeEnemy();
	meleeEnemy1 ->location = Vector2i(1800, 1800);
	meleeEnemy1 -> name = "MeleeEnemy1";
	meleeEnemy1 -> rotation = 0.0f;
	meleeEnemy1 -> xScale = 0.0f;
	meleeEnemy1 -> yScale = 0.0f;
	meleeEnemy1 -> imageName = "MeleeEnemy";
	meleeEnemy1 -> health = 50;
	meleeEnemy1 -> damage = 10;
	meleeEnemy1 -> atkRange = 1;
	meleeEnemy1 -> moveSpeed = 6;

	RangedEnemy* rangedEnemy1 = new RangedEnemy();
	rangedEnemy1->location = Vector2i(2500, 2500);
	rangedEnemy1->name = "RangedEnemy1";
	rangedEnemy1->rotation = 0.0f;
	rangedEnemy1->xScale = 0.0f;
	rangedEnemy1->yScale = 0.0f;
	rangedEnemy1->imageName = "RangedEnemy";
	rangedEnemy1->health = 25;
	rangedEnemy1->damage = 5;
	rangedEnemy1->atkRange = 10;
	rangedEnemy1->moveSpeed = 8;

	Key* key1 = new Key();
	key1 -> location = Vector2i(0, 1500);
	key1 -> name = "Key1";
	key1 -> rotation = 0.0f;
	key1 -> xScale = 0.0f;
	key1 -> yScale = 0.0f;
	key1 -> imageName = "Key";
	key1 -> pickUpRange = 1;

	Door* door1 = new Door();
	door1 -> location = Vector2i(100, 500);
	door1 -> name = "Door1";
	door1 -> rotation = 0.0f;
	door1 -> xScale = 0.0f;
	door1 -> yScale = 0.0f;
	door1 -> imageName = "Door";

	Wall* wall1 = new Wall();
	wall1 -> location = Vector2i(100, 2500);
	wall1 -> name = "Wall1";
	wall1 -> rotation = 0.0f;
	wall1 -> xScale = 0.0f;
	wall1 -> yScale = 0.0f;
	wall1 -> imageName = "Wall";

	HealingSmoke* healingSmoke1 = new HealingSmoke();
	healingSmoke1 -> location = Vector2i(1000, 1000);
	healingSmoke1 -> name = "HealingSmoke1";
	healingSmoke1 -> rotation = 0.0f;
	healingSmoke1 -> xScale = 0.0f;
	healingSmoke1 -> yScale = 0.0f;
	healingSmoke1 -> imageName = "HealingSmoke";
	healingSmoke1 -> addHealth = 5;
	healingSmoke1 -> AOE = 3;
	healingSmoke1-> duration = 10;


	PoisonGas* poisonGas1 = new PoisonGas();
	poisonGas1 -> location = Vector2i(2000, 2000);
	poisonGas1 -> name = "PosionGas1";
	poisonGas1 -> rotation = 0.0f;
	poisonGas1 -> xScale = 0.0f;
	poisonGas1 -> yScale = 0.0f;
	poisonGas1 -> imageName = "PosionGas";
	poisonGas1 -> damage = 15;
	poisonGas1 -> AOE = 3;
	poisonGas1-> duration = 10;


	HealthPickUp* healthPickUp1 = new HealthPickUp();
	healthPickUp1->location = Vector2i(2000, 1000);
	healthPickUp1->name = "HealthPickUp1";
	healthPickUp1->rotation = 0.0f;
	healthPickUp1->xScale = 0.0f;
	healthPickUp1->yScale = 0.0f;
	healthPickUp1->imageName = "HealthPickUp";
	healthPickUp1->addHealth = 30;
	healthPickUp1->pickUpRange = 1;

	std::ofstream outputFile("objects.csv");
	outputFile << 1 << std::endl;
	player1 -> SaveAsText(outputFile);
	meleeEnemy1->SaveAsText(outputFile);
	rangedEnemy1->SaveAsText(outputFile);
	key1 -> SaveAsText(outputFile);
	door1 -> SaveAsText(outputFile);
	wall1 -> SaveAsText(outputFile);
	healingSmoke1 -> SaveAsText(outputFile);
	poisonGas1 -> SaveAsText(outputFile);
	healthPickUp1->SaveAsText(outputFile);
	outputFile.close();

	delete player1;
	delete meleeEnemy1;
	delete rangedEnemy1;
	delete key1;
	delete door1;
	delete wall1;
	delete healingSmoke1;
	delete poisonGas1;
	delete healthPickUp1;

	std::ifstream inputFile("objects.csv");
	int numObjects = 8;
	inputFile >> numObjects;

	objects.reserve(numObjects);
	for (int index = 0; index < numObjects; ++index)
	{
		Player* player2 = new Player();
		player2 -> LoadFromText(inputFile);
		objects.push_back(player2);

		MeleeEnemy* meleeEnemy2 = new MeleeEnemy();
		meleeEnemy2->LoadFromText(inputFile);
		objects.push_back(meleeEnemy2);

		RangedEnemy* rangedEnemy2 = new RangedEnemy();
		rangedEnemy2->LoadFromText(inputFile);
		objects.push_back(rangedEnemy2);

		Key* key2 = new Key();
		key2 -> LoadFromText(inputFile);
		objects.push_back(key2);

		Door* door2 = new Door();
		door2 -> LoadFromText(inputFile);
		objects.push_back(door2);

		Wall* wall2 = new Wall();
		wall2 -> LoadFromText(inputFile);
		objects.push_back(wall2);

		HealingSmoke* healingSmoke2 = new HealingSmoke();
		healingSmoke2 -> LoadFromText(inputFile);
		objects.push_back(healingSmoke2);

		PoisonGas* poisonGas2 = new PoisonGas();
		poisonGas2 -> LoadFromText(inputFile);
		objects.push_back(poisonGas2);

		HealthPickUp* healthPickUp2 = new HealthPickUp();
		healthPickUp2 -> LoadFromText(inputFile);
		objects.push_back(healthPickUp2);
	}

	// End example code
	////////////////////////////////////////////////////////////////////////////////
}

void GameManager::EndPlay()
{
	// iterate over all of the game objects in the list
	std::vector<GameEntity*>::iterator objectIt;
	for (objectIt = objects.begin(); objectIt != objects.end(); ++objectIt)
	{
		GameEntity* objectPtr = *objectIt;
		delete objectPtr;
	}

	// clear the vector (empty the elements)
	objects.clear();
}

void GameManager::Update(double deltaTime)
{

}

void GameManager::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	////////////////////////////////////////////////////////////////////////////////
	// Begin example code

	// Save the current transformation of the scene
	Gdiplus::Matrix transform;
	canvas.GetTransform(&transform);

	canvas.ScaleTransform(0.2f, 0.2f);
	canvas.RotateTransform(0.0f);
	canvas.TranslateTransform(0.0f, 0.0f);

	for (GameEntity* objectPtr : objects)
	{
		objectPtr->Render(canvas, clientRect);
	}


	canvas.SetTransform(&transform);


	GameFrameworkInstance.DrawText(canvas, Vector2i(100, 0), 12, "Arial", "Hey! If you're seeing this then the game doesn't crash! Hopefully everything works :)", Gdiplus::Color::White);

	// Load the image file Untitled.png from the Images folder. Give it the unique name of Image1


	// Restore the transformation of the scene
	canvas.SetTransform(&transform);

	// End example code
	////////////////////////////////////////////////////////////////////////////////
}
