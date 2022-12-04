#include <SFML/Graphics.hpp>
#include <ctime>

using namespace sf;
#include "Settings.h"
int main()
{
    // Объект, который, собственно, является главным окном приложения
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGTH), WINDOW_TITLE);
    window.setFramerateLimit(FPS); 
  //Создани игровых объектов
    // Ракетки 
    RectangleShape leftbat, rightbat;
    leftbat.setSize(Vector2f(BAT_WIDTH, BAT_HEIGTH)); 
    leftbat.setPosition(BAT_OFFSET, (WINDOW_HEIGTH - BAT_HEIGTH) / 2 );
    leftbat.setFillColor(LEFT_BAT_COLOR); 
    rightbat.setSize(Vector2f(BAT_WIDTH, BAT_HEIGTH)); 
    rightbat.setPosition(WINDOW_WIDTH - BAT_WIDTH - BAT_OFFSET , (WINDOW_HEIGTH - BAT_HEIGTH) / 2 ); 
    rightbat.setFillColor(RIGHT_BAT_COLOR); 
// Мяч 
    CircleShape ball(BALL_RADIUS); 
    ball.setPosition((WINDOW_WIDTH - 2 * BALL_RADIUS) / 2,  (WINDOW_HEIGTH - 2 * BALL_RADIUS) / 2); 
    ball.setFillColor(BALL_COLOR); 
    float ball_speedx = 2.f; 
    float ball_speedy = 3.f; 

    // Главный цикл приложения. Выполняется, пока открыто окно
    while (window.isOpen())
    {
       
      
        // Обрабатываем очередь событий в цикле
        Event event;
        while (window.pollEvent(event))
        {
            // Пользователь нажал на «крестик» и хочет закрыть окно?
            if (event.type == Event::Closed)
                // тогда закрываем его
                window.close();
        }
        // обновление объектов игры.
        ball.move( ball_speedx ,ball_speedy);
        if (ball.getPosition().x <= 0 || (ball.getPosition().x + 2 * BALL_RADIUS) >= WINDOW_WIDTH) 
        {
            ball_speedx = -ball_speedx; 
        }

        if (ball.getPosition().y <= 0 || ball.getPosition().y + 2 * BALL_RADIUS >= WINDOW_HEIGTH )
        {
            ball_speedy = -ball_speedy; 
        }
        // отрисовка объектов и окна.
        window.clear();
        window.draw(leftbat);
        window.draw(rightbat);
        window.draw(ball); 

         
        

        // Отрисовка окна 
        window.display();
    }

    return 0;
}