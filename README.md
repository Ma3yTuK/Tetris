# Курсовой проект
Cтудента группы 153502\
Матвеева Назара Сергеевича



## Тема:
Тетрис



## Диаграмма классов:
![Kursach](https://user-images.githubusercontent.com/80688100/222981709-47f8ebc0-720a-4ad0-aab8-9b9c82ed4434.svg)



## Описание классов и функций
### Класс GameLayout
Объект класса представляет собой матрицу, в ячейках которой храняться коды цветов соответствующих квадратов.

#### int operator()(int x, int y)
Перегрузка оператора () для доступа к ячейкам матрицы.

##
### Класс BasicForm
Родительский класс для всех фигур.

#### int getSquareHeight()
Функция возвращает высоту одного квадрата в пикселях.

#### int getSquareWidth()
Функция возвращает ширину одного квадрата в пикселях.

#### virtual GameLayout getLayout() = 0
Функция должна возращать объект GameLayout, который описывает текущее положение данной фигуры.

##
### Класс NotActiveForm
Объект класса представляет собой фигуру, включающую в себя все неактивные "упавшие" фигуры.

#### void include(BasicForm form)
Функция присоедияет фигуру form к данному объекту.

#### bool interefireWith(BasicForm form)
Функция проверяет, имеет ли фигура form и данный объект общие квадраты.

#### void removeFullLines()
Функция удаляет заполненные линии.

#### GameLayout getLayout()
Реализует BasicForm::GetLayout().

##
### Класс AbstractFigure
Родительский класс для для активных "падающих" фигур.

#### void rotateRight()
Поворачивает фигуру по часовой стрелке.

#### void rotateLeft()
Поворачивает фигуру против часовой стрелки.

#### void moveRight()
Сдвигает фигуру на один квадрат вправо.

#### void moveLeft()
Сдвигает фигуру на один квадрат влево.

#### void moveTop()
Сдвигает фигуру на один квадрат вверх.

#### void moveBot()
Сдвигает фигуру на один квадрат вниз.

#### virtual GameLayout getLayout() = 0
То же что и BasicForm::GetLayout().

##
### Классы RLShape, RGShape, Square, LLShape, LGShape, TShape
Реализуют BasicForm::GetLayout() для соответствующих фигур.

##
### Класс Game
Описывает взаимодействие между объектами и пользователем в процессе игры.

#### void timerEvent()
Событие, которое вызывается таймером timer. При вызове активная фигура смещается на один квадрат вниз, в случае если это невозможно, фигура становится неактивной, происходит удаление пустых строк и создается новая активная фигура.

#### void keyPressEvent()
Событие, вызывающееся нажатием пользователем на клавиатуру. В зависимости от нажатой клавиши происходит поворот или сдвиг фигуры.
