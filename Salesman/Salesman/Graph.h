#pragma once
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


void cordCalculate(vector <sf::CircleShape>& vec, size_t new_size);

template <typename T>
class graph
{
public:
	graph();
	~graph();
	size_t size() { return this->_size; }		//количество вершин в графе
	void addVertex(T data);	//метод добавляет вершину в граф
	void addEdge(T data_v1, T data_v2, int weight);	//добавление ребра по ключу
	void addEdge(size_t v1, size_t v2, int weight);	//данный метод добавляет ребро между вершинами
	void addDirectEdge(T v_start, T v_finish, int weight);		//добавление направленного ребра, между вершинами
	void addDirectEdge(size_t start, size_t finish, int weight);
	void removeVertex(T data);				//удаление вершины, по ключу
	void removeEdge(T data_v1, T data_v2);	//удаление ребра по ключу, ключ - значение вершины
	void removeEdge(size_t v1, size_t v2);	//удаление ребра по индексу вершины
	vector<T> getVertexData() { return this->data; }	//метод возвращает вектор с данными

	void calcCordEdge(vector<sf::RectangleShape>& vec, vector<sf::ConvexShape>& v_direction, const vector<sf::CircleShape>& vert);		//расчет для отрисовки ребер
	void calcCordText(vector<sf::Text>& v_text, const vector<sf::CircleShape>& vert, sf::Text& text);	//рассчет для отрисовки данных в вершине
	void calcCordWeight(vector<sf::Text>& v_weight, const vector<sf::CircleShape>& vert, sf::Text& text);					//расчет для отрисовки веса ребра
	void calcCordDijkstra(vector<sf::Text>& v_text, const vector<sf::CircleShape>& vert, const vector<int>& v_dijkstra, sf::Text text);

	//решение задачи комивояжера
	void SalesmanTravel(const int& start);
	list<int> getPath() { return this->pathh; }
	int getPathWeight() { return this->pathWeight; }
	void clearPath() { this->pathh.clear(); }
	vector<int> dijkstra(size_t start);		//реализация алгоритма дейкстры.

	void BFS(const int& v_start);	//алгоритм обхода в ширину.
	void DFS(const int& v_start);	//алгоритм обхода в глубину.

	bool BFSHelper(T data);
	bool DFSHelper(T data);
private:
	//методы для решению задачи комивояжера
	bool AllVisited(std::vector<bool>& visitedVerts);
	std::vector<int> getNeighbours(const int& vert);
	void mainSalesman(const int& start, const int& current, std::list<int>& path, std::vector<bool>& visitedVerts);
	int pathWeight;

	size_t _size;					//количество верщин в графе
	vector<T> data;					//массив с данными
	vector<vector <int>> matrix;		//матрица смежности
	list<int> pathh;					//список с путем
};


template<typename T>
inline bool graph<T>::BFSHelper(T data)
{
	auto it = find(this->data.begin(), this->data.end(), data);
	if (it == this->data.end())
		return false;
	BFS(distance(this->data.begin(), it));
	return true;
}

template<typename T>
inline bool graph<T>::DFSHelper(T data)
{
	auto it = find(this->data.begin(), this->data.end(), data);
	if (it == this->data.end())
		return false;
	DFS(distance(this->data.begin(), it));
	return true;
}

template <typename T>
void graph<T>::DFS(const int& v_start)
{
	size_t i = 0;
	vector<bool> visited(_size, false);			// массив посещенных вершин
	stack<int> st;							// очередь для обхода в ширину

	visited[v_start] = true;					// помечаем начальную вершину как посещенную
	st.push(v_start);							// добавляем начальную вершину в очередь

	while (!st.empty())
	{
		auto current = st.top();				// берем текущую вершину из очереди
		st.pop();

		cout << ++i << ". " << this->data[current] << endl;

		// Получаем смежные вершины и добавляем их в очередь, если они еще не посещены
		vector<int> neighbours = getNeighbours(current);
		for (const auto& neighbour : neighbours)
		{
			if (!visited[neighbour])
			{
				visited[neighbour] = true;
				st.push(neighbour);
			}
		}
	}
}

template <typename T>
void graph<T>::BFS(const int& v_start)
{
	size_t i = 0;
	vector<bool> visited(_size, false);			// массив посещенных вершин
	queue<int> queue;							// очередь для обхода в ширину

	visited[v_start] = true;					// помечаем начальную вершину как посещенную
	queue.push(v_start);							// добавляем начальную вершину в очередь

	while (!queue.empty())
	{
		auto current = queue.front();				// берем текущую вершину из очереди
		queue.pop();

		cout << ++i << ". " << this->data[current] << endl;

		// Получаем смежные вершины и добавляем их в очередь, если они еще не посещены
		vector<int> neighbours = getNeighbours(current);
		for (const auto& neighbour : neighbours)
		{
			if (!visited[neighbour])
			{
				visited[neighbour] = true;
				queue.push(neighbour);
			}
		}
	}
}



template<typename T>
inline std::vector<int> graph<T>::getNeighbours(const int& vert)
{

	std::list<int> result;
	for (int j = 0; j < this->data.size(); ++j)
	{
		if (this->matrix[vert][j] != 0 && this->matrix[vert][j] != INT_MAX)
		{
			result.push_back(j);
		}
	}
	return std::vector<int>(result.begin(), result.end());
}

template<typename T>
inline void graph<T>::SalesmanTravel(const int& start)
{
	this->pathh.clear();
	this->pathWeight = INT_MAX;
	std::list<int> path;
	path.clear();
	path.push_back(start);
	std::vector<bool> vis(this->data.size(), false);
	vis[start] = true;
	this->mainSalesman(start, start, path, vis);
}

template<typename T>
inline bool graph<T>::AllVisited(std::vector<bool>& visitedVerts)
{
	bool flag = true;
	for (int i = 0; i < this->data.size(); i++)
		if (visitedVerts[i] != true)
			flag = false;
	return flag;
};

template<typename T>
inline void graph<T>::mainSalesman(const int& start, const int& current, std::list<int>& path, std::vector<bool>& visitedVerts)
{
	if (this->AllVisited(visitedVerts))
	{
		int min = 0;
		if (!this->matrix[current][start])
		{
			return;
		}

		std::vector<int> p(path.begin(), path.end());
		for (int i = 0; i < p.size() - 1; ++i)
		{
			min += this->matrix[p[i]][p[i + 1]];
			/*std::cout << this->vertexList[p[i]] << ' ';*/
		}
		min += this->matrix[current][start];
		if (this->pathWeight >= min)
		{
			this->pathWeight = min;
			this->pathh = path;
		}
	}

	std::vector<int> nbrs = this->getNeighbours(current);

	for (int& i : nbrs)
	{
		if (!visitedVerts[i])
		{
			std::vector<bool> cpy_vis(visitedVerts.begin(), visitedVerts.end());
			std::list<int> path_cpy(path.begin(), path.end());
			cpy_vis[i] = true;
			path_cpy.push_back(i);
			mainSalesman(start, i, path_cpy, cpy_vis);
		}
	};

}

template <typename T>
vector<int> graph<T>::dijkstra(size_t start) {
	const int INF = INT_MAX;
	vector<int> distance(this->_size, INF);
	vector<bool> visited(this->_size, false);
	distance[start] = 0;
	size_t current;
	int minDistance = INF;
	// выбор непосещенной вершины с минимальным расстоянием
	for (size_t i = 0; i < this->_size - 1; ++i) {
		minDistance = INF;
		current = -1;

		for (size_t j = 0; j < this->_size; ++j) {
			if (!visited[j] && distance[j] < minDistance) {
				current = j;
				minDistance = distance[j];
			}
		}
		// если вершина не найдена, то алгоритм закончил работу
		if (current == -1) break;

		visited[current] = true;
		// обновление расстояний до соседей текущей вершины
		for (size_t j = 0; j < this->_size; ++j) {
			if (this->matrix[current][j] != INF && this->matrix[current][j] != 0) {  //проверяем вершину на существование
				int pathLength = this->matrix[current][j] + minDistance;
				if (pathLength < distance[j]) {
					distance[j] = pathLength;
				}
			}
		}
	}
	for (auto& i : distance)	//если пути нет, то заменяем на несуществующее растояние
		if (i == INF)
			i = -1;
	return distance;
}



template<typename T>
inline graph<T>::graph()
{
	matrix.reserve(10);
	data.reserve(10);
	_size = 0;
	pathWeight = INT_MAX;
}

template<typename T>
inline void graph<T>::addVertex(T data)
{
	this->data.push_back(data);				//добавление элемента в массив, где хранятся данные
	++this->_size;		

	vector<int> vec(this->data.size(), 0);	//создание временного массива, для того, чтобы запушить его в матрицу
	vec[_size - 1] = INT_MAX;
	for (auto& i : this->matrix)			//добавление к уже имеющимся массивам в матрице еще одну ячейку с нулями, так как 
		i.push_back(0);						//ребер к новой вершине нет.	(добавление в матрицу еще одного столбца)
	this->matrix.push_back(vec);			//добавляем массив в матрицу ( строку )
}

template<typename T>
inline void graph<T>::addEdge(T data_v1, T data_v2, int weight)
{
	auto it1 = find(this->data.begin(), this->data.end(), data_v1);
	auto it2 = find(this->data.begin(), this->data.end(), data_v2);
	if (it1 == this->data.end() || it2 == this->data.end()) return;
	addEdge(size_t(distance(this->data.begin(), it1)), size_t(distance(this->data.begin(), it2)), weight);
}

template<typename T>
void graph<T>::addEdge(size_t v1, size_t v2, int weight)		//параметрами в данном методе являются индексы в массиве с данными
{
	if (v1 == v2) return;			//не будет создано петли
	this->matrix[v1][v2] = weight;
	this->matrix[v2][v1] = weight;
}

template<typename T>
inline void graph<T>::addDirectEdge(T v_start, T v_finish, int weight)
{
	auto it1 = find(this->data.begin(), this->data.end(), v_start);
	auto it2 = find(this->data.begin(), this->data.end(), v_finish);
	if (it1 == this->data.end() || it2 == this->data.end()) return;
	addDirectEdge(size_t(distance(this->data.begin(), it1)), size_t(distance(this->data.begin(), it2)), weight);
}

template<typename T>
inline void graph<T>::addDirectEdge(size_t start, size_t finish, int weight)
{
	if (start == finish) return;			//не будет создано петли
	this->matrix[start][finish] = weight;
}

template<typename T>
inline void graph<T>::removeVertex(T data)
{
	auto it1 = find(this->data.begin(), this->data.end(), data);
	if (it1 == this->data.end()) return;
	this->matrix.erase(matrix.begin() + distance(this->data.begin(), it1));
	for (int i = 0; i < this->matrix.size(); ++i)
		this->matrix[i].erase(this->matrix[i].begin() + distance(this->data.begin(), it1));
	this->data.erase(it1);
	--this->_size;
	//this->data.erase(remove_if(this->data.begin(), this->data.end(), [data](T s) {return data == s;}), this->data.end());
}

template<typename T>
inline void graph<T>::removeEdge(T data_v1, T data_v2)
{
	auto it1 = find(this->data.begin(), this->data.end(), data_v1);
	auto it2 = find(this->data.begin(), this->data.end(), data_v2);
	if (it1 == this->data.end() || it2 == this->data.end()) return;
	removeEdge(size_t(distance(this->data.begin(), it1)), size_t(distance(this->data.begin(), it2)));
}

template<typename T>
inline void graph<T>::removeEdge(size_t v1, size_t v2)
{
	if (v1 == v2) return;
	this->matrix[v1][v2] = 0;
	this->matrix[v2][v1] = 0;
}

template<typename T>
inline void graph<T>::calcCordEdge(vector<sf::RectangleShape>& edges, vector<sf::ConvexShape>& v_direction, const vector<sf::CircleShape>& vert)
{
	edges.clear();
	v_direction.clear();

	if (this->matrix.size() == 0) return;

	float length, angle;		//длина прямоуголника и угол поворота

	float width, height;



	//создание прототипов треугольника, для стрелки
	sf::ConvexShape triangle_trash(3); // создаем многоугольник с 3 вершинами (треугольник)
	triangle_trash.setPoint(0, sf::Vector2f(0, 0));
	triangle_trash.setPoint(1, sf::Vector2f(0, 0));
	triangle_trash.setPoint(2, sf::Vector2f(0, 0));

	sf::ConvexShape triangle(3); // создаем многоугольник с 3 вершинами (треугольник)
	triangle.setPoint(0, sf::Vector2f(0, 0)); // задаем координаты первой вершины
	triangle.setPoint(1, sf::Vector2f(25, 0)); // задаем координаты второй вершины
	triangle.setPoint(2, sf::Vector2f(14, 25)); // задаем координаты третьей вершины
	triangle.setFillColor(sf::Color::Black); // задаем цвет заливки
	triangle.setOutlineThickness(0); // задаем толщину границы
	
	float x, y, k, b, t;
	sf::Vector2f center1;
	sf::Vector2f center2;


	sf::Vector2f temp;			//временная пара координат
	size_t row = 0, column = 1;		//индексы колонок и строк для итерации по матрице смежности
	
	//короче тут такая байда, что мне необходимо сейчас правильно расположить треугольники, поэтому вся поебота с ними
	//надо как то грамотно это реализовать, поэтому нужно заняться этим.
	while (row < this->_size - 1)	
	{
		while (column < this->_size)
		{
			if (this->matrix[row][column] == 0 && this->matrix[column][row] == 0)		//если ребра между вершинами нет
				++column;
			else if (this->matrix[column][row] != 0)
			{
				temp = vert[column].getPosition() - vert[row].getPosition();		//вычисляем вектор, направленный от point1 к point2
				length = sqrt(pow(temp.x, 2) + pow(temp.y, 2));	//вычисляем длину вектора temp
				angle = atan2(temp.y, temp.x) * 180 / 3.14159;	//вычисляем угол между осью X и вектором temp и переводим радианы в градусы
				sf::RectangleShape line(sf::Vector2f(length, 3.f));	//создаем прямоуголник шириной 3 пикселя, и вычисленной длиной 
				line.setPosition(vert[row].getPosition()); // устанавливаем начальную точку линии
				line.setRotation(angle); // поворачиваем прямоугольник на нужный угол
				line.setFillColor(sf::Color::Black); // задаем цвет линии
				edges.push_back(line);					//добавляем ребро в вектор
				if (this->matrix[row][column] == 0)		//если ребро направленное
				{
					center1 = vert[column].getPosition();	//берем центры окружностей
					center2 = vert[row].getPosition();	
					k = (center2.y - center1.y) / (center2.x - center1.x);	//находим угловой кожфициент данной прямой
					b = center1.y - k * center1.x;					//находим свободный коэффициент прямой
					t = 1 - (55 / length);							//расчитываем коэфициент смещения (подобран опытным путем)
					x = center1.x + t * (center2.x - center1.x);	//находим x и y для треуголника (стрелки)
					y = center1.y + t * (center2.y - center1.y);
					width = triangle.getLocalBounds().width;		
					height = triangle.getLocalBounds().height;
					triangle.setOrigin(width / 2.0f, height / 2.0f);//устанавливаем отсчета треугоолника от середины
					triangle.setRotation(angle + 90);				//поворачиваем треугольник на нужный угол + поправка, так как треуголник отрисовывается изначально перевернутым
					triangle.setPosition(x, y);		//устанавливаем позицию
					v_direction.push_back(triangle);	//добавляем в вектор для последующей отрисовки
				}
				else
				{
					v_direction.push_back(triangle_trash);	//если ребро не направленное, то просто добавляем треугольник в конец вектора (для простоты отрисовки)
				}
				++column;
			}
			else		//здесь все аналогично, только работаем с верхней частью матрицы 
			{
				temp = vert[row].getPosition() - vert[column].getPosition();		//вычисляем вектор, направленный от point1 к point2
				length = sqrt(pow(temp.x, 2) + pow(temp.y, 2));	//вычисляем длину вектора temp
				angle = atan2(temp.y, temp.x) * 180 / 3.14159;	//вычисляем угол между осью X и вектором temp и переводим радианы в градусы
				sf::RectangleShape line(sf::Vector2f(length, 3.f));	//создаем прямоуголник шириной 3 пикселя, и вычисленной длиной 
				line.setPosition(vert[column].getPosition()); // устанавливаем начальную точку линии
				line.setRotation(angle); // поворачиваем прямоугольник на нужный угол
				line.setFillColor(sf::Color::Black); // задаем цвет линии
				edges.push_back(line);
				if (this->matrix[column][row] == 0)
				{
					center1 = vert[row].getPosition();
					center2 = vert[column].getPosition();
					k = (center2.y - center1.y) / (center2.x - center1.x);
					b = center1.y - k * center1.x;
					t = 1 - (50 / length);
					x = center1.x + t * (center2.x - center1.x);
					y = center1.y + t * (center2.y - center1.y);
					width = triangle.getLocalBounds().width;
					height = triangle.getLocalBounds().height;
					triangle.setOrigin(width / 2.0f, height / 2.0f);
					triangle.setRotation(angle + 90);
					triangle.setPosition(x, y);
					v_direction.push_back(triangle);
				}
				else
				{
					v_direction.push_back(triangle_trash);
				}
				++column;
			}
		}
		++row;
		column = row + 1;
	}
}


//Попробовать передавать объект Text по ссылке, оставить только цикл в методе
template<typename T>
inline void graph<T>::calcCordText(vector<sf::Text>& v_text, const vector<sf::CircleShape>& vert, sf::Text& text)
{
	float width, height;		//переменные для установки точки отсчета от середины
	v_text.clear();
	string str;
	for (int i = 0; i < this->data.size(); i++)
	{
		str = this->data[i];
		text.setString(str);
		//text.setString(sf::String::fromUtf8(str.begin(), str.end()));			//устанавливаем текст
		width = text.getLocalBounds().width;
		height = text.getLocalBounds().height;
		text.setOrigin(width / 2.0f, height / 2.0f);		//устанавливаем точку отрисовки в центр
		text.setPosition(vert[i].getPosition().x, vert[i].getPosition().y - 5);	//
		v_text.push_back(text);
	}
}

template<typename T>
inline void graph<T>::calcCordDijkstra(vector<sf::Text>& v_text, const vector<sf::CircleShape>& vert, const vector<int>& v_dijkstra, sf::Text text)
{
	float width, height;		//переменные для установки точки отсчета от середины
	v_text.clear();
	string str;
	text.setOutlineColor(sf::Color::Green);
	text.setOutlineThickness(3);
	for (int i = 0; i < v_dijkstra.size(); i++)
	{
		str = to_string(v_dijkstra[i]);
		text.setString(str);
		width = text.getLocalBounds().width;
		height = text.getLocalBounds().height;
		text.setOrigin(width / 2.0f, height / 2.0f);		//устанавливаем точку отрисовки в центр
		text.setPosition(vert[i].getPosition().x, vert[i].getPosition().y - 60);	//
		v_text.push_back(text);
	}
}

template<typename T>
inline void graph<T>::calcCordWeight(vector<sf::Text>& v_weight, const vector<sf::CircleShape>& vert, sf::Text& text)
{
	if (vert.size() == 0) return;
	v_weight.clear();
	string str;
	float x1, y1, x2, y2, midX, midY;
	float width, height;
	size_t row = 0, column = 1;
	while (row < this->_size - 1)
	{
		while (column < this->_size)
		{
			if (this->matrix[row][column] == 0 && this->matrix[column][row] == 0)		//если ребра между вершинами нет
				++column;
			else if (this->matrix[column][row] != 0)
			{
				str = to_string(this->matrix[column][row]);
				str = str.substr(0, str.length() - 7);
				text.setString(str);
				x1 = vert[column].getPosition().x;
				y1 = vert[column].getPosition().y;
				x2 = vert[row].getPosition().x;
				y2 = vert[row].getPosition().y;
				midX = (x1 + x2) / 2;
				midY = (y1 + y2) / 2;
				sf::FloatRect textRect = text.getLocalBounds();
				text.setOrigin(textRect.width / 2, textRect.height / 2);
				text.setPosition(midX, midY);
				v_weight.push_back(text);
				++column;
			}
			else
			{
				str = to_string(this->matrix[row][column]);
				str = str.substr(0, str.length() - 7);
				text.setString(str);
				x1 = vert[row].getPosition().x;
				y1 = vert[row].getPosition().y;
				x2 = vert[column].getPosition().x;
				y2 = vert[column].getPosition().y;
				midX = (x1 + x2) / 2;
				midY = (y1 + y2) / 2;
				sf::FloatRect textRect = text.getLocalBounds();
				text.setOrigin(textRect.width / 2, textRect.height / 2);
				text.setPosition(midX, midY);
				v_weight.push_back(text);
				++column;
			}
		}
		++row;
		column = row + 1;
	}

}




template<typename T>
graph<T>::~graph()
{
	this->_size = 0;
	this->data.clear();
	this->matrix.clear();
}

