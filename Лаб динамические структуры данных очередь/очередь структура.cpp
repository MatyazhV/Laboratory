
#include <iostream>
using namespace std;
int n;
char key;
struct Queue { // Создаем структуру 
	char data;
	Queue* next;
};
Queue* make_queue(int n, Queue*& first, Queue*& last) {
	if (n == 0) return NULL;
	Queue* p = new Queue; // Выделение памяти под 1 элемент
	char a;
	cin >> a;
	p->data = a;
	p->next = NULL;       /* Так как он первый, то он ни на что не указывает */
	first = p;            // Новый элемент является первым
	last = p;             // И последним
	for (int i = 2; i <= n; i++) {
		Queue* h = new Queue; // Выделение памяти для нового элемента
		cin >> a;
		h->data = a;
		h->next = p;     // Указываем на следующий элемент 
		last = h;        /* Показываем, что введённый элемент стал последним */
		p = last;        // Перешли к последнему элементу
	}
	return first;
}
void print_queue(Queue* last)
{    /* Печать очереди без удаления элементов */
	Queue* p = last;              // p указывает на последний элемент
	while (p != NULL)
	{           // Печать с конца очереди
		cout << p->data << " "; // Печать
		p = p->next;            // Переход к следующему элементу
	}
	cout << endl;
}
char pop(Queue*& first, Queue*& last) {
	// Функция удаления элемента
	Queue* p = last;
	int k = 0;          // Кол-во элементов в очереди
	while (p != NULL) { // Считаем кол-во элементов
		k++;
		p = p->next;
	}
	p = last;
	if (k == 1) {       /* Если элемент один, то обнуляем  указатели и возвращаем последний элемент */
		char t = last->data;
		delete p;
		last = NULL;
		first = NULL;
		return t;
	}
	else {               // Если больше 1
		while (p->next->next != NULL) // Переходим к предпоследнему элементу
		{
			p = p->next;
		}
		Queue* t = p;    // Указатель на предпоследний элемент
		char e = p->next->data; // Сохранение значения последнего элемента
		p = p->next;    // Переход к последнему элементу
		t->next = NULL; // Предпоследний указатель указывает на NULL
		first = t;      // И он теперь первый элемент
		delete p;       // Удаление последнего элемента
		return e;       // Возвращение первого элемента
	}
}
Queue* push(char n, Queue*& last) {
	Queue* p = new Queue; // Выделение памяти для нового элемента 
	p->data = n;          // Присвоение
	p->next = last;       // Наш новый элемент указывает на следующий
	last = p;             // Новый элемент стал последним
	return last;
}

int main() {
	setlocale(LC_ALL, "Rus");
	cout << "Введите кол-во элементов " << endl;
	cin >> n;
	cout << "Введите ключ для удаления" << endl;
	cin >> key;
	Queue* first, * last; /* Указатели на первый и последний
							элементы
							 очереди */
	make_queue(n, first, last); //  Формирование очереди
	print_queue(last);   // Печать очереди
	char *mas = new char[n];
	int i = 0;
	while(i < n)
	{
		char t = pop(first, last); // Удаляем элемент, сохраняя в переменную
		if (t != key) // Проверяем на равенство элементу для удаления 
		{
			mas[i] = t; 
			i++;
		}
		else
		{
			n--;
		}
	}
	for (int i = 0; i < n; i++) // Перенос элементов в массив
	{
		push(mas[i], last);
	}
	cout << "Очередь после удаления: ";
	print_queue(last);   // Печать очереди
	cout << "Номер элемента для добавления " << endl;
	int number;
	cin >> number;
	cout << "Кол-во элементов для добавления " << endl;
	int kol;
	cin >> kol;
	for (int i = 0; i < n; i++)
		// Перенос элементов в массив
		mas[i] = pop(first, last);
	for (int i = 0; i <= number; i++)
		// Добавление первой половины из массива
		push(mas[i], last);
	cout << "Введите " << kol << " элементов" << endl;
	for (int i = 0; i < kol; i++) // Добавление новых элементов
	{
		char a;
		cin >> a;
		push(a, last);
	}
	for (int i = number + 1; i < n; i++) /* Добавление второй половины из массива */
		push(mas[i], last);
	cout << "Очередь после добавления: ";
	print_queue(last);          // Печать очереди
	return 0;
}


