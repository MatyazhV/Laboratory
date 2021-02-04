#include <iostream>
#include <queue> // Заголовок очереди
using namespace std;
int n, k, s;
char* arr;
char d;
void print(queue<char> qu) {
	int p = qu.size();            /* Сохранили размер очереди
									  в переменную */
	for (int i = 0; i < p; i++) 
	{								// Печать элементов очереди
		arr[i] = qu.front();
		cout << qu.front() << " ";
		qu.pop();
	}
	for (int i = 0; i < p; i++)   // Перенос элементов в массив
		qu.push(arr[i]);
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "Rus");
	arr = new char[n];
	cout << "Введите размер: ";
	cin >> n;
	cout << "Введите ключ: ";
	cin >> d;
	queue<char> qu; // Создали пустую очередь
	cout << "Введите " << n <<" элементов: ";
	for (int i = 0; i < n; i++)
	{
		char a;
		cin >> a;

		qu.push(a); // Добавление элементов в очередь
	}
	cout << "Очередь: ";
	print(qu); //Печать очереди
	int j = 0;
	while (j < n) { // Удаление элемента с заданным ключем 
		if (d == qu.front())
		{
			qu.pop(); // Удаление элемента, равного ключу
			n--;
		}
		else
		{
			arr[j] = qu.front();     // Перенос элемента в массив
			qu.pop(); // Удаление элемента из очереди
			j++;
		}
	}
	for (int i = 0; i < n; i++)   // Перенос элементов из массива
		qu.push(arr[i]);
		cout << "Очередь после удаления: ";
		print(qu);                    // Печать очереди
	cout << "Введите номер элемента, полсе которго нужно добавление: ";
	cin >> s;
	cout << "Введите количество элементов для добавления: ";
	cin >> k;
	if (s >= n)
	{
		cout << "Введите другое значение s, меньшее " << n << ": ";
		cin >> s;
	}
	for (int i = 0; i < n; i++)
	{								
		arr[i] = qu.front(); // Перенос элемента в массив
		qu.pop();  // Удаление элемента
	}
	for (int i = 0; i <= s; i++)  
	{
		qu.push(arr[i]);  // Перенос элементов до элемента с заданным номером из массива
	}
	cout << "Введите " << k << " элементов: ";
	for (int i = 1; i <= k; i++) // Добавление K элементов после элемента с заданным номером
	{
		char a;
		cin >> a;
		qu.push(a);
	}
	for (int i = s + 1; i < n; i++) 
	{
		qu.push(arr[i]);  // Перенос остальных элементов из массива
	}
	cout << "Очередь после добавления: ";
	print(qu);
	for (int i = 0; i < n+k; i++)
	{								
		qu.pop();
	}
	return 0;
}
