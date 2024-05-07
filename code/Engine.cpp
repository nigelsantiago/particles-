#include "Engine.h"
using namespace sf;
using namespace std;

Engine::Engine()
{
  unsigned int desktop_w = VideoMode::getDesktopMode().width; 
  unsigned int desktop_h = VideoMode::getDesktopMode().height;
  VideoMode vm(desktop_w, desktop_h);
  m_Window.create(vm, "Particles", Style::Default);
}

void Engine::input()
{
  //Particle p;
  //while (m_Window.isOpen())
	//{
        Event event;
        while (m_Window.pollEvent(event))
		    {
            if (event.type == Event::Closed)
            {
                m_Window.close();
            }
            else if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                m_Window.close();
            }
            else if (event.type == Event::MouseButtonPressed) 
            {
              if (event.mouseButton.button == sf::Mouse::Left)
	            {      
                for(int i = 0; i <= 5; i++) // 6 particles
                {
		              int numPoints = rand()%(50 - 42 + 1) + 42; //check rand formula
        	        Particle p(m_Window, numPoints, {event.mouseButton.x, event.mouseButton.y});
			            m_Particles.push_back(p);  // try storing the particle in tbe array?
                }
				// perform this randomly
				bonusFeature();
              }
            }
        }
  //}
}

void Engine::update(float dtAsSeconds)
{
	vector<Particle>::iterator iter;
	for (iter = m_Particles.begin(); iter != m_Particles.end();)
	{
		if (iter->getTTL() > 0.0)
		{
			iter->update(dtAsSeconds);
			iter++;
		}
		else
		{
			iter = m_Particles.erase(iter);
		}
	}
		
}

void Engine::draw()
{
	m_Window.clear();
	for (size_t i = 0; i < m_Particles.size(); i++)
	{
		m_Window.draw(m_Particles.at(i));
	}
	m_Window.display();		
}

void Engine::run()
{
  Clock clock;
  Time t;
  float s;
  
  cout << "Starting Particle unit tests..." << endl;
  Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
  p.unitTests();
  cout << "Unit tests complete.  Starting engine..." << endl;

  while(m_Window.isOpen())
  {
    t = clock.restart();
    s = t.asSeconds();
    
    input();
    update(s);
    draw();
  }
      
}

void Engine::bonusFeature()
{
	int num = rand() % 401;
	int xPos = rand() % (1281) + 320;
	int yPos = rand() % (801) + 200;
	cout << num << endl; //tester

	if (num > 300)
	{
		//int vX = 50;
		//slakoth
		Texture textureChar;
		textureChar.loadFromFile("graphics/slakoth.png"); // double check
		Sprite spriteChar;
		spriteChar.setTexture(textureChar);
		spriteChar.setPosition(xPos, yPos);
		
		m_Window.draw(spriteChar);
	}
	else if (num > 200)
	{
		//pikachu
		//int vX = -150;

		Texture textureChar;
		textureChar.loadFromFile("graphics/pikachu.png"); // double check
		Sprite spriteChar;
		spriteChar.setTexture(textureChar);
		spriteChar.setPosition(xPos, yPos);

		m_Window.draw(spriteChar);
	}
	else if (num > 100)
	{
		//mew
		//int vX = 200;
		//int vY = 250;

		Texture textureChar;
		textureChar.loadFromFile("graphics/mew1.jpeg"); // double check
		Sprite spriteChar;
		spriteChar.setTexture(textureChar);
		spriteChar.setPosition(xPos, yPos);

		m_Window.draw(spriteChar);
	}
	else
	{
		//linda

		Texture textureChar;
		textureChar.loadFromFile("graphics/linda.jpeg"); // double check
		Sprite spriteChar;
		spriteChar.setTexture(textureChar);
		spriteChar.setPosition(960, 540);

		m_Window.draw(spriteChar);
	}
}
