/*
 * STARTER CODE
 */
#include <iomanip>
#include <iostream>
#include <map>

#include <fstream>
#include <cstdlib>

#include <vector>

#include "GameObject.h"
#include "Vector3D.h"


static void BuildGameObjects(std::vector<GameObject*>& game_objects, const int num = 2)
{
	for (auto count = 0; count < num; ++count)
	{
		int id;
		std::cout << "Enter the gameObject's ID: ";
		std::cin >> id;
		Vector2D<float> point;
		std::cout << "Enter the gameObject's Position (x, y): ";
		std::cin >> point;
		std::cout << "\n--------------------------------------------------------------" << std::endl;
		std::cout << "You Entered " << id << " for the gameObject's ID " << std::endl;
		std::cout << "You Entered " << point << " for the gameObject's Position" << std::endl;
		std::cout << "--------------------------------------------------------------\n" << std::endl;
		auto* gameObject = new GameObject(id, point);
		game_objects.push_back(gameObject);
	}
	
}

static void CompareGameObjects(GameObject* object1, GameObject* object2)
{
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "Magnitude of first gameObject is: " << object1->GetPosition().GetMagnitude() << std::endl;
	std::cout << "Magnitude of second gameObject is: " << object2->GetPosition().GetMagnitude() << std::endl;
	std::cout << "Distance between first gameObject and second gameObject is: "
		<< Vector2D<float>::Distance(object1->GetPosition(), object2->GetPosition()) << std::endl;
	std::cout << "--------------------------------------------------------------\n" << std::endl;

	std::cout << "The angle (in degrees) from the first gameObject to the second gameObject is: "
		<< Vector2D<float>::SignedAngle(object1->GetPosition(), object2->GetPosition()) << std::endl;

	std::cout << "--------------------------------------------------------------\n" << std::endl;
	std::cout << "First Game Object Details:" << std::endl;
	std::cout << object1->ToString() << std::endl;

	std::cout << "Second Game Object Details:" << std::endl;
	std::cout << object2->ToString() << std::endl;
}



int main()
{
	// game object map
	std::map<std::string, GameObject*> gameObjects;

	// makes game objects
	auto* ship = new GameObject("Ship", 0, 3.0f, 4.0f);
	auto* enemy = new GameObject("Enemy", 1, 10.0f, 20.0f);
	
	// add game objects to map
	gameObjects[ship->GetName()] = ship;
	gameObjects[enemy->GetName()] = enemy;

	// Loop through the map
	for (const auto& game_object : gameObjects)
	{
		std::cout << "Key  : " << game_object.first << std::endl;
		std::cout << "Value: " << std::endl;
		std::cout << "====================================================================" << std::endl;
		std::cout << game_object.second->ToString() << std::endl;
	}

	// Gets distance from ship to enemy in map
	auto distance = Vector2D<float>::Distance(gameObjects["Ship"]->GetPosition(), gameObjects["Enemy"]->GetPosition());

	// Out to console
	std::cout << "Distance between: " << gameObjects["Ship"]->GetName() << " and " << gameObjects["Enemy"]->GetName() << " is: " << std::to_string(distance) << std::endl;

	// File
	std::ofstream outfile("gameObject.txt", std::ios::out);
	// Out to file
	outfile << gameObjects["Ship"]->ToFile() << std::endl;
	outfile << gameObjects["Enemy"]->ToFile() << std::endl;
	outfile.close();
	std::ifstream infile("gameObject.txt", std::ios::in);


	GameObject* tempGameObject = new GameObject();
	while(infile >> new GameObject())
	{
		int id;
		float x, y = 0;
		std::string name;
		Vector2D<float> position;

		infile >> id >> name;
		infile.ignore();
		infile >> x;
		infile.ignore();
		infile >> x;
		
		auto* tempObject = new GameObject(name, id, x, y);
		gameObjects[name + " 2"] = tempObject;
	}
	infile.close();


	// Loop through the map
	for (const auto& game_object : gameObjects)
	{
		std::cout << "Key  : " << game_object.first << std::endl;
		std::cout << "Value: " << std::endl;
		std::cout << "====================================================================" << std::endl;
		std::cout << game_object.second->ToString() << std::endl;
	}


	/*outfile << gameObjects["Ship"]->GetID() << " " << gameObjects["Ship"]->GetName() << " " << gameObjects["Ship"]->GetPosition() << std::endl;
	outfile << gameObjects["Enemy"]->GetID() << " " << gameObjects["Enemy"]->GetName() << " " << gameObjects["Enemy"]->GetPosition() << std::endl;*/



	/*std::vector<GameObject*> gameObjects;

	int num_of_GO;
	std::cout << "How Many Game Objects do you need?: ";
	std::cin >> num_of_GO;
	std::cout << "\n--------------------------------------------------------------" << std::endl;

	BuildGameObjects(gameObjects, num_of_GO);
	
	
	int index1;
	std::cout << "What is the First Object index?: ";
	std::cin >> index1;
	std::cout << "\n--------------------------------------------------------------" << std::endl;
	int index2;
	std::cout << "What is the Second Object index?: ";
	std::cin >> index2;
	std::cout << "\n--------------------------------------------------------------" << std::endl;
	
	CompareGameObjects(gameObjects[index1], gameObjects[index2]);
	CompareGameObjects(gameObjects[index1], gameObjects[index2]);*/
}

