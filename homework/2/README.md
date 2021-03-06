Quicksort
=========

[Quicksort](https://en.wikipedia.org/wiki/Quicksort) е бърз алгоритъм
за сортиране на масиви от данни. Алгоритъмът се състои от три основни стъпки:

1. Избираме елемент, наречен `pivot`.
2. Разместваме елементите в масива така, че по-малките от `pivot` елементи
да са преди `pivot`, а по-големите от `pivot` елементи да са след `pivot`.
За елементите, равни на `pivot`, няма значение дали ще бъдат преди или след
`pivot`. След тази стъпка `pivot` се намира на правилната позиция. Тази стъпка
се нарича "разделяне" ("partitioning").
3. Рекурсивно прилагаме горните две стъпки върху подмасива с елементи, по-малки
от `pivot`, и върху подмасива с елементи, по-големи от `pivot`.

Изборът на `pivot` и "разделянето" са критични за бързината на алгоритъма и
могат да бъдат направени по няколко различни начина.

Доказано е, че за малки масиви (например, с по-малко от 10 елемента)
алгоритъмът [insertion sort](https://en.wikipedia.org/wiki/Insertion_sort)
работи по-бързо от `quicksort`.

Вашата задача е да имплементирате алгоритъма `quicksort`, като направите
следните оптимизации:
* Изборът на `pivot` да става по правилото "median-of-three": за `pivot` се
избира медианата на първия, средния и последния елемент в масива.
* За масиви, съдържащи по-малко от 10 елемента, да се прилага алгоритъмът
`insertion sort`.

Напишете програма, която тества алгоритъма.
