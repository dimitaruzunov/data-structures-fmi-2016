Пресмятане на аритметични изрази
================================

Напишете програма, която пресмята аритметични изрази, представени чрез [обратен
полски запис](https://en.wikipedia.org/wiki/Reverse_Polish_notation)
(постфиксен запис).

Ето няколко примера за аритметични изрази, преобразувани от инфиксен запис в
обратен полски запис (постфиксен запис):

| Инфиксен запис   | Постфиксен запис |
| ---------------- | ---------------- |
| 4 + 2            | 4 2 +            |
| (18 + 3) * 2     | 18 3 + 2 *       |
| 18 * (3 + 2)     | 18 3 2 + *       |
| 18 + 3 * 2       | 18 3 2 * +       |
| 42 / 2 * (4 - 2) | 42 2 / 4 2 - *   |

Входни данни
------------
Аритметичните изрази в обратен полски запис се четат от файл `expressions.txt`.
Изразите са разделени със символа `;`.  
[Примерен файл](expressions.txt)

Изходни данни
-------------
Числата, получени в резултат от пресмятането на аритметичните изрази,
се записват в двоичен файл `results.bin`, като следват последователността
на аритметичните изрази в `expressions.txt`.