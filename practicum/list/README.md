Списък
======

Ще използваме следните реализации на структурата от данни списък:
* `[std::list](http://www.cplusplus.com/reference/list/list)` –
двусвързан списък (свързано представяне)
* `[std::vector](http://www.cplusplus.com/reference/vector/vector)` –
динамичен масив (последователно представяне)

Конкатенация
------------
Да се напише функция
`vector<T> append(const vector<T>& first_list, const vector<T>& second_list`,
която конкатенира списъците `first_list` и `second_list` и връща нов списък –
резултата от конкатенацията.

[Решение](append.cpp)

Обръщане
--------
Да се напише функция `vector<T> reverse(const vector<T>& list)`, която
връща нов списък, чиито елементи са елементите на `list` в обратен ред.

[Решение](reverse.cpp)

Разделяне на две
----------------
Да се напише функция
`void split(const vector<T>& list, vector<T>& first_list, vector<T>& second_list)`,
която разделя списъка `list` на два нови списъка,
чиято дължина се различава с най-много единица. Двата нови списъка се пазят
в аргументите `first_list` и `second_list`.

[Решение](split.cpp)

Сливане на сортирани масиви
---------------------------
Да се напише функция
`vector<T> merge(const vector<T>& first_list, const vector<T>& second_list)`,
която слива сортираните във възходящ ред списъци `first_list` и `second_list`
и връща нов списък – резултата от сливането.

[Решение](merge.cpp)

Сортиране чрез сливане
----------------------
Да се напише функция `vector<T> merge_sort(const vector<T>& list)`, която
сортира списъка `list` чрез сливане
([merge sort](https://www.wikiwand.com/en/Merge_sort)).

[Решение](merge-sort.cpp)
