# Битовая реализация конечного числового множества неотрицательных чисел

Строго говоря, массив и множество не одно и то же.

Во-первых, массив, в отличие от множества, может содержать одно и то же значение в нескольких экземплярах.
Во-вторых, элементы в n-элементном множестве можно расположить n! способами, переставляя их.

Таким образом, массив содержит, кроме списка элементов, избыточную информацию об их упорядочении.
С учётом того, что имеется n! различных способов упорядочить множество, состоящее из nэлементов, количество дополнительной информации равно согласно формуле Хартли log₂n!.
Для множества из

- 10 элементов перерасход составит приблизительно 18,47 бит,
- для 100-элементного — 518,12,
- для 1000-элементного — 8519,43,
- для 10000-элементного — 118444,85,
- для 100000-элементного — 1516687,56,
- для 1000000-элементного — 18488864,88.

Конечное множество неотрицательных чисел удобно реализовать на базе воображаемого массива битов.
Присутствие числа i в множестве обозначается установкой i-го бита в массиве, отсутствие — очисткой соответствующего бита.
Например, множество простых чисел, не превосходящих 32, то есть { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 }, представляется в виде битового массива

```text
00110101 00010100 01010001 00000101
0        8       16       24        индексы битов в массиве
```

Биты в байтах принято нумеровать справа налево, так же, как и разряды в десятичных числах (в сущности, байты и есть восьмизначные двоичные числа).
Однако это наблюдение вынуждает нас скорректировать представления о битовом массиве.
Следует отразить каждый байт относительно его середины, и тогда следующая четырёхбайтная строка будет представлять собой рассмотренное ранее множество первых одиннадцати простых чисел:

```text
0       │1       │2       │3		номера байтов
10101100│00101000│10001010│10100000
76543210│76543210│76543210│76543210 номера битов в байтах
```

Общее количество бит кратно восьми, и с этим ничего поделать нельзя.
Это не проблема: лишние биты будут всё равно очищены.
По мере добавления чисел в множество, справа будут добавляться байты, при удалении чисел последние (правые) байты будут удаляться, если они полностью обнулятся.

Сначала научимся по индексу i бита в битовом массиве определять номер x того байта в строке, который содержит i-й бит, и положение y бита в этом байте.
Это несложно: x = i div 8 (целочисленное частное при делении i на 8), y = i mod 8 (остаток от деления i на 8).

Теперь самое время выяснить, как проверить, установлен ли в данном байте byte бит с данным номером или нет.
Для этого имеется стандартный приём.
Сначала подготовим вспомогательный байт mask — так называемую маску.
В маске должен быть установлен единственный бит — с номером y, остальные биты очищены.
Затем выполняем с байтами byte и mask операцию побитового «И».
Результатом операции побитового «И» над двумя байтами будет байт, каждый бит в котором получается в результате операции «И» над битами с теми же номерами в байтах-операндах.  
Если один из операндов операции побитового «И» является маской, в которой установлен лишь один бит с номером y, в результате может получиться или байт, равный маске, или полностью нулевой.
Нижеследующие примеры показывают, как проверить состояние битов № 3 и № 4 в байте 01001010 с помощью масок:

```text
    ╭──────	проверяемый бит
    ▼
01001010	байт byte
00001000	байт mask
────────
00001000	результат операции byte & mask


   ╭───────	проверяемый бит
   ▼
01001010	байт byte
00010000	байт mask
────────
00000000	результат операции byte & mask
```

Как же приготовить маску с единственным установленным битом № y ?
Можно взять выражение 2^y.
Лучше воспользоваться оператором << битового сдвига влево: выражение byte<<y возвращает байт, у которого все биты сдвинулись влево на y позиций.
Приводим иллюстрацию битового сдвига влево с байтом byte, имеющим значение 01001010, на три позиции:

```text
   01001010   исходный байт byte
01001010◄◄◄   сдвигаем биты на три позиции влево
╳╳╳01010000   три самых левых бита (вышедшие за левую границу байта)
              отбрасываются, а три самых правых бита очищаются
───────────
   01010000   результат операции byte<﻿<3
```

Если применить левый сдвиг на y позиций к единичному байту (значение 00000001), получится как раз байт со значением 2^y.
Это байт, в котором установлен лишь бит № y, что и требуется.
Таким образом, выражение 1<<y даёт более быстрый способ возвести двойку в неотрицательную степень y, чем 2^y.

Совершенно аналогично определяется операция >> правого сдвига.
Проиллюстрируем её на примере всё того же байта 01001010 и правого сдвига на четыре позиции:

```text
01001010      исходный байт byte
►►►►01001010  сдвигаем биты на четыре позиции вправо
00000100╳╳╳╳  четыре самых правых бита (вышедшие за правую границу байта)
              отбрасываются, а четыре самых левых бита очищаются
────────────
00000100      результат операции byte>>4
```

Операции левого и правого байтовых сдвигов дают альтернативный способ проверить состояние бита № y.
Сначала сдвигаем байт вправо на y позиций, а затем влево на 7 позиций:

```text
    ╭──────	проверяемый бит № y
    ▼
01001010	  исходный байт byte
       ╭─── проверяемый бит
►►►    ▼
00001001    результат операции byte>>y
╭────────── проверяемый бит
▼◄◄◄◄◄◄◄
10000000    результат операции (byte>>y)<﻿<7

```

Или наоборот, сначала сдвигаем влево на  7 − y позиций, а затем вправо на 7 позиций:

```text
    ╭────── проверяемый бит № y
    ▼
01001010    исходный байт byte
╭────────── проверяемый бит
▼   ◄◄◄◄
10100000    результат операции byte<﻿<(7-y)
       ╭─── проверяемый бит
►►►►►►►▼
00000001    результат операции (byte<﻿<(7-y))>>7
```

В обоих случаях значения выражений (byte>>y)<﻿<7 или (byte<﻿<(7-y))>>7 будет ненулевым (истинным) тогда и только тогда, когда y-й бит в байте byte установлен.
Первый способ предпочтительней, так как не требует дополнительного вычитания.

Суммируем все наши соображения насчёт проверки состояния y-го бита в байте byte. Любое из выражений

- byte&(1<﻿<y)
- (byte>>y)<﻿<7
- (byte<﻿<(7-y))>>7

истинно, только если бит установлен.

Теперь пора выяснить, как установить или очистить y-й бит в байте byte.
Тут нам опять поможет битовая маска.
Если с байтом и маской выполнить операцию | побитового «ИЛИ», бит будет установлен:

```text
   ╭─────── устанавливаемый бит
   ▼
01001010    байт byte
00010000    байт mask
────────
01011010    результат операции byte|mask
```

Для очистки бита следует выполнить операцию побитового «И», но не с исходной, а с дополнительной маской.
Дополнительная маска — это маска, подвергнутая операции ~ побитовой инверсии.
Операция побитовой инверсии меняет состояния всех битов в байте на противоположные:

```text
 ╭───────── очищаемый бит
 ▼
01001010    байт byte
10111111    байт ~mask (дополнительная маска)
────────
00001010    результат операции byte & ~mask
```

Итак, приводим выражения, которые устанавливают

```text
byte=byte|(1<<y)
```

или очищают

```text
byte=byte&~(1<<y)
```

y-й бит в байте byte.

Имеются комбинированные операторы &= и |=, сочетающие соответственно операторы побитового «И» и «ИЛИ» с присваиванием.
Поэтому приведённые команды можно записать короче:

```text
byte|=(1<<y)
```

и

```text
byte&=~(1<<y)
```