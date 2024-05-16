#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <SFML/Graphics.hpp>
#include <thread>

using namespace std;

#include "Graph.h"

void cordCalculate(vector <sf::CircleShape>& vec, size_t new_size);





int main()
{
	system("chcp 1251 >> null");

	bool upravlenie = true, dejkstra = false, salesman = false, close = false;
	list<int> lst;

	graph<string> gr;
	gr.addVertex("0");	//0
	gr.addVertex("12.2");	//1
	gr.addVertex("13.3");	//2
	gr.addVertex("14.4");	//3
	gr.addVertex("15.5");	//4
	gr.addVertex("17.7");	//5
	gr.addVertex("10.01");	//6
	gr.addEdge("12.2", "13.3", 23);
	gr.addDirectEdge("17.7", "13.3", 1);
	gr.addDirectEdge("14.4", "17.7", 2);
	gr.addDirectEdge("10.01","0", 23);
	gr.addEdge("0", "14.4", 25);
	gr.addEdge("10.01", "14.4", 23);
	gr.addDirectEdge("15.5", "12.2", 13);
	gr.addEdge("12.2", "17.7", 35);
	gr.addEdge("10.01", "13.3", 25);
	gr.addEdge("10.01", "12.2", 12);
	gr.addEdge("12.2", "14.4", 12);
	gr.addEdge("14.4", "13.3", 1);
	gr.addEdge("14.4", "15.5", 53);
	gr.addEdge("17.7", "15.5", 42);
	gr.addEdge("17.7", "10.01", 15);

	gr.BFSHelper("12.2");
	cout << endl << endl;
	gr.DFSHelper("12.2");

	//создание вектора для координат вершины и заполнение его координатами
	vector<sf::CircleShape> v(gr.size());	//создание вектора для координат вершин
	vector<sf::RectangleShape> v_edges;		//создание вектора для координат ребер
	vector<sf::Text> v_text;				//создание вектора для координат текста
	vector<sf::Text> v_weight;				//создание вектора для координат веса ребер
	vector<sf::Text> v_dejkstra;			//создание вектора для коориднат текста алгоритма Дейкстры

	vector<int> for_dejk;
	//создание шрифта для данных вершин
	sf::Font font;
	font.loadFromFile("arial.ttf");
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(18);
	text.setFillColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold);
	text.setOutlineColor(sf::Color::White);
	text.setOutlineThickness(2);

	//создание шрифта для веса ребра
	sf::Font font_weight;
	font_weight.loadFromFile("arial.ttf");
	sf::Text text_weight;
	text_weight.setFont(font_weight);
	text_weight.setCharacterSize(18);
	text_weight.setFillColor(sf::Color::Black);
	text_weight.setStyle(sf::Text::Bold);
	text_weight.setOutlineColor(sf::Color::White);
	text_weight.setOutlineThickness(4);

	vector<sf::ConvexShape> v_direction;
	//вызов функций, для первичного расчета постановок
	cordCalculate(v, gr.size());	//функция, которая выполняет расчет расположения вершин
	gr.calcCordEdge(v_edges, v_direction, v);	//метод, который выполняет расчет координат для ребер
	gr.calcCordText(v_text, v, text);	//метода, расчитывающий координаты для даннных вершины
	gr.calcCordWeight(v_weight, v, text_weight);	//метод, рассчитывающий координаты для веса ребра

	size_t temp_size = gr.size();	//переменная, которая отвечает за перерасчет расположения ребер и вершин
	sf::Color color(255, 255, 255);			//цвет для окна
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "My Graph");	//создание окна, в котором будет отрисовываться граф.
	window.setFramerateLimit(30);									// Ограничение на 30 fps

	thread t([&upravlenie, &gr, &dejkstra, &for_dejk, &window, &salesman, &lst, &close]()	//параллельный поток для управления графом
		{
			auto vector_my = gr.getVertexData();
			string menu;
			string data, data2;
			int menu_control;
			int weight;
			vector<string>::iterator it;
			menu = "---------------MENU--------------\n1. Добавить вершину\n2. Удалить вершину\n3. Добавить ненаправленное ребро\n4. Добавить направленное ребро\n5. Удалить ребро\n6. Алгоритм Дейкстры\n7. Задача комивояжера\n8. Обход в ширину\n9. Обход в глубину\n";
			/*"---------------MENU--------------\n
			1. Добавить вершину\n
			2. Удалить вершину\n
			3. Добавить ненаправленное ребро\n
			4. Добавить направленное ребро\n
			5. Удалить ребро\n
			6. Алгоритм Дейкстры\n
			7. Задача комивояжера\n"
			8. Обход в ширину
			9. Обход в глубину
			0. Выход.*/

			while (true)
			{
				cout << menu << endl << "> ";
				cin >> menu_control;
				if (!window.isOpen())
					return;
				switch (menu_control)
				{
				case 1:
					cout << "Введите данные для вершины: " << endl << "> "; cin >> data;
					gr.addVertex(data);
					upravlenie = true;
					break;
				case 2:
					cout << "Введите данные вершины для удаления: " << endl << "> "; cin >> data;
					gr.removeVertex(data);
					upravlenie = true;
					break;
				case 3:
					cout << "Введите 2 вершины, которые необходимо соединить: " << endl << "> "; cin >> data;
					cout << "> "; cin >> data2;
					cout << "Введите вес ребра: " << endl << "> "; cin >> weight;
					gr.addEdge(data, data2, weight);
					upravlenie = true;
					break;
				case 4:
					cout << "Введите 2 вершины, которые необходимо соединить (start -> finish): " << endl << "> "; cin >> data;
					cout << "> "; cin >> data2;
					cout << "Введите вес ребра: " << endl << "> "; cin >> weight;
					gr.addDirectEdge(data, data2, weight);
					upravlenie = true;
					break;
				case 5:
					cout << "Введите 2 вершины, ребро между которыми необходимо удалить: " << endl << "> "; cin >> data;
					cout << "> "; cin >> data2;
					gr.removeEdge(data, data2);
					upravlenie = true;
					break;
				case 6:
					vector_my = gr.getVertexData();
					cout << "Введите стартовую вершину: " << endl << "> "; cin >> data;
					it = find(vector_my.begin(), vector_my.end(), data);
					if (it == vector_my.end())
					{
						cout << endl << endl << "Данной вершины не существует." << endl;
						system("pause");
					}
					else
					{
						for_dejk = gr.dijkstra(size_t(distance(vector_my.begin(), it)));
						dejkstra = true;
						system("pause");
						dejkstra = false;
					}
					break;
				case 7:
					cout << "Введите стартовую вершину: " << endl << "> "; cin >> data;
					vector_my = gr.getVertexData();
					it = find(vector_my.begin(), vector_my.end(), data);
					if (it == vector_my.end())
					{
						cout << endl << endl << "Данной вершины не существует." << endl;
						system("pause");
						break;
					}
					//gr.clearPath();
					gr.SalesmanTravel(distance(vector_my.begin(), it));
					lst = gr.getPath();
					if (lst.size() != vector_my.size())
					{
						cout << endl << endl << "Решение задачи коммивояжера для данного графа не существует." << endl;
						cout << "Попробуйте изменить граф." << endl << endl;
						system("pause");
					}
					else
					{
						cout << endl << "Путь комивояжера:" << endl;
						for (auto& i : lst)
						{
							cout << vector_my[i] << " -> ";
						}
						cout << vector_my[lst.front()] << endl;
						cout << "Цена пути: " << gr.getPathWeight() << endl << endl;
						salesman = true;
						system("pause");
						salesman = false;
					}
					break;
				case 8:
					cout << "Введите стартовую вершину: " << endl << "> "; cin >> data;
					cout << "Обход в ширину:" << endl;
					if (!gr.BFSHelper(data))
					{
						system("cls");
						cout << "Данной вершины не существует." << endl;
						system("pause");
						break;
					}
					system("pause");
					break;
				case 9:
					cout << "Введите стартовую вершину: " << endl << "> "; cin >> data;
					cout << "Обход в глубину:" << endl;
					if (!gr.DFSHelper(data))
					{
						system("cls");
						cout << "Данной вершины не существует." << endl;
						system("pause");
						break;
					}
					system("pause");
					break;
				default:
					menu_control = 0;
					break;
				}
				system("cls");
				string fl;
			}

		});


	//главный цикл отрисовки окна с графом. Пока окно открыто, оно отрисовывается
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed || !t.joinable())
			{
				window.close();
				t.join();
			}
		if (upravlenie)
		{
			upravlenie = false;
			temp_size = gr.size();
			cordCalculate(v, temp_size);
			gr.calcCordEdge(v_edges, v_direction, v);
			gr.calcCordText(v_text, v, text);
			gr.calcCordWeight(v_weight, v, text_weight);
		}

		if (salesman)
		{
			vector<sf::CircleShape> v_point;	//вектор для отметки пройденных вершин
			vector<sf::CircleShape> v_path;		//вектор для отрисовки пройденного пути
			v_path.reserve(800);
			sf::CircleShape trailShape(3.0f);
			trailShape.setFillColor(sf::Color::Green);
			trailShape.setOrigin(trailShape.getLocalBounds().width / 2, trailShape.getLocalBounds().height / 2);

			//создание спрайта (машинки)
			sf::Image image;
			image.loadFromFile("images/car_sprite.png");
			image.createMaskFromColor(sf::Color(255, 255, 255));
			sf::Texture texture_car;
			texture_car.loadFromImage(image);
			sf::Sprite car_sprite;
			car_sprite.setTexture(texture_car);		//устанавливаем текстуру
			car_sprite.setScale(0.7f, 0.7f);		//устанавливаем размер спрайта
			car_sprite.setOrigin(car_sprite.getLocalBounds().width / 2.0f, car_sprite.getLocalBounds().height / 2.0f);

			//дополнительные переменные для отрисовки 
			const float animationSpeed = 300.0f; // Скорость перемещения спрайта (пикселей в секунду)
			sf::Clock clock;
			float elapsedTime = 0.0f;
			int current_local, next_local;
			sf::Vector2f temp;
			auto lst_temp = gr.getPath();
			int size_temp = lst_temp.size();
			next_local = lst_temp.front();


			for (size_t i = 1; i < size_temp; ++i)
			{
				elapsedTime = 0.0f;

				//получение нового пути
				current_local = next_local;
				lst_temp.pop_front();
				next_local = lst_temp.front();

				//создание текстуры для отмеки пути
				v_point.push_back(v[current_local]);
				v_point[i - 1].setOutlineColor(sf::Color::Green);
				v_point[i - 1].setOutlineThickness(6);

				//установка спрайта
				temp = v[current_local].getPosition() - v[next_local].getPosition();
				car_sprite.setPosition(v[current_local].getPosition());
				car_sprite.setRotation((atan2(temp.y, temp.x) * 180 / 3.14159) - 90);

				sf::Vector2f startPosition = v[current_local].getPosition();
				sf::Vector2f targetPosition = v[next_local].getPosition();
				sf::Vector2f distance = targetPosition - startPosition;
				float totalDistance = std::sqrt(distance.x * distance.x + distance.y * distance.y);
				float travelTime = totalDistance / animationSpeed;

				if (!salesman) break;
				//отрисовка спрайта и экрана
				while (elapsedTime < travelTime)
				{
					clock.restart();
					window.clear(color);
					if (!salesman) break;
					for (int j = 0; j < v_point.size(); j++)
					{
						window.draw(v_point[j]);
					}
					for (int j = 0; j < v_edges.size(); j++)
					{
						window.draw(v_edges[j]);
						window.draw(v_direction[j]);
					}
					for (int j = 0; j < v_path.size(); j++)
					{
						window.draw(v_path[j]);
					}
					for (int j = 0; j < v.size(); j++)
					{
						window.draw(v[j]);
						window.draw(v_text[j]);
					}
					for (int j = 0; j < v_weight.size(); j++)
					{
						window.draw(v_weight[j]);
					}

					window.draw(car_sprite);
					window.display();

					elapsedTime += clock.getElapsedTime().asSeconds();

					float t = elapsedTime / travelTime;
					sf::Vector2f currentPosition = startPosition + distance * t;
					trailShape.setPosition(car_sprite.getPosition());
					v_path.push_back(trailShape);
					car_sprite.setPosition(currentPosition);
					travelTime = totalDistance / animationSpeed;
					sf::sleep(sf::milliseconds(10));
				}
			}

			v_point.push_back(v[next_local]);
			v_point.back().setOutlineColor(sf::Color::Green);
			v_point.back().setOutlineThickness(6);


			if (salesman)
			{
				elapsedTime = 0.0f;
				lst_temp = gr.getPath();
				temp = v[lst_temp.back()].getPosition() - v[lst_temp.front()].getPosition();
				car_sprite.setPosition(v[lst_temp.back()].getPosition());
				car_sprite.setRotation((atan2(temp.y, temp.x) * 180 / 3.14159) - 90);

				sf::Vector2f startPosition = v[lst_temp.back()].getPosition();
				sf::Vector2f targetPosition = v[lst_temp.front()].getPosition();
				sf::Vector2f distance = targetPosition - startPosition;
				float totalDistance = std::sqrt(distance.x * distance.x + distance.y * distance.y);
				float travelTime = totalDistance / animationSpeed;

				if (!salesman) break;

				while (elapsedTime < travelTime)
				{
					clock.restart();
					window.clear(color);
					if (!salesman) break;
					for (int j = 0; j < v_point.size(); j++)
					{
						window.draw(v_point[j]);
					}
					for (int j = 0; j < v_edges.size(); j++)
					{
						window.draw(v_edges[j]);
						window.draw(v_direction[j]);
					}
					for (int j = 0; j < v_path.size(); j++)
					{
						window.draw(v_path[j]);
					}
					for (int j = 0; j < v.size(); j++)
					{
						window.draw(v[j]);
						window.draw(v_text[j]);
					}
					for (int j = 0; j < v_weight.size(); j++)
					{
						window.draw(v_weight[j]);
					}

					window.draw(car_sprite);
					window.display();

					elapsedTime += clock.getElapsedTime().asSeconds();

					float t = elapsedTime / travelTime;
					sf::Vector2f currentPosition = startPosition + distance * t;
					trailShape.setPosition(car_sprite.getPosition());
					v_path.push_back(trailShape);
					car_sprite.setPosition(currentPosition);
					travelTime = totalDistance / animationSpeed;
					sf::sleep(sf::milliseconds(10));
				}
				while (salesman)
				{
					sf::sleep(sf::milliseconds(33)); // Задержка на ~30 кадров в секунду
				}
			}
		}
		else
		{

			if (dejkstra)
			{
				gr.calcCordDijkstra(v_dejkstra, v, for_dejk, text);
			}
			window.clear(color);

			for (int i = 0; i < v_edges.size(); i++)
			{
				window.draw(v_edges[i]);
				window.draw(v_direction[i]);
			}

			for (int i = 0; i < v.size(); i++)
			{
				window.draw(v[i]);
			}
			for (int i = 0; i < v_text.size(); i++)
			{
				window.draw(v_text[i]);
			}
			for (int i = 0; i < v_weight.size(); i++)
			{
				window.draw(v_weight[i]);
			}

			if (dejkstra)
			{
				for (int i = 0; i < v_dejkstra.size(); i++)
					window.draw(v_dejkstra[i]);
			}
		}


		window.display();
		sf::sleep(sf::milliseconds(33)); // Задержка на ~30 кадров в секунду
	}



	return 0;
}


//функция рассчиывающая расстановку вершин
void cordCalculate(vector <sf::CircleShape>& vec, size_t new_size)
{
	if (new_size == 0)
	{
		vec.clear();
		return;
	}
	float width, height;
	vec.clear();
	sf::CircleShape circle(40);
	circle.setFillColor(sf::Color::White);
	circle.setOutlineThickness(3);
	circle.setOutlineColor(sf::Color::Black);
	float radius = 400.f;					//радиус круга
	sf::Vector2f center = { 500.f, 500.f };	//Место где будет находится центр круга
	float currentAngle = 0.f;				//поворот конкретной элемента 
	float angleStep = 360.f / new_size;		//щаг поворота относительно круга
	for (int i = 0; i < new_size; i++)
	{
		circle.setPosition(center.x + radius * std::cos(currentAngle * 3.14159 / 180.f), center.y + radius * std::sin(currentAngle * 3.14159 / 180.f));
		currentAngle += angleStep;
		width = circle.getLocalBounds().width;
		height = circle.getLocalBounds().height;
		circle.setOrigin(width / 2.0f, height / 2.0f);
		vec.push_back(circle);
	}
}