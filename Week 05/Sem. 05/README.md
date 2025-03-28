<h1> Задачи от семинар №5 на 06.11.2024 </h1>
<em> Забележка по условията: Приемете, че функциите могат да приемат още аргументи, освен тези, които са изрично зададени. Допълнителни аргументи ще са ви необходими за решаване на задачите. </em> <br />  <br />
<strong> Задача 1: </strong> Напишете функция, която намира стойността и индексът на най-голямия елемент на целочислен масив.
<br />
Пример:
<br />
Вход: <br />

```
1 6 8 200 14 27 30
```

Изход: <br />

```
200 3
```

Обяснение: <br />
Най-големият елемент на подадения масив е със стойност 200 и се намира на индекс 3 (напомняне, че броенето на индексите започва от 0!)
<br />
<br />

<strong> Задача 2: </strong> Напишете функция, която приема два сортирани целочислени масива с фиксиран размер 8 
и ги обединява, тоест създава трети масив, който съдържа сортирани елементите на двата Входни масива. Ако има дублиращи се елементи, те се записват в резултатния масив само веднъж.
<br />
Органичения: <br />
Входните масиви трябва да са с размер 8, да нямат за елемент 0, и в рамките на един масив едно число да се среща най-много веднъж (локална уникалност на елементите). <br />
Резултатният масив трябва да е с размер 16 и ако са останали незапълнени елементи след сливането, свободните места да се запълнят с 0. <br />
Примери: <br />
Вход: <br />

```
1 3 6 8 9 11 12 13
2 4 6 7 10 15 17 18

```
Изход: <br />

```
1 2 3 4 6 7 8 9 10 11 12 13 15 17 18 0
```

Обяснение: <br />
Уникалните елементи от двата масива са {1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 13, 15, 17, 18}. Понеже 6 се среща и в двата масива, го записваме само веднъж и така ни остават 15 уникални числа за масив от 16 елемента - свободният елемент се запълва с 0. <br />
Вход:

```
-9 -5 -3 1 2 7 9 10
3 4 5 6 8 11 12 13
```
Изход:

```
-9 -5 -3 1 2 3 4 5 6 7 8 9 10 11 12 13
```

Обяснение: <br />
Уникалните елементи от двата масива са {-9, -5, -3, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}. Няма нужда от допълване с 0.

Разяснение на алгоритъма: <br />
Тъй като масивите са сортирани по условие, знаем, че текущият най-малък елемент винаги ще е текущият елемент на един от двата масива. Пазим индекси, с които итерираме по трите масива.
Първоначално итерираме, докато не се запишат всички елементи на единия масив. За текущите елементи на двата масива: <br /> <br />
  Сравняваме ги <br /> <br />
  Добавяме в резултатния масив по-малкия <br /> <br />
  Увеличаваме индекса на масива, чийто елемент сме добавили <br /> <br />
  Така по-големият елемент си "чака реда" и ще бъде добавен, щом стане по-малък <br /> <br />
Със сигурност един от масивите ще свърши първи. Щом това стане, неговият индекс ще е станал равен на размера му (тоест невалиден индекс). Другият все още няма да е стигнал до там - от него остават още елементи, които трябва да бъдат прочетени. <br /> <br />
Следователно ако се опитаме да итерираме последователно по единия и по другия масив, елементите на единия ще бъдат добавени, а другият няма да влезе в цикъла, защото ще е изчерпан. <br /> <br />
Така изчерпваме и двата масива и резултатният масив е готов.
