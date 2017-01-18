Контролна работа 2
==================

Префикс на път между два върха в граф
-------------------------------------
Тук под граф ще имаме предвид краен неориентиран безтегловен граф.

Да се напише функция
`list<int> path_with_prefix(Graph& graph, queue<int>& prefix, int start, int end)`,
която по даден граф `graph`, опашка `prefix` и два върха `start` и `end`
намира път между върховете `start` и `end`, на който опашката `prefix` е
префикс. Ако няма такъв път, да се върне празен списък.

Напишете програма, която конструира примерен граф и опашка и тества функцията
`path_with_prefix`, като извежда намерения път.

### Пример
Нека имаме следния граф:

![Graph example](https://cdn.rawgit.com/dimitaruzunov/data-structures-fmi-2016/cddc11ba/homework/5/graph-example.svg 'Graph example')

Нека имаме и опашката `(22, 25, 42)`, която сме конструирали по следния начин:
```cpp
queue<int> prefix;
prefix.push(22);
prefix.push(25);
prefix.push(42);
```

* Извикването `path_with_prefix(graph, prefix, 22, 56)` трябва да върне
списъка `(22, 25, 42, 56)`
* Извикването `path_with_prefix(graph, prefix, 22, 10)` трябва да върне
списъка `(22, 25, 42, 10)`
* Извикването `path_with_prefix(graph, prefix, 22, 6)` трябва да върне
списъка `(22, 25, 42, 6)`
* Извикването `path_with_prefix(graph, prefix, 22, 42)` трябва да върне
списъка `(22, 25, 42)`
* Извикването `path_with_prefix(graph, prefix, 22, 25)` трябва да върне
списъка `()`
* Извикването `path_with_prefix(graph, prefix, 6, 10)` трябва да върне
списъка `()`
