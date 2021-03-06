#include "stdafx.h"
#include <windows.h>

#define STRING_BUFFER_SIZE 128

#define BST_KEYS_CNT 2
#define CAPITAL_KEY_IDX 0
#define POPULATION_KEY_IDX 1

typedef long unsigned int ulong;
typedef short unsigned int ushort;

// Реализация структуры для хранения представленных в задании данных:

/**
* Структура "Государство".
*
* @property name        наименование государства.
* @property capital     столица государства.
* @property language    язык.
* @property population  численность населения.
* @property area        площадь.
**/
typedef struct Country
{
	char name[STRING_BUFFER_SIZE];
	char capital[STRING_BUFFER_SIZE];
	char language[STRING_BUFFER_SIZE];
	ulong population;
	double area;
} Data;

/**
* Печать в консоль информации о государстве.
*
* @param country  указатель на структуру данных.
**/
void print(Country* country)
{
	if (country != NULL) 
	{
		printf("%s; %s; %s; %lu; %.2lf;\n", country->name, country->capital, country->language, country->population, country->area);

		//printf("\nНазвание: %s\nСтолица: %s\nЯзык: %s\nЧисленность населения: %lu\nПлощадь: %lf\n\n",
		//	country->name, country->capital, country->language, country->population, country->area);
	}
}

typedef struct Link
{
	struct Node* left;
	struct Node* right;
	struct Node* parent;
} Link;

/**
* Структура элемента в дереве.
*
* @property left    указатель на левое поддерево.
* @property right   указатель на правое поддерево.
* @property parent  указатель на родительский элемент.
**/
typedef struct Node
{
	Data data;
	ushort linksCnt;
	Link** links;
} Node;

/**
* Инициализация элемента дерева начальными значениями.
*
* @param node  указатель на элемент дерева.
**/
void initNode(Node* node, ushort linksCnt)
{
	node->linksCnt = linksCnt;
	node->links = (Link**)malloc(node->linksCnt * sizeof(Link*));
	for (ushort i = 0; i < node->linksCnt; ++i)
	{
		node->links[i] = (Link*)malloc(sizeof(Link));
		node->links[i]->left = NULL;
		node->links[i]->right = NULL;
		node->links[i]->parent = NULL;
	}
}

void freeNode(Node* node, bool isRecursive, ushort idx)
{
	if (node == NULL) return;

	if (isRecursive)
	{
		if (node->links[idx]->left != NULL)
		{
			freeNode(node->links[idx]->left, isRecursive, idx);
			node->links[idx]->left = NULL;
		}
		if (node->links[idx]->right != NULL)
		{
			freeNode(node->links[idx]->right, isRecursive, idx);
			node->links[idx]->right = NULL;
		}
	}

	if (node->links != NULL)
	{
		for (ushort i = 0; i < node->linksCnt; ++i)
		{
			if (node->links[i] != NULL)
			{
				free(node->links[i]);
				node->links[i] = NULL;
			}
		}
		free(node->links);
		node->links = NULL;
	}

	free(node);
}

void printNode(Node* node)
{
	print(&node->data);
}

/**
* Вызывает переданную по указателю функцию для каждого элемента дерева (рекурсивно обходит дерево).
*
* @param node    указатель на текущий элемент дерева.
* @param action  указатель на функцию-действие.
**/
void makeAction(Node* node, ushort linkIdx, void(*action)(Node*))
{
	if (node != NULL) 
		action(node);
	if (node->links[linkIdx]->left != NULL) 
		makeAction(node->links[linkIdx]->left, linkIdx, action);
	if (node->links[linkIdx]->right != NULL) 
		makeAction(node->links[linkIdx]->right, linkIdx, action);
}

/**
* Производит прямой обход (CLR) дерева и вызывает для каждого узла переданную функцию.
*
* @param node    указатель на текущий элемент дерева.
* @param action  указатель на функцию-действие.
**/
void preOrder(Node* node, ushort linkIdx, void(*action)(Node*))
{
	if (node != NULL) 
		action(node);
	if (node->links[linkIdx]->left != NULL) 
		preOrder(node->links[linkIdx]->left, linkIdx, action);
	if (node->links[linkIdx]->right != NULL) 
		preOrder(node->links[linkIdx]->right, linkIdx, action);
}

/**
* Производит центрированный (симметричный) (LCR) обход дерева и вызывает для каждого узла переданную функцию.
*
* @param node    указатель на текущий элемент дерева.
* @param action  указатель на функцию-действие.
**/
void inOrder(Node* node, ushort linkIdx, void(*action)(Node*))
{
	if (node->links[linkIdx]->left != NULL) 
		inOrder(node->links[linkIdx]->left, linkIdx, action);
	if (node != NULL) 
		action(node);
	if (node->links[linkIdx]->right != NULL) 
		inOrder(node->links[linkIdx]->right, linkIdx, action);
}

/**
* Производит обратный обход (LRC) дерева и вызывает для каждого узла переданную функцию.
*
* @param node  указатель на текущий элемент дерева.
* @param foo   указатель на функцию-действие.
**/
void postOrder(Node* node, ushort linkIdx, void(*action)(Node*))
{
	if (node->links[linkIdx]->left != NULL) 
		postOrder(node->links[linkIdx]->left, linkIdx, action);
	if (node->links[linkIdx]->right != NULL) 
		postOrder(node->links[linkIdx]->right, linkIdx, action);
	if (node != NULL) 
		action(node);
}

/**
* Дерево.
*
* @property root  указатель на корень дерева.
**/
typedef struct Tree
{
	ushort rootsCnt;
	Node** roots;
} Tree;

/**
* Инициализация дерева начальным значением.
*
* @param tree  указатель на структуру дерева.
**/
void initTree(Tree* tree, ushort rootsCnt)
{
	tree->rootsCnt = rootsCnt;
	tree->roots = (Node**)malloc(tree->rootsCnt * sizeof(Node*));
	for (ushort i = 0; i < tree->rootsCnt; ++i)
	{
		tree->roots[i] = NULL;
	}
}

void freeTree(Tree* tree)
{
	freeNode(tree->roots[CAPITAL_KEY_IDX], true, CAPITAL_KEY_IDX);

	for (ushort i = 0; i < tree->rootsCnt; ++i) tree->roots[i] = NULL;
	free(tree->roots);
	tree->roots = NULL;

	free(tree);
}

/**
* Добавление нового элемента в дерево (нерекурсивная версия).
*
* @param tree     указатель на структуру дерева.
* @param newNode  указатель на новый элемент.
**/
void addNewNodeToTree(Tree* tree, Node* newNode, ushort idx, int(*comparingFunction)(Node* node1, Node* node2))
{
	if (tree == NULL) return;
	if (tree->roots[idx] == NULL) { tree->roots[idx] = newNode; return; }
	Node* current = tree->roots[idx];

	while (current != NULL)
	{
		int c = comparingFunction(newNode, current);
		if (c < 0)
		{
			if (current->links[idx]->left != NULL) { current = current->links[idx]->left; continue; }
			current->links[idx]->left = newNode;
			newNode->links[idx]->parent = current;
			break;
		}
		else if (c >= 0)
		{
			if (current->links[idx]->right != NULL) { current = current->links[idx]->right; continue; }
			current->links[idx]->right = newNode;
			newNode->links[idx]->parent = current;
			break;
		}
	}
}

/**
* Добавление нового элемента в дерево (с рекурсивным проходом).
*
* @param tree     указатель на структуру дерева.
* @param newNode  указатель на новый элемент.
* @param current  указатель на текущий элемент (при первом вызове равен NULL).
**/
void addNewNodeToTreeRecursive(Tree* tree, Node* newNode, Node* current, ushort idx, int(*comparingFunction)(Node* node1, Node* node2))
{
	if (tree == NULL) return;
	if (tree->roots[idx] == NULL) { tree->roots[idx] = newNode; return; }
	if (current == NULL) current = tree->roots[idx];

	int c = comparingFunction(newNode, current);
	if (c < 0) 
	{  // если новое имя больше текущего, то переходим в левое поддерево:
		if (current->links[idx]->left != NULL) addNewNodeToTreeRecursive(tree, newNode, current->links[idx]->left, idx, comparingFunction);
		else
		{
			current->links[idx]->left = newNode;
			newNode->links[idx]->parent = current;
		}
	}
	else if (c >= 0) 
	{  // если новое имя меньше текущего, то переходим в правое поддерево:
		if (current->links[idx]->right != NULL) addNewNodeToTreeRecursive(tree, newNode, current->links[idx]->right, idx, comparingFunction);
		else
		{
			current->links[idx]->right = newNode;
			newNode->links[idx]->parent = current;
		}
	}
}

/**
* @return  -, если node1 < node2; +, если node2 < node1; 0, если они равны.
**/
int compareCapitals(Node* node1, Node* node2) {
	return strcmp(node1->data.capital, node2->data.capital);
}

/**
* @return  -, если node1 < node2; +, если node2 < node1; 0, если они равны.
**/
int comparePopulations(Node* node1, Node* node2) {
	return node1->data.population - node2->data.population;
}

/**
* Добавить государство в дерево.
**/
void add(Tree* tree, bool isRecursive)
{
	Node* newCountry = (Node*)malloc(sizeof(Node));
	initNode(newCountry, tree->rootsCnt);

	// Информация в элемент структуры вводится со стандартного потока ввода:

	printf("Название -> ");
	fgets(newCountry->data.name, STRING_BUFFER_SIZE, stdin);
	newCountry->data.name[strcspn(newCountry->data.name, "\n")] = '\0';

	printf("Столица -> ");
	fgets(newCountry->data.capital, STRING_BUFFER_SIZE, stdin);
	newCountry->data.capital[strcspn(newCountry->data.capital, "\n")] = '\0';

	printf("Язык -> ");
	fgets(newCountry->data.language, STRING_BUFFER_SIZE, stdin);
	newCountry->data.language[strcspn(newCountry->data.language, "\n")] = '\0';

	printf("Численность населения -> ");
	scanf("%lu", &newCountry->data.population);

	printf("Площадь -> ");
	scanf("%lf", &newCountry->data.area);

	printf("\n");

	if (isRecursive)
	{
		addNewNodeToTreeRecursive(tree, newCountry, NULL, 0, compareCapitals);
		addNewNodeToTreeRecursive(tree, newCountry, NULL, 1, comparePopulations);
	}
	else
	{
		addNewNodeToTree(tree, newCountry, 0, compareCapitals);
		addNewNodeToTree(tree, newCountry, 1, comparePopulations);
	}

	return;
}

/**
* Поиск государства в дереве по названию столицы.
*
* @param tree         указатель на структуру дерева.
* @param capitalName  название столицы.
* @return             найденный элемент или NULL.
**/
Node* findNodeInTreeByCapital(Tree* tree, char capitalName[])
{
	if (tree == NULL) return NULL;
	Node* current = tree->roots[CAPITAL_KEY_IDX];
	while (current != NULL)
	{
		int c = strcmp(capitalName, current->data.capital);
		if (c < 0) { current = current->links[CAPITAL_KEY_IDX]->left; continue; }
		else if (c > 0) { current = current->links[CAPITAL_KEY_IDX]->right; continue; }
		else if (c == 0) return current;
	}
	return NULL;
}

/**
* Поиск элемента в дереве по названию (рекурсивная версия).
*
* @param tree         указатель на структуру дерева.
* @param capitalName  название книги.
* @param current      указатель на текущий элемент (при первом вызове равен NULL).
* @return             найденный элемент или NULL.
**/
Node* findNodeInTreeByCapitalRecursive(Tree* tree, char capitalName[], Node* current)
{
	if (tree == NULL) return NULL;
	if (current == NULL) current = tree->roots[CAPITAL_KEY_IDX];
	int c = strcmp(capitalName, current->data.capital);
	if (c < 0)
	{
		if (current->links[CAPITAL_KEY_IDX]->left != NULL)
			return findNodeInTreeByCapitalRecursive(tree, capitalName, current->links[CAPITAL_KEY_IDX]->left);
		else return NULL;
	}
	else if (c > 0)
	{
		if (current->links[CAPITAL_KEY_IDX]->right != NULL)
			return findNodeInTreeByCapitalRecursive(tree, capitalName, current->links[CAPITAL_KEY_IDX]->right);
		else return NULL;
	}
	else if (c == 0) return current;
	return NULL;
}

/**
* Найти государство по столице в дереве.
*
* @param tree указатель на структуру дерева.
**/
void find(Tree* tree, bool isRecursive)
{
	char capital[STRING_BUFFER_SIZE];

	printf("Столица -> ");
	fgets(capital, STRING_BUFFER_SIZE, stdin);
	capital[strcspn(capital, "\n")] = '\0';

	Node* country = isRecursive
		? findNodeInTreeByCapitalRecursive(tree, capital, NULL)
		: findNodeInTreeByCapital(tree, capital);

	printf("\nРезультаты поиска:\n");
	if (country) printNode(country); else printf("Ничего не найдено.\n");

	printf("\n");
}

/**
* Удаление узла из дерева.
**/
Node* removeNodeFromTree(Node* root, Node* key, ushort idx, int(*comparingFunction)(Node* node1, Node* node2))
{
	// Основной случай:
	if (root == NULL) return root;

	int c = comparingFunction(key, root);

	// Если удаляемый ключ меньше, чем ключ root, то он лежит в левом поддереве:
	if (c < 0)
		root->links[idx]->left = removeNodeFromTree(root->links[idx]->left, key, idx, comparingFunction);

	// Если удаляемый ключ больше, чем ключ root, то он лежит в правом поддереве:
	else if (c > 0)
		root->links[idx]->right = removeNodeFromTree(root->links[idx]->right, key, idx, comparingFunction);

	// Если ключ такой же как и у root, то это узел для удаления:
	else
	{
		// Если у узла только один потомок или нет потомков:

		if (root->links[idx]->left == NULL)
		{
			Node* temp = root->links[idx]->right;
			return temp;
		}
		else if (root->links[idx]->right == NULL)
		{
			Node* temp = root->links[idx]->left;
			return temp;
		}

		// Если узел с двумя потомками: получить мин. в правом поддереве.
		Node* temp = root->links[idx]->right;
		/* Спускаться вниз и найти самый левый лист: */
		while (temp->links[idx]->left != NULL)
			temp = temp->links[idx]->left;


		if (root->links[idx]->parent != NULL)
			if (root->links[idx]->parent->links[idx]->left == root)
				root->links[idx]->parent->links[idx]->left = temp;
			else
				root->links[idx]->parent->links[idx]->right = temp;

		if (root->links[idx]->left != NULL && root->links[idx]->left != temp)
			root->links[idx]->left->links[idx]->parent = temp;
		if (root->links[idx]->right != NULL && root->links[idx]->right != temp)
			root->links[idx]->right->links[idx]->parent = temp;

		if (temp->links[idx]->parent != NULL)
			if (temp->links[idx]->parent->links[idx]->left == temp)
				temp->links[idx]->parent->links[idx]->left = temp->links[idx]->right;
			else
				temp->links[idx]->parent->links[idx]->right = temp->links[idx]->right;

		temp->links[idx]->parent = root->links[idx]->parent;
		temp->links[idx]->left = root->links[idx]->left;
		temp->links[idx]->right = root->links[idx]->right;

		root = temp;
	}

	return root;
}

/**
* Удалить государство из дерева.
*
* @param tree указатель на структуру дерева.
**/
void remove(Tree* tree)
{
	char capital[STRING_BUFFER_SIZE];

	printf("Столица удаляемого государства -> ");
	fgets(capital, STRING_BUFFER_SIZE, stdin);
	capital[strcspn(capital, "\n")] = '\0';

	bool isRecursive = false;
	Node* country = isRecursive
		? findNodeInTreeByCapitalRecursive(tree, capital, NULL)
		: findNodeInTreeByCapital(tree, capital);

	if (country)
	{
		tree->roots[CAPITAL_KEY_IDX] = removeNodeFromTree(tree->roots[CAPITAL_KEY_IDX], country, CAPITAL_KEY_IDX, compareCapitals);
		tree->roots[POPULATION_KEY_IDX] = removeNodeFromTree(tree->roots[POPULATION_KEY_IDX], country, POPULATION_KEY_IDX, comparePopulations);
		freeNode(country, false, CAPITAL_KEY_IDX);
	}
	else printf("Ничего не найдено.\n");

	printf("\n");
}

Node* cloneNode(Node* node)
{
	Node* clone = (Node*)malloc(sizeof(Node));
	initNode(clone, node->linksCnt);
	strcpy(clone->data.name, node->data.name);
	strcpy(clone->data.capital, node->data.capital);
	strcpy(clone->data.language, node->data.language);
	clone->data.population = node->data.population;
	clone->data.area = node->data.area;
	return clone;
}

void filterGreater(Node* node, ulong population, Tree* resultTree)
{
	if (node == NULL) return;

	if (node->data.population > population)
	{
		Node* newNode = cloneNode(node);
		addNewNodeToTree(resultTree, newNode, CAPITAL_KEY_IDX, compareCapitals);
		addNewNodeToTree(resultTree, newNode, POPULATION_KEY_IDX, comparePopulations);

		filterGreater(node->links[POPULATION_KEY_IDX]->left, population, resultTree);
		filterGreater(node->links[POPULATION_KEY_IDX]->right, population, resultTree);
	}
	else if (node->data.population <= population)
	{
		filterGreater(node->links[POPULATION_KEY_IDX]->right, population, resultTree);
	}
}

void filterLess(Node* node, ulong population, Tree* resultTree)
{
	if (node == NULL) return;

	if (node->data.population < population)
	{
		Node* newNode = cloneNode(node);
		addNewNodeToTree(resultTree, newNode, CAPITAL_KEY_IDX, compareCapitals);
		addNewNodeToTree(resultTree, newNode, POPULATION_KEY_IDX, comparePopulations);

		filterLess(node->links[POPULATION_KEY_IDX]->left, population, resultTree);
		filterLess(node->links[POPULATION_KEY_IDX]->right, population, resultTree);
	}
	else if (node->data.population >= population)
	{
		filterLess(node->links[POPULATION_KEY_IDX]->left, population, resultTree);
	}
}

void filterEquals(Node* node, ulong population, Tree* resultTree)
{
	if (node == NULL) return;

	if (node->data.population == population)
	{
		Node* newNode = cloneNode(node);
		addNewNodeToTree(resultTree, newNode, CAPITAL_KEY_IDX, compareCapitals);
		addNewNodeToTree(resultTree, newNode, POPULATION_KEY_IDX, comparePopulations);

		filterEquals(node->links[POPULATION_KEY_IDX]->right, population, resultTree);
	}
	else if (node->data.population < population)
	{
		filterEquals(node->links[POPULATION_KEY_IDX]->right, population, resultTree);
	}
	else if (node->data.population > population)
	{
		filterEquals(node->links[POPULATION_KEY_IDX]->left, population, resultTree);
	}
}

/**
* Фильтрация.
*
* @param tree указатель на структуру дерева.
* @return     фильтр возвращает новое дерево элементов, удовлетворяющих условию.
**/
Tree* filterByPopulation(Tree* tree)
{
	if (tree == NULL) return NULL;

	Tree* filtered = (Tree*)malloc(sizeof(Tree));
	initTree(filtered, BST_KEYS_CNT);

	printf("\nУсловия:\n");
	printf("1) >\n");
	printf("2) <\n");
	printf("3) =\n");

	printf("\nВведите номер условия -> ");
	unsigned short int condition;
	scanf("%hu", &condition);
	fgetc(stdin);

	printf("Введите значение -> ");
	unsigned long int population;
	scanf("%lu", &population);
	fgetc(stdin);

	Node* current = tree->roots[POPULATION_KEY_IDX];
	switch (condition)
	{
	case 1: filterGreater(current, population, filtered); break;
	case 2: filterLess(current, population, filtered); break;
	case 3: filterEquals(current, population, filtered); break;
	default: break;
	}

	return filtered;
}

/**
* Сохраняем элемент в файл.
*
* @param node  элемент.
* @param fp    указатель на файл.
**/
void saveNode(Node* node, FILE* fp, ushort idx)
{
	if (fp == NULL)
		return;
	if (node != NULL)
	{
		fputs(node->data.name, fp);
		fputs("\n", fp);
		fputs(node->data.capital, fp);
		fputs("\n", fp);
		fputs(node->data.language, fp);
		fputs("\n", fp);
		fprintf(fp, "%lu\n%lf\n", node->data.population, node->data.area);

		if (node->links[idx]->left != NULL)
			saveNode(node->links[idx]->left, fp, idx);
		if (node->links[idx]->right != NULL)
			saveNode(node->links[idx]->right, fp, idx);
	}
}

/**
* Сохраняем дерево в файл.
*
* @param tree      дерево.
* @param fileName  имя файла.
**/
void saveTree(Tree* tree, char fileName[], ushort idx)
{
	if (tree == NULL) return;
	FILE *ptr;
	ptr = fopen(fileName, "w");
	if (ptr == NULL)
	{
		printf("\nНевозможно открыть файл: %s", fileName);
		return;
	}
	saveNode(tree->roots[idx], ptr, idx);
	fputs("NULL\n", ptr);
	fputs("NULL\n", ptr);
	fputs("NULL\n", ptr);
	fprintf(ptr, "%lu\n%lf", 0UL, 0.0);
	fclose(ptr);
}

/**
* Сохранить дерево государств в файл.
**/
void save(Tree* tree, ushort idx)
{
	char fileName[STRING_BUFFER_SIZE];

	printf("Имя файла -> ");
	fgets(fileName, STRING_BUFFER_SIZE, stdin);
	fileName[strcspn(fileName, "\n")] = '\0';

	saveTree(tree, fileName, idx);

	return;
}

/**
* Определение длины строки.
*
* @param s  строка.
* @return   длина строки.
**/
size_t stringLength(const char *s) {  // size_t - это long unsigned int.
	const char *p = s;  // указатель на начало строки.

	// Движемся до конца строки.
	// Концом строки считается первый встретившийся специальный нуль-символ.
	while (*p != '\0') p++;

	return (size_t)(p - s);
}

/**
* Определяет, начинается ли строка с подстроки.
*
* @param text       строка, в которой проверяем.
* @param substring  строка, которую ищем.
* @param count      число символов для проверки.
* @return           1 - да, 0 - нет.
**/
int stringStartsWith(char text[], const char substring[], int count)
{
	// Проверка на случай, если строки разной длины:
	if (stringLength(substring) > stringLength(text))
		return 0;

	for (int i = 0; i < count; i++)
	{
		if (text[i] != substring[i])
			return 0;
	}
	return 1;
}

/**
* Загружает дерево из файла.
*
* @param tree      дерево.
* @param fileName  имя файла.
**/
void loadTree(Tree* tree, char fileName[])
{
	if (tree == NULL) return;
	FILE* fp;
	fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		printf("\nНевозможно открыть файл: %s", fileName);
		return;
	}

	char name[STRING_BUFFER_SIZE];
	char capital[STRING_BUFFER_SIZE];
	char language[STRING_BUFFER_SIZE];
	unsigned long int population;
	double area;

	while (1)
	{
		fgets(name, STRING_BUFFER_SIZE, fp);
		name[strcspn(name, "\n")] = '\0';

		fgets(capital, STRING_BUFFER_SIZE, fp);
		capital[strcspn(capital, "\n")] = '\0';

		fgets(language, STRING_BUFFER_SIZE, fp);
		language[strcspn(language, "\n")] = '\0';

		fscanf(fp, "%lu%lf", &population, &area);
		fgetc(fp);

		//if(strcmp(name, "NULL") != 0 && strcmp(capital, "NULL") != 0)
		if (!stringStartsWith(name, "NULL", 4)
			&& !stringStartsWith(capital, "NULL", 4)
			&& !stringStartsWith(language, "NULL", 4)
			&& population != 0UL
			&& area != 0.0)
		{
			Node* node = (Node*)malloc(sizeof(Node));
			initNode(node, tree->rootsCnt);
			strcpy(node->data.name, name);
			strcpy(node->data.capital, capital);
			strcpy(node->data.language, language);
			node->data.population = population;
			node->data.area = area;

			addNewNodeToTree(tree, node, 0, compareCapitals);
			addNewNodeToTree(tree, node, 1, comparePopulations);

			//addNewNodeToTreeRecursive(tree, node, NULL, 0, compareCapitals);
			//addNewNodeToTreeRecursive(tree, node, NULL, 1, comparePopulations);
		}
		else
			break;
	}
	fclose(fp);
}

/**
* Загрузить дерево государств из файла.
**/
void load(Tree* tree)
{
	char fileName[STRING_BUFFER_SIZE];

	printf("Имя файла -> ");
	fgets(fileName, STRING_BUFFER_SIZE, stdin);
	fileName[strcspn(fileName, "\n")] = '\0';

	loadTree(tree, fileName);

	return;
}

/**
* Переход на кириллицу.
**/
void cyrillic(void) {
	// Эти строки нужны для правильного отображения кириллицы:
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	// Также надо изменить шрифт в консоли на Lucida Console.
	// Для замены шрифта кликаете правой кнопкой на надписи «Командная строка» окна консоли. 
	// В открывшемся меню выбираете «Свойства». 
	// В появившемся окне выбираете вкладку «Шрифт» и там выбираете «Lucida Console». 

	return;
}

void nodesPrintHier(Node* p, ushort idx, ushort space)
{
	if (p == NULL) {
		for (int i = 0; i < space; i++) printf(" ");
		printf("[]\n");
		return;
	}

	for (int i = 0; i < space; i++) printf(" ");
	printf("%s\n", p->data.capital);

	for (int i = 0; i < space; i++) printf(" ");
	printf("(\n");

	nodesPrintHier(p->links[idx]->left, idx, space * 2);

	for (int i = 0; i < space; i++) printf(" ");
	printf(")\n");

	for (int i = 0; i < space; i++) printf(" ");
	printf("(\n");

	nodesPrintHier(p->links[idx]->right, idx, space * 2);

	for (int i = 0; i < space; i++) printf(" ");
	printf(")\n");

	return;
}

/**
* Вывод меню.
**/
void printMenu(void)
{
	printf("Меню:\n");
	printf("\n1) добавить государство в дерево (нерекурсивно);\n");
	printf("2) добавить государство в дерево (рекурсивно);\n");

	printf("\n3) удалить государство из дерева по столице;\n");
	
	printf("\n4) найти государство по столице в дереве (нерекурсивно);\n");
	printf("5) найти государство по столице в дереве (рекурсивно);\n");
	
	printf("\n6) отфильтровать государства по численности населения;\n");
	
	printf("\n7) вывод узлов с прямым обходом (CLR) дерева по ключу 'Столица';\n");
	printf("8) вывод узлов с центрированным обходом (LCR) дерева по ключу 'Столица';\n");
	printf("9) вывод узлов с обратным обходом (LRC) дерева по ключу 'Столица';\n");
	printf("10) вывод узлов иерархически по ключу 'Столица';\n");

	printf("\n11) вывод узлов с прямым обходом (CLR) дерева по ключу 'Численность';\n");
	printf("12) вывод узлов с центрированным обходом (LCR) дерева по ключу 'Численность';\n");
	printf("13) вывод узлов с обратным обходом (LRC) дерева по ключу 'Численность';\n");
	printf("14) вывод узлов иерархически по ключу 'Численность';\n");

	printf("\n15) сохранить дерево государств в файл;\n");
	printf("16) загрузить дерево государств из файла;\n");

	printf("\n17) выход.\n\n");
	return;
}

int main(void)
{	
	Tree* ptr = (Tree*)malloc(sizeof(Tree));
	initTree(ptr, BST_KEYS_CNT);

	cyrillic();
	printMenu();

	void(*f_ptr)(Node*);
	f_ptr = printNode;

	unsigned short int userChoice;
	do
	{
		printf("Введите номер пункта меню -> ");
		scanf("%hu", &userChoice);
		fgetc(stdin);

		switch (userChoice)
		{
		// Создаем элемент (нерекурсивно):
		case 1: add(ptr, false);  break;

		// Создаем элемент (рекурсивно):
		case 2: add(ptr, true); break;

		case 3: remove(ptr); break;

		case 4: find(ptr, false); break;
		case 5: find(ptr, true); break;

		case 6: 
			ptr = filterByPopulation(ptr); 
			break;

		// Вывод узлов дерево с обходом в глубину тремя способами:

		case 7: 
			printf("\n-----\nPreorder:\n"); 
			preOrder(ptr->roots[CAPITAL_KEY_IDX], CAPITAL_KEY_IDX, f_ptr);
			printf("\n"); 
			break;
		case 8: 
			printf("\n-----\nInorder:\n"); 
			inOrder(ptr->roots[CAPITAL_KEY_IDX], CAPITAL_KEY_IDX, f_ptr);
			printf("\n"); 
			break;
		case 9: 
			printf("\n-----\nPostorder:\n"); 
			postOrder(ptr->roots[CAPITAL_KEY_IDX], CAPITAL_KEY_IDX, f_ptr);
			printf("\n"); 
			break;
		case 10:
			nodesPrintHier(ptr->roots[CAPITAL_KEY_IDX], CAPITAL_KEY_IDX, 1);
			printf("\n");
			break;

		case 11: 
			printf("\n-----\nPreorder:\n"); preOrder(ptr->roots[POPULATION_KEY_IDX], POPULATION_KEY_IDX, f_ptr);
			printf("\n"); 
			break;
		case 12: 
			printf("\n-----\nInorder:\n"); inOrder(ptr->roots[POPULATION_KEY_IDX], POPULATION_KEY_IDX, f_ptr);
			printf("\n"); 
			break;
		case 13: 
			printf("\n-----\nPostorder:\n"); postOrder(ptr->roots[POPULATION_KEY_IDX], POPULATION_KEY_IDX, f_ptr);
			printf("\n"); 
			break;
		case 14:
			nodesPrintHier(ptr->roots[POPULATION_KEY_IDX], POPULATION_KEY_IDX, 1);
			printf("\n");
			break;

		case 15: save(ptr, 0); break;
		case 16: load(ptr); break;

		case 17:
		default: userChoice = 0; break;
		}
	} while (userChoice);

	// Освобождение памяти из-под элементов дерева:
	freeTree(ptr);
	ptr = NULL;

	return 0;
}
