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
	cout << "Введите размер" << endl;
	cin >> n;
	cout << "Введите ключ" << endl;
	cin >> d;
	queue<char> qu; // Создали пустую очередь
	for (int i = 0; i < n; i++)
	{
		cout << "Введите "<< i << " символ" << endl;
		char a;
		cin >> a;

		qu.push(a); // Добавление элементов в очередь
	}
	print(qu);
	bool flag = false;
	int j = 0;
	while (j < n) { // Перенос элементов в массив
		if (d == qu.front())
		{
			flag = true;
			qu.pop();
			n -= 1;
		}
		else
		{
			arr[j] = qu.front();     // Забирает первый элемент без удаления
			qu.pop(); // Удаление элемента из очереди
			j++;
		}
	}
	for (int i = 0; i < n; i++)   // Перенос элементов в массив
		qu.push(arr[i]);
	if (flag == false) 
		cout << "Такого ключа не найдено" << endl;
	else
	{
		cout << "Массив после удаления" << endl;
		print(qu);                    // Печать очереди
	}
	cout << "Введите номер элемента, полсе которго нужно добавление" << endl;
	cin >> s;
	cout << "Введите количество элементов для добавления" << endl;
	cin >> k;
	if (s >= n)
	{
		cout << "Введите другое значение s, меньшее " << n << endl;
		cin >> s;
	}
	for (int i = 0; i < n; i++)
	{								
		arr[i] = qu.front();
		qu.pop();
	}
	for (int i = 0; i <= s; i++)
	{
		qu.push(arr[i]);
	}
	for (int i = 1; i <= k; i++)
	{
		cout << "Добавьте элемент номер " << i << endl;
		char a;
		cin >> a;
		qu.push(a);
	}
	for (int i = s + 1; i < n; i++)
	{
		qu.push(arr[i]);
	}
	cout << "Массив после добавления " << endl;
	print(qu);
	for (int i = 0; i < n+k; i++)
	{								
		qu.pop();
	}
	return 0;
}
